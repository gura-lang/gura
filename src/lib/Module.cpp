#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Module
//-----------------------------------------------------------------------------
bool Module::IsModule() const { return true; }

Module::Module(const Module &module) :
	ObjectBase(module), _pSymbol(module._pSymbol),
	_pExprScript((module._pExprScript == NULL)? NULL : module._pExprScript->Clone()),
	_moduleTerminate(module._moduleTerminate)
{
}

Module::Module(Environment *pEnvOuter, const Symbol *pSymbol, const char *sourceName,
						Expr *pExprScript, ModuleTerminateType moduleTerminate) :
		ObjectBase(pEnvOuter, ENVTYPE_module), _pSymbol(pSymbol),
		_pExprScript(pExprScript), _moduleTerminate(moduleTerminate)
{
	Environment &env = *this;
	AssignValue(Gura_Symbol(__name__), Value(env, GetName()), false);
	AssignValue(Gura_Symbol(__symbol__), Value(GetSymbol()), false);
	AssignValue(Gura_Symbol(__source__), Value(env, sourceName), false);
}

Module::~Module()
{
	Expr::Delete(_pExprScript);
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

bool Module::DirProp(Signal sig, SymbolSet &symbols)
{
	foreach_const (ValueMap, iter, GetTopFrame().GetValueMap()) {
		symbols.insert(iter->first);
	}
	return DoDirProp(sig, symbols);
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
