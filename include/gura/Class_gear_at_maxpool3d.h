//=============================================================================
// Gura class: gear@maxpool3d
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_MAXPOOL3D_H__
#define __GURA_CLASS_GEAR_AT_MAXPOOL3D_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_MaxPool3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_MaxPool3d : public Gear {
private:
	size_t _sizePlane;
	size_t _sizeRow;
	size_t _sizeCol;
	size_t _stridesPlane;
	size_t _stridesRow;
	size_t _stridesCol;
	PaddingType _paddingType;
	Array::ChannelPos _channelPos;
public:
	Gura_DeclareReferenceAccessor(Gear_MaxPool3d);
public:
	inline Gear_MaxPool3d(size_t sizePlane, size_t sizeRow, size_t sizeCol,
							size_t stridesPlane, size_t stridesRow, size_t stridesCol,
							PaddingType paddingType, Array::ChannelPos channelPos) :
		Gear("gear@maxpool3d"), _sizePlane(sizePlane), _sizeRow(sizeRow), _sizeCol(sizeCol),
		_stridesPlane(stridesPlane), _stridesRow(stridesRow), _stridesCol(stridesCol),
		_paddingType(paddingType), _channelPos(channelPos) {}
	inline size_t GetSizePlane() const { return _sizePlane; }
	inline size_t GetSizeRow() const { return _sizeRow; }
	inline size_t GetSizeCol() const { return _sizeCol; }
	inline size_t GetStridesPlane() const { return _stridesPlane; }
	inline size_t GetStridesRow() const { return _stridesRow; }
	inline size_t GetStridesCol() const { return _stridesCol; }
	inline PaddingType GetPaddingType() const { return _paddingType; }
	inline Array::ChannelPos GetChannelPos() const { return _channelPos; }
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
};

//-------------------------------------------------------------------------
// NodeGear_MaxPool3d
//-------------------------------------------------------------------------
class NodeGear_MaxPool3d : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const;
	};
public:
	inline NodeGear_MaxPool3d(Gear_MaxPool3d *pGear, Connector *pConnectorDst) :
			NodeGear(pGear, pConnectorDst) {}
	inline Gear_MaxPool3d *GetGear() { return dynamic_cast<Gear_MaxPool3d *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// Class_gear_at_maxpool3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_maxpool3d : public ClassFundamental {
public:
	Class_gear_at_maxpool3d(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_maxpool3d
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_maxpool3d : public Object_gear {
public:
	Gura_DeclareObjectAccessor(gear_at_maxpool3d)
public:
	Object_gear_at_maxpool3d(Environment &env, Gear_MaxPool3d *pGear);
	virtual Object *Clone() const;
	inline Gear_MaxPool3d *GetGear() { return dynamic_cast<Gear_MaxPool3d *>(_pGear.get()); }
	inline const Gear_MaxPool3d *GetGear() const { return dynamic_cast<const Gear_MaxPool3d *>(_pGear.get()); }
};

}

#endif
