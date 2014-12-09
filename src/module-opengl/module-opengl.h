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
// Object_Buffer
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Buffer);

class Object_Buffer : public Object {
public:
	Gura_DeclareObjectAccessor(Buffer)
private:
	AutoPtr<Memory> _pBuff;
public:
	Object_Buffer(size_t n);
	virtual ~Object_Buffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	inline GLuint *GetBuffer() {
		return reinterpret_cast<GLuint *>(_pBuff->GetPointer());
	}
	inline size_t GetSize() const { return _pBuff->GetSize() / sizeof(GLuint); }
private:
	inline Object_Buffer(const Object_Buffer &obj) : Object(obj) {}
};

//-----------------------------------------------------------------------------
// helper
//-----------------------------------------------------------------------------
size_t GetParamCount(GLenum pname);
bool CheckParamCount(GLenum pname, size_t n);

GLenum GetImageFormat(Signal sig, const Image *pImage);
void SetError_NotImpFunction(Signal &sig, const char *funcName);

Gura_EndModuleHeader(opengl)

#endif
