//=============================================================================
// Gura class: filter@maxpool1d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_MAXPOOL1D_H__
#define __GURA_CLASS_FILTER_AT_MAXPOOL1D_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_MaxPool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_MaxPool1d : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_MaxPool1d &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_MaxPool1d() {}
public:
	static Array *Apply(
		Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_MaxPool1d &filter);
};

//-----------------------------------------------------------------------------
// Class_filter_at_maxpool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_maxpool1d : public ClassFundamental {
public:
	Class_filter_at_maxpool1d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_maxpool1d : public Object {
private:
	Filter_MaxPool1d _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_maxpool1d)
public:
	Object_filter_at_maxpool1d(Environment &env);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_MaxPool1d &GetFilter() { return _filter; }
	inline const Filter_MaxPool1d &GetFilter() const { return _filter; }
};

}

#endif
