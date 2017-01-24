//=============================================================================
// Gura class: propdeclaration
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_propdeclaration
//-----------------------------------------------------------------------------
Object_propdeclaration::Object_propdeclaration(const Object_propdeclaration &obj) :
	Object(obj), _pPropDeclaration(obj._pPropDeclaration->Reference())
{
}

Object *Object_propdeclaration::Clone() const
{
	return new Object_propdeclaration(*this);
}

String Object_propdeclaration::ToString(bool exprFlag)
{
	String str = "<propdeclaration:";
	str += _pPropDeclaration->GetName();
	ValueType valType = _pPropDeclaration->GetValueType();
	if (valType != VTYPE_any) {
		str += ":";
		str += ValueTypeInfo::MakeFullName(valType);
	}
	if (_pPropDeclaration->IsReadable()) str += ":R";
	if (_pPropDeclaration->IsWritable()) str += ":W";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// propdeclaration#name
Gura_DeclareProperty_R(propdeclaration, name)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(propdeclaration, name)
{
	const PropDeclaration *pPropDeclaration =
		Object_propdeclaration::GetObject(valueThis)->GetPropDeclaration();
	return Value(pPropDeclaration->GetName());
}

// propdeclaration#readable
Gura_DeclareProperty_R(propdeclaration, readable)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(propdeclaration, readable)
{
	const PropDeclaration *pPropDeclaration =
		Object_propdeclaration::GetObject(valueThis)->GetPropDeclaration();
	return Value(pPropDeclaration->IsReadable());
}

// propdeclaration#symbol
Gura_DeclareProperty_R(propdeclaration, symbol)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(propdeclaration, symbol)
{
	const PropDeclaration *pPropDeclaration =
		Object_propdeclaration::GetObject(valueThis)->GetPropDeclaration();
	return Value(pPropDeclaration->GetSymbol());
}

// propdeclaration#type
Gura_DeclareProperty_R(propdeclaration, type)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(propdeclaration, type)
{
	const PropDeclaration *pPropDeclaration =
		Object_propdeclaration::GetObject(valueThis)->GetPropDeclaration();
	return Value(ValueTypeInfo::MakeFullName(pPropDeclaration->GetValueType()));
}

// propdeclaration#writable
Gura_DeclareProperty_R(propdeclaration, writable)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(propdeclaration, writable)
{
	const PropDeclaration *pPropDeclaration =
		Object_propdeclaration::GetObject(valueThis)->GetPropDeclaration();
	return Value(pPropDeclaration->IsWritable());
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// propdeclaration.gethelp(lang?:symbol):map {block?}
Gura_DeclareMethod(propdeclaration, gethelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lang", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
	);
}

Gura_ImplementMethod(propdeclaration, gethelp)
{
	const PropDeclaration *pPropDeclaration =
		Object_propdeclaration::GetObjectThis(arg)->GetPropDeclaration();
	const Symbol *pSymbol = arg.Is_symbol(0)? arg.GetSymbol(0) : env.GetLangCode();
	const Help *pHelp = pPropDeclaration->GetHelpProvider().GetHelp(pSymbol, true);
	if (pHelp == nullptr) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_help(env, pHelp->Reference())));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_propdeclaration::Class_propdeclaration(Environment *pEnvOuter) :
	Class(pEnvOuter, VTYPE_propdeclaration)
{
}

void Class_propdeclaration::DoPrepare(Environment &env)
{
	// Assignment of properties
	Gura_AssignProperty(propdeclaration, name);
	Gura_AssignProperty(propdeclaration, readable);
	Gura_AssignProperty(propdeclaration, symbol);
	Gura_AssignProperty(propdeclaration, type);
	Gura_AssignProperty(propdeclaration, writable);
	// Assignment of methods
	Gura_AssignMethod(propdeclaration, gethelp);
	// Assignment of value
	Gura_AssignValue(propdeclaration, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_propdeclaration::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

//-----------------------------------------------------------------------------
// Iterator_propdeclaration
//-----------------------------------------------------------------------------
Iterator_propdeclaration::Iterator_propdeclaration() : Iterator(Finite), _idx(0)
{
}

void Iterator_propdeclaration::AddPropDeclarations(const PropDeclarationMap &propDeclarationMap)
{
	foreach_const (PropDeclarationMap, iter, propDeclarationMap) {
		_propDeclarations.push_back(iter->second->Reference());
	}
	_propDeclarations.SortByName();
}

Iterator *Iterator_propdeclaration::GetSource()
{
	return nullptr;
}

bool Iterator_propdeclaration::DoNext(Environment &env, Value &value)
{
	if (_idx >= _propDeclarations.size()) return false;
	value = Value(new Object_propdeclaration(env, _propDeclarations[_idx]->Reference()));
	_idx++;
	return true;
}

String Iterator_propdeclaration::ToString() const
{
	return "propdeclaration";
}

void Iterator_propdeclaration::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
