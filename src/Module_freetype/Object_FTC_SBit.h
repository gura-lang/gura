#ifndef __FREETYPE_OBJECT_FTC_SBIT_H__
#define __FREETYPE_OBJECT_FTC_SBIT_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_SBit declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_SBit);

class Object_FTC_SBit : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_SBit)
private:
	FTC_SBit _sbit;
public:
	inline Object_FTC_SBit(const FTC_SBit &sbit) :
			Object(Gura_UserClass(FTC_SBit)), _sbit(sbit) {}
	inline Object_FTC_SBit(const Object_FTC_SBit &obj) :
			Object(obj), _sbit(obj._sbit) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FTC_SBit &GetEntity() { return _sbit; }
	inline const FTC_SBit &GetEntity() const { return _sbit; }
};

}}

#endif
