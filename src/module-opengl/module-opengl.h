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
#elif defined(GURA_ON_MSWIN)
#define GLEW_STATIC
#include <glew.h>
#else
#include <GL/gl.h>
#endif
#include "Utils.h"

#if defined(__GLEW_H__)
#define ImplementGLExtension() if (!SetupGLEW(env)) return Value::Nil
#else
#define ImplementGLExtension()
#endif

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
bool CheckArray(Signal &sig, GLenum pname, const Array *pArray);

GLenum GetImageFormat(Environment &env, const Image *pImage);
void SetError_NotImpFunction(Environment &env, const char *funcName);
void SetError_RequiredGLVersion(Environment &env, const char *version);

#if defined(__GLEW_H__)
bool SetupGLEW(Environment &env);
#endif

Gura_EndModuleHeader(opengl)

#endif
