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
	AssignValue(Gura_Symbol(__name__), Value(GetName()), EXTRA_Public);
	AssignValue(Gura_Symbol(__symbol__), Value(GetSymbol()), EXTRA_Public);
	AssignValue(Gura_Symbol(__source__), Value(sourceName), EXTRA_Public);
}

Module *Module::Clone() const
{
	return new Module(*this);
}

String Module::ToString(bool exprFlag)
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

Expr *Module::MakeExpr() const
{
	return new Expr_Symbol(_pSymbol);
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

bool Module::ImportBuiltIns(Environment &env, Signal sig)
{
	do { // import(basement) {*}
		Gura_Module(basement)::MixIn(env, sig);
		if (sig.IsSignalled()) return false;
	} while (0);
	do { // import(sys) .. this module must be imported just after basement
		Module *pModule = Gura_Module(sys)::Import(env, sig);
		if (sig.IsSignalled()) return false;
		env.GetGlobal()->SetModule_sys(pModule);
	} while (0);
	do {
		Module *pModule = new Module(&env, Gura_Symbol(codecs),
											"<integrated>", NULL, NULL);
		env.AssignModule(pModule);
		// import(codecs.basic)
		if (Gura_Module(codecs_basic)::Import(*pModule, sig) == NULL) return false;
		// import(codecs.iso8859)
		if (Gura_Module(codecs_iso8859)::Import(*pModule, sig) == NULL) return false;
		// import(codecs.japanese)
		if (Gura_Module(codecs_japanese)::Import(*pModule, sig) == NULL) return false;
	} while (0);
	// import(base64)
	if (Gura_Module(base64)::Import(env, sig) == NULL) return false;
	// import(fs)
	if (Gura_Module(fs)::Import(env, sig) == NULL) return false;
	// import(os)
	if (Gura_Module(os)::Import(env, sig) == NULL) return false;
	// import(path)
	if (Gura_Module(path)::Import(env, sig) == NULL) return false;
	// import(math)
	if (Gura_Module(math)::Import(env, sig) == NULL) return false;
	// import(conio)
	if (Gura_Module(conio)::Import(env, sig) == NULL) return false;
	return true;
}

}
