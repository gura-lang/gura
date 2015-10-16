//=============================================================================
// Gura class: Struct
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_Struct
//-----------------------------------------------------------------------------
Object_Struct::Object_Struct(const Object_Struct &obj) : Object(obj)
{
}

Object_Struct::~Object_Struct()
{
}

Object *Object_Struct::Clone() const
{
	return new Object_Struct(*this);
}

String Object_Struct::ToString(bool exprFlag)
{
	Signal sig;
	bool evaluatedFlag = false;
	Value value = EvalMethod(*this, Gura_Symbol(__str__),
											ValueList::Empty, evaluatedFlag);
	if (sig.IsSignalled()) return "";
	if (evaluatedFlag) return value.ToString(false);
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
		if (pValue == nullptr) {
			str += "nil";
		} else {
			str += pValue->ToString(true);
		}
	}
	str += ")";
	return str;
}

const DeclarationList &Object_Struct::GetDeclList() const
{
	const Class *pClass = _pClass.get();
	for ( ; pClass != nullptr; pClass = pClass->GetClassSuper()) {
		if (pClass->GetConstructor()->IsConstructorOfStruct()) break;
	}
	if (pClass == nullptr) pClass = _pClass.get();
	return pClass->GetConstructor()->GetDeclOwner();
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// struct#tolist()
Gura_DeclareMethod(Struct, tolist)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a list of values extracted from the struct object in an order\n"
	"declared by struct() function.");
}

Gura_ImplementMethod(Struct, tolist)
{
	Object_Struct *pThis = Object_Struct::GetObjectThis(arg);
	Value result;
	ValueList &valList = result.InitAsList(env);
	const DeclarationList &declList = pThis->GetDeclList();
	foreach_const (DeclarationList, ppDecl, declList) {
		const Value *pValue = pThis->LookupValue((*ppDecl)->GetSymbol(), ENVREF_NoEscalate);
		if (pValue == nullptr) {
			valList.push_back(Value::Nil);
		} else {
			valList.push_back(*pValue);
		}
	}
	return result;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_Struct::Class_Struct(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_Struct)
{
}

void Class_Struct::Prepare(Environment &env)
{
	Gura_AssignMethod(Struct, tolist);
}

bool Class_Struct::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	Signal &sig = GetSignal();
	if (value.Is_list()) {
		Class *pClass = env.LookupClass(pDecl->GetValueType());
		if (pClass == nullptr) return false;
		const Function *pConstructor = pClass->GetConstructor();
		if (pConstructor == nullptr) return false;
		AutoPtr<Argument> pArg(new Argument(pConstructor));
		if (!pArg->StoreValues(env, value.GetList())) return false;
		value = pConstructor->Eval(env, *pArg);
		return !sig.IsSignalled();
	}
	return false;
}

Object *Class_Struct::CreateDescendant(Environment &env, Class *pClass)
{
	return new Object_Struct((pClass == nullptr)? this : pClass);
}

//-----------------------------------------------------------------------------
// Class_Struct::Constructor
//-----------------------------------------------------------------------------
bool Class_Struct::Constructor::IsConstructorOfStruct() const { return true; }

Class_Struct::Constructor::Constructor(Environment &env) :
		Function(env, Gura_Symbol(_anonymous_), FUNCTYPE_Function, FLAG_None)
{
}

Value Class_Struct::Constructor::DoEval(Environment &env, Argument &arg) const
{
	Object *pObjThis = nullptr;
	Value valueRtn(arg.GetValueThis());
	if (valueRtn.IsObject()) {
		pObjThis = valueRtn.GetObject();
	} else {
		pObjThis = _pClassToConstruct->CreateDescendant(env, _pClassToConstruct);
		valueRtn.InitAsObject(pObjThis);
	}
	arg.AssignToEnvironment(*pObjThis);
	return ReturnValue(env, arg, valueRtn);
}

}
