//----------------------------------------------------------------------------
// wxPropertyGridPage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPERTYGRIDPAGE_H__
#define __CLASS_WX_PROPERTYGRIDPAGE_H__
#include <wx/propgrid/manager.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropertyGridPage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropertyGridPage);

//----------------------------------------------------------------------------
// Object declaration for wxPropertyGridPage
//----------------------------------------------------------------------------
class Object_wx_PropertyGridPage : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_PropertyGridPage)
public:
	inline Object_wx_PropertyGridPage(wxPropertyGridPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_PropertyGridPage), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PropertyGridPage(Class *pClass, wxPropertyGridPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PropertyGridPage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPropertyGridPage *GetEntity() {
		return static_cast<wxPropertyGridPage *>(_pEntity);
	}
	inline wxPropertyGridPage *ReleaseEntity() {
		wxPropertyGridPage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPropertyGridPage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
