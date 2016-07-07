//=============================================================================
// Class_parser.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_parser
//-----------------------------------------------------------------------------
Object_parser::~Object_parser()
{
}

Object *Object_parser::Clone() const
{
	return nullptr;
}

bool Object_parser::DoDirProp(Environment &env, SymbolSet &symbols)
{
#if 0
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(string));
	symbols.insert(Gura_Symbol(begin));
	symbols.insert(Gura_Symbol(end));
#endif
	return true;
}

Value Object_parser::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(_parser.GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(begin))) {
		return Value(_parser.GetPosBegin());
	} else if (pSymbol->IsIdentical(Gura_Symbol(end))) {
		return Value(_parser.GetPosEnd());
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_parser::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.parser:";
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// doxygen.parser(extracted?:boolean) {block?}
Gura_DeclareFunction(parser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "extractec", VTYPE_boolean, OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(parser));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(parser)
{
	Signal &sig = env.GetSignal();
	bool extractedFlag = arg.IsValid(0)? arg.GetBoolean(0) : false;
	Object_parser *pObj = Object_parser::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_parser(Gura_UserClass(parser));
		if (extractedFlag) pObj->GetParser().SetExtractedMode();
		return ReturnValue(env, arg, Value(pObj));
	} else {
		if (extractedFlag) pObj->GetParser().SetExtractedMode();
		return ReturnValue(env, arg, arg.GetValueThis());
	}
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.parser#parse(stream:stream):map
Gura_DeclareMethod(parser, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads doxygen document coming from the specified `stream`\n"
		"and returns the parsed result in `string`.");
}

Gura_ImplementMethod(parser, parse)
{
	Parser &parser = Object_parser::GetObjectThis(arg)->GetParser();
	if (!parser.ParseStream(env, arg.GetStream(0))) return Value::Nil;
	return Value(new Object_elem(parser.GetResult()->Reference()));
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.parser
//-----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(parser)
{
	Gura_AssignFunction(parser);
	Gura_AssignMethod(parser, parse);
}

Gura_ImplementDescendantCreator(parser)
{
	return new Object_parser((pClass == nullptr)? this : pClass);
}

Gura_EndModuleScope(doxygen)
