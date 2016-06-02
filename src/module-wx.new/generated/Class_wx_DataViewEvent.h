//----------------------------------------------------------------------------
// wxDataViewEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWEVENT_H__
#define __CLASS_WX_DATAVIEWEVENT_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewEvent);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewEvent
//----------------------------------------------------------------------------
class Object_wx_DataViewEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_DataViewEvent)
public:
	inline Object_wx_DataViewEvent(wxDataViewEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_DataViewEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewEvent(Class *pClass, wxDataViewEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewEvent *GetEntity() {
		return static_cast<wxDataViewEvent *>(_pEntity);
	}
	inline wxDataViewEvent *ReleaseEntity() {
		wxDataViewEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
