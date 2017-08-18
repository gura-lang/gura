//=============================================================================
// Filter
//=============================================================================
#ifndef __GURA_FILTER_H__
#define __GURA_FILTER_H__

#include "Array.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter {
public:
	inline Filter() {}
	virtual ~Filter();
};

//-----------------------------------------------------------------------------
// Filter_MaxPool
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_MaxPool : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_MaxPool &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
public:
	inline Filter_MaxPool() {}
public:
	static Array *Apply(
		Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_MaxPool &filter);
};

//-----------------------------------------------------------------------------
// Filter_Conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv1d : public Filter {
public:
	inline Filter_Conv1d() {}
};

//-----------------------------------------------------------------------------
// Filter_Conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv2d : public Filter {
public:
	inline Filter_Conv2d() {}
};

//-----------------------------------------------------------------------------
// Filter_Conv3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv3d : public Filter {
public:
	inline Filter_Conv3d() {}
};

}

#endif
