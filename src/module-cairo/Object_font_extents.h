#ifndef __CAIRO_OBJECT_FONT_EXTENTS_H__
#define __CAIRO_OBJECT_FONT_EXTENTS_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_font_extents declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(font_extents);

class Object_font_extents : public Object {
private:
	cairo_font_extents_t _font_extents;
public:
	Gura_DeclareObjectAccessor(font_extents)
public:
	inline Object_font_extents(const cairo_font_extents_t &font_extents) :
			Object(Gura_UserClass(font_extents)), _font_extents(font_extents) {}
	virtual ~Object_font_extents();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_font_extents_t &GetEntity() { return _font_extents; }
};

}}

#endif
