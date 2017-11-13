//=============================================================================
// Gura class: filter@conv2d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_CONV2D_H__
#define __GURA_CLASS_FILTER_AT_CONV2D_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_Conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_Conv2d : public Filter {
public:
	typedef bool (*FilterFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Filter_Conv2d *pFilter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
private:
	AutoPtr<Array> _pArrayFilter;
	size_t _stridesRow;
	size_t _stridesCol;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	inline Filter_Conv2d(Array *pArrayFilter, size_t stridesRow, size_t stridesCol,
						 PaddingType paddingType, Array::ChannelPos channelPos) :
		_pArrayFilter(pArrayFilter),
		_stridesRow(stridesRow), _stridesCol(stridesCol),
		_paddingType(paddingType), _channelPos(channelPos) {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
	inline bool IsChLast() const { return _channelPos == Array::CHANNELPOS_Last; }
	inline Array *GetArrayFilter() { return _pArrayFilter.get(); }
	inline const Array *GetArrayFilter() const { return _pArrayFilter.get(); }
	inline bool HasChannelDim() const { return _pArrayFilter->GetDimensions().size() >= 3; }
	inline bool HasFilterDim() const { return _pArrayFilter->GetDimensions().size() == 4; }
	inline size_t GetSizeCol() const {
		return _pArrayFilter->GetDimensions().GetBack(IsChLast()? 1 : 0).GetSize();
	}
	inline size_t GetSizeRow() const {
		return _pArrayFilter->GetDimensions().GetBack(IsChLast()? 2 : 1).GetSize();
	}
	inline size_t GetChannelNum() const {
		return HasChannelDim()? _pArrayFilter->GetDimensions().GetBack(IsChLast()? 0 : 2).GetSize() : 1;
	}
	inline size_t GetFilterNum() const {
		return HasFilterDim()? _pArrayFilter->GetDimensions().GetBack(3).GetSize() : 1;
	}
	inline size_t GetStridesRow() const { return _stridesRow; }
	inline size_t GetStridesCol() const { return _stridesCol; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
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
