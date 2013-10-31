#ifndef __FREETYPE_OBJECT_FTC_IMAGETYPE_H__
#define __FREETYPE_OBJECT_FTC_IMAGETYPE_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_ImageType declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_ImageType);

class Object_FTC_ImageType : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_ImageType)
private:
	FTC_ImageType _imageType;
public:
	inline Object_FTC_ImageType(const FTC_ImageType &imageType) :
			Object(Gura_UserClass(FTC_ImageType)), _imageType(imageType) {}
	inline Object_FTC_ImageType(const Object_FTC_ImageType &obj) :
			Object(obj), _imageType(obj._imageType) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FTC_ImageType &GetEntity() { return _imageType; }
	inline const FTC_ImageType &GetEntity() const { return _imageType; }
};

Gura_EndModuleScope(freetype)

#endif
