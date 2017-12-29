//=============================================================================
// Gura class: gear@sigmoid
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_SIGMOID_H__
#define __GURA_CLASS_GEAR_AT_SIGMOID_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_Sigmoid
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_Sigmoid : public Gear {
public:
	typedef bool (*GearFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Gear_Sigmoid *pGear);
	struct GearFuncTable {
		GearFuncT funcs[Array::ETYPE_Max];
	};
public:
	static GearFuncTable gearFuncTable;
public:
	Gura_DeclareReferenceAccessor(Gear_Sigmoid);
public:
	inline Gear_Sigmoid() : Gear("gear@sigmoid") {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString() const;
	virtual Object *ToObject(Environment &env) const;
};

//-------------------------------------------------------------------------
// NodeGear_Sigmoid
//-------------------------------------------------------------------------
class NodeGear_Sigmoid : public Trainer::NodeGear {
public:
	class CreatorEx : public Creator {
	public:
		virtual NodeGear *Create(const Value &value, Connector *pConnectorDst, const Trainer *pTrainer) const;
	};
private:
	AutoPtr<Array> _pArrayTmp;
public:
	inline NodeGear_Sigmoid(Gear_Sigmoid *pGear, Connector *pConnectorDst) :
			NodeGear(pGear, pConnectorDst) {}
	inline Gear_Sigmoid *GetGear() { return dynamic_cast<Gear_Sigmoid *>(_pGear.get()); }
	virtual bool IsVulnerable() const;
	virtual bool EvalForward(Environment &env);
	virtual bool EvalBackward(Environment &env);
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// Class_gear_at_sigmoid
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_sigmoid : public ClassFundamental {
public:
	Class_gear_at_sigmoid(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_sigmoid
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_sigmoid : public Object_gear {
public:
	static Value valueConst;
public:
	Gura_DeclareObjectAccessor(gear_at_sigmoid)
public:
	Object_gear_at_sigmoid(Environment &env, Gear_Sigmoid *pGear);
	virtual Object *Clone() const;
	inline Gear_Sigmoid *GetGear() { return dynamic_cast<Gear_Sigmoid *>(_pGear.get()); }
	inline const Gear_Sigmoid *GetGear() const { return dynamic_cast<const Gear_Sigmoid *>(_pGear.get()); }
};

}

#endif
