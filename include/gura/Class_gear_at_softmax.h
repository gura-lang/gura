//=============================================================================
// Gura class: gear@softmax
//=============================================================================
#ifndef __GURA_CLASS_GEAR_AT_SOFTMAX_H__
#define __GURA_CLASS_GEAR_AT_SOFTMAX_H__

#include "Class_gear.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Gear_Softmax
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Gear_Softmax : public Gear {
public:
	typedef bool (*GearFuncT)(Signal &sig, AutoPtr<Array> &pArrayRtn,
								const Array *pArray, const Gear_Softmax *pGear);
	struct GearFuncTable {
		GearFuncT funcs[Array::ETYPE_Max];
	};
public:
	static GearFuncTable gearFuncTable;
private:
	size_t _axis;
public:
	inline Gear_Softmax(size_t axis = static_cast<size_t>(-1)) : _axis(axis) {}
	inline size_t GetAxis() const { return _axis; }
public:
	virtual bool Apply(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray) const;
	virtual String ToString() const;
};

//-----------------------------------------------------------------------------
// Class_gear_at_softmax
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_gear_at_softmax : public ClassFundamental {
public:
	Class_gear_at_softmax(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_gear_at_softmax
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_gear_at_softmax : public Object_gear {
public:
	Gura_DeclareObjectAccessor(gear_at_softmax)
public:
	Object_gear_at_softmax(Environment &env, Gear_Softmax *pGear);
	virtual Object *Clone() const;
	inline Gear_Softmax *GetGear() { return dynamic_cast<Gear_Softmax *>(_pGear.get()); }
	inline const Gear_Softmax *GetGear() const { return dynamic_cast<const Gear_Softmax *>(_pGear.get()); }
};

}

#endif
