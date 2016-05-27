//----------------------------------------------------------------------------
// wxPropertyGridManager
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPERTYGRIDMANAGER_H__
#define __CLASS_WX_PROPERTYGRIDMANAGER_H__
#include <wx/propgrid/manager.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropertyGridManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropertyGridManager);

//----------------------------------------------------------------------------
// Object declaration for wxPropertyGridManager
//----------------------------------------------------------------------------
class Object_wx_PropertyGridManager : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_PropertyGridManager)
public:
	inline Object_wx_PropertyGridManager(wxPropertyGridManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_PropertyGridManager), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PropertyGridManager(Class *pClass, wxPropertyGridManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PropertyGridManager();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPropertyGridManager *GetEntity() {
		return static_cast<wxPropertyGridManager *>(_pEntity);
	}
	inline wxPropertyGridManager *ReleaseEntity() {
		wxPropertyGridManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPropertyGridManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
