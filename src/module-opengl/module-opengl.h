//-----------------------------------------------------------------------------
// Gura module: opengl
// see http://www.opengl.org/sdk/docs/man/ for detailed information of each API
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_OPENGL_H__
#define __GURA_MODULE_OPENGL_H__
#include <gura.h>
#if defined(GURA_ON_DARWIN)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

Gura_BeginModuleHeader(opengl)

bool DoGLSection(Environment &env, Signal sig, Args &args, Image *pImage);

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
size_t GetParamCount(GLenum pname);

GLenum GetImageFormat(Signal sig, const Image *pImage);
void SetError_NotImpFunction(Signal &sig, const char *funcName);

Gura_EndModuleHeader(opengl)

#endif
