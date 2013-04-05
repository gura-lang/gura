#ifndef __GURA_OBJECT_COLOR_H__
#define __GURA_OBJECT_COLOR_H__

#include "Object.h"

namespace Gura {

typedef std::map<const Symbol *, Color>	ColorMap;

//-----------------------------------------------------------------------------
// Class_color
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_color : public Class {
public:
	Class_color(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_color
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_color : public Object {
public:
public:
	Gura_DeclareObjectAccessor(color)
private:
	Color _color;
	static ColorMap *_pColorMap;
public:
	inline Object_color(const Object_color &obj) : Object(obj),
					_color(obj._color) {}
	inline Object_color(Environment &env, unsigned char red, unsigned char green,
									unsigned char blue, unsigned char alpha) :
			Object(env.LookupClass(VTYPE_color)), _color(red, green, blue, alpha) {}
	inline Object_color(Environment &env, const Color &color) :
			Object(env.LookupClass(VTYPE_color)), _color(color) {}
	inline Object_color(Class *pClass) : Object(pClass) {}
	inline void SetColor(Color &color) { _color = color; }
	inline Color &GetColor() { return _color; }
	inline const Color &GetColor() const { return _color; }
	inline unsigned char GetRed() const { return _color.GetRed(); }
	inline unsigned char GetGreen() const { return _color.GetGreen(); }
	inline unsigned char GetBlue() const { return _color.GetBlue(); }
	inline unsigned char GetAlpha() const { return _color.GetAlpha(); }
	inline void SetRed(unsigned char red) { _color.SetRed(red); }
	inline void SetGreen(unsigned char green) { _color.SetGreen(green); }
	inline void SetBlue(unsigned char blue) { _color.SetBlue(blue); }
	inline void SetAlpha(unsigned char alpha) { _color.SetAlpha(alpha); }
	virtual ~Object_color();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	String GetHTML() const;
	inline size_t CalcDist(unsigned char red, unsigned char green, unsigned char blue) const {
		return _color.CalcDist(red, green, blue);
	}
	inline size_t CalcDist(const Object_color *pObjColor) const {
		return _color.CalcDist(pObjColor->GetRed(), pObjColor->GetGreen(), pObjColor->GetBlue());
	}
	static Object_color *CreateNamedColor(Environment &env,
						Signal sig, const char *name, unsigned char alpha);
};

}

#endif
