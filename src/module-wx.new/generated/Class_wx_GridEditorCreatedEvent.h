//----------------------------------------------------------------------------
// wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDEDITORCREATEDEVENT_H__
#define __CLASS_WX_GRIDEDITORCREATEDEVENT_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridEditorCreatedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
class Object_wx_GridEditorCreatedEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_GridEditorCreatedEvent)
public:
	inline Object_wx_GridEditorCreatedEvent(wxGridEditorCreatedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_GridEditorCreatedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridEditorCreatedEvent(Class *pClass, wxGridEditorCreatedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridEditorCreatedEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridEditorCreatedEvent *GetEntity() {
		return static_cast<wxGridEditorCreatedEvent *>(_pEntity);
	}
	inline wxGridEditorCreatedEvent *ReleaseEntity() {
		wxGridEditorCreatedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridEditorCreatedEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
