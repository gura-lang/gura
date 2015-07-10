//----------------------------------------------------------------------------
// wxClientDC
// extracted from clientdc.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIENTDC_H__
#define __CLASS_WX_CLIENTDC_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClientDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClientDC);

//----------------------------------------------------------------------------
// Object declaration for wxClientDC
//----------------------------------------------------------------------------
class Object_wx_ClientDC : public Object_wx_WindowDC {
public:
	Gura_DeclareObjectAccessor(wx_ClientDC)
public:
	inline Object_wx_ClientDC(wxClientDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WindowDC(Gura_UserClass(wx_ClientDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ClientDC(Class *pClass, wxClientDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WindowDC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ClientDC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxClientDC *GetEntity() {
		return dynamic_cast<wxClientDC *>(_pEntity);
	}
	inline wxClientDC *ReleaseEntity() {
		wxClientDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxClientDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
