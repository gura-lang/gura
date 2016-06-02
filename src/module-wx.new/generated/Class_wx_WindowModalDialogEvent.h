//----------------------------------------------------------------------------
// wxWindowModalDialogEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOWMODALDIALOGEVENT_H__
#define __CLASS_WX_WINDOWMODALDIALOGEVENT_H__
#include <wx/dialog.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindowModalDialogEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WindowModalDialogEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWindowModalDialogEvent
//----------------------------------------------------------------------------
class Object_wx_WindowModalDialogEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_WindowModalDialogEvent)
public:
	inline Object_wx_WindowModalDialogEvent(wxWindowModalDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_WindowModalDialogEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WindowModalDialogEvent(Class *pClass, wxWindowModalDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WindowModalDialogEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWindowModalDialogEvent *GetEntity() {
		return static_cast<wxWindowModalDialogEvent *>(_pEntity);
	}
	inline wxWindowModalDialogEvent *ReleaseEntity() {
		wxWindowModalDialogEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWindowModalDialogEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
