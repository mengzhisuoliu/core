#pragma once

#include "BiffAttribute.h"
//#include <Logic/Biff_structures/Phs.h>
//#include <Logic/Biff_structures/BiffString.h>

namespace XLS
{;

class CFRecord;

class FontIndex : public BiffAttributeSimple<unsigned __int16>
{
public:
	BiffStructurePtr clone();

	//virtual void toXML(BiffStructurePtr & parent, const std::wstring & attrib_name);
	//virtual const bool fromXML(MSXML2::IXMLDOMElementPtr xml_tag, const std::wstring & attrib_name);
	operator const _variant_t () const;
	const unsigned __int16 getValue() const;
};

} // namespace XLS
