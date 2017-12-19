//=============================================================================
// Gura class: trainernode
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_trainernode
//-----------------------------------------------------------------------------
Object_trainernode::Object_trainernode(const Object_trainernode &obj) :
	Object(obj), _pTrainer(obj._pTrainer->Reference()), _pNode(obj._pNode)
{
}

Object_trainernode::~Object_trainernode()
{
}

Object *Object_trainernode::Clone() const
{
	return new Object_trainernode(*this);
}

bool Object_trainernode::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return _pNode->DoDirProp(env, symbols);
}

Value Object_trainernode::DoGetProp(Environment &env, const Symbol *pSymbol,
									const SymbolSet &attrs, bool &evaluatedFlag)
{
	return _pNode->DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Object_trainernode::ToString(bool exprFlag)
{
	String str;
	str += "<trainernode:";
	str += _pNode->ToString();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// trainernode#isbinary()
Gura_DeclareMethod(trainernode, isbinary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target is a binary node.\n");
}

Gura_ImplementMethod(trainernode, isbinary)
{
	Object_trainernode *pThis = Object_trainernode::GetObjectThis(arg);
	return Value(pThis->GetTrainerNode()->IsBinary());
}

// trainernode#isbottom()
Gura_DeclareMethod(trainernode, isbottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target is a bottom node.\n");
}

Gura_ImplementMethod(trainernode, isbottom)
{
	Object_trainernode *pThis = Object_trainernode::GetObjectThis(arg);
	return Value(pThis->GetTrainerNode()->IsBottom());
}

// trainernode#isgear()
Gura_DeclareMethod(trainernode, isgear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target is a gear node.\n");
}

Gura_ImplementMethod(trainernode, isgear)
{
	Object_trainernode *pThis = Object_trainernode::GetObjectThis(arg);
	return Value(pThis->GetTrainerNode()->IsGear());
}

// trainernode#ishead()
Gura_DeclareMethod(trainernode, ishead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target is a head node.\n");
}

Gura_ImplementMethod(trainernode, ishead)
{
	Object_trainernode *pThis = Object_trainernode::GetObjectThis(arg);
	return Value(pThis->GetTrainerNode()->IsHead());
}

// trainernode#isunary()
Gura_DeclareMethod(trainernode, isunary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target is a unary node.\n");
}

Gura_ImplementMethod(trainernode, isunary)
{
	Object_trainernode *pThis = Object_trainernode::GetObjectThis(arg);
	return Value(pThis->GetTrainerNode()->IsUnary());
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_trainernode::Class_trainernode(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_trainernode)
{
}

void Class_trainernode::DoPrepare(Environment &env)
{
	// Assignment of function
	// Assignment of properties
	// Assignment of methods
	Gura_AssignMethod(trainernode, isbinary);
	Gura_AssignMethod(trainernode, isbottom);
	Gura_AssignMethod(trainernode, isgear);
	Gura_AssignMethod(trainernode, ishead);
	Gura_AssignMethod(trainernode, isunary);
	// Assignment of values
	Gura_AssignValue(trainernode, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_trainernode::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
