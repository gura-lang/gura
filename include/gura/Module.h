#ifndef __GURA_MODULE_H__
#define __GURA_MODULE_H__

#include "Fundamental.h"

//-----------------------------------------------------------------------------
// Macros and functions to implement modules
//-----------------------------------------------------------------------------
#define Gura_Module(name) ModuleNS_##name

#define Gura_BeginModuleHeader(name) \
namespace Gura { \
namespace ModuleNS_##name {

#define Gura_EndModuleHeader(name) \
GURA_DLLEXPORT void MixIn(Environment &env, Signal sig); \
GURA_DLLEXPORT Module *Import(Environment &env, Signal sig); \
}}

#define Gura_BeginModuleBody(name) \
namespace Gura { \
namespace ModuleNS_##name {

#define Gura_EndModuleBody(name, nameBase) \
GURA_DLLEXPORT void Terminate(Module *pModule) \
{ \
	_Terminate(pModule); \
} \
GURA_DLLEXPORT Module *Import(Environment &env, Signal sig) \
{ \
	AutoPtr<Module> pModule(new Module(&env, Symbol::Add(#nameBase), "<integrated>", NULL, Terminate)); \
	MixIn(*pModule, sig); \
	if (sig.IsSignalled()) return NULL; \
	env.AssignModule(pModule.get()); \
	return pModule.release(); \
} \
}}

#define Gura_BeginModuleScope(name) \
namespace Gura { \
namespace ModuleNS_##name {

#define Gura_EndModuleScope(name) \
}}

#if defined(GURA_MODULE_SEPARATED)
#define Gura_RegisterModule(name) \
extern "C" GURA_DLLEXPORT \
void GuraModuleEntry(Gura::Environment &env, Gura::Signal sig) \
{ \
	Gura::ModuleNS_##name::MixIn(env, sig); \
} \
extern "C" GURA_DLLEXPORT \
void GuraModuleTerminate(Gura::Module *pModule) \
{ \
	Gura::ModuleNS_##name::Terminate(pModule); \
}
#else // GURA_MODULE_INTEGRATED
#define Gura_RegisterModule(name) \
namespace Gura { \
namespace ModuleNS_##name { \
ModuleIntegrator s_integrator(#name, MixIn, Terminate); \
} }
#endif

#define Gura_ModuleEntry() \
GURA_DLLEXPORT void MixIn(Environment &env, Signal sig)

#define Gura_ModuleTerminate() \
GURA_DLLEXPORT void _Terminate(Module *pModule)

namespace Gura {

class Environment;
class Signal;

//-----------------------------------------------------------------------------
// Module
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Module : public Fundamental {
protected:
	const Symbol *_pSymbol;
	String _sourceName;
	AutoPtr<Expr> _pExprScript;		// this is set to NULL in binary modules
	ModuleTerminateType _moduleTerminate;
public:
	Gura_DeclareReferenceAccessor(Module);
private:
	Module(const Module &module);
public:
	Module(Environment *pEnvOuter, const Symbol *pSymbol, const char *sourceName,
					Expr *pExprScript, ModuleTerminateType moduleTerminate);
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline bool IsAnonymous() const {
		return _pSymbol->IsIdentical(Gura_Symbol(_anonymous_));
	}
	inline void SetSymbol(const Symbol *pSymbol) {
		_pSymbol = pSymbol; 
		AssignValue(Gura_Symbol(__name__), Value(*this, GetName()), EXTRA_Public);
	}
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	inline const char *GetSourceName() const { return _sourceName.c_str(); }
	Expr *MakeExpr() const;
	bool DirProp(Environment &env, Signal sig, SymbolSet &symbols);
	void DirValueType(SymbolSet &symbols) const;
	virtual bool IsModule() const;
	virtual void AssignValueType(ValueTypeInfo *pValueTypeInfo);
	virtual Module *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
public:
	static bool ImportBuiltIns(Environment &env, Signal sig);
};

}

#endif
