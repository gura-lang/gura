//=============================================================================
// Gura class: filter@tanh
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_TANH_H__
#define __GURA_CLASS_FILTER_AT_TANH_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Tanh : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Tanh *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Tanh() {}
public:
	virtual Array *Apply(Signal &sig, Array *pArrayResult, const Array *pArray) const;
	virtual String ToString() const;
};

//-----------------------------------------------------------------------------
// Class_filter_at_tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_tanh : public ClassFundamental {
public:
	Class_filter_at_tanh(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter_at_tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_tanh : public Object_filter {
public:
	static Value valueConst;
public:
	Gura_DeclareObjectAccessor(filter_at_tanh)
public:
	Object_filter_at_tanh(Environment &env, Filter_Tanh *pFilter);
	virtual Object *Clone() const;
	inline Filter_Tanh *GetFilter() { return dynamic_cast<Filter_Tanh *>(_pFilter.get()); }
	inline const Filter_Tanh *GetFilter() const { return dynamic_cast<const Filter_Tanh *>(_pFilter.get()); }
};

}

#endif
