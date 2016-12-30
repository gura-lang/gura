#ifndef __FREETYPE_CLASS_FTC_IMAGECACHE_H__
#define __FREETYPE_CLASS_FTC_IMAGECACHE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_ImageCache declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_ImageCache);

class Object_FTC_ImageCache : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_ImageCache)
private:
	FTC_ImageCache _imageCache;
public:
	inline Object_FTC_ImageCache(const FTC_ImageCache &imageCache) :
			Object(Gura_UserClass(FTC_ImageCache)), _imageCache(imageCache) {}
	inline Object_FTC_ImageCache(const Object_FTC_ImageCache &obj) :
			Object(obj), _imageCache(obj._imageCache) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FTC_ImageCache &GetEntity() { return _imageCache; }
	inline const FTC_ImageCache &GetEntity() const { return _imageCache; }
};

Gura_EndModuleScope(freetype)

#endif
