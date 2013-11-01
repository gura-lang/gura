//----------------------------------------------------------------------------
// wxPreviewControlBar
// extracted from prevwin.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PREVIEWCONTROLBAR_H__
#define __CLASS_WX_PREVIEWCONTROLBAR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PreviewControlBar);

//----------------------------------------------------------------------------
// Object declaration for wxPreviewControlBar
//----------------------------------------------------------------------------
class Object_wx_PreviewControlBar : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_PreviewControlBar)
public:
	inline Object_wx_PreviewControlBar(wxPreviewControlBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_PreviewControlBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PreviewControlBar(Class *pClass, wxPreviewControlBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PreviewControlBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPreviewControlBar *GetEntity() {
		return dynamic_cast<wxPreviewControlBar *>(_pEntity);
	}
	inline wxPreviewControlBar *ReleaseEntity() {
		wxPreviewControlBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPreviewControlBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
