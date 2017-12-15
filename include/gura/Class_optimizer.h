//=============================================================================
// Gura class: optimizer
//=============================================================================
#ifndef __GURA_CLASS_OPTIMIZER_H__
#define __GURA_CLASS_OPTIMIZER_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_optimizer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_optimizer : public ClassFundamental {
public:
	Class_optimizer(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_optimizer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_optimizer : public Object {
protected:
	AutoPtr<Trainer::Optimizer> _pOptimizer;
public:
	Gura_DeclareObjectAccessor(optimizer)
public:
	Object_optimizer(Environment &env, Trainer::Optimizer *pOptimizer);
	Object_optimizer(Class *pClass, Trainer::Optimizer *pOptimizer);
	virtual String ToString(bool exprFlag);
	inline Trainer::Optimizer *GetOptimizer() { return _pOptimizer.get(); }
	inline const Trainer::Optimizer *GetOptimizer() const { return _pOptimizer.get(); }
};

}

#endif
