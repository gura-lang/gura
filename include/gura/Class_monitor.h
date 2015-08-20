//=============================================================================
// Gura class: monitor
//=============================================================================
#ifndef __GURA_CLASS_MONITOR_H__
#define __GURA_CLASS_MONITOR_H__

#include "Class.h"
#include "Monitor.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_monitor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_monitor : public Class {
public:
	Class_monitor(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_monitor
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_monitor : public Object {
private:
	AutoPtr<Monitor> _pMonitor;
public:
	Gura_DeclareObjectAccessor(monitor)
public:
	Object_monitor(const Object_monitor &obj);
	inline Object_monitor(Environment &env, Monitor *pMonitor) :
						Object(env.LookupClass(VTYPE_monitor)), _pMonitor(pMonitor) {}
	inline Object_monitor(Class *pClass, Monitor *pMonitor) :
						Object(pClass), _pMonitor(pMonitor) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Monitor *GetMonitor() { return _pMonitor.get(); }
	inline const Monitor *GetMonitor() const { return _pMonitor.get(); }
};

}

#endif
