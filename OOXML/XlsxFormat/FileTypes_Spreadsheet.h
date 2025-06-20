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
#pragma once
#include "../DocxFormat/FileType.h"

namespace OOX
{
	namespace Spreadsheet
	{
		namespace FileTypes
		{
			extern const FileType Workbook;

			extern const FileType WorkbookMacro;

			extern const FileType SharedStrings;

			extern const FileType Styles;

			extern const FileType Worksheet;

			extern const FileType Chartsheets;

			extern const FileType CalcChain;

			extern const FileType ThreadedComments;

			extern const FileType Persons;

			extern const FileType Comments;

			extern const FileType Table;

			extern const FileType TableSingleCells;

			extern const FileType QueryTable;

			extern const FileType Connections;

			extern const FileType CtrlProp;

			extern const FileType Drawings;

			extern const FileType ExternalLinks;

			extern const FileType PivotTable;

			extern const FileType PivotCacheDefinition;

			extern const FileType PivotCacheRecords;

			extern const FileType SlicerCache;

			extern const FileType Slicer;

			extern const FileType NamedSheetView;

			extern const FileType XlBinaryIndex;

			//onlyoffice workbook comments
			extern const FileType WorkbookComments;

			extern const FileType SpreadsheetFlat;

			extern const FileType Timeline;

			extern const FileType TimelineCache;

			extern const FileType Metadata;

			extern const FileType RdRichValue;

			extern const FileType RdRichValueStructure;

			extern const FileType RdRichValueTypes;
			
			extern const FileType XmlMaps;
		} // namespace FileTypes
	}
} // namespace OOX
