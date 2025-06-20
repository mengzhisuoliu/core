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
#include "Vsdx.h"

#include "../DocxFormat/App.h"
#include "../DocxFormat/Core.h"

#include "FileTypes_Draw.h"

#include "../../DesktopEditor/common/SystemUtils.h"

#include "VisioDocument.h"
#include "VisioConnections.h"
#include "Shapes.h"


OOX::Draw::CVsdx::CVsdx() : OOX::IFileContainer(dynamic_cast<OOX::Document*>(this))
{
}
OOX::Draw::CVsdx::CVsdx(const CPath& oFilePath) : OOX::IFileContainer(dynamic_cast<OOX::Document*>(this))
{
	m_bVisioPages = true;
	Read( oFilePath );
}
OOX::Draw::CVsdx::~CVsdx()
{

}	
bool OOX::Draw::CVsdx::Read(const CPath& oFilePath)
{
	m_sDocumentPath = oFilePath.GetPath();

	OOX::CRels oRels(oFilePath / FILE_SEPARATOR_STR);
	IFileContainer::Read(oRels, oFilePath, oFilePath);

	m_pDocument = Find(FileTypes::Document).smart_dynamic_cast<Draw::CDocumentFile>();
	m_pApp = Find(OOX::FileTypes::App).smart_dynamic_cast<CApp>();
	m_pCore = Find(OOX::FileTypes::Core).smart_dynamic_cast<CCore>();
	
	m_pContentTypes = new CContentTypes(m_sDocumentPath);
	return true;
}
bool OOX::Draw::CVsdx::Write(const CPath& oDirPath, OOX::CContentTypes &oContentTypes)
{  
	IFileContainer::Write(oDirPath / L"" , OOX::CPath(L""), oContentTypes);

    oContentTypes.Write(oDirPath);
    return true;
}
//-----------------------------------------------------------------------------------------------------------------------------
