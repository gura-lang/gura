//----------------------------------------------------------------------------
// wxFileCtrlEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FILECTRLEVENT_H__
#define __CLASS_WX_FILECTRLEVENT_H__
#include <wx/filectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFileCtrlEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FileCtrlEvent);

//----------------------------------------------------------------------------
// Object declaration for wxFileCtrlEvent
//----------------------------------------------------------------------------
class Object_wx_FileCtrlEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_FileCtrlEvent)
public:
	inline Object_wx_FileCtrlEvent(wxFileCtrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_FileCtrlEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FileCtrlEvent(Class *pClass, wxFileCtrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FileCtrlEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFileCtrlEvent *GetEntity() {
		return static_cast<wxFileCtrlEvent *>(_pEntity);
	}
	inline wxFileCtrlEvent *ReleaseEntity() {
		wxFileCtrlEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFileCtrlEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
