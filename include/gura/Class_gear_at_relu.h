//=============================================================================
// Gura class: gear@relu
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_RELU_H__
#define __GURA_CLASS_GEAR_AT_RELU_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_Relu
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_Relu : public Gear {
public:
	typedef bool (*GearFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Gear_Relu *pGear);
	struct GearFuncTable {
		GearFuncT funcs[Array::ETYPE_Max];
	};
public:
	static GearFuncTable gearFuncTable;
public:
	Gura_DeclareReferenceAccessor(Gear_Relu);
public:
	inline Gear_Relu() : Gear("gear@relu") {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
};

//-------------------------------------------------------------------------
// NodeGear_Relu
//-------------------------------------------------------------------------
class NodeGear_Relu : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst) const;
	};
private:
	AutoPtr<Array> _pArrayBool;
public:
	inline NodeGear_Relu(Gear_Relu *pGear, Connector *pConnectorDst) :
			NodeGear(pGear, pConnectorDst) {}
	inline Gear_Relu *GetGear() { return dynamic_cast<Gear_Relu *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// Class_gear_at_relu
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_relu : public ClassFundamental {
public:
	Class_gear_at_relu(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_relu
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_relu : public Object_gear {
public:
	static Value valueConst;
public:
	Gura_DeclareObjectAccessor(gear_at_relu)
public:
	Object_gear_at_relu(Environment &env, Gear_Relu *pGear);
	virtual Object *Clone() const;
	inline Gear_Relu *GetGear() { return dynamic_cast<Gear_Relu *>(_pGear.get()); }
	inline const Gear_Relu *GetGear() const { return dynamic_cast<const Gear_Relu *>(_pGear.get()); }
};

}

#endif
