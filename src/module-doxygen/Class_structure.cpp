//=============================================================================
// Class_structure.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_structure
//-----------------------------------------------------------------------------
Object_structure::~Object_structure()
{
}

Object *Object_structure::Clone() const
{
	return nullptr;
}

bool Object_structure::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(elems));
	return true;
}

Value Object_structure::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(elems))) {
		AutoPtr<Iterator> pIterator(
			new Iterator_Elem(_pStructure->GetElemOwner().Reference()));
		return Value(new Object_iterator(env, pIterator.release()));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_structure::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.structure";
	do {
		char buff[32];
		::sprintf(buff, ":%ldelems", _pStructure->GetElemOwner().size());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.structure#each() {block?}
Gura_DeclareMethod(structure, each)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(structure, each)
{
	const Structure *pStructure = Object_structure::GetObjectThis(arg)->GetStructure();
	AutoPtr<Iterator> pIterator(
		new Iterator_Elem(pStructure->GetElemOwner().Reference()));
	return ReturnIterator(env, arg, pIterator.release());
}

// doxygen.structure#each@command(name?:string) {block?}
Gura_DeclareMethodAlias(structure, each_at_command, "each@command")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(structure, each_at_command)
{
	const Structure *pStructure = Object_structure::GetObjectThis(arg)->GetStructure();
	const char *name = arg.IsValid(0)? arg.GetString(0) : "";
	AutoPtr<Iterator> pIterator(
		new Iterator_Elem_Command(pStructure->GetElemOwner().Reference(), name));
	return ReturnIterator(env, arg, pIterator.release());
}

// doxygen.structure#each@composite() {block?}
Gura_DeclareMethodAlias(structure, each_at_composite, "each@composite")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(structure, each_at_composite)
{
	const Structure *pStructure = Object_structure::GetObjectThis(arg)->GetStructure();
	AutoPtr<Iterator> pIterator(
		new Iterator_Elem_Composite(pStructure->GetElemOwner().Reference()));
	return ReturnIterator(env, arg, pIterator.release());
}

// doxygen.structure#print(indent?:number, out?:stream):void
Gura_DeclareMethod(structure, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(structure, print)
{
	int indentLevel = arg.IsValid(0)? arg.GetInt(0) : 0;
	Stream &stream = arg.IsValid(1)? arg.GetStream(1) : *env.GetConsole();
	const Structure *pStructure = Object_structure::GetObjectThis(arg)->GetStructure();
	pStructure->GetElemOwner().Print(env, stream, indentLevel);
	return Value::Nil;
}

// doxygen.structure#render(renderer:doxygen.renderer, cfg?:doxygen.configuration, out?:stream:w)
Gura_DeclareMethod(structure, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_renderer, OCCUR_Once);
	DeclareArg(env, "cfg", VTYPE_configuration, OCCUR_ZeroOrOnce);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(structure, render)
{
	Structure *pStruct = Object_structure::GetObjectThis(arg)->GetStructure();
	Renderer *pRenderer = Object_renderer::GetObject(arg, 0)->GetRenderer();
	const Configuration *pCfg = arg.IsValid(1)?
		Object_configuration::GetObject(arg, 1)->GetConfiguration() : nullptr;
	if (arg.IsValid(2)) {
		SimpleStream &stream = arg.GetStream(2);
		pStruct->GetElemOwner().Render(pRenderer, pCfg, stream);
		return Value::Nil;
	} else {
		String str;
		SimpleStream_StringWriter stream(str);
		if (!pStruct->GetElemOwner().Render(pRenderer, pCfg, stream)) return Value::Nil;
		return Value(str);
	}
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.structure
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(structure)
{
	Gura_AssignValue(structure, Value(Reference()));
	Gura_AssignMethod(structure, each);
	Gura_AssignMethod(structure, each_at_command);
	Gura_AssignMethod(structure, each_at_composite);
	Gura_AssignMethod(structure, print);
	Gura_AssignMethod(structure, render);
}

Gura_EndModuleScope(doxygen)
