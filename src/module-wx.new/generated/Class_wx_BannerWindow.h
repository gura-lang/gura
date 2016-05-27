//----------------------------------------------------------------------------
// wxBannerWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BANNERWINDOW_H__
#define __CLASS_WX_BANNERWINDOW_H__
#include <wx/bannerwindow.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBannerWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BannerWindow);

//----------------------------------------------------------------------------
// Object declaration for wxBannerWindow
//----------------------------------------------------------------------------
class Object_wx_BannerWindow : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_BannerWindow)
public:
	inline Object_wx_BannerWindow(wxBannerWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_BannerWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_BannerWindow(Class *pClass, wxBannerWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_BannerWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBannerWindow *GetEntity() {
		return static_cast<wxBannerWindow *>(_pEntity);
	}
	inline wxBannerWindow *ReleaseEntity() {
		wxBannerWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxBannerWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
