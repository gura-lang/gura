//----------------------------------------------------------------------------
// wxHelpControllerHelpProvider
// extracted from hprovcnt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HELPCONTROLLERHELPPROVIDER_H__
#define __OBJECT_WX_HELPCONTROLLERHELPPROVIDER_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHelpControllerHelpProvider *GetEntity() {
		return dynamic_cast<wxHelpControllerHelpProvider *>(_pEntity);
	}
	inline wxHelpControllerHelpProvider *ReleaseEntity() {
		wxHelpControllerHelpProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHelpControllerHelpProvider");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
