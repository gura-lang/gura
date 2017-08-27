//=============================================================================
// Gura class: filter@tanh
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_TANH_H__
#define __GURA_CLASS_FILTER_AT_TANH_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Tanh : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Tanh &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Tanh() {}
	inline Filter_Tanh(const Filter_Tanh &filter) {}
public:
	virtual Array *Apply(Signal &sig, Array *pArrayResult, const Array *pArray);
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
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_tanh : public Object {
private:
	Filter_Tanh _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_tanh)
public:
	Object_filter_at_tanh(Environment &env, const Filter_Tanh &filter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Tanh &GetFilter() { return _filter; }
	inline const Filter_Tanh &GetFilter() const { return _filter; }
};

}

#endif
