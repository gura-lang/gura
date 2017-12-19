//=============================================================================
// Gura class: gear@conv1d
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_CONV1D_H__
#define __GURA_CLASS_GEAR_AT_CONV1D_H__

#include "Class_gear.h"
#include "Trainer.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_Conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_Conv1d : public Gear {
public:
	typedef bool (*GearFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Gear_Conv1d *pGear);
	struct GearFuncTable {
		GearFuncT funcs[Array::ETYPE_Max][Array::ETYPE_Max];
	};
public:
	static GearFuncTable gearFuncTable;
private:
	AutoPtr<Array> _pArrayGear;
	size_t _strides;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	Gura_DeclareReferenceAccessor(Gear_Conv1d);
public:
	inline Gear_Conv1d(Array *pArrayGear, size_t strides, PaddingType paddingType, Array::ChannelPos channelPos) :
		Gear("gear@conv1d"), _pArrayGear(pArrayGear), _strides(strides),
		_paddingType(paddingType), _channelPos(channelPos) {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
	inline bool IsChLast() const { return _channelPos == Array::CHANNELPOS_Last; }
	inline Array *GetArrayGear() { return _pArrayGear.get(); }
	inline const Array *GetArrayGear() const { return _pArrayGear.get(); }
	inline bool HasChannelDim() const {
		return _channelPos == Array::CHANNELPOS_First || _channelPos == Array::CHANNELPOS_Last;
	}
	inline bool HasFilterDim() const {
		return _pArrayGear->GetDimensions().size() == (HasChannelDim()? 3 : 2);
	}
	inline size_t GetSize() const {
		return _pArrayGear->GetDimensions().GetBack(IsChLast()? 1 : 0).GetSize();
	}
	inline size_t GetChannelNum() const {
		return HasChannelDim()? _pArrayGear->GetDimensions().GetBack(IsChLast()? 0 : 1).GetSize() : 1;
	}
	inline size_t GetFilterNum() const {
		return HasFilterDim()? _pArrayGear->GetDimensions().GetBack(HasChannelDim()? 2 : 1).GetSize() : 1;
	}
	inline size_t GetStrides() const { return _strides; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
};

//-------------------------------------------------------------------------
// NodeGear_Conv1d
//-------------------------------------------------------------------------
class NodeGear_Conv1d : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
	};
private:
	AutoPtr<Array> _pArrayFwdSrcVec;
	AutoPtr<Array> _pArrayGearReshape;
	AutoPtr<Array> _pArrayGearTrans;
	AutoPtr<Array> _pArrayFwdPre;
public:
	inline NodeGear_Conv1d(Gear_Conv1d *pGear, Connector *pConnectorDst) :
		NodeGear(pGear, pConnectorDst) {}
	inline Gear_Conv1d *GetGear() { return dynamic_cast<Gear_Conv1d *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// Class_gear_at_conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_conv1d : public ClassFundamental {
public:
	Class_gear_at_conv1d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_conv1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_conv1d : public Object_gear {
public:
	Gura_DeclareObjectAccessor(gear_at_conv1d)
public:
	Object_gear_at_conv1d(Environment &env, Gear_Conv1d *pGear);
	virtual Object *Clone() const;
	inline Gear_Conv1d *GetGear() { return dynamic_cast<Gear_Conv1d *>(_pGear.get()); }
	inline const Gear_Conv1d *GetGear() const { return dynamic_cast<const Gear_Conv1d *>(_pGear.get()); }
};

}

#endif
