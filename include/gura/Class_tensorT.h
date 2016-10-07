//=============================================================================
// Gura class: tensorT
//=============================================================================
#ifndef __GURA_CLASS_TENSORT_H__
#define __GURA_CLASS_TENSORT_H__

#include "Class.h"
#include "TensorT.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_tensorT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Object_tensorT : public Object {
public:
	Gura_DeclareObjectAccessor(tensorT)
private:
	AutoPtr<TensorT<T_Elem> > _pTensorT;
public:
	Object_tensorT(Environment &env, ValueType valType, TensorT<T_Elem> *pTensorT) :
				Object(env.LookupClass(valType)), _pTensorT(pTensorT) {}
	Object_tensorT(Class *pClass, TensorT<T_Elem> *pTensorT) :
				Object(pClass), _pTensorT(pTensorT) {}
	inline TensorT<T_Elem> *GetTensorT() { return _pTensorT.get(); }
	inline const TensorT<T_Elem> *GetTensorT() const { return _pTensorT.get(); }
	virtual Object *Clone() const { return nullptr; }
	virtual String ToString(bool exprFlag) {
		char buff[64];
		String str;
		str += "<";
		str += GetClassName();
		str += ":";
		//::sprintf(buff, "%ldelements", _pTensorT->GetSize());
		str += buff;
		str += ">";
		return str;
	}
};

//-----------------------------------------------------------------------------
// Class_tensorT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Class_tensorT : public Class {
public:
private:
	String _elemName;
public:
	Class_tensorT(Environment *pEnvOuter, ValueType valType, const String &elemName) :
							Class(pEnvOuter, valType), _elemName(elemName) {}
	virtual void Prepare(Environment &env) {
	}
};

}

#endif
