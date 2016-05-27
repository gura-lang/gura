//----------------------------------------------------------------------------
// wxPaletteChangedEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PALETTECHANGEDEVENT_H__
#define __CLASS_WX_PALETTECHANGEDEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPaletteChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PaletteChangedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxPaletteChangedEvent
//----------------------------------------------------------------------------
class Object_wx_PaletteChangedEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_PaletteChangedEvent)
public:
	inline Object_wx_PaletteChangedEvent(wxPaletteChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_PaletteChangedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PaletteChangedEvent(Class *pClass, wxPaletteChangedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PaletteChangedEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPaletteChangedEvent *GetEntity() {
		return static_cast<wxPaletteChangedEvent *>(_pEntity);
	}
	inline wxPaletteChangedEvent *ReleaseEntity() {
		wxPaletteChangedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPaletteChangedEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
