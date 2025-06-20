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

#include <string>
#include "../../../DesktopEditor/common/Types.h"

namespace NSBinPptxRW
{
	const double eps     = 0.001;

	const double g_dKoef_mm_to_pt = 72 / (2.54 * 10);
	const double g_dKoef_mm_to_twips = 20 * g_dKoef_mm_to_pt;
	const double g_dKoef_mm_to_emu = 36000;
	const double g_dKoef_mm_to_eightpoint = 8 * g_dKoef_mm_to_pt;

	const BYTE g_nodeAttributeStart = 0xFA;
	const BYTE g_nodeAttributeEnd	= 0xFB;

	const int g_nFormatVersionNoBase64 = 10;

	namespace NSSerFormat
	{
		enum SerFormat
		{
			Version		= 0,
			Signature	= 0x50505459
		};
	}

	namespace NSMainTables
	{
		enum MainTables
		{
			Main			= 255,
			App				= 1,
			Core			= 2,
			Presentation	= 3,
			ViewProps		= 4,
			VmlDrawing		= 5,
			TableStyles		= 6,
			PresProps		= 7,
			Customs			= 8,

			Themes			= 20,
			ThemeOverride	= 21,
			SlideMasters	= 22,
			SlideLayouts	= 23,
			Slides			= 24,
			NotesMasters	= 25,
			NotesSlides		= 26,

			HandoutMasters	= 30,

			SlideRels		= 40,
			ThemeRels		= 41,

			ImageMap		= 42,
			FontMap			= 43,

			FontsEmbedded	= 44,
			SlideNotesRels	= 45,
			NotesRels		= 46,
			NotesMastersRels= 47,
			CustomProperties= 48
		};
	}
}

#define COLOR_TYPE_NONE		0
#define COLOR_TYPE_SRGB		1
#define COLOR_TYPE_PRST		2
#define COLOR_TYPE_SCHEME	3
#define COLOR_TYPE_SYS		4
#define COLOR_TYPE_STYLE	5

#define FILL_TYPE_NONE		0
#define FILL_TYPE_BLIP		1
#define FILL_TYPE_NOFILL	2
#define FILL_TYPE_SOLID		3
#define FILL_TYPE_GRAD		4
#define FILL_TYPE_PATT		5
#define FILL_TYPE_GRP		6

#define EFFECT_TYPE_NONE				0
#define EFFECT_TYPE_OUTERSHDW			1
#define EFFECT_TYPE_GLOW				2
#define EFFECT_TYPE_DUOTONE				3
#define EFFECT_TYPE_XFRM				4
#define EFFECT_TYPE_BLUR				5
#define EFFECT_TYPE_PRSTSHDW			6
#define EFFECT_TYPE_INNERSHDW			7
#define EFFECT_TYPE_REFLECTION			8
#define EFFECT_TYPE_SOFTEDGE			9
#define EFFECT_TYPE_FILLOVERLAY			10
#define EFFECT_TYPE_ALPHACEILING		11
#define EFFECT_TYPE_ALPHAFLOOR			12
#define EFFECT_TYPE_TINTEFFECT			13
#define EFFECT_TYPE_RELOFF				14
#define EFFECT_TYPE_LUM					15
#define EFFECT_TYPE_HSL					16
#define EFFECT_TYPE_GRAYSCL				17
#define EFFECT_TYPE_ELEMENT				18
#define EFFECT_TYPE_ALPHAREPL			19
#define EFFECT_TYPE_ALPHAOUTSET			20
#define EFFECT_TYPE_ALPHAMODFIX			21
#define EFFECT_TYPE_ALPHABILEVEL		22
#define EFFECT_TYPE_BILEVEL				23
#define EFFECT_TYPE_DAG					24
#define EFFECT_TYPE_FILL				25
#define EFFECT_TYPE_CLRREPL				26
#define EFFECT_TYPE_CLRCHANGE			27
#define EFFECT_TYPE_ALPHAINV			28
#define EFFECT_TYPE_ALPHAMOD			29
#define EFFECT_TYPE_BLEND				30

#define GEOMETRY_TYPE_NONE				0
#define GEOMETRY_TYPE_PRST				1
#define GEOMETRY_TYPE_CUSTOM			2

#define GEOMETRY_TYPE_AH_NONE			0
#define GEOMETRY_TYPE_AH_POLAR			1
#define GEOMETRY_TYPE_AH_XY				2

#define GEOMETRY_TYPE_PATH_NONE			0
#define GEOMETRY_TYPE_PATH_MOVETO		1
#define GEOMETRY_TYPE_PATH_LINETO		2
#define GEOMETRY_TYPE_PATH_CLOZE		3
#define GEOMETRY_TYPE_PATH_CUBICBEZTO	4
#define GEOMETRY_TYPE_PATH_ARCTO		5
#define GEOMETRY_TYPE_PATH_QUADBEZTO	6

#define EFFECTPROPERTIES_TYPE_NONE		0
#define EFFECTPROPERTIES_TYPE_LIST		1
#define EFFECTPROPERTIES_TYPE_DAG		EFFECT_TYPE_DAG

#define BULLET_TYPE_COLOR_NONE			0
#define BULLET_TYPE_COLOR_CLRTX			1
#define BULLET_TYPE_COLOR_CLR			2

