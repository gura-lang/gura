#ifndef __GURA_CLASSOFSTRUCT_H__
#define __GURA_CLASSOFSTRUCT_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ClassOfStruct
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ClassOfStruct : public Class {
public:
	class GURA_DLLDECLARE Constructor : public Function {
	public:
		Constructor(Environment &env);
		virtual bool IsConstructorOfStruct() const;
		virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
	};
public:
	ClassOfStruct(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// ObjectOfStruct
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ObjectOfStruct : public Object {
public:
	Gura_DeclareObjectAccessorEx(ObjectOfStruct)
public:
	inline ObjectOfStruct(Class *pClass) : Object(pClass) {}
	inline ObjectOfStruct(Environment &env) : Object(env.LookupClass(VTYPE_Struct)) {}
	ObjectOfStruct(const ObjectOfStruct &obj);
	virtual ~ObjectOfStruct();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	const DeclarationList &GetDeclList() const;
};

}

#endif
