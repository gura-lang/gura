//=============================================================================
// Gura class: filter
//=============================================================================
#ifndef __GURA_CLASS_FILTER_H__
#define __GURA_CLASS_FILTER_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Filter {
public:
	enum PaddingType {
		PADDINGTYPE_None,
		PADDINGTYPE_Valid,
		PADDINGTYPE_Same,
	};
protected:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Filter);
public:
	inline Filter() : _cntRef(1) {}
protected:
	virtual ~Filter();
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const = 0;
	virtual String ToString() const = 0;
public:
	static void CalcPadding(size_t sizeIn, size_t sizeKernel, size_t strides, PaddingType paddingType,
							size_t *pSizeOut, size_t *pSizePad);
	static void CalcPadding(size_t sizeIn, size_t sizeKernel, size_t strides, PaddingType paddingType,
							size_t *pSizeOut, size_t *pSizePadHead, size_t *pSizePadTail);
	static PaddingType SymbolToPaddingType(Signal &sig, const Symbol *pSymbol);
	static PaddingType SymbolToPaddingType(const Symbol *pSymbol);
	static const Symbol *PaddingTypeToSymbol(PaddingType paddingType);
	template<typename T_Filter>
	static void CalcPadding1d(const T_Filter *pFilter, const Array::Dimensions &dims,
							  size_t *pSizePad);
	template<typename T_Filter>
	static void CalcPadding2d(const T_Filter *pFilter, const Array::Dimensions &dims,
							  size_t *pSizePadRow, size_t *pSizePadCol);
	template<typename T_Filter>
	static void CalcPadding3d(const T_Filter *pFilter, const Array::Dimensions &dims,
							  size_t *pSizePadPlane, size_t *pSizePadRow, size_t *pSizePadCol);
};

template<typename T_Filter>
void Filter::CalcPadding1d(const T_Filter *pFilter, const Array::Dimensions &dims,
						  size_t *pSizePad)
{
	size_t sizeOut = 0;
	bool chLastFlag = (pFilter->GetChannelAt() == Array::CHANNELAT_Last);
	CalcPadding(dims.GetBack(chLastFlag? 1 : 0).GetSize(),
				pFilter->GetSize(), pFilter->GetStrides(), pFilter->GetPaddingType(),
				&sizeOut, pSizePad);
}

template<typename T_Filter>
void Filter::CalcPadding2d(const T_Filter *pFilter, const Array::Dimensions &dims,
						   size_t *pSizePadRow, size_t *pSizePadCol)
{
	size_t sizeOutRow = 0;
	size_t sizeOutCol = 0;
	bool chLastFlag = (pFilter->GetChannelAt() == Array::CHANNELAT_Last);
	CalcPadding(dims.GetBack(chLastFlag? 2 : 1).GetSize(),
				pFilter->GetSizeRow(), pFilter->GetStridesRow(), pFilter->GetPaddingType(),
				&sizeOutRow, pSizePadRow);
	CalcPadding(dims.GetBack(chLastFlag? 1 : 0).GetSize(),
				pFilter->GetSizeCol(), pFilter->GetStridesCol(), pFilter->GetPaddingType(),
				&sizeOutCol, pSizePadCol);
}

template<typename T_Filter>
void Filter::CalcPadding3d(const T_Filter *pFilter, const Array::Dimensions &dims,
						   size_t *pSizePadPlane, size_t *pSizePadRow, size_t *pSizePadCol)
{
	size_t sizeOutPlane = 0;
	size_t sizeOutRow = 0;
	size_t sizeOutCol = 0;
	bool chLastFlag = (pFilter->GetChannelAt() == Array::CHANNELAT_Last);
	CalcPadding(dims.GetBack(chLastFlag? 3 : 2).GetSize(),
				pFilter->GetSizePlane(), pFilter->GetStridesPlane(), pFilter->GetPaddingType(),
				&sizeOutPlane, pSizePadPlane);
	CalcPadding(dims.GetBack(chLastFlag? 2 : 1).GetSize(),
				pFilter->GetSizeRow(), pFilter->GetStridesRow(), pFilter->GetPaddingType(),
				&sizeOutRow, pSizePadRow);
	CalcPadding(dims.GetBack(chLastFlag? 1 : 0).GetSize(),
				pFilter->GetSizeCol(), pFilter->GetStridesCol(), pFilter->GetPaddingType(),
				&sizeOutCol, pSizePadCol);
}

//-----------------------------------------------------------------------------
// Class_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_filter : public ClassFundamental {
public:
	Class_filter(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_filter
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_filter : public Object {
protected:
	AutoPtr<Filter> _pFilter;
public:
	Gura_DeclareObjectAccessor(filter)
public:
	Object_filter(Environment &env, Filter *pFilter);
	Object_filter(Class *pClass, Filter *pFilter);
	virtual String ToString(bool exprFlag);
	inline Filter *GetFilter() { return _pFilter.get(); }
	inline const Filter *GetFilter() const { return _pFilter.get(); }
};

}

#endif
