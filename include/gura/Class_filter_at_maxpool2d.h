//=============================================================================
// Gura class: filter@maxpool2d
//=============================================================================
#ifndef __GURA_CLASS_FILTER_AT_MAXPOOL2D_H__
#define __GURA_CLASS_FILTER_AT_MAXPOOL2D_H__

#include "Class.h"
#include "Filter.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter_MaxPool2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter_MaxPool2d : public Filter {
public:
	typedef Array *(*FilterFuncT)(Signal &sig, Array *pArrayResult,
								  const Array *pArray, const Filter_MaxPool2d &filter);
	struct FilterFuncTable {
		FilterFuncT funcs[Array::ETYPE_Max];
	};
public:
	static FilterFuncTable filterFuncTable;
private:
	size_t _sizeRow;
	size_t _sizeCol;
	size_t _stridesRow;
	size_t _stridesCol;
	PaddingType _paddingType;
	ChannelAt _channelAt;
public:
	inline Filter_MaxPool2d(size_t sizeRow, size_t sizeCol, size_t stridesRow, size_t stridesCol,
							PaddingType paddingType, ChannelAt channelAt) :
		_sizeRow(sizeRow), _sizeCol(sizeCol),
		_stridesRow(stridesRow), _stridesCol(stridesCol),
		_paddingType(paddingType), _channelAt(channelAt) {}
	inline Filter_MaxPool2d(const Filter_MaxPool2d &filter) :
		_sizeRow(filter._sizeRow), _sizeCol(filter._sizeCol),
		_stridesRow(filter._stridesRow), _stridesCol(filter._stridesCol),
		_paddingType(filter._paddingType), _channelAt(filter._channelAt) {}
	inline size_t GetSizeRow() const { return _sizeRow; }
	inline size_t GetSizeCol() const { return _sizeCol; }
	inline size_t GetStridesRow() const { return _stridesRow; }
	inline size_t GetStridesCol() const { return _stridesCol; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline ChannelAt GetChannelAt() const { return _channelAt; }
public:
	static Array *Apply(
		Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_MaxPool2d &filter);
};

//-----------------------------------------------------------------------------
// Class_filter_at_maxpool2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter_at_maxpool2d : public ClassFundamental {
public:
	Class_filter_at_maxpool2d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter_at_maxpool2d : public Object {
private:
	Filter_MaxPool2d _filter;
public:
	Gura_DeclareObjectAccessor(filter_at_maxpool2d)
public:
	Object_filter_at_maxpool2d(Environment &env, const Filter_MaxPool2d &filter);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline Filter_MaxPool2d &GetFilter() { return _filter; }
	inline const Filter_MaxPool2d &GetFilter() const { return _filter; }
};

}

#endif
