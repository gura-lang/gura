//=============================================================================
// Gura class: gear@conv3d
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_CONV3D_H__
#define __GURA_CLASS_GEAR_AT_CONV3D_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_Conv3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_Conv3d : public Gear {
public:
	typedef bool (*GearFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								  const Array *pArray, const Gear_Conv3d *pGear);
	struct GearFuncTable {
		GearFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static GearFuncTable gearFuncTable;
private:
	AutoPtr<Array> _pArrayGear;
	size_t _stridesPlane;
	size_t _stridesRow;
	size_t _stridesCol;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	Gura_DeclareReferenceAccessor(Gear_Conv3d);
public:
	inline Gear_Conv3d(Array *pArrayGear, size_t stridesPlane, size_t stridesRow, size_t stridesCol,
						 PaddingType paddingType, Array::ChannelPos channelPos) :
		Gear("gear@conv3d"), _pArrayGear(pArrayGear),
		_stridesPlane(stridesPlane), _stridesRow(stridesRow), _stridesCol(stridesCol),
		_paddingType(paddingType), _channelPos(channelPos) {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString() const;
	inline bool IsChLast() const { return _channelPos == Array::CHANNELPOS_Last; }
	inline Array *GetArrayGear() { return _pArrayGear.get(); }
	inline const Array *GetArrayGear() const { return _pArrayGear.get(); }
	inline bool HasChannelDim() const {
		return _channelPos == Array::CHANNELPOS_First || _channelPos == Array::CHANNELPOS_Last;
	}
	inline bool HasFilterDim() const {
		return _pArrayGear->GetDims().size() == (HasChannelDim()? 5 : 4);
	}
	inline size_t GetSizePlane() const {
		return _pArrayGear->GetDims().GetBack(IsChLast()? 3 : 2).GetSize();
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
	inline size_t GetStridesPlane() const { return _stridesPlane; }
	inline size_t GetStridesRow() const { return _stridesRow; }
	inline size_t GetStridesCol() const { return _stridesCol; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
};

//-------------------------------------------------------------------------
// NodeGear_Conv3d
//-------------------------------------------------------------------------
class NodeGear_Conv3d : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const;
	};
private:
	std::unique_ptr<Trainer::Optimizer::Instance> _pOptimizerInst;
	AutoPtr<Array> _pArrayFwdSrcVec;
	AutoPtr<Array> _pArrayGearReshape;
	AutoPtr<Array> _pArrayGearTrans;
	AutoPtr<Array> _pArrayFwdPre;
public:
	inline NodeGear_Conv3d(Gear_Conv3d *pGear, Connector *pConnectorDst, Trainer::Optimizer::Instance *pOptimizerInst) :
			NodeGear(pGear, pConnectorDst), _pOptimizerInst(pOptimizerInst) {}
	inline Gear_Conv3d *GetGear() { return dynamic_cast<Gear_Conv3d *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// Class_gear_at_conv3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_conv3d : public ClassFundamental {
public:
	Class_gear_at_conv3d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_conv3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_conv3d : public Object_gear {
public:
	Gura_DeclareObjectAccessor(gear_at_conv3d)
public:
	Object_gear_at_conv3d(Environment &env, Gear_Conv3d *pGear);
	virtual Object *Clone() const;
	inline Gear_Conv3d *GetGear() { return dynamic_cast<Gear_Conv3d *>(_pGear.get()); }
	inline const Gear_Conv3d *GetGear() const { return dynamic_cast<const Gear_Conv3d *>(_pGear.get()); }
};

}

#endif