#define BULLET_TYPE_SIZE_NONE			0
#define BULLET_TYPE_SIZE_TX				1
#define BULLET_TYPE_SIZE_PCT			2
#define BULLET_TYPE_SIZE_PTS			3

#define BULLET_TYPE_TYPEFACE_NONE		0
#define BULLET_TYPE_TYPEFACE_TX			1
#define BULLET_TYPE_TYPEFACE_BUFONT		2

#define BULLET_TYPE_BULLET_NONE			0
#define BULLET_TYPE_BULLET_CHAR			1
#define BULLET_TYPE_BULLET_AUTONUM		2
#define BULLET_TYPE_BULLET_BLIP			3

#define PARRUN_TYPE_NONE				0
#define PARRUN_TYPE_RUN					1
#define PARRUN_TYPE_FLD					2
#define PARRUN_TYPE_BR					3
#define PARRUN_TYPE_MATH				4
#define PARRUN_TYPE_MATHPARA			5

#define SPTREE_TYPE_NONE				0
#define SPTREE_TYPE_SHAPE				1
#define SPTREE_TYPE_PIC					2
#define SPTREE_TYPE_CXNSP				3
#define SPTREE_TYPE_SPTREE				4
#define SPTREE_TYPE_GRFRAME				5
#define SPTREE_TYPE_OLE					6
#define SPTREE_TYPE_VIDEO				7
#define SPTREE_TYPE_AUDIO				8
#define SPTREE_TYPE_LOCKED_CANVAS		9

#define SPTREE_TYPE_ALTERNATIVE			0x99


#define DIAGRAM_LAYOUT_TYPE_NONE			0xB0
#define DIAGRAM_LAYOUT_TYPE_ALG				0xB1
#define DIAGRAM_LAYOUT_TYPE_CHOOSE			0xB2
#define DIAGRAM_LAYOUT_TYPE_CONSTRLST		0xB3
#define DIAGRAM_LAYOUT_TYPE_FOREACH			0xB4
#define DIAGRAM_LAYOUT_TYPE_LAYOUTNODE		0xB5
#define DIAGRAM_LAYOUT_TYPE_PRESOF			0xB6
#define DIAGRAM_LAYOUT_TYPE_RULELST			0xB7
#define DIAGRAM_LAYOUT_TYPE_SHAPE			0xB8
#define DIAGRAM_LAYOUT_TYPE_VARIABLELIST	0xB9


#define SPTREE_TYPE_MACRO					0xA1


static BYTE SchemeClr_GetBYTECode(const std::wstring& sValue)
{
    if ((L"accent1") == sValue)
		return 0;
    if ((L"accent2") == sValue)
		return 1;
    if ((L"accent3") == sValue)
		return 2;
    if ((L"accent4") == sValue)
		return 3;
    if ((L"accent5") == sValue)
		return 4;
    if ((L"accent6") == sValue)
		return 5;
    if ((L"bg1") == sValue)
		return 6;
    if ((L"bg2") == sValue)
		return 7;
    if ((L"dk1") == sValue)
		return 8;
    if ((L"dk2") == sValue)
		return 9;
    if ((L"folHlink") == sValue)
		return 10;
    if ((L"hlink") == sValue)
		return 11;
    if ((L"lt1") == sValue)
		return 12;
    if ((L"lt2") == sValue)
		return 13;
    if ((L"phClr") == sValue)
		return 14;
    if ((L"tx1") == sValue)
		return 15;
    if ((L"tx2") == sValue)
		return 16;
	return 0;
}
static std::wstring SchemeClr_GetStringCode(const BYTE& val)
{
	switch (val)
	{
	case 0:
        return (L"accent1");
	case 1:
        return (L"accent2");
	case 2:
        return (L"accent3");
	case 3:
        return (L"accent4");
	case 4:
        return (L"accent5");
	case 5:
        return (L"accent6");
	case 6:
        return (L"bg1");
	case 7:
        return (L"bg2");
	case 8:
        return (L"dk1");
	case 9:
        return (L"dk2");
	case 10:
        return (L"folHlink");
	case 11:
        return (L"hlink");
	case 12:
        return (L"lt1");
	case 13:
        return (L"lt2");
	case 14:
        return (L"phClr");
	case 15:
        return (L"tx1");
	case 16:
        return (L"tx2");
	}
    return (L"accent1");
}

#define XMLWRITER_DOC_TYPE_PPTX				0
#define XMLWRITER_DOC_TYPE_DOCX				1
#define XMLWRITER_DOC_TYPE_XLSX				2
#define XMLWRITER_DOC_TYPE_CHART			3
#define XMLWRITER_DOC_TYPE_WORDART			4
#define XMLWRITER_DOC_TYPE_GRAPHICS			5
#define XMLWRITER_DOC_TYPE_CHART_DRAWING	6
#define XMLWRITER_DOC_TYPE_DOCX_GLOSSARY	7
#define XMLWRITER_DOC_TYPE_DIAGRAM			8
#define XMLWRITER_DOC_TYPE_DSP_DRAWING		9
#define XMLWRITER_DOC_TYPE_VSDX				10

#define XMLWRITER_RECORD_TYPE_SPPR			0
#define XMLWRITER_RECORD_TYPE_CLRMAPOVR		1
#define XMLWRITER_RECORD_TYPE_TEXT_OUTLINE	2
#define XMLWRITER_RECORD_TYPE_TEXT_FILL		3
