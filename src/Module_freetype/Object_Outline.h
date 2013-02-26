#ifndef __FREETYPE_OBJECT_OUTLINE_H__
#define __FREETYPE_OBJECT_OUTLINE_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Outline declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Outline);

class Object_Outline : public Object {
public:
	Gura_DeclareObjectAccessor(Outline)
private:
	FT_Outline _outline;
public:
	inline Object_Outline(const FT_Outline &outline) :
			Object(Gura_UserClass(Outline)), _outline(outline) {}
	inline Object_Outline(const Object_Outline &obj) :
			Object(obj), _outline(obj._outline) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Outline &GetEntity() { return _outline; }
	inline const FT_Outline &GetEntity() const { return _outline; }
};

}}

#endif
