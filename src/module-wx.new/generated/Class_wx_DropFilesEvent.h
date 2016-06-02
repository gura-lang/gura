//----------------------------------------------------------------------------
// wxDropFilesEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DROPFILESEVENT_H__
#define __CLASS_WX_DROPFILESEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDropFilesEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DropFilesEvent);

//----------------------------------------------------------------------------
// Object declaration for wxDropFilesEvent
//----------------------------------------------------------------------------
class Object_wx_DropFilesEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_DropFilesEvent)
public:
	inline Object_wx_DropFilesEvent(wxDropFilesEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_DropFilesEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DropFilesEvent(Class *pClass, wxDropFilesEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DropFilesEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDropFilesEvent *GetEntity() {
		return static_cast<wxDropFilesEvent *>(_pEntity);
	}
	inline wxDropFilesEvent *ReleaseEntity() {
		wxDropFilesEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDropFilesEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
