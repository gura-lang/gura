//=============================================================================
// Gura class: traineropt
//=============================================================================
#ifndef __GURA_CLASS_TRAINEROPT_H__
#define __GURA_CLASS_TRAINEROPT_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_traineropt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_traineropt : public ClassFundamental {
public:
	Class_traineropt(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_traineropt
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_traineropt : public Object {
protected:
	AutoPtr<Trainer::Optimizer> _pOptimizer;
public:
	Gura_DeclareObjectAccessor(traineropt)
public:
	Object_traineropt(Environment &env, Trainer::Optimizer *pOptimizer);
	Object_traineropt(Class *pClass, Trainer::Optimizer *pOptimizer);
	virtual String ToString(bool exprFlag);
	inline Trainer::Optimizer *GetOptimizer() { return _pOptimizer.get(); }
	inline const Trainer::Optimizer *GetOptimizer() const { return _pOptimizer.get(); }
};

}

#endif
