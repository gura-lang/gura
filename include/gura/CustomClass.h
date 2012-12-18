#ifndef __GURA_CUSTOMCLASS_H__
#define __GURA_CUSTOMCLASS_H__

#include "Common.h"
#include "Object.h"

namespace Gura {

class DLLDECLARE CustomClass : public Class {
private:
	AutoPtr<Expr_Block> _pExprContent;
	Signal _sig;
public:
	CustomClass(const CustomClass &cls);
	CustomClass(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent, Signal sig);
	virtual ~CustomClass();
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	Function *Prepare(Environment &env, Signal sig);
	static void OnModuleEntry(Environment &env, Signal sig);
	inline Signal &GetSignal() { return _sig; }
};

}

#endif
