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
	inline Gear_Sigmoid() {}
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
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
