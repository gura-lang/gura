//=============================================================================
// Gura class: Struct
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ObjectOfStruct
//-----------------------------------------------------------------------------
ObjectOfStruct::ObjectOfStruct(const ObjectOfStruct &obj) : Object(obj)
{
}

ObjectOfStruct::~ObjectOfStruct()
{
}

Object *ObjectOfStruct::Clone() const
{
	return new ObjectOfStruct(*this);
}

String ObjectOfStruct::ToString(bool exprFlag)
{
	Signal sig;
	bool evaluatedFlag = false;
	Value value = EvalMethod(*this, sig, Gura_Symbol(__str__),
											ValueList::Null, evaluatedFlag);
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

const DeclarationList &ObjectOfStruct::GetDeclList() const
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
	ObjectOfStruct *pThis = ObjectOfStruct::GetThisObj(args);
	Value result;
	ValueList &valList = result.InitAsList(env);
	const DeclarationList &declList = pThis->GetDeclList();
	foreach_const (DeclarationList, ppDecl, declList) {
		const Value *pValue = pThis->LookupValue((*ppDecl)->GetSymbol(), ENVREF_NoEscalate);
		if (pValue == nullptr) {
			valList.push_back(Value::Null);
		} else {
			valList.push_back(*pValue);
		}
	}
	return result;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
ClassOfStruct::ClassOfStruct(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_Struct)
{
}

void ClassOfStruct::Prepare(Environment &env)
{
	Gura_AssignMethod(Struct, tolist);
}

bool ClassOfStruct::CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl)
{
	if (value.Is_list()) {
		Class *pClass = env.LookupClass(pDecl->GetValueType());
		if (pClass == nullptr) return false;
		const Function *pConstructor = pClass->GetConstructor();
		if (pConstructor == nullptr) return false;
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetValueListArg(value.GetList());
		value = pConstructor->Eval(env, sig, *pArgs);
		return !sig.IsSignalled();
	}
	return false;
}

Object *ClassOfStruct::CreateDescendant(Environment &env, Signal &sig, Class *pClass)
{
	return new ObjectOfStruct((pClass == nullptr)? this : pClass);
}

//-----------------------------------------------------------------------------
// ClassOfStruct::Constructor
//-----------------------------------------------------------------------------
bool ClassOfStruct::Constructor::IsConstructorOfStruct() const { return true; }

ClassOfStruct::Constructor::Constructor(Environment &env) :
		Function(env, Gura_Symbol(_anonymous_), FUNCTYPE_Function, FLAG_None)
{
}

Value ClassOfStruct::Constructor::DoEval(Environment &env, Signal &sig, Args &args) const
{
	Object *pObjThis = nullptr;
	Value valueRtn(args.GetThis());
	if (valueRtn.IsObject()) {
		pObjThis = valueRtn.GetObject();
	} else {
		pObjThis = _pClassToConstruct->CreateDescendant(env, sig, _pClassToConstruct);
		valueRtn.InitAsObject(pObjThis);
	}
	ValueList::const_iterator pValue = args.GetValueListArg().begin();
	DeclarationList::const_iterator ppDecl = GetDeclOwner().begin();
	for ( ; pValue != args.GetValueListArg().end() && ppDecl != GetDeclOwner().end();
														pValue++, ppDecl++) {
		const Declaration *pDecl = *ppDecl;
		pObjThis->AssignValue(pDecl->GetSymbol(), *pValue, EXTRA_Public);
	}
	return ReturnValue(env, sig, args, valueRtn);
}

}
