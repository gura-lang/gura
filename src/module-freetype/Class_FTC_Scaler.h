#ifndef __FREETYPE_CLASS_FTC_SCALER_H__
#define __FREETYPE_CLASS_FTC_SCALER_H__

Gura_BeginModuleScope(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_Scaler declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_Scaler);

class Object_FTC_Scaler : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_Scaler)
private:
	FTC_Scaler _scaler;
public:
	inline Object_FTC_Scaler(const FTC_Scaler &scaler) :
			Object(Gura_UserClass(FTC_Scaler)), _scaler(scaler) {}
	inline Object_FTC_Scaler(const Object_FTC_Scaler &obj) :
			Object(obj), _scaler(obj._scaler) {}
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline FTC_Scaler &GetEntity() { return _scaler; }
	inline const FTC_Scaler &GetEntity() const { return _scaler; }
};

Gura_EndModuleScope(freetype)

#endif
