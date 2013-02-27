#ifndef __FREETYPE_OBJECT_FTC_SBITCACHE_H__
#define __FREETYPE_OBJECT_FTC_SBITCACHE_H__

Gura_BeginModule(freetype)

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
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FTC_SBitCache &GetEntity() { return _sbitCache; }
	inline const FTC_SBitCache &GetEntity() const { return _sbitCache; }
};

}}

#endif
