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

const char *Version::GetOpening()
{
	static char buff[256];
#if defined(_MSC_VER)
	::sprintf(buff, "Gura %s [MSC v.%d, %s] %s",
				GURA_VERSION, _MSC_VER, __DATE__, GURA_COPYRIGHT);
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
	::sprintf(buff, "Gura %s [GNUC v.%d.%d, %s] %s",
				GURA_VERSION, __GNUC__, __GNUC_MINOR__, __DATE__, GURA_COPYRIGHT);
#else
	::sprintf(buff, "Gura %s [%s] %s",
				GURA_VERSION, __DATE__, GURA_COPYRIGHT);
#endif
	return buff;
}

}
