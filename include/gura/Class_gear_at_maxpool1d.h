//=============================================================================
// Gura class: gear@maxpool1d
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_MAXPOOL1D_H__
#define __GURA_CLASS_GEAR_AT_MAXPOOL1D_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_MaxPool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_MaxPool1d : public Gear {
private:
	size_t _size;
	size_t _strides;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	Gura_DeclareReferenceAccessor(Gear_MaxPool1d);
public:
	inline Gear_MaxPool1d(size_t size, size_t strides, PaddingType paddingType, Array::ChannelPos channelPos) :
		Gear("gear@maxpool1d"), _size(size), _strides(strides),
		_paddingType(paddingType), _channelPos(channelPos) {}
	inline size_t GetSize() const { return _size; }
	inline size_t GetStrides() const { return _strides; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
};

//-------------------------------------------------------------------------
// NodeGear_MaxPool1d
//-------------------------------------------------------------------------
class NodeGear_MaxPool1d : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const;
	};
public:
	inline NodeGear_MaxPool1d(Gear_MaxPool1d *pGear, Connector *pConnectorDst) :
			NodeGear(pGear, pConnectorDst) {}
	inline Gear_MaxPool1d *GetGear() { return dynamic_cast<Gear_MaxPool1d *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// Class_gear_at_maxpool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_maxpool1d : public ClassFundamental {
public:
	Class_gear_at_maxpool1d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_maxpool1d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_maxpool1d : public Object_gear {
public:
	Gura_DeclareObjectAccessor(gear_at_maxpool1d)
public:
	Object_gear_at_maxpool1d(Environment &env, Gear_MaxPool1d *pGear);
	virtual Object *Clone() const;
	inline Gear_MaxPool1d *GetGear() { return dynamic_cast<Gear_MaxPool1d *>(_pGear.get()); }
	inline const Gear_MaxPool1d *GetGear() const { return dynamic_cast<const Gear_MaxPool1d *>(_pGear.get()); }
};

}

#endif
