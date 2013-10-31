//----------------------------------------------------------------------------
// wxSockAddress
// extracted from sckaddr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SOCKADDRESS_H__
#define __OBJECT_WX_SOCKADDRESS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSockAddress
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SockAddress);

//----------------------------------------------------------------------------
// Object declaration for wxSockAddress
//----------------------------------------------------------------------------
class Object_wx_SockAddress : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_SockAddress)
public:
	inline Object_wx_SockAddress(wxSockAddress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_SockAddress), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SockAddress(Class *pClass, wxSockAddress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SockAddress();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSockAddress *GetEntity() {
		return dynamic_cast<wxSockAddress *>(_pEntity);
	}
	inline wxSockAddress *ReleaseEntity() {
		wxSockAddress *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSockAddress");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
