#ifndef __FREETYPE_CLASS_GLYPHSLOT_H__
#define __FREETYPE_CLASS_GLYPHSLOT_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_GlyphSlot declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(GlyphSlot);

class Object_GlyphSlot : public Object {
public:
	Gura_DeclareObjectAccessor(GlyphSlot)
private:
	AutoPtr<Object> _pObjHolder;
	FT_GlyphSlot _glyphSlot;
public:
	inline Object_GlyphSlot(Object *pObjHolder, FT_GlyphSlot glyphSlot) :
			Object(Gura_UserClass(GlyphSlot)), _pObjHolder(pObjHolder), _glyphSlot(glyphSlot) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_GlyphSlot &GetEntity() { return _glyphSlot; }
	inline const FT_GlyphSlot &GetEntity() const { return _glyphSlot; }
};

Gura_EndModuleScope(freetype)

#endif
