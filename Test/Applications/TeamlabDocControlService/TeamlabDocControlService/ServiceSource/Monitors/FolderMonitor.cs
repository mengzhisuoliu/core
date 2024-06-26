/*
 * (c) Copyright Ascensio System SIA 2010-2023
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-6 Ernesta Birznieka-Upish
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
using System;
using System.Collections.Generic;
using System.Text;
using System.Security.Permissions;
using System.IO;
using System.Diagnostics;

namespace TeamlabDocControlService.ServiceSource.Monitors
{
    public delegate void TeamlabSizeExceedEventHandler (object sender, double size);

    class FolderMonitor
    {
        private string mPath;
        private double mLimit = 10.0*1024.0*1024.0;    // 10 M
        private FileSystemWatcher mWatcher = null;
        private Object mSync = new Object();
        private Logger mLogger = null;

        public event TeamlabSizeExceedEventHandler SizeExceeded;

        public FolderMonitor(string path, Logger log)
        {
            mLogger = log;
            mPath = path;
            mWatcher = new FileSystemWatcher();
            mWatcher.NotifyFilter = NotifyFilters.Size;
            mWatcher.Path = mPath;
            mWatcher.Changed += new FileSystemEventHandler(OnChange);
        }
        public void Start()
        {
            mWatcher.EnableRaisingEvents = true;
        }
        public void Stop()
        {
            mWatcher.EnableRaisingEvents = false;
        }
        public void SetSizeLimit(float limit)
        {
            lock (mSync)
            {
                mLimit = limit;
            }
        }
        protected void OnChange(object source, FileSystemEventArgs e)
        {
            double size = ServiceHelpers.CalculateFolderSize(mPath, mLogger);
            
            // log it
            if (size > mLimit)
            {
                // fire event
                SizeExceeded(this, size);
            }
        }
    }
}
