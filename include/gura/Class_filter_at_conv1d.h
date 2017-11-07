//=============================================================================
// Gura class: filter@conv1d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_CONV1D_H__
#define __GURA_CLASS_FILTER_AT_CONV1D_H__

#include "Class_filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv1d : public Filter {
public:
	typedef bool (*FilterFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Filter_Conv1d *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
private:
	AutoPtr<Array> _pArrayFilter;
	size_t _strides;
	PaddingType _paddingType;
	Array::ChannelAt _channelAt;
public:
	inline Filter_Conv1d(Array *pArrayFilter, size_t strides, PaddingType paddingType, Array::ChannelAt channelAt) :
		_pArrayFilter(pArrayFilter), _strides(strides),
		_paddingType(paddingType), _channelAt(channelAt) {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
	inline Array *GetArray() { return _pArrayFilter.get(); }
	inline const Array *GetArray() const { return _pArrayFilter.get(); }
	inline bool HasC() const { return _pArrayFilter->GetDimensions().size() >= 2; }
	inline bool HasFN() const { return _pArrayFilter->GetDimensions().size() == 3; }
	inline size_t GetSize() const { return _pArrayFilter->GetDimensions().GetBack(0).GetSize(); }
	inline size_t GetC() const { return _pArrayFilter->GetDimensions().GetBack(1).GetSize(); }
	inline size_t GetFN() const { return _pArrayFilter->GetDimensions().GetBack(2).GetSize(); }
	inline size_t GetStrides() const { return _strides; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelAt GetChannelAt() const { return _channelAt; }
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
// Object_filter_at_conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_conv1d : public Object_filter {
public:
	Gura_DeclareObjectAccessor(filter_at_conv1d)
public:
	Object_filter_at_conv1d(Environment &env, Filter_Conv1d *pFilter);
	virtual Object *Clone() const;
	inline Filter_Conv1d *GetFilter() { return dynamic_cast<Filter_Conv1d *>(_pFilter.get()); }
	inline const Filter_Conv1d *GetFilter() const { return dynamic_cast<const Filter_Conv1d *>(_pFilter.get()); }
};

}

#endif
