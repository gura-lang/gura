//=============================================================================
// Gura class: filter@sigmoid
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_SIGMOID_H__
#define __GURA_CLASS_FILTER_AT_SIGMOID_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Sigmoid
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Sigmoid : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Sigmoid *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Sigmoid() {}
public:
	virtual Array *Apply(Signal &sig, Array *pArrayResult, const Array *pArray) const;
};

//-----------------------------------------------------------------------------
// Class_filter_at_sigmoid
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_sigmoid : public ClassFundamental {
public:
	Class_filter_at_sigmoid(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter_at_sigmoid
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_sigmoid : public Object_filter {
public:
	static Value valueConst;
public:
	Gura_DeclareObjectAccessor(filter_at_sigmoid)
public:
	Object_filter_at_sigmoid(Environment &env, Filter_Sigmoid *pFilter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Sigmoid *GetFilter() { return dynamic_cast<Filter_Sigmoid *>(_pFilter.get()); }
	inline const Filter_Sigmoid *GetFilter() const { return dynamic_cast<const Filter_Sigmoid *>(_pFilter.get()); }
};

}

#endif
