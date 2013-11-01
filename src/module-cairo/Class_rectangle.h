#ifndef __CAIRO_CLASS_RECTANGLE_H__
#define __CAIRO_CLASS_RECTANGLE_H__

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(rectangle);

class Object_rectangle : public Object {
private:
	cairo_rectangle_t _rectangle;
public:
	Gura_DeclareObjectAccessor(rectangle)
public:
	inline Object_rectangle(const cairo_rectangle_t &rectangle) :
					Object(Gura_UserClass(rectangle)), _rectangle(rectangle) {}
	virtual ~Object_rectangle();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline cairo_rectangle_t &GetEntity() { return _rectangle; }
};

Gura_EndModuleScope(cairo)

#endif
