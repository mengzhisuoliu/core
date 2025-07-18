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
#ifndef PPTX_LOGIC_TXBODY_INCLUDE_H_
#define PPTX_LOGIC_TXBODY_INCLUDE_H_

#include "./../WrapperWritingElement.h"

#include "BodyPr.h"
#include "TextListStyle.h"
#include "Paragraph.h"
#include "ShapeStyle.h"

namespace PPTX
{
	namespace Logic
	{
		class TxBody : public WrapperWritingElement
		{
		public:
			TxBody(std::wstring name = L"p:txBody");
			virtual ~TxBody();
			explicit TxBody(XmlUtils::CXmlNode& node);

			const TxBody& operator =(XmlUtils::CXmlNode& node);
			explicit TxBody(XmlUtils::CXmlLiteReader& oReader);
			const TxBody& operator =(XmlUtils::CXmlLiteReader& oReader);
			TxBody(const TxBody& oSrc);
			TxBody& operator=(const TxBody& oSrc);

			virtual void fromXML(XmlUtils::CXmlLiteReader& oReader);
			virtual void fromXML(XmlUtils::CXmlNode& node);

			virtual std::wstring toXML() const;
			std::wstring toVML();

			virtual void toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const;
			void toXmlWriterExcel(NSBinPptxRW::CXmlWriter* pWriter) const;

			std::wstring GetText(bool bParagraphSeparator = true) const;
			void Merge(nullable<TxBody>& txBody);

			virtual void toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const;
			virtual void fromPPTY(NSBinPptxRW::CBinaryFileReader* pReader);

			nullable<Sp3d>			sp3d;
			nullable<BodyPr>		bodyPr;
			nullable<TextListStyle> lstStyle;
			std::vector<Paragraph>	Paragrs;

			std::wstring			m_name;

		protected:
			virtual void FillParentPointersForChilds();

		public:
			std::wstring GetDocxTxBoxContent(NSBinPptxRW::CBinaryFileWriter* pWriter, const nullable<PPTX::Logic::ShapeStyle>& shape_style);
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_TXBODY_INCLUDE_H
