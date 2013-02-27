#ifndef __FREETYPE_OBJECT_FTC_MANAGER_H__
#define __FREETYPE_OBJECT_FTC_MANAGER_H__

Gura_BeginModule(freetype)

//-----------------------------------------------------------------------------
// Object_FTC_Manager declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(FTC_Manager);

class Object_FTC_Manager : public Object {
public:
	Gura_DeclareObjectAccessor(FTC_Manager)
private:
	FTC_Manager _manager;
public:
	inline Object_FTC_Manager(const FTC_Manager &manager) :
			Object(Gura_UserClass(FTC_Manager)), _manager(manager) {}
	inline Object_FTC_Manager(const Object_FTC_Manager &obj) :
			Object(obj), _manager(obj._manager) {}
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline FTC_Manager &GetEntity() { return _manager; }
	inline const FTC_Manager &GetEntity() const { return _manager; }
};

}}

#endif
