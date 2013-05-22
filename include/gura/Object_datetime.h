#ifndef __GURA_OBJECT_DATETIME_H__
#define __GURA_OBJECT_DATETIME_H__

#include "Object.h"
#include "Environment.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_datetime / Object_datetime
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_datetime : public Class {
public:
	Class_datetime(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void DoAssignConstructor(Environment &env, Signal sig);
};

class GURA_DLLDECLARE Object_datetime : public Object {
public:
	Gura_DeclareObjectAccessor(datetime)
private:
	DateTime _dateTime;
public:
	inline Object_datetime(Environment &env, const DateTime &dateTime) :
				Object(env.LookupClass(VTYPE_datetime)), _dateTime(dateTime) {}
	inline Object_datetime(Class *pClass, const DateTime &dateTime) :
				Object(pClass), _dateTime(dateTime) {}
	Object_datetime(const Object_datetime &obj);
	virtual ~Object_datetime();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline DateTime &GetDateTime() { return _dateTime; }
	inline const DateTime &GetDateTime() const { return _dateTime; }
};

}

#endif
