//----------------------------------------------------------------------------
// wxVScrolledWindow
// extracted from vscroll.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VSCROLLEDWINDOW_H__
#define __CLASS_WX_VSCROLLEDWINDOW_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVScrolledWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VScrolledWindow);

//----------------------------------------------------------------------------
// Object declaration for wxVScrolledWindow
//----------------------------------------------------------------------------
class Object_wx_VScrolledWindow : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_VScrolledWindow)
public:
	inline Object_wx_VScrolledWindow(wxVScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_VScrolledWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VScrolledWindow(Class *pClass, wxVScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VScrolledWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVScrolledWindow *GetEntity() {
		return dynamic_cast<wxVScrolledWindow *>(_pEntity);
	}
	inline wxVScrolledWindow *ReleaseEntity() {
		wxVScrolledWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxVScrolledWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
