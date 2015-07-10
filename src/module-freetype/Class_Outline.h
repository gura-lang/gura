#ifndef __FREETYPE_CLASS_OUTLINE_H__
#define __FREETYPE_CLASS_OUTLINE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_Outline declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Outline);

class Object_Outline : public Object {
public:
	Gura_DeclareObjectAccessor(Outline)
private:
	AutoPtr<Object> _pObjHolder;
	FT_Outline *_outline;
public:
	inline Object_Outline(Object *pObjHolder, FT_Outline *outline) :
			Object(Gura_UserClass(Outline)), _pObjHolder(pObjHolder), _outline(outline) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Outline *GetEntity() { return _outline; }
	inline const FT_Outline *GetEntity() const { return _outline; }
};

Gura_EndModuleScope(freetype)

#endif
