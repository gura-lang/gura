//=============================================================================
// Gura class: filter@conv2d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_CONV2D_H__
#define __GURA_CLASS_FILTER_AT_CONV2D_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv2d : public Filter {
private:
	AutoPtr<Array> _pArrayFilter;
public:
	typedef bool (*FilterFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Filter_Conv2d *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Conv2d(Array *pArrayFilter) : _pArrayFilter(pArrayFilter) {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
	inline Array *GetArray() { return _pArrayFilter.get(); }
	inline const Array *GetArray() const { return _pArrayFilter.get(); }
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
// Object_filter_at_conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_conv2d : public Object_filter {
public:
	Gura_DeclareObjectAccessor(filter_at_conv2d)
public:
	Object_filter_at_conv2d(Environment &env, Filter_Conv2d *pFilter);
	virtual Object *Clone() const;
	inline Filter_Conv2d *GetFilter() { return dynamic_cast<Filter_Conv2d *>(_pFilter.get()); }
	inline const Filter_Conv2d *GetFilter() const { return dynamic_cast<const Filter_Conv2d *>(_pFilter.get()); }
};

}

#endif
