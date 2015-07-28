//=============================================================================
// Gura class: symbol
//=============================================================================
#ifndef __GURA_CLASS_SYMBOL_H__
#define __GURA_CLASS_SYMBOL_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_symbol
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_symbol : public Class {
public:
	Class_symbol(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal &__to_delete__, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal &__to_delete__, Stream &stream, Value &value) const;
};

}

#endif
