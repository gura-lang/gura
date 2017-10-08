//=============================================================================
// Gura class: filter@maxpool3d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_MAXPOOL3D_H__
#define __GURA_CLASS_FILTER_AT_MAXPOOL3D_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_MaxPool3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_MaxPool3d : public Filter {
public:
	typedef bool (*FilterFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Filter_MaxPool3d *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_MaxPool3d() {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
};

//-----------------------------------------------------------------------------
// Class_filter_at_maxpool3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_maxpool3d : public ClassFundamental {
public:
	Class_filter_at_maxpool3d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter_at_maxpool3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_maxpool3d : public Object_filter {
public:
	Gura_DeclareObjectAccessor(filter_at_maxpool3d)
public:
	Object_filter_at_maxpool3d(Environment &env, Filter_MaxPool3d *pFilter);
	virtual Object *Clone() const;
	inline Filter_MaxPool3d *GetFilter() { return dynamic_cast<Filter_MaxPool3d *>(_pFilter.get()); }
	inline const Filter_MaxPool3d *GetFilter() const { return dynamic_cast<const Filter_MaxPool3d *>(_pFilter.get()); }
};

}

#endif
