//-----------------------------------------------------------------------------
// Gura module: opengl
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_OPENGL_H__
#define __GURA_MODULE_OPENGL_H__
#include <gura.h>
#include <GL/gl.h>

Gura_BeginModuleHeader(opengl)

bool DoGLSection(Environment &env, Signal sig, Args &args, Image *pImage);

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
#define ToArrayTemplate(type, getFunc) \
bool ToArray(Signal sig, type v[], const ValueList &valList, size_t n, \
			bool checkFlag, const char *funcName, const char *paramName) \
{ \
	if (checkFlag && valList.size() != n) { \
		sig.SetError(ERR_ValueError, \
				"%s's %s parameter takes a list with %d elements", \
				funcName, paramName, n); \
		return false; \
	} \
	size_t i = 0; \
	foreach_const (ValueList, pValue, valList) { \
		if (i >= n) break; \
		v[i++] = pValue->getFunc(); \
	} \
	return true; \
}

#define DeclareArray(type, varName, n, iParam) \
type varName[n]; \
if (!ToArray(sig, varName, args.GetList(iParam), n, true, GetName(), #varName)) { \
	return Value::Null; \
}

#define DeclareNewArray(type, varName, iParam) \
size_t n_##varName = args.GetList(iParam).size(); \
type *varName = new type[n_##varName]; \
if (!ToArray(sig, varName, args.GetList(iParam), n_##varName, true, GetName(), #varName)) { \
	delete[] varName; \
	return Value::Null; \
}

size_t GetParamCount(GLenum pname);
size_t GetLightParamCount(GLenum pname);
GLenum GetImageFormat(Signal sig, const Image *pImage);

Gura_EndModuleHeader(opengl)

#endif
