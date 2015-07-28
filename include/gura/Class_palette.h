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
class GURA_DLLDECLARE Class_palette : public Class {
public:
	Class_palette(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal &__to_delete__, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal &__to_delete__, Class *pClass);
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
	virtual Value IndexGet(Environment &env, Signal &__to_delete__, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal &__to_delete__, const Value &valueIdx, const Value &value);
	inline Palette *GetPalette() { return _pPalette.get(); }
	inline const Palette *GetPalette() const { return _pPalette.get(); }
};

}

#endif
