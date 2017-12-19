//=============================================================================
// Gura class: gear@tanh
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_TANH_H__
#define __GURA_CLASS_GEAR_AT_TANH_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_Tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_Tanh : public Gear {
public:
	typedef bool (*GearFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Gear_Tanh *pGear);
	struct GearFuncTable {
		GearFuncT funcs[Array::ETYPE_Max];
	};
public:
	static GearFuncTable gearFuncTable;
public:
	Gura_DeclareReferenceAccessor(Gear_Tanh);
public:
	inline Gear_Tanh() {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
};

//-------------------------------------------------------------------------
// NodeGear_Tanh
//-------------------------------------------------------------------------
class NodeGear_Tanh : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
	};
public:
	inline NodeGear_Tanh(Gear_Tanh *pGear, Connector *pConnectorDst) :
			NodeGear("gear_tanh", pGear, pConnectorDst) {}
	inline Gear_Tanh *GetGear() { return dynamic_cast<Gear_Tanh *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
};

//-----------------------------------------------------------------------------
// Class_gear_at_tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_tanh : public ClassFundamental {
public:
	Class_gear_at_tanh(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_tanh
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_tanh : public Object_gear {
public:
	static Value valueConst;
public:
	Gura_DeclareObjectAccessor(gear_at_tanh)
public:
	Object_gear_at_tanh(Environment &env, Gear_Tanh *pGear);
	virtual Object *Clone() const;
	inline Gear_Tanh *GetGear() { return dynamic_cast<Gear_Tanh *>(_pGear.get()); }
	inline const Gear_Tanh *GetGear() const { return dynamic_cast<const Gear_Tanh *>(_pGear.get()); }
};

}

#endif
