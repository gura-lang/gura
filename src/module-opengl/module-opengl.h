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
// Buffer class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Buffer);

template<typename T>
class Object_Buffer : public Object {
public:
	Gura_DeclareObjectAccessor(Buffer)
private:
	AutoPtr<Memory> _pBuff;
public:
	Object_Buffer(size_t n) : Object(Gura_UserClass(Buffer)),
								_pBuff(new MemoryHeap(n * sizeof(T))) {}
	virtual ~Object_Buffer() {}
	virtual Object *Clone() const { return NULL; }
	virtual String ToString(bool exprFlag) {
		return String("<opengl.Buffer>");
	}
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx) {
		if (!valueIdx.Is_number()) {
			sig.SetError(ERR_ValueError, "index must be a number");
			return Value::Null;
		}
		size_t idx = valueIdx.GetSizeT();
		if (idx >= GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "index is out of range");
			return Value::Null;
		}
		return Value(GetBuffer()[idx]);
	}
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value) {
		if (!valueIdx.Is_number()) {
			sig.SetError(ERR_ValueError, "index must be a number");
			return;
		}
		size_t idx = valueIdx.GetSizeT();
		if (idx >= GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "index is out of range");
			return;
		}
		GetBuffer()[idx] = static_cast<T>(value.GetNumber());
	}
	inline T *GetBuffer() {
		return reinterpret_cast<T *>(_pBuff->GetPointer());
	}
	inline size_t GetSize() const { return _pBuff->GetSize() / sizeof(T); }
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
