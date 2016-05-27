//----------------------------------------------------------------------------
// wxCommandEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COMMANDEVENT_H__
#define __CLASS_WX_COMMANDEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCommandEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CommandEvent);

//----------------------------------------------------------------------------
// Object declaration for wxCommandEvent
//----------------------------------------------------------------------------
class Object_wx_CommandEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_CommandEvent)
public:
	inline Object_wx_CommandEvent(wxCommandEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_CommandEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CommandEvent(Class *pClass, wxCommandEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CommandEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxCommandEvent *GetEntity() {
		return static_cast<wxCommandEvent *>(_pEntity);
	}
	inline wxCommandEvent *ReleaseEntity() {
		wxCommandEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxCommandEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
