#ifndef __FREETYPE_CLASS_FTC_CMAPCACHE_H__
#define __FREETYPE_CLASS_FTC_CMAPCACHE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_CMapCache declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_CMapCache);

class Object_FTC_CMapCache : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_CMapCache)
private:
	FTC_CMapCache _cmapCache;
public:
	inline Object_FTC_CMapCache(const FTC_CMapCache &cmapCache) :
			Object(Gura_UserClass(FTC_CMapCache)), _cmapCache(cmapCache) {}
	inline Object_FTC_CMapCache(const Object_FTC_CMapCache &obj) :
			Object(obj), _cmapCache(obj._cmapCache) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FTC_CMapCache &GetEntity() { return _cmapCache; }
	inline const FTC_CMapCache &GetEntity() const { return _cmapCache; }
};

Gura_EndModuleScope(freetype)

#endif
