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

#include "BgPr.h"

namespace PPTX
{
	namespace Logic
	{
		void BgPr::fromXML(XmlUtils::CXmlNode& node)
		{
			XmlMacroReadAttributeBase(node, L"shadeToTitle", shadeToTitle);
			
			std::vector<XmlUtils::CXmlNode> oNodes;
			if (node.GetNodes(L"*", oNodes))
			{
				size_t nCount = oNodes.size();
				for (size_t i = 0; i < nCount; ++i)
				{
					XmlUtils::CXmlNode& oNode = oNodes[i];

					std::wstring strName = XmlUtils::GetNameNoNS(oNode.GetName());

					if (L"blipFill" == strName ||
						L"gradFill" == strName ||
						L"grpFill" == strName ||
						L"noFill" == strName ||
						L"pattFill" == strName ||
						L"solidFill" == strName)
					{
						Fill.fromXML(oNode);
					}
					else if (L"effectDag" == strName ||
						L"effectLst" == strName)
					{
						EffectList.fromXML(oNode);
					}
				}
			}


			FillParentPointersForChilds();
		}
		std::wstring BgPr::toXML() const
		{
			XmlUtils::CAttribute oAttr;
			oAttr.Write(_T("shadeToTitle"), shadeToTitle);

			XmlUtils::CNodeValue oValue;
			oValue.Write(Fill);
			oValue.Write(EffectList);

			return XmlUtils::CreateNode(_T("p:bgPr"), oAttr, oValue);
		}
		void BgPr::toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
		{
			pWriter->StartNode(_T("p:bgPr"));

			pWriter->StartAttributes();
			pWriter->WriteAttribute(_T("shadeToTitle"), shadeToTitle);
			pWriter->EndAttributes();

			Fill.toXmlWriter(pWriter);
			EffectList.toXmlWriter(pWriter);

			pWriter->EndNode(_T("p:bgPr"));
		}
		void BgPr::toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
		{
			pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeStart);
			pWriter->WriteBool2(0, shadeToTitle);
			pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeEnd);

			pWriter->WriteRecord1(0, Fill);
			pWriter->WriteRecord1(1, EffectList);
		}
		void BgPr::fromPPTY(NSBinPptxRW::CBinaryFileReader* pReader)
		{
			LONG _end_rec = pReader->GetPos() + pReader->GetRecordSize() + 4;

			pReader->Skip(1); // start attributes

			while (true)
			{
				BYTE _at = pReader->GetUChar_TypeNode();
				if (_at == NSBinPptxRW::g_nodeAttributeEnd)
					break;

				if (0 == _at)
					shadeToTitle = pReader->GetBool();
				else
					break;
			}

			while (pReader->GetPos() < _end_rec)
			{
				BYTE _at = pReader->GetUChar();
				switch (_at)
				{
					case 0:
					{
						Fill.fromPPTY(pReader);
						break;
					}
					case 1:
					{
						EffectList.fromPPTY(pReader);
						break;
					}
					default:
						break;
				}
			}

			pReader->Seek(_end_rec);
		}
		void BgPr::FillParentPointersForChilds()
		{
			Fill.SetParentPointer(this);
			EffectList.SetParentPointer(this);
		}
	} // namespace Logic
} // namespace PPTX
