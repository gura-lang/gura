#ifndef __GURA_MODULE_H__
#define __GURA_MODULE_H__

#include "Object.h"

//-----------------------------------------------------------------------------
// Macros and functions to implement modules
//-----------------------------------------------------------------------------
#define Gura_Module(name) ModuleNS_##name

#define Gura_IncludeModule(name) \
namespace Gura { \
namespace ModuleNS_##name { \
void MixIn(Environment &env, Signal sig); \
Module *Import(Environment &env, Signal sig); \
} }

#define Gura_IncludeModuleBegin(name) \
namespace Gura { \
namespace ModuleNS_##name { \
void MixIn(Environment &env, Signal sig); \
Module *Import(Environment &env, Signal sig);

#define Gura_IncludeModuleEnd() \
} }

#define Gura_BeginModule(name) \
namespace Gura { \
namespace ModuleNS_##name {

#define Gura_EndModule(name, nameBase) \
DLLEXPORT void Terminate(Module *pModule) \
{ \
	_Terminate(pModule); \
} \
DLLEXPORT Module *Import(Environment &env, Signal sig) \
{ \
	Module *pModule = new Module(&env, Symbol::Add(#nameBase), "<integrated>", NULL, Terminate); \
	MixIn(*pModule, sig); \
	if (sig.IsSignalled()) { \
		delete pModule; \
		return NULL; \
	} \
	env.AssignModule(pModule); \
	return pModule; \
} \
}}

#define Gura_BeginSubModule(name) \
namespace SubModuleNS_##name {

#define Gura_EndSubModule(name) \
}

#define Gura_AssignSubModule(name, nameBase) \
do { \
	Module *pModule = new Module(&env, Symbol::Add(#nameBase), "<integrated>", NULL, NULL); \
	SubModuleNS_##name::MixIn(*pModule, sig); \
	if (sig.IsSignalled()) { \
		delete pModule; \
		return; \
	} \
	env.AssignModule(pModule); \
} while (0)

#if defined(GURA_MODULE_SEPARATED)
#define Gura_RegisterModule(name) \
extern "C" DLLEXPORT \
void GuraModuleEntry(Gura::Environment &env, Gura::Signal sig) \
{ \
	Gura::ModuleNS_##name::MixIn(env, sig); \
} \
extern "C" DLLEXPORT \
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
DLLEXPORT void MixIn(Environment &env, Signal sig)

#define Gura_ModuleTerminate() \
DLLEXPORT void _Terminate(Module *pModule)

namespace Gura {

class Environment;
class Signal;

//-----------------------------------------------------------------------------
// Module
//-----------------------------------------------------------------------------
class DLLDECLARE Module : public ObjectBase {
protected:
	const Symbol *_pSymbol;
	Expr *_pExprScript;		// this is set to NULL in binary modules
	ModuleTerminateType _moduleTerminate;
private:
	Module(const Module &module);
public:
	Module(Environment *pEnvOuter, const Symbol *pSymbol, const char *sourceName,
					Expr *pExprScript, ModuleTerminateType moduleTerminate);
	virtual ~Module();
	inline Module *IncRef() { _cntRef++; return this; }
	inline static void Delete(Module *pModule) {
		if (pModule != NULL && pModule->DecRef() <= 0) delete pModule;
	}
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline bool IsAnonymous() const {
		return _pSymbol->IsIdentical(Gura_Symbol(_anonymous_));
	}
	inline void SetSymbol(const Symbol *pSymbol) {
		_pSymbol = pSymbol; 
		AssignValue(Gura_Symbol(__name__), Value(*this, GetName()), false);
	}
	inline const Symbol *GetSymbol() const { return _pSymbol; }
	bool DirProp(Signal sig, SymbolSet &symbols);
	void DirValueType(SymbolSet &symbols) const;
	virtual bool IsModule() const;
	virtual Module *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
};

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
namespace Gura_Module(math) {
DLLEXPORT Expr *CreateFuncExpr(const char *name, Expr *pExprArg);
}

}

#endif
