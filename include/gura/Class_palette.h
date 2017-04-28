//=============================================================================
// Gura class: palette
//=============================================================================
#ifndef __GURA_CLASS_PALETTE_H__
#define __GURA_CLASS_PALETTE_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_palette
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_palette : public ClassFundamental {
public:
	Class_palette(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_palette
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_palette : public Object {
public:
	Gura_DeclareObjectAccessor(palette)
private:
	AutoPtr<Palette> _pPalette;
public:
	inline Object_palette(Class *pClass, Palette *pPalette) :
				Object(pClass), _pPalette(pPalette) {}
	inline Object_palette(Environment &env, Palette *pPalette) :
				Object(env.LookupClass(VTYPE_palette)), _pPalette(pPalette) {}
	Object_palette(const Object_palette &obj);
	virtual ~Object_palette();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual Iterator *CreateIterator(Signal &sig);
#if NEW_INDEXING
	virtual Value IndexGet(Environment &env, const ValueList &valListIdx);
	virtual void IndexSet(Environment &env, const ValueList &valListIdx, const Value &value);
#else
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
#endif
	inline Palette *GetPalette() { return _pPalette.get(); }
	inline const Palette *GetPalette() const { return _pPalette.get(); }
};

}

#endif
