//=============================================================================
// Gura class: filter@maxpool
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_MAXPOOL_H__
#define __GURA_CLASS_FILTER_AT_MAXPOOL_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_filter_at_maxpool
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_maxpool : public ClassFundamental {
public:
	Class_filter_at_maxpool(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_maxpool : public Object {
private:
	Filter_MaxPool _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_maxpool)
public:
	Object_filter_at_maxpool(Environment &env);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_MaxPool &GetFilter() { return _filter; }
	inline const Filter_MaxPool &GetFilter() const { return _filter; }
};

}

#endif
