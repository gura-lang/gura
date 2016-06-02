//----------------------------------------------------------------------------
// wxSpinDoubleEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SPINDOUBLEEVENT_H__
#define __CLASS_WX_SPINDOUBLEEVENT_H__
#include <wx/spinctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSpinDoubleEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SpinDoubleEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSpinDoubleEvent
//----------------------------------------------------------------------------
class Object_wx_SpinDoubleEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_SpinDoubleEvent)
public:
	inline Object_wx_SpinDoubleEvent(wxSpinDoubleEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_SpinDoubleEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SpinDoubleEvent(Class *pClass, wxSpinDoubleEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SpinDoubleEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSpinDoubleEvent *GetEntity() {
		return static_cast<wxSpinDoubleEvent *>(_pEntity);
	}
	inline wxSpinDoubleEvent *ReleaseEntity() {
		wxSpinDoubleEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSpinDoubleEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
