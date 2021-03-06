//----------------------------------------------------------------------------
// wxTipWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TIPWINDOW_H__
#define __CLASS_WX_TIPWINDOW_H__
#include <wx/tipwin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTipWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TipWindow);

//----------------------------------------------------------------------------
// Object declaration for wxTipWindow
//----------------------------------------------------------------------------
class Object_wx_TipWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_TipWindow)
public:
	inline Object_wx_TipWindow(wxTipWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_TipWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TipWindow(Class *pClass, wxTipWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TipWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTipWindow *GetEntity() {
		return static_cast<wxTipWindow *>(_pEntity);
	}
	inline wxTipWindow *ReleaseEntity() {
		wxTipWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTipWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
