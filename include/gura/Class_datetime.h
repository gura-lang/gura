//=============================================================================
// Gura class: datetime
//=============================================================================
#ifndef __GURA_CLASS_DATETIME_H__
#define __GURA_CLASS_DATETIME_H__

#include "Class.h"
#include "Environment.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_datetime
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_datetime : public ClassFundamental {
public:
	Class_datetime(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_datetime
//-----------------------------------------------------------------------------
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
	virtual String ToString(bool exprFlag);
	inline DateTime &GetDateTime() { return _dateTime; }
	inline const DateTime &GetDateTime() const { return _dateTime; }
};

}

#endif
