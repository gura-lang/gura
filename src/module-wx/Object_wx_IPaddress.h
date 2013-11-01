//----------------------------------------------------------------------------
// wxIPaddress
// extracted from ipaddr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_IPADDRESS_H__
#define __OBJECT_WX_IPADDRESS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIPaddress
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IPaddress);

//----------------------------------------------------------------------------
// Object declaration for wxIPaddress
//----------------------------------------------------------------------------
class Object_wx_IPaddress : public Object_wx_SockAddress {
public:
	Gura_DeclareObjectAccessor(wx_IPaddress)
public:
	inline Object_wx_IPaddress(wxIPaddress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SockAddress(Gura_UserClass(wx_IPaddress), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IPaddress(Class *pClass, wxIPaddress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SockAddress(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IPaddress();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxIPaddress *GetEntity() {
		return dynamic_cast<wxIPaddress *>(_pEntity);
	}
	inline wxIPaddress *ReleaseEntity() {
		wxIPaddress *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxIPaddress");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
