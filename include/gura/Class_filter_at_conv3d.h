//=============================================================================
// Gura class: filter@conv3d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_CONV3D_H__
#define __GURA_CLASS_FILTER_AT_CONV3D_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Conv3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv3d : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Conv3d *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Conv3d() {}
public:
	virtual Array *Apply(Signal &sig, Array *pArrayResult, const Array *pArray) const;
};

//-----------------------------------------------------------------------------
// Class_filter_at_conv3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_conv3d : public ClassFundamental {
public:
	Class_filter_at_conv3d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter_at_conv3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_conv3d : public Object_filter {
public:
	Gura_DeclareObjectAccessor(filter_at_conv3d)
public:
	Object_filter_at_conv3d(Environment &env, Filter_Conv3d *pFilter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Conv3d *GetFilter() { return dynamic_cast<Filter_Conv3d *>(_pFilter.get()); }
	inline const Filter_Conv3d *GetFilter() const { return dynamic_cast<const Filter_Conv3d *>(_pFilter.get()); }
};

}

#endif
