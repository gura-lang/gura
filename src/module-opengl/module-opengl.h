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

Gura_BeginModuleHeader(opengl)

bool DoGLSection(Environment &env, Signal sig, Args &args, Image *pImage);

//-----------------------------------------------------------------------------
// Buffer class
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(BufferGLuint);
Gura_DeclareUserClass(BufferGLfloat);
Gura_DeclareUserClass(BufferGLdouble);

template<typename T_Elem>
class Object_Buffer : public Object {
public:
	Gura_DeclareObjectAccessor(Buffer)
private:
	AutoPtr<Memory> _pMemory;
	size_t _offset;
public:
	Object_Buffer(Class *pClass, size_t n) : Object(pClass),
		_pMemory(new MemoryHeap(n * sizeof(T_Elem))), _offset(0) {}
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
		return Value(GetPointer(idx));
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
		*GetPointer(idx) = static_cast<T_Elem>(value.GetNumber());
	}
	static Object_Buffer *Create(Signal sig, Class *pClass, const ValueList &valList) {
		AutoPtr<Object_Buffer> pObj(new Object_Buffer(pClass, valList.size()));
		T_Elem *p = pObj->GetPointer(0);
		foreach_const (ValueList, pValue, valList) {
			if (!pValue->Is_number()) {
				sig.SetError(ERR_ValueError, "element must be a number");
				return NULL;
			}
			*p++ = static_cast<T_Elem>(pValue->GetNumber());
		}
		return pObj.release();
	}
	inline Memory *GetMemory() { return _pMemory.get(); }
	inline T_Elem *GetPointer(size_t idx) {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + _offset + idx;
	}
	inline size_t GetSize() const { return _pMemory->GetSize() / sizeof(T_Elem) - _offset; }
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
