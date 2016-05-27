//----------------------------------------------------------------------------
// wxHScrolledWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HSCROLLEDWINDOW_H__
#define __CLASS_WX_HSCROLLEDWINDOW_H__
#include <wx/vscroll.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHScrolledWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HScrolledWindow);

//----------------------------------------------------------------------------
// Object declaration for wxHScrolledWindow
//----------------------------------------------------------------------------
class Object_wx_HScrolledWindow : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_HScrolledWindow)
public:
	inline Object_wx_HScrolledWindow(wxHScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_HScrolledWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HScrolledWindow(Class *pClass, wxHScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HScrolledWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHScrolledWindow *GetEntity() {
		return static_cast<wxHScrolledWindow *>(_pEntity);
	}
	inline wxHScrolledWindow *ReleaseEntity() {
		wxHScrolledWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHScrolledWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
