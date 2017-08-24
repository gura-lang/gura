//=============================================================================
// Gura class: filter@conv2d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_CONV2D_H__
#define __GURA_CLASS_FILTER_AT_CONV2D_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv2d : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Conv2d &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Conv2d() {}
	inline Filter_Conv2d(const Filter_Conv2d &filter) {}
public:
	static Array *Apply(
		Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_Conv2d &filter);
};

//-----------------------------------------------------------------------------
// Class_filter_at_conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_conv2d : public ClassFundamental {
public:
	Class_filter_at_conv2d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_conv2d : public Object {
private:
	Filter_Conv2d _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_conv2d)
public:
	Object_filter_at_conv2d(Environment &env, const Filter_Conv2d &filter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Conv2d &GetFilter() { return _filter; }
	inline const Filter_Conv2d &GetFilter() const { return _filter; }
};

}

#endif
