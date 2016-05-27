//----------------------------------------------------------------------------
// wxMouseEventsManager
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MOUSEEVENTSMANAGER_H__
#define __CLASS_WX_MOUSEEVENTSMANAGER_H__
#include <wx/mousemanager.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMouseEventsManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MouseEventsManager);

//----------------------------------------------------------------------------
// Object declaration for wxMouseEventsManager
//----------------------------------------------------------------------------
class Object_wx_MouseEventsManager : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_MouseEventsManager)
public:
	inline Object_wx_MouseEventsManager(wxMouseEventsManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_MouseEventsManager), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MouseEventsManager(Class *pClass, wxMouseEventsManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MouseEventsManager();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMouseEventsManager *GetEntity() {
		return static_cast<wxMouseEventsManager *>(_pEntity);
	}
	inline wxMouseEventsManager *ReleaseEntity() {
		wxMouseEventsManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMouseEventsManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
