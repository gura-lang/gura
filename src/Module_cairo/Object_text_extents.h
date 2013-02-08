#ifndef __CAIRO_OBJECT_TEXT_EXTENTS_H__
#define __CAIRO_OBJECT_TEXT_EXTENTS_H__

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_text_extents declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(text_extents);

class Object_text_extents : public Object {
private:
	cairo_text_extents_t _text_extents;
public:
	Gura_DeclareObjectAccessor(text_extents)
public:
	inline Object_text_extents(const cairo_text_extents_t &text_extents) :
			Object(Gura_UserClass(text_extents)), _text_extents(text_extents) {}
	virtual ~Object_text_extents();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline cairo_text_extents_t &GetEntity() { return _text_extents; }
};

}}

#endif
