//----------------------------------------------------------------------------
// wxHVScrolledWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HVSCROLLEDWINDOW_H__
#define __CLASS_WX_HVSCROLLEDWINDOW_H__
#include <wx/vscroll.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHVScrolledWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HVScrolledWindow);

//----------------------------------------------------------------------------
// Object declaration for wxHVScrolledWindow
//----------------------------------------------------------------------------
class Object_wx_HVScrolledWindow : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_HVScrolledWindow)
public:
	inline Object_wx_HVScrolledWindow(wxHVScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_HVScrolledWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HVScrolledWindow(Class *pClass, wxHVScrolledWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HVScrolledWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHVScrolledWindow *GetEntity() {
		return static_cast<wxHVScrolledWindow *>(_pEntity);
	}
	inline wxHVScrolledWindow *ReleaseEntity() {
		wxHVScrolledWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHVScrolledWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
