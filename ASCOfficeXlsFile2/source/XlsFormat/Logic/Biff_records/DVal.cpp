#include "precompiled_xls.h"
#include "DVal.h"

namespace XLS
{;

DVal::DVal()
{
}


DVal::~DVal()
{
}


BaseObjectPtr DVal::clone()
{
	return BaseObjectPtr(new DVal(*this));
}


void DVal::writeFields(CFRecord& record)
{
	unsigned __int16 flags = 0;
	SETBIT(flags, 0, fWnClosed);
	record << flags << xLeft << yTop << idObj << idvMac;
}


void DVal::readFields(CFRecord& record)
{
	unsigned __int16 flags;
	record >> flags >> xLeft >> yTop >> idObj >> idvMac;
	fWnClosed = GETBIT(flags, 0);
}

} // namespace XLS
