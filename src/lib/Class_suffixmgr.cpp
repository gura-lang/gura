//=============================================================================
// Gura class: suffixmgr
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_suffixmgr
//-----------------------------------------------------------------------------
Object_suffixmgr::Object_suffixmgr(Environment &env, SuffixMgr &suffixMgr) :
			Object(env.LookupClass(VTYPE_suffixmgr)), _suffixMgr(suffixMgr)
{
}

Object_suffixmgr::Object_suffixmgr(Class *pClass, SuffixMgr &suffixMgr) :
			Object(pClass), _suffixMgr(suffixMgr)
{
}

Object *Object_suffixmgr::Clone() const
{
	return NULL; //new Object_suffixmgr(*this);
}

bool Object_suffixmgr::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_suffixmgr::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

Value Object_suffixmgr::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_suffixmgr::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<suffixmgr";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// suffixmgr(target:symbol) {block?}
Gura_DeclareFunction(suffixmgr)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "target", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_suffixmgr));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"");
}

Gura_ImplementFunction(suffixmgr)
{
	const Symbol *pSymbol = args.GetSymbol(0);
	AutoPtr<Object_suffixmgr> pObj;
	if (pSymbol->IsIdentical(Gura_Symbol(number))) {
		pObj.reset(new Object_suffixmgr(env,
						env.GetGlobal()->GetSuffixMgrForNumber()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		pObj.reset(new Object_suffixmgr(env,
						env.GetGlobal()->GetSuffixMgrForString()));
	} else {
		sig.SetError(ERR_ValueError, "target must be `number or `string");
		return Value::Null;
	}
	return Value(pObj.release());
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// suffixmgr#assign(suffix:symbol):void:[overwrite] {block}
Gura_DeclareMethod(suffixmgr, assign)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "suffix", VTYPE_symbol);
	DeclareAttr(Gura_Symbol(overwrite));
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(suffixmgr, assign)
{
	SuffixMgr &suffixMgr = Object_suffixmgr::GetThisObj(args)->GetSuffixMgr();
	const Function *pFuncBlock = args.GetBlockFunc(env, sig, GetSymbolForBlock());
	if (pFuncBlock == NULL) return Value::Null;
	const Symbol *pSymbol = args.GetSymbol(0);
	if (!args.IsSet(Gura_Symbol(overwrite)) && suffixMgr.Lookup(pSymbol) != NULL) {
		sig.SetError(ERR_ValueError, "suffix '%s' has already been assigned", pSymbol->GetName());
		return Value::Null;
	}
	SuffixMgrEntryCustom *pSuffixMgrEntry =
					new SuffixMgrEntryCustom(Function::Reference(pFuncBlock));
	suffixMgr.Assign(pSymbol, pSuffixMgrEntry);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_suffixmgr::Class_suffixmgr(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_suffixmgr)
{

}

void Class_suffixmgr::Prepare(Environment &env)
{
	Gura_AssignFunction(suffixmgr);
	Gura_AssignMethod(suffixmgr, assign);
}

}
