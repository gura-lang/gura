//=============================================================================
// Gura class: filter@relu
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_RELU_H__
#define __GURA_CLASS_FILTER_AT_RELU_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Relu
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Relu : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Relu *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Relu() {}
public:
	virtual Array *Apply(Signal &sig, Array *pArrayResult, const Array *pArray) const;
};

//-----------------------------------------------------------------------------
// Class_filter_at_relu
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_relu : public ClassFundamental {
public:
	Class_filter_at_relu(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter_at_relu
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_relu : public Object_filter {
public:
	Gura_DeclareObjectAccessor(filter_at_relu)
public:
	Object_filter_at_relu(Environment &env, Filter_Relu *pFilter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Relu *GetFilter() { return dynamic_cast<Filter_Relu *>(_pFilter.get()); }
	inline const Filter_Relu *GetFilter() const { return dynamic_cast<const Filter_Relu *>(_pFilter.get()); }
};

}

#endif
