//----------------------------------------------------------------------------
// wxIPV4address
// extracted from ipvaddr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_IPV4ADDRESS_H__
#define __OBJECT_WX_IPV4ADDRESS_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIPV4address
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IPV4address);

//----------------------------------------------------------------------------
// Object declaration for wxIPV4address
//----------------------------------------------------------------------------
class Object_wx_IPV4address : public Object_wx_IPaddress {
public:
	Gura_DeclareObjectAccessor(wx_IPV4address)
public:
	inline Object_wx_IPV4address(wxIPV4address *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_IPaddress(Gura_UserClass(wx_IPV4address), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IPV4address(Class *pClass, wxIPV4address *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_IPaddress(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IPV4address();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxIPV4address *GetEntity() {
		return dynamic_cast<wxIPV4address *>(_pEntity);
	}
	inline wxIPV4address *ReleaseEntity() {
		wxIPV4address *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxIPV4address");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
