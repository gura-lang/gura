//=============================================================================
// Gura class: matrix
//=============================================================================
#ifndef __GURA_CLASS_MATRIX_H__
#define __GURA_CLASS_MATRIX_H__

#include "Class_list.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_matrix
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_matrix : public Class {
public:
	Class_matrix(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal &__to_delete__, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal &__to_delete__, Class *pClass);
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
	virtual Value EmptyIndexGet(Environment &env, Signal &__to_delete__);
	virtual Value IndexGet(Environment &env, Signal &__to_delete__, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal &__to_delete__, const Value &valueIdx, const Value &value);
	virtual String ToString(bool exprFlag);
	Matrix *GetMatrix() { return _pMat.get(); }
	const Matrix *GetMatrix() const { return _pMat.get(); }
};

}

#endif
