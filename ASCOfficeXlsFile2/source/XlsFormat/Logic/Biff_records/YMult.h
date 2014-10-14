#pragma once

#include "BiffRecord.h"

namespace XLS
{;


// Logical representation of YMult record in BIFF8
class YMult: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(YMult)
	BASE_OBJECT_DEFINE_CLASS_NAME(YMult)
public:
	YMult();
	~YMult();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);
private:
//	BIFF_WORD userName;
public:
	BO_ATTRIB_MARKUP_BEGIN
//		BO_ATTRIB_MARKUP_ATTRIB(userName)
	BO_ATTRIB_MARKUP_END

};

} // namespace XLS
