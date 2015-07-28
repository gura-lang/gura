#ifndef __SDL2_CLASS_POINT_H__
#define __SDL2_CLASS_POINT_H__

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Point declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Point);

class Object_Point : public Object {
private:
	SDL_Point _point;
public:
	Gura_DeclareObjectAccessor(Point)
public:
	inline Object_Point(const SDL_Point &point) :
						Object(Gura_UserClass(Point)), _point(point) {}
	virtual ~Object_Point();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__,
							const Symbol *pSymbol, const SymbolSet &attrs,
							bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__,
							const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline SDL_Point *GetEntity() { return &_point; }
};

Gura_EndModuleScope(sdl2)

#endif
