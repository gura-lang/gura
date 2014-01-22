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
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
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
	inline Object_color(Environment &env, const Color &color = Color::Black) :
			Object(env.LookupClass(VTYPE_color)), _color(color) {}
	inline Object_color(Class *pClass) : Object(pClass) {}
	inline void SetColor(const Color &color) { _color = color; }
	inline Color &GetColor() { return _color; }
	inline const Color &GetColor() const { return _color; }
	virtual ~Object_color();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
