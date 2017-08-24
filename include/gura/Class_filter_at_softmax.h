//=============================================================================
// Gura class: filter@softmax
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_SOFTMAX_H__
#define __GURA_CLASS_FILTER_AT_SOFTMAX_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Softmax
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Softmax : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_Softmax &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_Softmax() {}
	inline Filter_Softmax(const Filter_Softmax &filter) {}
public:
	static Array *Apply(
		Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_Softmax &filter);
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
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_softmax : public Object {
private:
	Filter_Softmax _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_softmax)
public:
	Object_filter_at_softmax(Environment &env, const Filter_Softmax &filter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_Softmax &GetFilter() { return _filter; }
	inline const Filter_Softmax &GetFilter() const { return _filter; }
};

}

#endif
