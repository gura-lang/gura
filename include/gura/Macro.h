//=============================================================================
// Macro
//=============================================================================
#ifndef __GURA_MACRO_H__
#define __GURA_MACRO_H__

#if defined(_MSC_VER)
#define GURA_ON_MSWIN
#define GURA_PLATFORM_NAME "mswin"
#elif defined(__linux__)
#define GURA_ON_LINUX
#define GURA_PLATFORM_NAME "linux"
#elif defined(__APPLE__)
#define GURA_ON_DARWIN
#define GURA_PLATFORM_NAME "darwin"
#else
#define GURA_ON_UNKNOWN
#define GURA_PLATFORM_NAME "unknown"
#endif

#if defined(_MSC_VER)
#define GURA_HOST_COMPILER_NAME "msc"
#elif defined(__GNUC__) && defined(__GNUC_MINOR__)
#define GURA_HOST_COMPILER_NAME "gnuc"
#else
#define GURA_HOST_COMPILER_NAME "unknown"
#endif

#if defined(GURA_ON_MSWIN)
#undef SetProp
#undef GetProp
#undef GetObject
#pragma warning(disable:4251)
#pragma warning(disable:4275)
#pragma warning(disable:4355)
#pragma warning(disable:4996)
#define GURA_DLLIMPORT __declspec(dllimport)
#define GURA_DLLEXPORT __declspec(dllexport)
#if defined(gura_EXPORTS)
#define GURA_DLLDECLARE __declspec(dllexport)
#else
#define GURA_DLLDECLARE __declspec(dllimport)
#endif
#define strcasecmp stricmp
#define GURA_USE_MSWIN_DIB 1
#else
#define GURA_DLLIMPORT
#define GURA_DLLEXPORT
#define GURA_DLLDECLARE
#define GURA_USE_MSWIN_DIB 0
#endif

#define Gura_BeginNameSpace() \
namespace Gura {

#define Gura_EndNameSpace()	\
}

#define ArraySizeOf(array) \
(sizeof(array) / sizeof(array[0]))

#define foreach(T, i, c) \
for (T::iterator i = (c).begin(); i != (c).end(); i++)

#define foreach_const(T, i, c) \
for (T::const_iterator i = (c).begin(); i != (c).end(); i++)

#define foreach_reverse(T, i, c) \
for (T::reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)

#define foreach_const_reverse(T, i, c) \
for (T::const_reverse_iterator i = (c).rbegin(); i != (c).rend(); i++)

#define GURA_ASSUME(env, x) if (!(x)) { env.Error(__FILE__, __LINE__, #x); }
#define GURA_ERROREND(env, str) (env).Error(__FILE__, __LINE__, (str))

#define Gura_DeclareReferenceAccessor(T) \
inline static T *Reference(const T *p) { \
	if (p == nullptr) return nullptr; \
	T *pCasted = const_cast<T *>(p); \
	pCasted->_cntRef++; \
	return pCasted; \
} \
inline T *Reference() const { return Reference(this); } \
inline static void Delete(T *p) { \
	if (p == nullptr) return; \
	p->_cntRef--; \
	if (p->_cntRef <= 0) delete p; \
}

#define Gura_BeginPushbackRegion() \
bool __pushbackFlag = false; \
do { \
__pushbackFlag = false

#define Gura_EndPushbackRegion() \
} while (__pushbackFlag)

#define Gura_Pushback() \
__pushbackFlag = true

#define Gura_PushbackCond(pushbackFlag) \
__pushbackFlag = (pushbackFlag)

#define Gura_BeginPushbackRegionEx(T, n, var)	\
T __pushbackBuff[n] = {var};  \
for (int __pushbackLevel = 1; __pushbackLevel > 0; ) { \
var = __pushbackBuff[--__pushbackLevel];

#define Gura_EndPushbackRegionEx() \
}

#define Gura_PushbackEx(value) \
__pushbackBuff[__pushbackLevel++] = (value)

#endif
