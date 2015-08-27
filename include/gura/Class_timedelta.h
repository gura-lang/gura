//=============================================================================
// Gura class: timedelta
//=============================================================================
#ifndef __GURA_CLASS_TIMEDELTA_H__
#define __GURA_CLASS_TIMEDELTA_H__

#include "Class.h"
#include "Environment.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_timedelta
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_timedelta : public Class {
public:
	Class_timedelta(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_timedelta
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_timedelta : public Object {
public:
	Gura_DeclareObjectAccessor(timedelta)
private:
	TimeDelta _timeDelta;
public:
	inline Object_timedelta(Class *pClass, const TimeDelta &timeDelta) :
				Object(pClass), _timeDelta(timeDelta) {}
	inline Object_timedelta(Environment &env, const TimeDelta &timeDelta) :
				Object(env.LookupClass(VTYPE_timedelta)), _timeDelta(timeDelta) {}
	Object_timedelta(const Object_timedelta &obj);
	virtual ~Object_timedelta();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline const TimeDelta &GetTimeDelta() const { return _timeDelta; }
};

}

#endif
