//=============================================================================
// Gura class: gear@averagepool1d
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_AVERAGEPOOL1D_H__
#define __GURA_CLASS_GEAR_AT_AVERAGEPOOL1D_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_AveragePool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_AveragePool1d : public Gear {
private:
	size_t _size;
	size_t _strides;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	Gura_DeclareReferenceAccessor(Gear_AveragePool1d);
public:
	inline Gear_AveragePool1d(size_t size, size_t strides, PaddingType paddingType, Array::ChannelPos channelPos) :
		Gear("gear@averagepool1d"), _size(size), _strides(strides),
		_paddingType(paddingType), _channelPos(channelPos) {}
	inline size_t GetSize() const { return _size; }
	inline size_t GetStrides() const { return _strides; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString() const;
	virtual Object *ToObject(Environment &env) const;
};

//-------------------------------------------------------------------------
// NodeGear_AveragePool1d
//-------------------------------------------------------------------------
class NodeGear_AveragePool1d : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const;
	};
public:
	inline NodeGear_AveragePool1d(Gear_AveragePool1d *pGear, Connector *pConnectorDst) :
			NodeGear(pGear, pConnectorDst) {}
	inline Gear_AveragePool1d *GetGear() { return dynamic_cast<Gear_AveragePool1d *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// Class_gear_at_averagepool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_averagepool1d : public ClassFundamental {
public:
	Class_gear_at_averagepool1d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_averagepool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_averagepool1d : public Object_gear {
public:
	Gura_DeclareObjectAccessor(gear_at_averagepool1d)
public:
	Object_gear_at_averagepool1d(Environment &env, Gear_AveragePool1d *pGear);
	virtual Object *Clone() const;
	inline Gear_AveragePool1d *GetGear() { return dynamic_cast<Gear_AveragePool1d *>(_pGear.get()); }
	inline const Gear_AveragePool1d *GetGear() const { return dynamic_cast<const Gear_AveragePool1d *>(_pGear.get()); }
};

}

#endif
