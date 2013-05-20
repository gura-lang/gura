#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Module
//-----------------------------------------------------------------------------
bool Module::IsModule() const { return true; }

Module::Module(const Module &module) :
	Fundamental(module), _pSymbol(module._pSymbol), _sourceName(module._sourceName),
	_pExprScript(module._pExprScript.IsNull()? NULL : module._pExprScript->Clone()),
	_moduleTerminate(module._moduleTerminate)
{
}

Module::Module(Environment *pEnvOuter, const Symbol *pSymbol, const char *sourceName,
						Expr *pExprScript, ModuleTerminateType moduleTerminate) :
	Fundamental(pEnvOuter, ENVTYPE_local), _pSymbol(pSymbol), _sourceName(sourceName),
	_pExprScript(pExprScript), _moduleTerminate(moduleTerminate)
{
	Environment &env = *this;
	AssignValue(Gura_Symbol(__name__), Value(env, GetName()), EXTRA_Public);
	AssignValue(Gura_Symbol(__symbol__), Value(GetSymbol()), EXTRA_Public);
	AssignValue(Gura_Symbol(__source__), Value(env, sourceName), EXTRA_Public);
}

Module *Module::Clone() const
{
	return new Module(*this);
}

String Module::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<module:";
	str += GetName();
	str += ":";
	str += GetSourceName();
	str += ">";
	return str;
}

void Module::AssignValueType(ValueTypeInfo *pValueTypeInfo)
{
	pValueTypeInfo->SetModule(this);
	Environment::AssignValueType(pValueTypeInfo);
}

bool Module::DirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	foreach_const (ValueMap, iter, GetTopFrame()->GetValueMap()) {
		symbols.insert(iter->first);
	}
	return DoDirProp(env, sig, symbols);
}

void Module::DirValueType(SymbolSet &symbols) const
{
	foreach_const (ValueTypeMap, iter, GetTopFrame()->GetValueTypeMap()) {
		symbols.insert(iter->first);
	}
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
namespace Gura_Module(math) {
Expr *CreateFuncExpr(const char *name, Expr *pExprArg)
{
	return new Expr_Caller(
			new Expr_Member(
					new Expr_Symbol(Symbol::Add("math")),
					new Expr_Symbol(Symbol::Add(name))),
			new Expr_Lister(pExprArg), NULL);
}
}

}
