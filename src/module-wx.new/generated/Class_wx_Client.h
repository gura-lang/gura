//----------------------------------------------------------------------------
// wxClient
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIENT_H__
#define __CLASS_WX_CLIENT_H__
#include <wx/ipc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClient
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Client);

//----------------------------------------------------------------------------
// Object declaration for wxClient
//----------------------------------------------------------------------------
class Object_wx_Client : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Client)
public:
	inline Object_wx_Client(wxClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Client), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Client(Class *pClass, wxClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Client();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxClient *GetEntity() {
		return static_cast<wxClient *>(_pEntity);
	}
	inline wxClient *ReleaseEntity() {
		wxClient *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxClient");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
