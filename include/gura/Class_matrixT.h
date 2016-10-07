//=============================================================================
// Gura class: matrixT
//=============================================================================
#ifndef __GURA_CLASS_MATRIXT_H__
#define __GURA_CLASS_MATRIXT_H__

#include "Class.h"
#include "MatrixT.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_matrixT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Object_matrixT : public Object {
public:
	Gura_DeclareObjectAccessor(matrixT)
private:
	AutoPtr<MatrixT<T_Elem> > _pMatrixT;
public:
	Object_matrixT(Environment &env, ValueType valType, MatrixT<T_Elem> *pMatrixT) :
				Object(env.LookupClass(valType)), _pMatrixT(pMatrixT) {}
	Object_matrixT(Class *pClass, MatrixT<T_Elem> *pMatrixT) :
				Object(pClass), _pMatrixT(pMatrixT) {}
	inline MatrixT<T_Elem> *GetMatrixT() { return _pMatrixT.get(); }
	inline const MatrixT<T_Elem> *GetMatrixT() const { return _pMatrixT.get(); }
	virtual Object *Clone() const { return nullptr; }
	virtual String ToString(bool exprFlag) {
		char buff[64];
		String str;
		str += "<";
		str += GetClassName();
		str += ":";
		//::sprintf(buff, "%ldelements", _pMatrixT->GetSize());
		str += buff;
		str += ">";
		return str;
	}
};

//-----------------------------------------------------------------------------
// Class_matrixT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class Class_matrixT : public Class {
public:
private:
	String _elemName;
public:
	Class_matrixT(Environment *pEnvOuter, ValueType valType, const String &elemName) :
							Class(pEnvOuter, valType), _elemName(elemName) {}
	virtual void Prepare(Environment &env) {
	}
};

}

#endif
