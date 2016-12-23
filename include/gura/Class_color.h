//=============================================================================
// Gura class: color
//=============================================================================
#ifndef __GURA_CLASS_COLOR_H__
#define __GURA_CLASS_COLOR_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_color
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_color : public Class {
public:
	Class_color(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_color
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_color : public Object {
public:
	Gura_DeclareObjectAccessor(color)
private:
	Color _color;
public:
	inline Object_color(const Object_color &obj) : Object(obj), _color(obj._color) {}
	inline Object_color(Environment &env, UChar r, UChar g, UChar b, UChar a) :
			Object(env.LookupClass(VTYPE_color)), _color(r, g, b, a) {}
	inline Object_color(Environment &env, const Color &color = Color::black) :
			Object(env.LookupClass(VTYPE_color)), _color(color) {}
	inline Object_color(Class *pClass) : Object(pClass) {}
	inline void SetColor(const Color &color) { _color = color; }
	inline Color &GetColor() { return _color; }
	inline const Color &GetColor() const { return _color; }
	virtual ~Object_color();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
};

}

#endif
