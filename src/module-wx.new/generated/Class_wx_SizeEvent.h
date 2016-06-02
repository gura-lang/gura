//----------------------------------------------------------------------------
// wxSizeEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SIZEEVENT_H__
#define __CLASS_WX_SIZEEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSizeEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SizeEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSizeEvent
//----------------------------------------------------------------------------
class Object_wx_SizeEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_SizeEvent)
public:
	inline Object_wx_SizeEvent(wxSizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_SizeEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SizeEvent(Class *pClass, wxSizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SizeEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSizeEvent *GetEntity() {
		return static_cast<wxSizeEvent *>(_pEntity);
	}
	inline wxSizeEvent *ReleaseEntity() {
		wxSizeEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSizeEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
