//----------------------------------------------------------------------------
// wxScreenDC
// extracted from screendc.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SCREENDC_H__
#define __OBJECT_WX_SCREENDC_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScreenDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScreenDC);

//----------------------------------------------------------------------------
// Object declaration for wxScreenDC
//----------------------------------------------------------------------------
class Object_wx_ScreenDC : public Object_wx_DC {
public:
	Gura_DeclareObjectAccessor(wx_ScreenDC)
public:
	inline Object_wx_ScreenDC(wxScreenDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(Gura_UserClass(wx_ScreenDC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ScreenDC(Class *pClass, wxScreenDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DC(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ScreenDC();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxScreenDC *GetEntity() {
		return dynamic_cast<wxScreenDC *>(_pEntity);
	}
	inline wxScreenDC *ReleaseEntity() {
		wxScreenDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxScreenDC");
		return true;
	}
};

}}

#endif
