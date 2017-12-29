//=============================================================================
// Gura class: gear@conv2d
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_CONV2D_H__
#define __GURA_CLASS_GEAR_AT_CONV2D_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_Conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_Conv2d : public Gear {
public:
	typedef bool (*GearFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Gear_Conv2d *pGear);
	struct GearFuncTable {
		GearFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static GearFuncTable gearFuncTable;
private:
	AutoPtr<Array> _pArrayGear;
	size_t _stridesRow;
	size_t _stridesCol;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	Gura_DeclareReferenceAccessor(Gear_Conv2d);
public:
	inline Gear_Conv2d(Array *pArrayGear, size_t stridesRow, size_t stridesCol,
						 PaddingType paddingType, Array::ChannelPos channelPos) :
		Gear("gear@conv2d"), _pArrayGear(pArrayGear),
		_stridesRow(stridesRow), _stridesCol(stridesCol),
		_paddingType(paddingType), _channelPos(channelPos) {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString() const;
	virtual Object *ToObject(Environment &env) const;
	inline bool IsChLast() const { return _channelPos == Array::CHANNELPOS_Last; }
	inline Array *GetArrayGear() { return _pArrayGear.get(); }
	inline const Array *GetArrayGear() const { return _pArrayGear.get(); }
	inline AutoPtr<Array> &GetArrayGearAutoPtr() { return _pArrayGear; }
	inline bool HasChannelDim() const {
		return _channelPos == Array::CHANNELPOS_First || _channelPos == Array::CHANNELPOS_Last;
	}
	inline bool HasFilterDim() const {
		return _pArrayGear->GetDims().size() == (HasChannelDim()? 4 : 3);
	}
	inline size_t GetSizeRow() const {
		return _pArrayGear->GetDims().GetBack(IsChLast()? 2 : 1).GetSize();
	}
	inline size_t GetSizeCol() const {
		return _pArrayGear->GetDims().GetBack(IsChLast()? 1 : 0).GetSize();
	}
	inline size_t GetChannelNum() const {
		return HasChannelDim()? _pArrayGear->GetDims().GetBack(IsChLast()? 0 : 2).GetSize() : 1;
	}
	inline size_t GetFilterNum() const {
		return HasFilterDim()? _pArrayGear->GetDims().GetBack(HasChannelDim()? 3 : 2).GetSize() : 1;
	}
	inline size_t GetStridesRow() const { return _stridesRow; }
	inline size_t GetStridesCol() const { return _stridesCol; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
};

//-------------------------------------------------------------------------
// NodeGear_Conv2d
//-------------------------------------------------------------------------
class NodeGear_Conv2d : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const;
	};
private:
	std::unique_ptr<Trainer::Optimizer::Instance> _pOptimizerInst;
	AutoPtr<Array> _pArrayFwdSrcVec;		// EvalForward
	AutoPtr<Array> _pArrayGearReshape;		// EvalForward
	AutoPtr<Array> _pArrayGearTrans;		// EvalForward
	AutoPtr<Array> _pArrayFwdPre;			// EvalForward
	AutoPtr<Array> _pArrayBwdSrcReshape;	// EvalBackward
	AutoPtr<Array> _pArrayBwdSrcTrans;		// EvalBackward
	AutoPtr<Array> _pArrayFwdSrcVecReshape;	// EvalBackward
	AutoPtr<Array> _pArrayGearDiff;			// EvalBackward
	AutoPtr<Array> _pArrayGearDiffPre;		// EvalBackward
	AutoPtr<Array> _pArrayFwdSrcVecDiff;	// EvalBackward
	AutoPtr<Array> _pArrayFwdSrcVecDiffPre;	// EvalBackward
	size_t _sizeRow;
	size_t _sizeCol;
	size_t _sizePadRow;
	size_t _sizePadCol;
	size_t _sizeOutRow;
	size_t _sizeOutCol;
public:
	inline NodeGear_Conv2d(Gear_Conv2d *pGear, Connector *pConnectorDst, Trainer::Optimizer::Instance *pOptimizerInst) :
		NodeGear(pGear, pConnectorDst), _pOptimizerInst(pOptimizerInst),
		_sizeRow(0), _sizeCol(0), _sizePadRow(0), _sizePadCol(0), _sizeOutRow(0), _sizeOutCol(0) {}
	inline Gear_Conv2d *GetGear() { return dynamic_cast<Gear_Conv2d *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// Class_gear_at_conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_conv2d : public ClassFundamental {
public:
	Class_gear_at_conv2d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_conv2d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_conv2d : public Object_gear {
public:
	Gura_DeclareObjectAccessor(gear_at_conv2d)
public:
	Object_gear_at_conv2d(Environment &env, Gear_Conv2d *pGear);
	virtual Object *Clone() const;
	inline Gear_Conv2d *GetGear() { return dynamic_cast<Gear_Conv2d *>(_pGear.get()); }
	inline const Gear_Conv2d *GetGear() const { return dynamic_cast<const Gear_Conv2d *>(_pGear.get()); }
};

}

#endif
