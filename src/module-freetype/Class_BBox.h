#ifndef __FREETYPE_CLASS_BBOX_H__
#define __FREETYPE_CLASS_BBOX_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_BBox declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(BBox);

class Object_BBox : public Object {
public:
	Gura_DeclareObjectAccessor(BBox)
private:
	FT_BBox _bbox;
public:
	inline Object_BBox(const FT_BBox &bbox) :
			Object(Gura_UserClass(BBox)), _bbox(bbox) {}
	inline Object_BBox(const Object_BBox &obj) :
			Object(obj), _bbox(obj._bbox) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_BBox &GetEntity() { return _bbox; }
	inline const FT_BBox &GetEntity() const { return _bbox; }
};

Gura_EndModuleScope(freetype)

#endif
