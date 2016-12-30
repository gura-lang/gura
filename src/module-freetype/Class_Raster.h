#ifndef __FREETYPE_CLASS_RASTER_H__
#define __FREETYPE_CLASS_RASTER_H__

Gura_BeginModuleScope(freetype)

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
	virtual String ToString(bool exprFlag);
	inline FT_Raster &GetEntity() { return _raster; }
	inline const FT_Raster &GetEntity() const { return _raster; }
};

Gura_EndModuleScope(freetype)

#endif
