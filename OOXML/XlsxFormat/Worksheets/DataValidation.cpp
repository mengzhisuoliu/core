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
#include "DataValidation.h"

#include "../../XlsbFormat/Biff12_unions/DVALS.h"
#include "../../XlsbFormat/Biff12_unions/DVALS14.h"
#include "../../XlsbFormat/Biff12_records/BeginDVals.h"
#include "../../XlsbFormat/Biff12_records/BeginDVals14.h"
#include "../../XlsbFormat/Biff12_records/CommonRecords.h"
#include "../../../MsBinaryFile/XlsFile/Format/Logic/Biff_structures/BIFF12/DValStrings.h"

#include "../../Common/SimpleTypes_Spreadsheet.h"
#include "../../Common/SimpleTypes_Shared.h"
#include "../../../MsBinaryFile/XlsFile/Format/Binary/CFStreamCacheWriter.h"


namespace OOX
{
	namespace Spreadsheet
	{
		CDataValidationFormula::CDataValidationFormula(OOX::Document *pMain) : WritingElement(pMain)
		{
		}
		CDataValidationFormula::~CDataValidationFormula()
		{
		}
		void CDataValidationFormula::fromXML(XmlUtils::CXmlNode& node)
		{
		}
		std::wstring CDataValidationFormula::toXML() const
		{
			return L"";
		}
		void CDataValidationFormula::toXML(NSStringUtils::CStringBuilder& writer) const
		{
			toXML2(writer, false);
		}
		EElementType CDataValidationFormula::getType () const
		{
			return et_x_DataValidationFormula;
		}
		void CDataValidationFormula::toXML2(NSStringUtils::CStringBuilder& writer, bool bExtendedWrite) const
		{
			std::wstring node_name = bExtendedWrite ? L"xm:f" : L"formula";

			writer.WriteString(L"<" + node_name + L">");
			writer.WriteEncodeXmlString(m_sText);
			writer.WriteString(L"</" + node_name + L">");
		}
		void CDataValidationFormula::fromXML(XmlUtils::CXmlLiteReader& oReader)
	{
		m_sNodeName = oReader.GetName();

		m_sText = oReader.GetText3();
	}

