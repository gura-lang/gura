#ifndef __FREETYPE_OBJECT_RASTER_H__
#define __FREETYPE_OBJECT_RASTER_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_Raster declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(Raster);

class Object_Raster : public Object {
public:
	Gura_DeclareObjectAccessor(Raster)
private:
	FT_Raster _raster;
public:
	inline Object_Raster(const FT_Raster &raster) :
			Object(Gura_UserClass(Raster)), _raster(raster) {}
	inline Object_Raster(const Object_Raster &obj) :
			Object(obj), _raster(obj._raster) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FT_Raster &GetEntity() { return _raster; }
	inline const FT_Raster &GetEntity() const { return _raster; }
};

}}

#endif
