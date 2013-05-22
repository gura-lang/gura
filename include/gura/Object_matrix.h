#ifndef __GURA_OBJECT_MATRIX_H__
#define __GURA_OBJECT_MATRIX_H__

#include "Object_list.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_matrix
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_matrix : public Class {
public:
	Class_matrix(Environment *pEnvOuter);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void DoAssignConstructor(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_matrix
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_matrix : public Object {
private:
	AutoPtr<Matrix> _pMat;
public:
	Gura_DeclareObjectAccessor(matrix)
public:
	Object_matrix(Environment &env, Matrix *pMat);
	Object_matrix(const Object_matrix &obj);
	virtual ~Object_matrix();
	virtual Object *Clone() const;
	virtual Value EmptyIndexGet(Environment &env, Signal sig);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	virtual String ToString(Signal sig, bool exprFlag);
	Matrix *GetMatrix() { return _pMat.get(); }
	const Matrix *GetMatrix() const { return _pMat.get(); }
};

}

#endif
