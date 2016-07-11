//=============================================================================
// Class_document.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_document
//-----------------------------------------------------------------------------
Object_document::~Object_document()
{
}

Object *Object_document::Clone() const
{
	return nullptr;
}

bool Object_document::DoDirProp(Environment &env, SymbolSet &symbols)
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

Value Object_document::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(_document.GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(begin))) {
		return Value(_document.GetPosBegin());
	} else if (pSymbol->IsIdentical(Gura_Symbol(end))) {
		return Value(_document.GetPosEnd());
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_document::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.document:";
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// doxygen.document(stream?:stream) {block?}
Gura_DeclareFunction(document)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(document));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(document)
{
	Parser parser(nullptr);
	if (!parser.ReadStream(env, arg.GetStream(0))) return Value::Nil;
	return Value(new Object_document(parser.GetResult()->Reference()));
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.document#parse(stream:stream:w):map
Gura_DeclareMethod(document, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Reads doxygen document coming from the specified `stream`\n"
		"and returns the parsed result in `string`.");
}

Gura_ImplementMethod(document, parse)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.document
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(document)
{
	Gura_AssignFunction(document);
}

Gura_EndModuleScope(doxygen)
