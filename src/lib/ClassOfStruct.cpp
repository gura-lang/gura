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
	ObjectOfStruct *pThis = ObjectOfStruct::GetObjectThis(arg);
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
ClassOfStruct::ClassOfStruct(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_Struct)
{
}

void ClassOfStruct::Prepare(Environment &env)
{
	Gura_AssignMethod(Struct, tolist);
}

bool ClassOfStruct::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	Signal &sig = GetSignal();
	if (value.Is_list()) {
		Class *pClass = env.LookupClass(pDecl->GetValueType());
		if (pClass == nullptr) return false;
		const Function *pConstructor = pClass->GetConstructor();
		if (pConstructor == nullptr) return false;
		AutoPtr<Argument> pArg(new Argument(pConstructor));
		if (!pArg->SetValues(env, value.GetList())) return false;
		value = pConstructor->Eval(env, *pArg);
		return !sig.IsSignalled();
	}
	return false;
}

Object *ClassOfStruct::CreateDescendant(Environment &env, Class *pClass)
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

Value ClassOfStruct::Constructor::DoEval(Environment &env, Argument &arg) const
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
