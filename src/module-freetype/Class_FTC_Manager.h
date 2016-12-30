#ifndef __FREETYPE_CLASS_FTC_MANAGER_H__
#define __FREETYPE_CLASS_FTC_MANAGER_H__

Gura_BeginModuleScope(freetype)

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
	virtual String ToString(bool exprFlag);
	inline FTC_Manager &GetEntity() { return _manager; }
	inline const FTC_Manager &GetEntity() const { return _manager; }
};

Gura_EndModuleScope(freetype)

#endif
