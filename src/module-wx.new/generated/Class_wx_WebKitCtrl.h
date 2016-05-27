//----------------------------------------------------------------------------
// wxWebKitCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBKITCTRL_H__
#define __CLASS_WX_WEBKITCTRL_H__
#include <wx/html/webkit.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebKitCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebKitCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxWebKitCtrl
//----------------------------------------------------------------------------
class Object_wx_WebKitCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_WebKitCtrl)
public:
	inline Object_wx_WebKitCtrl(wxWebKitCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_WebKitCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebKitCtrl(Class *pClass, wxWebKitCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebKitCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebKitCtrl *GetEntity() {
		return static_cast<wxWebKitCtrl *>(_pEntity);
	}
	inline wxWebKitCtrl *ReleaseEntity() {
		wxWebKitCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWebKitCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
