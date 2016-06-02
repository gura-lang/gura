//----------------------------------------------------------------------------
// wxWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOW_H__
#define __CLASS_WX_WINDOW_H__
#include <wx/window.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Window);

//----------------------------------------------------------------------------
// Object declaration for wxWindow
//----------------------------------------------------------------------------
class Object_wx_Window : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_Window)
public:
	inline Object_wx_Window(wxWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_Window), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Window(Class *pClass, wxWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Window();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWindow *GetEntity() {
		return static_cast<wxWindow *>(_pEntity);
	}
	inline wxWindow *ReleaseEntity() {
		wxWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
