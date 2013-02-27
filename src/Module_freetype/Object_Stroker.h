#ifndef __FREETYPE_OBJECT_STROKER_H__
#define __FREETYPE_OBJECT_STROKER_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Stroker declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Stroker);

class Object_Stroker : public Object {
public:
	Gura_DeclareObjectAccessor(Stroker)
private:
	FT_Stroker _stroker;
public:
	inline Object_Stroker() : Object(Gura_UserClass(Stroker)) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Stroker &GetEntity() { return _stroker; }
	inline const FT_Stroker &GetEntity() const { return _stroker; }
};

}}

#endif
