//
// StructObject
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// StructObject
//-----------------------------------------------------------------------------
StructObject::StructObject(const StructObject &obj) : Object(obj)
{
}

StructObject::~StructObject()
{
}

Object *StructObject::Clone() const
{
	return new StructObject(*this);
}

String StructObject::ToString(Signal sig, bool exprFlag)
{
	bool evaluatedFlag = false;
	Value value = EvalMethod(*this, sig, Gura_Symbol(__str__),
											ValueList::Null, evaluatedFlag);
	if (evaluatedFlag) return value.ToString(sig, false);
	String str;
	str += _pClass->GetName();
	str += "(";
	const DeclarationList &declList = GetDeclList();
	foreach_const (DeclarationList, ppDecl, declList) {
		const Declaration *pDecl = *ppDecl;
		if (ppDecl != declList.begin()) str += ", ";
		str += pDecl->GetSymbol()->GetName();
		str += " => ";
		const Value *pValue = LookupValue(pDecl->GetSymbol(), ENVREF_NoEscalate);
		if (pValue == NULL) {
			str += "nil";
		} else {
			str += pValue->ToString(sig, true);
		}
	}
	str += ")";
	return str;
}

const DeclarationList &StructObject::GetDeclList() const
{
	const Class *pClass = _pClass.get();
	for ( ; pClass != NULL; pClass = pClass->GetClassSuper()) {
		if (pClass->GetConstructor()->IsStructPrototype()) break;
	}
	if (pClass == NULL) pClass = _pClass.get();
	return pClass->GetConstructor()->GetDeclOwner();
}

//-----------------------------------------------------------------------------
// Gura interfaces for StructObject
//-----------------------------------------------------------------------------
// struct#tolist()
Gura_DeclareMethod(Struct, tolist)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), 
	"Returns a list of values extracted from the struct object in an order\n"
	"declared by struct() function.");
}

Gura_ImplementMethod(Struct, tolist)
{
	StructObject *pThis = StructObject::GetThisObj(args);
	Value result;
	ValueList &valList = result.InitAsList(env);
	const DeclarationList &declList = pThis->GetDeclList();
	foreach_const (DeclarationList, ppDecl, declList) {
		const Value *pValue = pThis->LookupValue((*ppDecl)->GetSymbol(), ENVREF_NoEscalate);
		if (pValue == NULL) {
			valList.push_back(Value::Null);
		} else {
			valList.push_back(*pValue);
		}
	}
	return result;
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
StructClass::StructClass(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_Struct)
{
	Gura_AssignMethod(Struct, tolist);
}

bool StructClass::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsList()) {
		Class *pClass = env.LookupClass(pDecl->GetValueType());
		if (pClass == NULL) return false;
		const Function *pConstructor = pClass->GetConstructor();
		if (pConstructor == NULL) return false;
		Args args(value.GetList());
		value = pConstructor->Eval(env, sig, args);
		return !sig.IsSignalled();
	}
	return false;
}

Object *StructClass::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	return new StructObject((pClass == NULL)? this : pClass);
}

void StructClass::OnModuleEntry(Environment &env, Signal sig)
{
}

}
