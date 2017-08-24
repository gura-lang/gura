//=============================================================================
// Gura class: filter@relu
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_RELU_H__
#define __GURA_CLASS_FILTER_AT_RELU_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Relu
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Relu : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Relu &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Relu() {}
	inline Filter_Relu(const Filter_Relu &filter) {}
public:
	static Array *Apply(
		Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_Relu &filter);
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
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_relu : public Object {
private:
	Filter_Relu _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_relu)
public:
	Object_filter_at_relu(Environment &env, const Filter_Relu &filter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Relu &GetFilter() { return _filter; }
	inline const Filter_Relu &GetFilter() const { return _filter; }
};

}

#endif
