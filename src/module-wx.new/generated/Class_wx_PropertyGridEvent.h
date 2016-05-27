//----------------------------------------------------------------------------
// wxPropertyGridEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPERTYGRIDEVENT_H__
#define __CLASS_WX_PROPERTYGRIDEVENT_H__
#include <wx/propgrid/propgrid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropertyGridEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropertyGridEvent);

//----------------------------------------------------------------------------
// Object declaration for wxPropertyGridEvent
//----------------------------------------------------------------------------
class Object_wx_PropertyGridEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_PropertyGridEvent)
public:
	inline Object_wx_PropertyGridEvent(wxPropertyGridEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_PropertyGridEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PropertyGridEvent(Class *pClass, wxPropertyGridEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PropertyGridEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPropertyGridEvent *GetEntity() {
		return static_cast<wxPropertyGridEvent *>(_pEntity);
	}
	inline wxPropertyGridEvent *ReleaseEntity() {
		wxPropertyGridEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPropertyGridEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
