//=============================================================================
// Gura class: filter@maxpool3d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_MAXPOOL3D_H__
#define __GURA_CLASS_FILTER_AT_MAXPOOL3D_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_MaxPool3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_MaxPool3d : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_MaxPool3d &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_MaxPool3d() {}
public:
	virtual Array *Apply(Signal &sig, Array *pArrayResult, const Array *pArray);
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
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_maxpool3d : public Object {
private:
	Filter_MaxPool3d _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_maxpool3d)
public:
	Object_filter_at_maxpool3d(Environment &env);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_MaxPool3d &GetFilter() { return _filter; }
	inline const Filter_MaxPool3d &GetFilter() const { return _filter; }
};

}

#endif
