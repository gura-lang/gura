#ifndef __FREETYPE_OBJECT_SPAN_H__
#define __FREETYPE_OBJECT_SPAN_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Span declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Span);

class Object_Span : public Object {
public:
	Gura_DeclareObjectAccessor(Span)
private:
	FT_Span _span;
public:
	inline Object_Span(const FT_Span &span) :
			Object(Gura_UserClass(Span)), _span(span) {}
	inline Object_Span(const Object_Span &obj) :
			Object(obj), _span(obj._span) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Span &GetEntity() { return _span; }
	inline const FT_Span &GetEntity() const { return _span; }
};

}}

#endif
