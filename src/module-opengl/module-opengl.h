//-----------------------------------------------------------------------------
// Gura module: opengl
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_OPENGL_H__
#define __GURA_MODULE_OPENGL_H__
#include <gura.h>
#if defined(GURA_ON_DARWIN)
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include "Utils.h"

Gura_BeginModuleHeader(opengl)

bool DoGLSection(Environment &env, Signal &sig, Argument &args, Image *pImage);

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
template<typename T>
Value CreateValueFromParams(Environment &env, const T params[], size_t n)
{
	return (n == 1)? Value(params[0]) : Value::CreateList(env, params, n);
}

size_t GetParamCount(GLenum pname);
bool CheckParamCount(GLenum pname, size_t n);

GLenum GetImageFormat(Environment &env, const Image *pImage);
void SetError_NotImpFunction(Environment &env, const char *funcName);
void SetError_OpenGLVersion(Environment &env, const char *version);

Gura_EndModuleHeader(opengl)

#endif
