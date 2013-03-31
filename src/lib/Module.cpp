#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Module
//-----------------------------------------------------------------------------
bool Module::IsModule() const { return true; }

Module::Module(const Module &module) :
	Fundamental(module), _pSymbol(module._pSymbol),
	_pExprScript(module._pExprScript.IsNull()? NULL : module._pExprScript->Clone()),
	_moduleTerminate(module._moduleTerminate)
{
}

Module::Module(Environment *pEnvOuter, const Symbol *pSymbol, const char *sourceName,
						Expr *pExprScript, ModuleTerminateType moduleTerminate) :
	Fundamental(pEnvOuter, ENVTYPE_local), _pSymbol(pSymbol),
	_pExprScript(pExprScript), _moduleTerminate(moduleTerminate)
{
	Environment &env = *this;
	AssignValueLocal(Gura_Symbol(__name__), Value(env, GetName()));
	AssignValueLocal(Gura_Symbol(__symbol__), Value(GetSymbol()));
	AssignValueLocal(Gura_Symbol(__source__), Value(env, sourceName));
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
	str += ">";
	return str;
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
