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

#include "CActionButtonDocument.h"

namespace OOXMLShapes
{
			CActionButtonDocument::CActionButtonDocument()
			{
				LoadFromXML(
					_T("<ooxml-shape>")
					_T("<gdLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"dx2\" fmla=\"*/ ss 3 8\" />")
					  _T("<gd name=\"g9\" fmla=\"+- vc 0 dx2\" />")
					  _T("<gd name=\"g10\" fmla=\"+- vc dx2 0\" />")
					  _T("<gd name=\"dx1\" fmla=\"*/ ss 9 32\" />")
					  _T("<gd name=\"g11\" fmla=\"+- hc 0 dx1\" />")
					  _T("<gd name=\"g12\" fmla=\"+- hc dx1 0\" />")
					  _T("<gd name=\"g13\" fmla=\"*/ ss 3 16\" />")
					  _T("<gd name=\"g14\" fmla=\"+- g12 0 g13\" />")
					  _T("<gd name=\"g15\" fmla=\"+- g9 g13 0\" />")
					_T("</gdLst>")
					_T("<cxnLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<cxn ang=\"0\">")
						_T("<pos x=\"r\" y=\"vc\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"cd4\">")
						_T("<pos x=\"hc\" y=\"b\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"cd2\">")
						_T("<pos x=\"l\" y=\"vc\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"3cd4\">")
						_T("<pos x=\"hc\" y=\"t\" />")
					  _T("</cxn>")
					_T("</cxnLst>")
					_T("<rect l=\"l\" t=\"t\" r=\"r\" b=\"b\" xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\" />")
					_T("<pathLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<path stroke=\"false\" extrusionOk=\"false\">")
						_T("<moveTo>")
						  _T("<pt x=\"l\" y=\"t\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"r\" y=\"t\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"r\" y=\"b\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"l\" y=\"b\" />")
						_T("</lnTo>")
						_T("<close />")
						_T("<moveTo>")
						  _T("<pt x=\"g11\" y=\"g9\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g14\" y=\"g9\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g12\" y=\"g15\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g12\" y=\"g10\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g11\" y=\"g10\" />")
						_T("</lnTo>")
						_T("<close />")
					  _T("</path>")
					  _T("<path stroke=\"false\" fill=\"darkenLess\" extrusionOk=\"false\">")
						_T("<moveTo>")
						  _T("<pt x=\"g11\" y=\"g9\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g14\" y=\"g9\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g14\" y=\"g15\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g12\" y=\"g15\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g12\" y=\"g10\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g11\" y=\"g10\" />")
						_T("</lnTo>")
						_T("<close />")
					  _T("</path>")
					  _T("<path stroke=\"false\" fill=\"darken\" extrusionOk=\"false\">")
						_T("<moveTo>")
						  _T("<pt x=\"g14\" y=\"g9\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g14\" y=\"g15\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g12\" y=\"g15\" />")
						_T("</lnTo>")
						_T("<close />")
					  _T("</path>")
					  _T("<path fill=\"none\" extrusionOk=\"false\">")
						_T("<moveTo>")
						  _T("<pt x=\"g11\" y=\"g9\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g14\" y=\"g9\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g12\" y=\"g15\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g12\" y=\"g10\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g11\" y=\"g10\" />")
						_T("</lnTo>")
						_T("<close />")
						_T("<moveTo>")
						  _T("<pt x=\"g12\" y=\"g15\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g14\" y=\"g15\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"g14\" y=\"g9\" />")
						_T("</lnTo>")
					  _T("</path>")
					  _T("<path fill=\"none\">")
						_T("<moveTo>")
						  _T("<pt x=\"l\" y=\"t\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"r\" y=\"t\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"r\" y=\"b\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"l\" y=\"b\" />")
						_T("</lnTo>")
						_T("<close />")
					  _T("</path>")
					_T("</pathLst>")
					_T("</ooxml-shape>")
				);
			}
}
