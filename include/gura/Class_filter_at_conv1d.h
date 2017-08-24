//=============================================================================
// Gura class: filter@conv1d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_CONV1D_H__
#define __GURA_CLASS_FILTER_AT_CONV1D_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv1d : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Conv1d &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Conv1d() {}
	inline Filter_Conv1d(const Filter_Conv1d &filter) {}
public:
	static Array *Apply(
		Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_Conv1d &filter);
};

//-----------------------------------------------------------------------------
// Class_filter_at_conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_conv1d : public ClassFundamental {
public:
	Class_filter_at_conv1d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_conv1d : public Object {
private:
	Filter_Conv1d _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_conv1d)
public:
	Object_filter_at_conv1d(Environment &env, const Filter_Conv1d &filter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Conv1d &GetFilter() { return _filter; }
	inline const Filter_Conv1d &GetFilter() const { return _filter; }
};

}

#endif
