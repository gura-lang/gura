//----------------------------------------------------------------------------
// wxClient
// extracted from ipcclint.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CLIENT_H__
#define __OBJECT_WX_CLIENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClient
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Client);

//----------------------------------------------------------------------------
// Object declaration for wxClient
//----------------------------------------------------------------------------
class Object_wx_Client : public Object_wx_ClientBase {
public:
	Gura_DeclareObjectAccessor(wx_Client)
public:
	inline Object_wx_Client(wxClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientBase(Gura_UserClass(wx_Client), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Client(Class *pClass, wxClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Client();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxClient *GetEntity() {
		return dynamic_cast<wxClient *>(_pEntity);
	}
	inline wxClient *ReleaseEntity() {
		wxClient *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxClient");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
