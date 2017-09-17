//=============================================================================
// Gura class: trainer
//=============================================================================
#ifndef __GURA_CLASS_TRAINER_H__
#define __GURA_CLASS_TRAINER_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_trainer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_trainer : public ClassFundamental {
public:
	Class_trainer(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_trainer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_trainer : public Object {
protected:
	AutoPtr<Trainer> _pTrainer;
public:
	Gura_DeclareObjectAccessor(trainer)
public:
	Object_trainer(Environment &env, Trainer *pTrainer);
	Object_trainer(Class *pClass, Trainer *pTrainer);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Trainer *GetTrainer() { return _pTrainer.get(); }
	inline const Trainer *GetTrainer() const { return _pTrainer.get(); }
};

}

#endif
