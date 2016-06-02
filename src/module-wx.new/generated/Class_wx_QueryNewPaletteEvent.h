//----------------------------------------------------------------------------
// wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_QUERYNEWPALETTEEVENT_H__
#define __CLASS_WX_QUERYNEWPALETTEEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_QueryNewPaletteEvent);

//----------------------------------------------------------------------------
// Object declaration for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
class Object_wx_QueryNewPaletteEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_QueryNewPaletteEvent)
public:
	inline Object_wx_QueryNewPaletteEvent(wxQueryNewPaletteEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_QueryNewPaletteEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_QueryNewPaletteEvent(Class *pClass, wxQueryNewPaletteEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_QueryNewPaletteEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxQueryNewPaletteEvent *GetEntity() {
		return static_cast<wxQueryNewPaletteEvent *>(_pEntity);
	}
	inline wxQueryNewPaletteEvent *ReleaseEntity() {
		wxQueryNewPaletteEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxQueryNewPaletteEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
