#ifndef __FREETYPE_CLASS_FTC_SBITCACHE_H__
#define __FREETYPE_CLASS_FTC_SBITCACHE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_SBitCache declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_SBitCache);

class Object_FTC_SBitCache : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_SBitCache)
private:
	FTC_SBitCache _sbitCache;
public:
	inline Object_FTC_SBitCache(const FTC_SBitCache &sbitCache) :
			Object(Gura_UserClass(FTC_SBitCache)), _sbitCache(sbitCache) {}
	inline Object_FTC_SBitCache(const Object_FTC_SBitCache &obj) :
			Object(obj), _sbitCache(obj._sbitCache) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FTC_SBitCache &GetEntity() { return _sbitCache; }
	inline const FTC_SBitCache &GetEntity() const { return _sbitCache; }
};

Gura_EndModuleScope(freetype)

#endif
