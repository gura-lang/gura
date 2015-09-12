//=============================================================================
// Class_Struct
//=============================================================================
#ifndef __GURA_CLASS_STRUCT_H__
#define __GURA_CLASS_STRUCT_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_Struct
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_Struct : public Class {
public:
	class GURA_DLLDECLARE Constructor : public Function {
	public:
		Constructor(Environment &env);
		virtual bool IsConstructorOfStruct() const;
		virtual Value DoEval(Environment &env, Argument &arg) const;
	};
public:
	Class_Struct(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_Struct
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_Struct : public Object {
public:
	Gura_DeclareObjectAccessorEx(Object_Struct)
public:
	inline Object_Struct(Class *pClass) : Object(pClass) {}
	inline Object_Struct(Environment &env) : Object(env.LookupClass(VTYPE_Struct)) {}
	Object_Struct(const Object_Struct &obj);
	virtual ~Object_Struct();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	const DeclarationList &GetDeclList() const;
};

}

#endif
