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
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(elem));
	return true;
}

Value Object_document::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(elem))) {
		return _pDocument.IsNull()? Value::Nil :
			Value(new Object_elem(_pDocument->GetElemTop()->Reference()));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_document::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.document:";
	if (_pDocument.IsNull()) {
		rtn += "invalid";
	} else {
		rtn += _pDocument->GetSourceName();
	}
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// doxygen.document(stream?:stream, aliases?:doxygen.aliases, extracted?:boolean):[] {block?}
Gura_DeclareFunction(document)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareArg(env, "aliases", VTYPE_aliases, OCCUR_ZeroOrOnce);
	DeclareArg(env, "extracted", VTYPE_boolean, OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(document));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(document)
{
	AutoPtr<Object_document> pObj(new Object_document());
	if (arg.IsValid(0)) {
		AutoPtr<Document> pDocument(new Document());
		Stream &stream = arg.GetStream(0);
		const Aliases *pAliases = arg.IsValid(1)?
			Object_aliases::GetObject(arg, 1)->GetAliases() : nullptr;
		bool extractedFlag = arg.IsValid(2) && arg.GetBoolean(2);
		if (!pDocument->ReadStream(env, stream, pAliases, extractedFlag)) return Value::Nil;
		pObj->SetDocument(pDocument.release());
	}
	return ReturnValue(env, arg, Value(pObj.release()));
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.document#render(renderer:doxygen.renderer, cfg?:doxygen.configuration, out?:stream:w)
Gura_DeclareMethod(document, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_renderer, OCCUR_Once);
	DeclareArg(env, "cfg", VTYPE_configuration, OCCUR_ZeroOrOnce);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(document, render)
{
	Document *pDoc = Object_document::GetObjectThis(arg)->GetDocument();
	Renderer *pRenderer = Object_renderer::GetObject(arg, 0)->GetRenderer();
	const Configuration *pCfg = arg.IsValid(1)?
		Object_configuration::GetObject(arg, 1)->GetConfiguration() : nullptr;
	if (arg.IsValid(2)) {
		SimpleStream &stream = arg.GetStream(2);
		pDoc->GetElemTop()->Render(pRenderer, pCfg, stream);
		return Value::Nil;
	} else {
		String str;
		SimpleStream_StringWriter stream(str);
		if (!pDoc->GetElemTop()->Render(pRenderer, pCfg, stream)) return Value::Nil;
		return Value(str);
	}
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.document
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(document)
{
	Gura_AssignFunction(document);
	Gura_AssignMethod(document, render);
}

Gura_EndModuleScope(doxygen)