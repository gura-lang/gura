//=============================================================================
// Gura class: filter@maxpool1d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_MAXPOOL1D_H__
#define __GURA_CLASS_FILTER_AT_MAXPOOL1D_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_MaxPool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_MaxPool1d : public Filter {
private:
	size_t _size;
	size_t _strides;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	inline Filter_MaxPool1d(size_t size, size_t strides, PaddingType paddingType, Array::ChannelPos channelPos) :
		_size(size), _strides(strides),
		_paddingType(paddingType), _channelPos(channelPos) {}
	inline size_t GetSize() const { return _size; }
	inline size_t GetStrides() const { return _strides; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
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
// Object_filter_at_maxpool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_maxpool1d : public Object_filter {
public:
	Gura_DeclareObjectAccessor(filter_at_maxpool1d)
public:
	Object_filter_at_maxpool1d(Environment &env, Filter_MaxPool1d *pFilter);
	virtual Object *Clone() const;
	inline Filter_MaxPool1d *GetFilter() { return dynamic_cast<Filter_MaxPool1d *>(_pFilter.get()); }
	inline const Filter_MaxPool1d *GetFilter() const { return dynamic_cast<const Filter_MaxPool1d *>(_pFilter.get()); }
};

}

#endif
