//=============================================================================
// Version
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Version
//-----------------------------------------------------------------------------
const char *Version::GetVersion()
{
	return GURA_VERSION;
}

const char *Version::GetBanner(bool timeStampFlag)
{
	static char buff[256];
#if defined(_MSC_VER)
	::sprintf(buff, "Gura %s [MSC v.%d, %s%s] %s",
			  GURA_VERSION, _MSC_VER, __DATE__,
			  timeStampFlag? " " __TIME__ : "", GURA_COPYRIGHT);
#elif defined(__clang_major__) && defined(__clang_minor__)
	::sprintf(buff, "Gura %s [clang v.%d.%d, %s%s] %s",
			  GURA_VERSION, __clang_major__, __clang_minor__, __DATE__,
			  timeStampFlag? " " __TIME__ : "", GURA_COPYRIGHT);
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
	::sprintf(buff, "Gura %s [GNUC v.%d.%d, %s%s] %s",
			  GURA_VERSION, __GNUC__, __GNUC_MINOR__, __DATE__,
			  timeStampFlag? " " __TIME__ : "", GURA_COPYRIGHT);
#else
	::sprintf(buff, "Gura %s [%s%s] %s",
			  GURA_VERSION, __DATE__, timeStampFlag? " " __TIME__ : "", GURA_COPYRIGHT);
#endif
	return buff;
}

const char *Version::GetTimeStamp()
{
	return __DATE__ " " __TIME__;
}

}
