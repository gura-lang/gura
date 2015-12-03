//=============================================================================
// Version
// Needs to modify content of src/CMakeLists.txt as well.
//=============================================================================
#ifndef __GURA_VERSION_H__
#define __GURA_VERSION_H__

#include "Common.h"

#define GURA_VERSION_MAJOR	0
#define GURA_VERSION_MINOR	7
#define GURA_VERSION_PATCH	0

#define GURA_VERSION	"0.7.0"

#define GURA_COPYRIGHT	"Copyright (C) 2011-2015 ypsitau"

namespace Gura {

//-----------------------------------------------------------------------------
// Version
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Version {
public:
	static const char *GetVersion();
	static const char *GetBanner(bool timeStampFlag);
	static const char *GetTimeStamp();
	static bool CheckCoreVersion(const char *strCoreVer, ...);
};

}

#endif
