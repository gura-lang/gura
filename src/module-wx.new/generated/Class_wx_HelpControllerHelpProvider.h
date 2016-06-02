//----------------------------------------------------------------------------
// wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HELPCONTROLLERHELPPROVIDER_H__
#define __CLASS_WX_HELPCONTROLLERHELPPROVIDER_H__
#include <wx/cshelp.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HelpControllerHelpProvider);

//----------------------------------------------------------------------------
// Object declaration for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
class Object_wx_HelpControllerHelpProvider : public Object_wx_SimpleHelpProvider {
public:
	Gura_DeclareObjectAccessor(wx_HelpControllerHelpProvider)
public:
	inline Object_wx_HelpControllerHelpProvider(wxHelpControllerHelpProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SimpleHelpProvider(Gura_UserClass(wx_HelpControllerHelpProvider), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HelpControllerHelpProvider(Class *pClass, wxHelpControllerHelpProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_SimpleHelpProvider(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HelpControllerHelpProvider();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHelpControllerHelpProvider *GetEntity() {
		return static_cast<wxHelpControllerHelpProvider *>(_pEntity);
	}
	inline wxHelpControllerHelpProvider *ReleaseEntity() {
		wxHelpControllerHelpProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxHelpControllerHelpProvider");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
