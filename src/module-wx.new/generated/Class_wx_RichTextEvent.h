//----------------------------------------------------------------------------
// wxRichTextEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTEVENT_H__
#define __CLASS_WX_RICHTEXTEVENT_H__
#include <wx/richtext/richtextctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextEvent);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextEvent
//----------------------------------------------------------------------------
class Object_wx_RichTextEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_RichTextEvent)
public:
	inline Object_wx_RichTextEvent(wxRichTextEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_RichTextEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextEvent(Class *pClass, wxRichTextEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextEvent *GetEntity() {
		return static_cast<wxRichTextEvent *>(_pEntity);
	}
	inline wxRichTextEvent *ReleaseEntity() {
		wxRichTextEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
