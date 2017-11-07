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
private:
	size_t _sizePlane;
	size_t _sizeRow;
	size_t _sizeCol;
	size_t _stridesPlane;
	size_t _stridesRow;
	size_t _stridesCol;
	PaddingType _paddingType;
	Array::ChannelAt _channelAt;
public:
	inline Filter_MaxPool3d(size_t sizePlane, size_t sizeRow, size_t sizeCol,
							size_t stridesPlane, size_t stridesRow, size_t stridesCol,
							PaddingType paddingType, Array::ChannelAt channelAt) :
		_sizePlane(sizePlane), _sizeRow(sizeRow), _sizeCol(sizeCol),
		_stridesPlane(stridesPlane), _stridesRow(stridesRow), _stridesCol(stridesCol),
		_paddingType(paddingType), _channelAt(channelAt) {}
	inline size_t GetSizePlane() const { return _sizePlane; }
	inline size_t GetSizeRow() const { return _sizeRow; }
	inline size_t GetSizeCol() const { return _sizeCol; }
	inline size_t GetStridesPlane() const { return _stridesPlane; }
	inline size_t GetStridesRow() const { return _stridesRow; }
	inline size_t GetStridesCol() const { return _stridesCol; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelAt GetChannelAt() const { return _channelAt; }
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
