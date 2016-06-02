//----------------------------------------------------------------------------
// wxConnection
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CONNECTION_H__
#define __CLASS_WX_CONNECTION_H__
#include <wx/ipc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxConnection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Connection);

//----------------------------------------------------------------------------
// Object declaration for wxConnection
//----------------------------------------------------------------------------
class Object_wx_Connection : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Connection)
public:
	inline Object_wx_Connection(wxConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Connection), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Connection(Class *pClass, wxConnection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Connection();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxConnection *GetEntity() {
		return static_cast<wxConnection *>(_pEntity);
	}
	inline wxConnection *ReleaseEntity() {
		wxConnection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxConnection");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
