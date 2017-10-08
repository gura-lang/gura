//=============================================================================
// Gura class: filter@softmax
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_SOFTMAX_H__
#define __GURA_CLASS_FILTER_AT_SOFTMAX_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Softmax
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Softmax : public Filter {
public:
	typedef bool (*FilterFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Filter_Softmax *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
private:
	size_t _axis;
public:
	inline Filter_Softmax(size_t axis = static_cast<size_t>(-1)) : _axis(axis) {}
	inline size_t GetAxis() const { return _axis; }
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
};

//-----------------------------------------------------------------------------
// Class_filter_at_softmax
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_softmax : public ClassFundamental {
public:
	Class_filter_at_softmax(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter_at_softmax
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_softmax : public Object_filter {
public:
	Gura_DeclareObjectAccessor(filter_at_softmax)
public:
	Object_filter_at_softmax(Environment &env, Filter_Softmax *pFilter);
	virtual Object *Clone() const;
	inline Filter_Softmax *GetFilter() { return dynamic_cast<Filter_Softmax *>(_pFilter.get()); }
	inline const Filter_Softmax *GetFilter() const { return dynamic_cast<const Filter_Softmax *>(_pFilter.get()); }
};

}

#endif
