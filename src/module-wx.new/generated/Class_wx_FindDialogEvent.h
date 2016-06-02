//----------------------------------------------------------------------------
// wxFindDialogEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FINDDIALOGEVENT_H__
#define __CLASS_WX_FINDDIALOGEVENT_H__
#include <wx/fdrepdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFindDialogEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FindDialogEvent);

//----------------------------------------------------------------------------
// Object declaration for wxFindDialogEvent
//----------------------------------------------------------------------------
class Object_wx_FindDialogEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_FindDialogEvent)
public:
	inline Object_wx_FindDialogEvent(wxFindDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_FindDialogEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FindDialogEvent(Class *pClass, wxFindDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FindDialogEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFindDialogEvent *GetEntity() {
		return static_cast<wxFindDialogEvent *>(_pEntity);
	}
	inline wxFindDialogEvent *ReleaseEntity() {
		wxFindDialogEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFindDialogEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
