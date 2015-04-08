#pragma once
#include "../PPTXShape.h"

namespace OOXMLShapes
{
	class CFlowChartDecision : public CPPTXShape
	{
		public:
			CFlowChartDecision()
			{
				LoadFromXML(
					_T("<ooxml-shape>")
					_T("<gdLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"ir\" fmla=\"*/ w 3 4\" />")
					  _T("<gd name=\"ib\" fmla=\"*/ h 3 4\" />")
					_T("</gdLst>")
					_T("<cxnLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<cxn ang=\"3cd4\">")
						_T("<pos x=\"hc\" y=\"t\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"cd2\">")
						_T("<pos x=\"l\" y=\"vc\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"cd4\">")
						_T("<pos x=\"hc\" y=\"b\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"0\">")
						_T("<pos x=\"r\" y=\"vc\" />")
					  _T("</cxn>")
					_T("</cxnLst>")
					_T("<rect l=\"wd4\" t=\"hd4\" r=\"ir\" b=\"ib\" xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\" />")
					_T("<pathLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<path w=\"2\" h=\"2\">")
						_T("<moveTo>")
						  _T("<pt x=\"0\" y=\"1\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"1\" y=\"0\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"2\" y=\"1\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"1\" y=\"2\" />")
						_T("</lnTo>")
						_T("<close />")
					  _T("</path>")
					_T("</pathLst>")
					_T("</ooxml-shape>")
				);
			}
	};
}