//=============================================================================
// Gura class: color
//=============================================================================
#ifndef __GURA_CLASS_COLOR_H__
#define __GURA_CLASS_COLOR_H__

#include "Class.h"

namespace Gura {

typedef std::map<const Symbol *, Color>	ColorMap;

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
	struct ElementEntry {
		const char *name;
		UChar r, g, b;
	};
public:
	static const ElementEntry ElementEntries[];
public:
	Gura_DeclareObjectAccessor(color)
private:
	Color _color;
	static ColorMap *_pColorMap;
public:
	inline Object_color(const Object_color &obj) : Object(obj),
					_color(obj._color) {}
	inline Object_color(Environment &env, UChar r, UChar g, UChar b, UChar a) :
			Object(env.LookupClass(VTYPE_color)), _color(r, g, b, a) {}
	inline Object_color(Environment &env, const Color &color = Color::Black) :
			Object(env.LookupClass(VTYPE_color)), _color(color) {}
	inline Object_color(Class *pClass) : Object(pClass) {}
	inline void SetColor(const Color &color) { _color = color; }
	inline Color &GetColor() { return _color; }
	inline const Color &GetColor() const { return _color; }
	inline UChar GetR() const { return _color.GetR(); }
	inline UChar GetG() const { return _color.GetG(); }
	inline UChar GetB() const { return _color.GetB(); }
	inline UChar GetA() const { return _color.GetA(); }
	inline void SetR(UChar r) { _color.SetR(r); }
	inline void SetG(UChar g) { _color.SetG(g); }
	inline void SetB(UChar b) { _color.SetB(b); }
	inline void SetA(UChar a) { _color.SetA(a); }
	virtual ~Object_color();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	String GetHTML() const;
	inline size_t CalcDistSqu(UChar r, UChar g, UChar b) const {
		return _color.CalcDistSqu(r, g, b);
	}
	inline size_t CalcDistSqu(const Object_color *pObjColor) const {
		return _color.CalcDistSqu(pObjColor->GetR(), pObjColor->GetG(), pObjColor->GetB());
	}
	static Object_color *CreateNamedColor(Environment &env,
								Signal sig, const char *name, UChar a);
};

}

#endif
