#include "CCssCalculator.h"
#include "CCssCalculator_Private.h"

namespace NSCSS
{
	CCssCalculator::CCssCalculator()
	{
		m_pInternal = new CCssCalculator_Private();
	}

	CCssCalculator::~CCssCalculator()
	{
		delete m_pInternal;
	}

	bool CCssCalculator::CalculateCompiledStyle(std::vector<CNode>& arSelectors) const
	{
		return m_pInternal->CalculateCompiledStyle(arSelectors);
	}

	std::wstring CCssCalculator::CalculateStyleId(const CNode& oNode)
	{
		return m_pInternal->CalculateStyleId(oNode);
	}

	bool CCssCalculator::CalculatePageStyle(NSProperties::CPage& oPageData, const std::vector<CNode> &arSelectors)
	{
		return m_pInternal->CalculatePageStyle(oPageData, arSelectors);
	}

	void CCssCalculator::AddStyles(const std::string &sStyle)
	{
		m_pInternal->AddStyles(sStyle);
	}

	void CCssCalculator::AddStyles(const std::wstring &wsStyle)
	{
		m_pInternal->AddStyles(wsStyle);
	}

	void CCssCalculator::AddStylesFromFile(const std::wstring &wsFileName)
	{
		m_pInternal->AddStylesFromFile(wsFileName);
	}

	void CCssCalculator::SetDpi(const unsigned short int& nValue)
	{
		m_pInternal->SetDpi(nValue);
	}

	std::wstring CCssCalculator::GetEncoding() const
	{
		return m_pInternal->GetEncoding();
	}

	unsigned short int CCssCalculator::GetDpi() const
	{
		return m_pInternal->GetDpi();
	}

	bool CCssCalculator::HaveStylesById(const std::wstring& wsId) const
	{
		return m_pInternal->HaveStylesById(wsId);
	}

	void CCssCalculator::ClearPageData()
	{
		m_pInternal->ClearPageData();
	}

	void CCssCalculator::ClearEmbeddedStyles()
	{
		m_pInternal->ClearEmbeddedStyles();
	}

	void CCssCalculator::ClearAllowedStyleFiles()
	{
		m_pInternal->ClearAllowedStyleFiles();
	}

	void CCssCalculator::ClearStylesFromFile(const std::wstring& wsFilePath)
	{
		m_pInternal->ClearStylesFromFile(wsFilePath);
	}

	void CCssCalculator::Clear()
	{
		m_pInternal->Clear();
	}
}
