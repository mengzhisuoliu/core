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
// ASCOfficeXlsFileTest.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "../../Common/DocxFormat/Source/Base/Base.h"
#include "../../DesktopEditor/common/Directory.h"

#include "../source/XlsXlsxConverter/ConvertXls2Xlsx.h"
#include "../source/XlsXlsxConverter/progressCallback.h"

#include "../../OfficeUtils/src/OfficeUtils.h"

#pragma comment(lib,"Shell32.lib")	
#pragma comment(lib,"Advapi32.lib")

#if defined(_WIN64)
	#pragma comment(lib, "../../build/bin/icu/win_64/icuuc.lib")
#elif defined (_WIN32)

	#if defined(_DEBUG)
		#pragma comment(lib, "../../build/lib/win_32/DEBUG/graphics.lib")
		#pragma comment(lib, "../../build/lib/win_32/DEBUG/kernel.lib")
		#pragma comment(lib, "../../build/lib/win_32/DEBUG/UnicodeConverter.lib")
	#else
		#pragma comment(lib, "../../build/lib/win_32/graphics.lib")
		#pragma comment(lib, "../../build/lib/win_32/kernel.lib")
		#pragma comment(lib, "../../build/lib/win_32/UnicodeConverter.lib")
	#endif
	#pragma comment(lib, "../../build/bin/icu/win_32/icuuc.lib")
#endif

HRESULT convert_single(std::wstring srcFileName)
{
	HRESULT hr = S_OK;

	std::wstring outputDir		= NSDirectory::GetFolderPath(srcFileName);	
	std::wstring dstTempPath	= NSDirectory::CreateDirectoryWithUniqueName(outputDir);
	std::wstring dstPath;

	bool bMacros = true;
	hr = ConvertXls2Xlsx(srcFileName, dstTempPath, L"password", L"C:\\Windows\\Fonts", L"C:\\Windows\\Temp", 1049, bMacros);

	if (bMacros)
	{
		dstPath = srcFileName + L"-my.xlsm";
	}
	else
	{
		dstPath = srcFileName + L"-my.xlsx";

	}
	if (hr == S_OK) 
	{
		COfficeUtils oCOfficeUtils(NULL);
		hr = oCOfficeUtils.CompressFileOrDirectory(dstTempPath.c_str(), dstPath.c_str(), true);
	}
	
	NSDirectory::DeleteDirectory(dstTempPath);


	return hr;
}

HRESULT convert_directory(std::wstring pathName)
{
	HRESULT hr = S_OK;

	std::vector<std::wstring> arFiles = NSDirectory::GetFiles(pathName, false);

	for (size_t i = 0; i < arFiles.size(); i++)
	{
		convert_single(arFiles[i]);
	}
	return S_OK;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 2) return 1;

	HRESULT hr = -1;
	if (NSFile::CFileBinary::Exists(argv[1]))
	{	
		hr = convert_single(argv[1]);
	}
	else if (NSDirectory::Exists(argv[1]))
	{
		hr = convert_directory(argv[1]);
	}

	return hr;
}