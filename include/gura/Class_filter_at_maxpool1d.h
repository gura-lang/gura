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
private:
	size_t _size;
	size_t _strides;
	PaddingType _paddingType;
	ChannelAt _channelAt;
public:
	inline Filter_MaxPool1d(size_t size, size_t strides, PaddingType paddingType, ChannelAt channelAt) :
		_size(size), _strides(strides),
		_paddingType(paddingType), _channelAt(channelAt) {}
	inline Filter_MaxPool1d(const Filter_MaxPool1d &filter) :
		_size(filter._size), _strides(filter._strides),
		_paddingType(filter._paddingType), _channelAt(filter._channelAt) {}
	inline size_t GetSize() const { return _size; }
	inline size_t GetStrides() const { return _strides; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline ChannelAt GetChannelAt() const { return _channelAt; }
public:
	virtual Array *Apply(Signal &sig, Array *pArrayResult, const Array *pArray);
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
	Object_filter_at_maxpool1d(Environment &env, const Filter_MaxPool1d &filter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_MaxPool1d &GetFilter() { return _filter; }
	inline const Filter_MaxPool1d &GetFilter() const { return _filter; }
};

}

#endif
