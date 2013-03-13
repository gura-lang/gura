#ifndef __FREETYPE_OBJECT_GLYPHSLOT_H__
#define __FREETYPE_OBJECT_GLYPHSLOT_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_GlyphSlot declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(GlyphSlot);

class Object_GlyphSlot : public Object {
public:
	Gura_DeclareObjectAccessor(GlyphSlot)
private:
	FT_GlyphSlot _glyphSlot;
public:
	inline Object_GlyphSlot(const FT_GlyphSlot &glyphSlot) :
			Object(Gura_UserClass(GlyphSlot)), _glyphSlot(glyphSlot) {}
	inline Object_GlyphSlot(const Object_GlyphSlot &obj) :
			Object(obj), _glyphSlot(obj._glyphSlot) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_GlyphSlot &GetEntity() { return _glyphSlot; }
	inline const FT_GlyphSlot &GetEntity() const { return _glyphSlot; }
};

}}

#endif