		CDataValidation::CDataValidation(OOX::Document *pMain) : WritingElement(pMain)
		{
		}
		CDataValidation::~CDataValidation()
		{
		}
		void CDataValidation::fromXML(XmlUtils::CXmlNode& node)
		{
		}
		std::wstring CDataValidation::toXML() const
		{
			return L"";
		}
		EElementType CDataValidation::getType () const
		{
			return et_x_DataValidation;
		}
		void CDataValidation::toXML(NSStringUtils::CStringBuilder& writer) const
		{
			toXML2(writer, false);
		}
		void CDataValidation::toXML2(NSStringUtils::CStringBuilder& writer, bool bExtendedWrite) const
		{
			if (!m_oSqRef.IsInit())  return;

			std::wstring node_name = bExtendedWrite ? L"x14:dataValidation" : L"dataValidation";

			writer.WriteString(L"<" + node_name);
			if (bExtendedWrite)
			{
				if (false == m_oUuid.IsInit())
				{
					m_oUuid = L"{" + XmlUtils::GenerateGuid() + L"}";
				}
				WritingStringNullableAttrString(L"xr:uid", m_oUuid, m_oUuid.get());
			}
			else
			{
				WritingStringNullableAttrString(L"sqref", m_oSqRef, m_oSqRef.get());
			}
			WritingStringNullableAttrString(L"type", m_oType, m_oType->ToString());
			WritingStringNullableAttrInt(L"allowBlank", m_oAllowBlank, m_oAllowBlank->GetValue());
			WritingStringNullableAttrEncodeXmlStringHHHH(L"error", m_oError, m_oError.get());
			WritingStringNullableAttrString(L"errorStyle", m_oErrorStyle, m_oErrorStyle->ToString());
			WritingStringNullableAttrEncodeXmlStringHHHH(L"errorTitle", m_oErrorTitle, m_oErrorTitle.get());
			WritingStringNullableAttrString(L"imeMode", m_oImeMode, m_oImeMode->ToString());
			WritingStringNullableAttrString(L"operator", m_oOperator, m_oOperator->ToString());
			WritingStringNullableAttrEncodeXmlStringHHHH(L"prompt", m_oPrompt, m_oPrompt.get());
			WritingStringNullableAttrEncodeXmlStringHHHH(L"promptTitle", m_oPromptTitle, m_oPromptTitle.get());
			WritingStringNullableAttrInt(L"showDropDown", m_oShowDropDown, m_oShowDropDown->GetValue());
			WritingStringNullableAttrInt(L"showErrorMessage", m_oShowErrorMessage, m_oShowErrorMessage->GetValue());
			WritingStringNullableAttrInt(L"showInputMessage", m_oShowInputMessage, m_oShowInputMessage->GetValue());
			writer.WriteString(L">");

			if (bExtendedWrite)
			{
				if (m_oFormula1.IsInit())
				{
					writer.WriteString(L"<x14:formula1>");
					m_oFormula1->toXML2(writer, true);
					writer.WriteString(L"</x14:formula1>");
				}
				if (m_oFormula2.IsInit())
				{
					writer.WriteString(L"<x14:formula2>");
					m_oFormula2->toXML2(writer, true);
					writer.WriteString(L"</x14:formula2>");
				}
				if (m_oSqRef.IsInit())
				{
					writer.WriteString(L"<xm:sqref>" + m_oSqRef.get() + L"</xm:sqref>");
				}
			}
			else
			{
				if (m_oList.IsInit())
				{
					writer.WriteString(L"<mc:AlternateContent \
xmlns:x12ac=\"http://schemas.microsoft.com/office/spreadsheetml/2011/1/ac\" \
xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\">");

					writer.WriteString(L"<mc:Choice Requires=\"x12ac\">");
					writer.WriteString(L"<x12ac:list>" + *m_oList + L"</x12ac:list>");
					writer.WriteString(L"</mc:Choice>");

					writer.WriteString(L"<mc:Fallback>");
				}
				if (m_oFormula1.IsInit())
				{
					writer.WriteString(L"<formula1>");
					writer.WriteEncodeXmlString(m_oFormula1->m_sText);
					writer.WriteString(L"</formula1>");
				}
				if (m_oFormula2.IsInit())
				{
					writer.WriteString(L"<formula2>");
					writer.WriteEncodeXmlString(m_oFormula2->m_sText);
					writer.WriteString(L"</formula2>");
				}
				if (m_oList.IsInit())
				{
					writer.WriteString(L"</mc:Fallback>");
					writer.WriteString(L"</mc:AlternateContent>");
				}
			}
			writer.WriteString(L"</" + node_name + L">");
		}
		bool CDataValidation::IsExtended()
		{
			if (m_oList.IsInit()) return false;

			bool result1 = true, result2 = true;
			if (m_oFormula1.IsInit())
			{
				if (m_oFormula1->m_sText.find(L"!") != std::wstring::npos && m_oFormula1->m_sText != L"#REF!")
					result1 = false;

				//if ((m_oFormula1->m_sText.size() > 2) && (m_oFormula1->m_sText[0] == L'\"' && m_oFormula1->m_sText.back() == L'\"'))
				//	result1 = false;
			}else result1 = false;

			if (m_oFormula2.IsInit())
			{
				if (m_oFormula2->m_sText.find(L"!") != std::wstring::npos && m_oFormula2->m_sText != L"#REF!")
					result2 = false;

				//if ((m_oFormula2->m_sText.size() > 2) && (m_oFormula2->m_sText[0] == L'\"' && m_oFormula2->m_sText.back() == L'\"'))
				//	result2 = false;
			}else result2 = false;

			return result1 || result2;
		}
		XLS::BaseObjectPtr CDataValidation::toBin()
		{
			auto ptr(new XLSB::DVal);
			XLS::BaseObjectPtr objectPtr(ptr);
            if(m_oType.IsInit())
            {
                if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeNone)
                    ptr->valType = XLS::typeDvNone;
                else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeWhole)
                    ptr->valType = XLS::typeDvWhole;
                else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDecimal)
                    ptr->valType = XLS::typeDvDecimal;
                else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeList)
                    ptr->valType = XLS::typeDvList;
                else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDate)
                    ptr->valType = XLS::typeDvDate;
                else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTime)
                    ptr->valType = XLS::typeDvTime;
                else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTextLength)
                    ptr->valType = XLS::typeDvTextLength;
                else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeCustom)
                    ptr->valType = XLS::typeDvCustom;
                else
                    ptr->valType = XLS::typeDvNone;
            }
            else
                ptr->valType = XLS::typeDvNone;
			if(m_oAllowBlank.IsInit())
				ptr->fAllowBlank = m_oAllowBlank->GetValue();
			else
				ptr->fAllowBlank = false;
			if(m_oError.IsInit())
				ptr->Error = m_oError.get();
			else
				ptr->Error = L"";

			if (m_oErrorTitle.IsInit())
				ptr->ErrorTitle = m_oErrorTitle.get();
			else
				ptr->ErrorTitle = L"";

			if (m_oPrompt.IsInit())
				ptr->Prompt = m_oPrompt.get();
			else
				ptr->Prompt = L"";

			if (m_oPromptTitle.IsInit())
				ptr->PromptTitle = m_oPromptTitle.get();
			else
				ptr->PromptTitle = L"";
            if(m_oErrorStyle.IsInit())
                ptr->errStyle = m_oErrorStyle->GetValue();
            else
                ptr->errStyle = 0;
            if(m_oImeMode.IsInit())
            {
                if(m_oImeMode == SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOn)
                {
                    ptr->mdImeMode = 0x01;
                }
                else if(m_oImeMode == SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOff)
                {
                    ptr->mdImeMode = 0x02;
                }
                else
                {
                    ptr->mdImeMode = m_oImeMode->GetValue();
                }
            }
            else
                 ptr->mdImeMode = 0;
            if(m_oOperator.IsInit())
            {
                if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorBetween)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvBetween;
                else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotBetween)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvNotBetween;
                else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorEqual)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvEquals;
                else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotEqual)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvNotEquals;
                else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThan)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvGreaterThan;
                else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThan)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvLessThan;
                else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThanOrEqual)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvGreaterThanOrEqual;
                else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThanOrEqual)
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvLessThanOrEqual;
                else
                    ptr->typOperator = XLS::_typOperatorDv::operatorDvBetween;
            }
            else
                ptr->typOperator = XLS::_typOperatorDv::operatorDvBetween;

            if(m_oShowDropDown.IsInit())
                ptr->fSuppressCombo = m_oShowDropDown->GetValue();
            else
                ptr->fSuppressCombo = false;
            if(m_oShowErrorMessage.IsInit())
                ptr->fShowErrorMsg = m_oShowErrorMessage->GetValue();
            else
                ptr->fShowErrorMsg = false;
            if(m_oShowInputMessage.IsInit())
                ptr->fShowInputMsg = m_oShowInputMessage->GetValue();
            else
                ptr->fShowInputMsg = false;
            if(m_oSqRef.IsInit())
			ptr->sqrfx.strValue = m_oSqRef.get();

            if(m_oFormula1.IsInit())
                ptr->formula1 = m_oFormula1->m_sText;	
            if(m_oFormula2.IsInit())
            	ptr->formula2 = m_oFormula2->m_sText;

            return objectPtr;
		}
        void CDataValidation::toBin(XLS::StreamCacheWriterPtr& writer)
        {
            BYTE valType = 0;
            BYTE typOperator = 0;
            auto record = writer->getNextRecord(XLSB::rt_DVal);
            {
                _UINT32 flags = 0;
                if(m_oType.IsInit())
                {
                    if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeNone)
                        valType = XLS::typeDvNone;
                    else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeWhole)
                        valType = XLS::typeDvWhole;
                    else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDecimal)
                        valType =  XLS::typeDvDecimal;
                    else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeList)
                        valType =  XLS::typeDvList;
                    else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDate)
                        valType =  XLS::typeDvDate;
                    else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTime)
                        valType =  XLS::typeDvTime;
                    else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTextLength)
                        valType = XLS::typeDvTextLength;
                    else if (m_oType->GetValue() == SimpleTypes::Spreadsheet::EDataValidationType::validationTypeCustom)
                        valType = XLS::typeDvCustom;
                }
                SETBITS(flags, 0, 3, valType)
                if(m_oErrorStyle.IsInit())
                    SETBITS(flags, 4, 6, m_oErrorStyle->GetValue())
                if(m_oAllowBlank.IsInit())
                    SETBIT(flags, 8, m_oAllowBlank->GetValue())
                if(m_oShowDropDown.IsInit())
                    SETBIT(flags, 9, m_oShowDropDown->GetValue())
                if(m_oImeMode.IsInit())
                {
                    if(m_oImeMode == SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOn)
                    {
                        SETBITS(flags, 10, 17, 1)
                    }
                    else if(m_oImeMode == SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOff)
                    {
                        SETBITS(flags, 10, 17, 2)
                    }
                    else
                    {
                        SETBITS(flags, 10, 17, m_oImeMode->GetValue())
                    }
                }
                if(m_oShowInputMessage.IsInit())
                    SETBIT(flags, 18, m_oShowInputMessage->GetValue())
                if(m_oShowErrorMessage.IsInit())
                    SETBIT(flags, 19, m_oShowErrorMessage->GetValue())
                if(m_oOperator.IsInit())
                {
                    if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorBetween)
                        typOperator = XLS::_typOperatorDv::operatorDvBetween;
                    else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotBetween)
                        typOperator = XLS::_typOperatorDv::operatorDvNotBetween;
                    else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorEqual)
                        typOperator = XLS::_typOperatorDv::operatorDvEquals;
                    else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotEqual)
                        typOperator = XLS::_typOperatorDv::operatorDvNotEquals;
                    else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThan)
                        typOperator = XLS::_typOperatorDv::operatorDvGreaterThan;
                    else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThan)
                        typOperator = XLS::_typOperatorDv::operatorDvLessThan;
                    else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThanOrEqual)
                        typOperator = XLS::_typOperatorDv::operatorDvGreaterThanOrEqual;
                    else if (m_oOperator->GetValue() == SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThanOrEqual)
                        typOperator = XLS::_typOperatorDv::operatorDvLessThanOrEqual;
                }
                SETBITS(flags, 20, 23, typOperator)
                *record << flags;
            }
            {
                XLSB::UncheckedSqRfX ref;
                if(m_oSqRef.IsInit())
                    ref.strValue = m_oSqRef.get();
                *record << ref;
            }
            {
                XLSB::DValStrings dvalstr;
                if (m_oPromptTitle.IsInit())
                    dvalstr.strPromptTitle = m_oPromptTitle.get();
                else
                    dvalstr.strPromptTitle.setSize(0xFFFFFFFF);
                if(m_oErrorTitle.IsInit())
                    dvalstr.strErrorTitle = m_oErrorTitle.get();
                else
                    dvalstr.strErrorTitle.setSize(0xFFFFFFFF);
                if(m_oPrompt.IsInit())
                    dvalstr.strPrompt = m_oPrompt.get();
                else
                    dvalstr.strPrompt.setSize(0xFFFFFFFF);
                if(m_oError.IsInit())
                    dvalstr.strError = m_oError.get();
                else
                    dvalstr.strError.setSize(0xFFFFFFFF);
                *record << dvalstr;
            }
            {
                XLS::DVParsedFormula formula1;
                XLS::DVParsedFormula formula2;
                if(m_oFormula1.IsInit())
                    formula1 = m_oFormula1->m_sText;
                if(m_oFormula2.IsInit())
                    formula2 = m_oFormula2->m_sText;
                formula1.save(*record, valType != XLS::typeDvNone);
                formula2.save(*record, valType != XLS::typeDvCustom && valType != XLS::typeDvList && valType != XLS::typeDvNone && typOperator < 2);
            }

            writer->storeNextRecord(record);
        }
		void CDataValidation::fromBin(XLS::BaseObjectPtr& obj)
		{
			ReadAttributes(obj);
		}
		void CDataValidation::ReadAttributes(XLS::BaseObjectPtr& obj)
		{
			if(obj->get_type() == XLS::typeDv)
			{
				auto ptr = static_cast<XLSB::DVal*>(obj.get());
				if(ptr != nullptr)
				{
					switch (ptr->valType)
					{
						case 0x0:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeNone; break;
						case 0x1:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeWhole; break;
						case 0x2:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDecimal; break;
						case 0x3:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeList; break;
						case 0x4:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDate; break;
						case 0x5:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTime; break;
						case 0x6:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTextLength; break;
						case 0x7:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeCustom; break;
					}

					m_oAllowBlank       = ptr->fAllowBlank;

					if(!ptr->Error.empty())
						m_oError = ptr->Error;

					if(!ptr->ErrorTitle.empty())
						m_oErrorTitle = ptr->ErrorTitle;

					if(!ptr->Prompt.empty())
						m_oPrompt = ptr->Prompt;

					if(!ptr->PromptTitle.empty())
						m_oPromptTitle = ptr->PromptTitle;

					m_oErrorStyle = (SimpleTypes::Spreadsheet::EDataValidationErrorStyle)ptr->errStyle;

					switch (ptr->mdImeMode)
					{
						case 0x01: m_oImeMode = SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOn; break;
						case 0x02: m_oImeMode = SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOff; break;
					default:
						m_oImeMode = (SimpleTypes::Spreadsheet::EDataValidationImeMode)ptr->mdImeMode; break;
					}

					switch (ptr->typOperator)
					{
						case XLS::_typOperatorDv::operatorDvBetween:            m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorBetween; break;
						case XLS::_typOperatorDv::operatorDvNotBetween:         m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotBetween; break;
						case XLS::_typOperatorDv::operatorDvEquals:             m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorEqual; break;
						case XLS::_typOperatorDv::operatorDvNotEquals:          m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotEqual; break;
						case XLS::_typOperatorDv::operatorDvGreaterThan:        m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThan; break;
						case XLS::_typOperatorDv::operatorDvLessThan:           m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThan; break;
						case XLS::_typOperatorDv::operatorDvGreaterThanOrEqual: m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThanOrEqual; break;
						case XLS::_typOperatorDv::operatorDvLessThanOrEqual:    m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThanOrEqual; break;
					}

					m_oShowDropDown     = ptr->fSuppressCombo;
					m_oShowErrorMessage = ptr->fShowErrorMsg;
					m_oShowInputMessage = ptr->fShowInputMsg;

					m_oSqRef            = ptr->sqrfx.strValue;

					auto f1 = ptr->formula1.getAssembledFormula();
					auto f2 = ptr->formula2.getAssembledFormula();
					if(!f1.empty())
					{
						m_oFormula1 = new CDataValidationFormula(m_pMainDocument);
						m_oFormula1->m_sNodeName = L"formula";
						m_oFormula1->m_sText = f1;
					}
					if(!f2.empty())
					{
						m_oFormula2 = new CDataValidationFormula(m_pMainDocument);
						m_oFormula2->m_sNodeName = L"formula";
						m_oFormula2->m_sText = f2;
					}

				}
			}
			else if(obj->get_type() == XLS::typeDVal14)
			{
				auto ptr = static_cast<XLSB::DVal14*>(obj.get());
				if(ptr != nullptr)
				{
					switch (ptr->valType)
					{
						case 0x0:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeNone; break;
						case 0x1:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeWhole; break;
						case 0x2:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDecimal; break;
						case 0x3:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeList; break;
						case 0x4:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeDate; break;
						case 0x5:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTime; break;
						case 0x6:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeTextLength; break;
						case 0x7:   m_oType = SimpleTypes::Spreadsheet::EDataValidationType::validationTypeCustom; break;
					}

					m_oAllowBlank       = ptr->fAllowBlank;

					if(!ptr->Error.empty())
						m_oError = ptr->Error;

					if(!ptr->ErrorTitle.empty())
						m_oErrorTitle = ptr->ErrorTitle;

					if(!ptr->Prompt.empty())
						m_oPrompt = ptr->Prompt;

					if(!ptr->PromptTitle.empty())
						m_oPromptTitle = ptr->PromptTitle;

					m_oErrorStyle = (SimpleTypes::Spreadsheet::EDataValidationErrorStyle)ptr->errStyle;

					switch (ptr->mdImeMode)
					{
						case 0x01: m_oImeMode = SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOn; break;
						case 0x02: m_oImeMode = SimpleTypes::Spreadsheet::EDataValidationImeMode::imeModeOff; break;
					default:
						m_oImeMode = (SimpleTypes::Spreadsheet::EDataValidationImeMode)ptr->mdImeMode; break;
					}

					switch (ptr->typOperator)
					{
						case XLS::_typOperatorDv::operatorDvBetween:            m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorBetween; break;
						case XLS::_typOperatorDv::operatorDvNotBetween:         m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotBetween; break;
						case XLS::_typOperatorDv::operatorDvEquals:             m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorEqual; break;
						case XLS::_typOperatorDv::operatorDvNotEquals:          m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorNotEqual; break;
						case XLS::_typOperatorDv::operatorDvGreaterThan:        m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThan; break;
						case XLS::_typOperatorDv::operatorDvLessThan:           m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThan; break;
						case XLS::_typOperatorDv::operatorDvGreaterThanOrEqual: m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorGreaterThanOrEqual; break;
						case XLS::_typOperatorDv::operatorDvLessThanOrEqual:    m_oOperator = SimpleTypes::Spreadsheet::EDataValidationOperator::operatorLessThanOrEqual; break;
					}

					m_oShowDropDown     = ptr->fSuppressCombo;
					m_oShowErrorMessage = ptr->fShowErrorMsg;
					m_oShowInputMessage = ptr->fShowInputMsg;

					if(ptr->FRTheader.fSqref && !ptr->FRTheader.rgSqrefs.array.empty())
						m_oSqRef = ptr->FRTheader.rgSqrefs.array[0].sqrfx.strValue;

					if(ptr->fDVMinFmla && ptr->FRTheader.rgFormulas.array.size() > 0)
					{
						auto f1 = ptr->FRTheader.rgFormulas.array[0].formula.getAssembledFormula();
						if(!f1.empty())
						{
							m_oFormula1 = new CDataValidationFormula(m_pMainDocument);
							m_oFormula1->m_sNodeName = L"formula";
							m_oFormula1->m_sText = f1;
						}
					}

					if(ptr->fDVMaxFmla && ptr->FRTheader.rgFormulas.array.size() > 1)
					{
						auto f2 = ptr->FRTheader.rgFormulas.array[1].formula.getAssembledFormula();
						if(!f2.empty())
						{
							m_oFormula2 = new CDataValidationFormula(m_pMainDocument);
							m_oFormula2->m_sNodeName = L"formula";
							m_oFormula2->m_sText = f2;
						}
					}
				}
			}
		}
		void CDataValidation::ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
		{

			WritingElement_ReadAttributes_StartChar( oReader )
				WritingElement_ReadAttributes_Read_ifChar		( oReader, "allowBlank",	m_oAllowBlank)
				else if ( strcmp("error", wsName) == 0 )
				{
					m_oError = oReader.GetAttributeTextWithHHHH();
				}
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "errorStyle",	m_oErrorStyle)
				else if ( strcmp("errorTitle", wsName) == 0 )
				{
					m_oErrorTitle = oReader.GetAttributeTextWithHHHH();
				}
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "imeMode",		m_oImeMode)
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "operator",		m_oOperator)
				else if ( strcmp("prompt", wsName) == 0 )
				{
					m_oPrompt = oReader.GetAttributeTextWithHHHH();
				}
				else if ( strcmp("promptTitle", wsName) == 0 )
				{
					m_oPromptTitle = oReader.GetAttributeTextWithHHHH();
				}
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "showDropDown",	m_oShowDropDown)
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "showErrorMessage",m_oShowErrorMessage)
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "showInputMessage",m_oShowInputMessage)
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "sqref",			m_oSqRef)
				WritingElement_ReadAttributes_Read_else_ifChar	( oReader, "type",			m_oType)
			WritingElement_ReadAttributes_EndChar( oReader )
		}

		CDataValidations::CDataValidations(OOX::Document *pMain) : WritingElementWithChilds<CDataValidation>(pMain)
		{
		}
		CDataValidations::~CDataValidations()
		{
		}
		void CDataValidations::fromXML(XmlUtils::CXmlNode& node)
		{
		}
		std::wstring CDataValidations::toXML() const
		{
			return L"";
		}
		EElementType CDataValidations::getType () const
		{
			return et_x_DataValidations;
		}
		void CDataValidations::toXML(NSStringUtils::CStringBuilder& writer) const
		{
			if (m_arrItems.empty()) return;

			toXML2(writer, false);
		}
		void CDataValidations::toXML2(NSStringUtils::CStringBuilder& writer, bool bExtendedWrite) const
		{
			if (m_arrItems.empty()) return;

			if (false == m_oCount.IsInit())
			{
				m_oCount = (int)m_arrItems.size();
			}
			std::wstring node_name = bExtendedWrite ? L"x14:dataValidations" : L"dataValidations";

			writer.WriteString(L"<" + node_name);
				if (bExtendedWrite)
				{
					WritingStringAttrString(L"xmlns:xm", L"http://schemas.microsoft.com/office/excel/2006/main");
				}
				WritingStringNullableAttrInt(L"count",			m_oCount,			*m_oCount);
				WritingStringNullableAttrInt(L"disablePrompts", m_oDisablePrompts,	m_oDisablePrompts->GetValue());
				WritingStringNullableAttrInt(L"xWindow",		m_oXWindow,			m_oXWindow->GetValue());
				WritingStringNullableAttrInt(L"yWindow",		m_oYWindow,			m_oYWindow->GetValue());
			writer.WriteString(L">");
			for ( size_t i = 0; i < m_arrItems.size(); ++i)
			{
				if ( m_arrItems[i] )
				{
					m_arrItems[i]->toXML2(writer, bExtendedWrite);
				}
			}
			writer.WriteString(L"</" + node_name + L">");
		}
		void CDataValidations::fromXML(XmlUtils::CXmlLiteReader& oReader)
		{
			ReadAttributes( oReader );

			if ( oReader.IsEmptyNode() )
				return;

			int nCurDepth = oReader.GetDepth();
			while( oReader.ReadNextSiblingNode( nCurDepth ) )
			{
				std::wstring sName = XmlUtils::GetNameNoNS(oReader.GetName());

				if ( L"dataValidation" == sName )
				{
					CDataValidation* pDataValidation = new CDataValidation();
					*pDataValidation = oReader;
					m_arrItems.push_back(pDataValidation);
				}
			}
		}
		void CDataValidations::fromBin(XLS::BaseObjectPtr& obj)
		{
			if(obj->get_type() == XLS::typeDVALS)
			{
				auto ptr = static_cast<XLSB::DVALS*>(obj.get());
				if(ptr != nullptr)
				{
					ReadAttributes(ptr->m_BrtBeginDVals);

					for(auto &dval : ptr->m_arBrtDVal)
					{
                        auto validation(new CDataValidation(dval));
                        if(validation->m_oType.IsInit())
                            m_arrItems.push_back(validation);
					}
				}
			}
			else if (obj->get_type() == XLS::typeDVALS14)
			{
				auto ptr = static_cast<XLSB::DVALS14*>(obj.get());
				if(ptr != nullptr)
				{
					ReadAttributes(ptr->m_BrtBeginDVals14);

					for(auto &dval14 : ptr->m_arBrtDVal14)
					{
                        auto validation(new CDataValidation(dval14));
                        if(validation->m_oType.IsInit())
                            m_arrItems.push_back(validation);
					}
				}
			}
			m_oCount = m_arrItems.size();
		}
        XLS::BaseObjectPtr CDataValidations::toBin()
    	{
			XLS::BaseObjectPtr objectPtr;
			auto ptr(new XLSB::DVALS);
			objectPtr = XLS::BaseObjectPtr{ptr};

			auto beginPtr(new XLSB::BeginDVals);
			ptr->m_BrtBeginDVals = XLS::BaseObjectPtr{beginPtr};
            if(m_oDisablePrompts.IsInit())
                beginPtr->dVals.fWnClosed = m_oDisablePrompts->GetValue();
            else
                beginPtr->dVals.fWnClosed = false;
            if(m_oXWindow.IsInit())
                beginPtr->dVals.xLeft = m_oXWindow->GetValue();
            else
                beginPtr->dVals.xLeft = 0;
            if(m_oYWindow.IsInit())
                beginPtr->dVals.yTop = m_oYWindow->GetValue();
            else
                beginPtr->dVals.yTop = false;

			for(auto i:m_arrItems)
			{
				ptr->m_arBrtDVal.push_back(i->toBin());
			}
			beginPtr->dVals.idvMac = ptr->m_arBrtDVal.size();

			return objectPtr;
		}
        void CDataValidations::toBin(XLS::StreamCacheWriterPtr& writer)
        {
            {
                auto begin = writer->getNextRecord(XLSB::rt_BeginDVals);
                _UINT16 flags1 = 0;
                if(m_oDisablePrompts.IsInit())
                    SETBIT(flags1, 0, m_oDisablePrompts->GetValue())
                *begin << flags1;
                _UINT32 topleft = 0;
                if(m_oXWindow.IsInit())
                    topleft = m_oXWindow->GetValue();
                *begin << topleft;
                if(m_oYWindow.IsInit())
                    topleft = m_oYWindow->GetValue();
                else
                    topleft = 0;
                *begin << topleft;
                begin->reserveNunBytes(4);
                _UINT32 idvMac = m_arrItems.size();
                *begin << idvMac;
                writer->storeNextRecord(begin);
            }
            for(auto i:m_arrItems)
            {
                i->toBin(writer);
            }
            {
                auto end = writer->getNextRecord(XLSB::rt_EndDVals);
                writer->storeNextRecord(end);
            }
        }
		void CDataValidations::ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
		{
			WritingElement_ReadAttributes_Start( oReader )
				WritingElement_ReadAttributes_Read_if		( oReader, L"count",	m_oCount)
				WritingElement_ReadAttributes_Read_else_if	( oReader, L"disablePrompts",m_oDisablePrompts)
				WritingElement_ReadAttributes_Read_else_if	( oReader, L"xWindow",	m_oXWindow)
				WritingElement_ReadAttributes_Read_else_if	( oReader, L"yWindow",	m_oYWindow)
			WritingElement_ReadAttributes_End( oReader )
		}
		void CDataValidations::ReadAttributes(XLS::BaseObjectPtr& obj)
		{
			if(obj->get_type() == XLS::typeBeginDVals)
			{
				auto ptr = static_cast<XLSB::BeginDVals*>(obj.get());
				if(ptr != nullptr)
				{
					//m_oCount            = ptr->dVals.idvMac;
					m_oDisablePrompts   = ptr->dVals.fWnClosed;
					m_oXWindow          = ptr->dVals.xLeft;
					m_oYWindow          = ptr->dVals.yTop;
				}
			}
			else if(obj->get_type() == XLS::typeBeginDVals14)
			{
				auto ptr = static_cast<XLSB::BeginDVals14*>(obj.get());
				if(ptr != nullptr)
				{
					m_oCount            = ptr->dVals.idvMac;
					m_oDisablePrompts   = ptr->dVals.fWnClosed;
					m_oXWindow          = ptr->dVals.xLeft;
					m_oYWindow          = ptr->dVals.yTop;
				}
			}
		}
        // void CDataValidation::fromXML(XmlUtils::CXmlLiteReader& oReader)
        //->sheetData
	} //Spreadsheet
} // namespace OOX
