//=============================================================================
// Module
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Module
//-----------------------------------------------------------------------------
bool Module::IsModule() const { return true; }

Module::Module(const Module &module) :
	Fundamental(module), _pSymbol(module._pSymbol), _sourceName(module._sourceName),
	_pExprScript(module._pExprScript.IsNull()? nullptr : module._pExprScript->Clone()),
	_moduleTerminate(module._moduleTerminate)
{
}

Module::Module(Environment *pEnvOuter, const Symbol *pSymbol, const char *sourceName,
						Expr *pExprScript, ModuleTerminateType moduleTerminate) :
	Fundamental(pEnvOuter, ENVTYPE_local), _pSymbol(pSymbol), _sourceName(sourceName),
	_pExprScript(pExprScript), _moduleTerminate(moduleTerminate)
{
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
	return new Expr_Identifier(_pSymbol);
}

bool Module::DirProp(Environment &env, SymbolSet &symbols)
{
	foreach_const (ValueMap, iter, GetTopFrame()->GetValueMap()) {
		symbols.insert(iter->first);
	}
	return DoDirProp(env, symbols);
}

void Module::DirValueType(SymbolSet &symbols) const
{
	foreach_const (ValueTypeMap, iter, GetTopFrame()->GetValueTypeMap()) {
		symbols.insert(iter->first);
	}
}

bool Module::ImportBuiltIns(Environment &env)
{
	Module *pModule = nullptr;
	// import(basement) {*}
	if (!Gura_Module(basement)::MixIn(env)) return false;
	// import(sys) .. this module must be imported just after basement
	if ((pModule = Gura_Module(sys)::Import(env)) == nullptr) return false;
	env.GetGlobal()->SetModule_sys(pModule);
	// import(codecs)
	if ((pModule = Gura_Module(codecs)::Import(env)) == nullptr) return false;
	do {
		Environment &env = *pModule;
		// import(codecs.basic)
		if (Gura_Module(codecs_basic)::Import(env) == nullptr) return false;
		// import(codecs.chinese)
		if (Gura_Module(codecs_chinese)::Import(env) == nullptr) return false;
		// import(codecs.iso8859)
		if (Gura_Module(codecs_iso8859)::Import(env) == nullptr) return false;
		// import(codecs.japanese)
		if (Gura_Module(codecs_japanese)::Import(env) == nullptr) return false;
		// import(codecs.korean)
		if (Gura_Module(codecs_korean)::Import(env) == nullptr) return false;
	} while (0);
	// import(base64)
	if (Gura_Module(base64)::Import(env) == nullptr) return false;
	// import(fs)
	if (Gura_Module(fs)::Import(env) == nullptr) return false;
	// import(os)
	if (Gura_Module(os)::Import(env) == nullptr) return false;
	// import(path)
	if (Gura_Module(path)::Import(env) == nullptr) return false;
	// import(math)
	if (Gura_Module(math)::Import(env) == nullptr) return false;
	return true;
}

}
