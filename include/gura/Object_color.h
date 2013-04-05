#ifndef __GURA_OBJECT_COLOR_H__
#define __GURA_OBJECT_COLOR_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Color
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Color {
public:
	struct ElementEntry {
		const char *name;
		unsigned char red, green, blue;
	};
private:
	unsigned long _num;
public:
	static const Color Zero;
	static const ElementEntry ElementEntries[];
public:
	inline Color() : _num(0x00000000) {}
	inline Color(unsigned long num) : _num(num) {}
	inline Color(const Color &color) : _num(color._num) {}
	inline Color(unsigned char red, unsigned char green, unsigned char blue) :
		_num((static_cast<unsigned long>(red) << 16) +
			 (static_cast<unsigned long>(green) << 8) + blue) {}
	inline Color(unsigned char red, unsigned char green, unsigned char blue, unsigned alpha) :
		_num((static_cast<unsigned long>(alpha) << 24) +
			 (static_cast<unsigned long>(red) << 16) +
			 (static_cast<unsigned long>(green) << 8) + blue) {}
	inline unsigned long GetULong() const { return _num; }
	inline unsigned char GetRed() const {
		return static_cast<unsigned char>(_num >> 16);
	}
	inline unsigned char GetGreen() const {
		return static_cast<unsigned char>(_num >> 8);
	}
	inline unsigned char GetBlue() const {
		return static_cast<unsigned char>(_num >> 0);
	}
	inline unsigned char GetAlpha() const {
		return static_cast<unsigned char>(_num >> 24);
	}
	inline unsigned char GetGray() const {
		return CalcGray(GetRed(), GetGreen(), GetBlue());
	}
	inline void SetRed(unsigned char red) {
		_num = _num & ~(0xff << 16) | (static_cast<unsigned long>(red) << 16);
	}
	inline void SetGreen(unsigned char green) {
		_num = _num & ~(0xff << 8) | (static_cast<unsigned long>(green) << 8);
	}
	inline void SetBlue(unsigned char blue) {
		_num = _num & ~(0xff << 0) | (static_cast<unsigned long>(blue) << 0);
	}
	inline void SetAlpha(unsigned char alpha) {
		_num = _num & ~(0xff << 24) | (static_cast<unsigned long>(alpha) << 24);
	}
	inline bool operator<(const Color &c) const {
		return (GetULong() & 0xffffff) < (c.GetULong() & 0xffffff);
	}
	inline size_t CalcDist(unsigned char red, unsigned char green, unsigned char blue) const {
		return CalcDistRGB(GetRed(), GetGreen(), GetBlue(), red, green, blue);
	}
	inline size_t CalcDist(const Color &c) const {
		return CalcDistRGB(GetRed(), GetGreen(), GetBlue(), c.GetRed(), c.GetGreen(), c.GetBlue());
	}
	inline String GetHTML() const {
		char buff[32];
		::sprintf(buff, "#%06x", static_cast<unsigned int>(_num & 0xffffff));
		return String(buff);
	}
	static inline size_t CalcDistRGB(
				unsigned char red1, unsigned char green1, unsigned char blue1,
				unsigned char red2, unsigned char green2, unsigned char blue2) {
		long distR = static_cast<long>(red1) - static_cast<long>(red2);
		long distG = static_cast<long>(green1) - static_cast<long>(green2);
		long distB = static_cast<long>(blue1) - static_cast<long>(blue2);
		return distR * distR + distG * distG + distB * distB;
	}
	// revise this equation to convert a color into gray scale.
	static inline unsigned char CalcGray(unsigned char red, unsigned char green, unsigned char blue) {
		return static_cast<unsigned char>(
			(static_cast<unsigned long>(red) * 299 +
			 static_cast<unsigned long>(green) * 587 +
			 static_cast<unsigned long>(blue) * 114) / 1000);
	}
};

typedef std::set<Color> ColorSet;
typedef std::map<const Symbol *, Color> ColorMap;

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
					Object(env.LookupClass(VTYPE_color)),
					_color(red, green, blue, alpha) {}
	inline Object_color(Class *pClass) : Object(pClass) {}
	inline void Set(unsigned char red, unsigned char green,
									unsigned char blue, unsigned char alpha) {
		_color = Color(red, green, blue, alpha);
	}
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
