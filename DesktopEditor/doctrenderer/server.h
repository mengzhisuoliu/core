﻿/*
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
#ifndef SERVER_SETTINGS_H
#define SERVER_SETTINGS_H

#include <string>
#include <map>
#include "../common/File.h"
#include "../common/StringBuilder.h"
#include <iostream>

// class for server version (disable local files and etc)
class CServerInstance
{
private:
	bool m_bIsEnabled;
	std::map<std::wstring, bool> m_arMapTmpFiles;

	CServerInstance()
	{
		m_bIsEnabled = false;
	}

public:
	static CServerInstance& getInstance()
	{
		static CServerInstance server;
		return server;
	}

	void Enable(const bool& enabled)
	{
		m_bIsEnabled = enabled;
	}

	bool IsEnable()
	{
		return m_bIsEnabled;
	}

	void AddTmpFile(const std::wstring& sFolder)
	{
		std::wstring sDirectory = sFolder + L"/media";
		NSStringUtils::string_replace(sDirectory, L"\\", L"/");
		std::map<std::wstring, bool>::iterator findDir = m_arMapTmpFiles.find(sDirectory);
		if (findDir == m_arMapTmpFiles.end())
			m_arMapTmpFiles.insert(std::make_pair(sDirectory, true));
	}

	void RemoveTmpFile(const std::wstring& sFolder)
	{
		std::wstring sDirectory = sFolder + L"/media";
		NSStringUtils::string_replace(sDirectory, L"\\", L"/");
		std::map<std::wstring, bool>::iterator findDir = m_arMapTmpFiles.find(sDirectory);
		if (findDir != m_arMapTmpFiles.end())
			m_arMapTmpFiles.erase(findDir);
	}

	bool CheckTmpDirectory(const std::wstring& sFile)
	{
		std::wstring sDirectory = NSFile::GetDirectoryName(sFile);
		NSStringUtils::string_replace(sDirectory, L"\\", L"/");
		std::map<std::wstring, bool>::iterator findDir = m_arMapTmpFiles.find(sDirectory);
		return (findDir != m_arMapTmpFiles.end()) ? true : false;
	}
};


#endif // SERVER_SETTINGS_H
