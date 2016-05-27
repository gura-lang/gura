//----------------------------------------------------------------------------
// wxTextUrlEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTURLEVENT_H__
#define __CLASS_WX_TEXTURLEVENT_H__
#include <wx/textctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextUrlEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextUrlEvent);

//----------------------------------------------------------------------------
// Object declaration for wxTextUrlEvent
//----------------------------------------------------------------------------
class Object_wx_TextUrlEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_TextUrlEvent)
public:
	inline Object_wx_TextUrlEvent(wxTextUrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_TextUrlEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextUrlEvent(Class *pClass, wxTextUrlEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextUrlEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextUrlEvent *GetEntity() {
		return static_cast<wxTextUrlEvent *>(_pEntity);
	}
	inline wxTextUrlEvent *ReleaseEntity() {
		wxTextUrlEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTextUrlEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
