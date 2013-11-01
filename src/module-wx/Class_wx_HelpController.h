//----------------------------------------------------------------------------
// wxHelpController
// extracted from helpinst.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HELPCONTROLLER_H__
#define __OBJECT_WX_HELPCONTROLLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHelpController
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HelpController);

//----------------------------------------------------------------------------
// Object declaration for wxHelpController
//----------------------------------------------------------------------------
class Object_wx_HelpController : public Object_wx_HelpControllerBase {
public:
	Gura_DeclareObjectAccessor(wx_HelpController)
public:
	inline Object_wx_HelpController(wxHelpController *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HelpControllerBase(Gura_UserClass(wx_HelpController), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HelpController(Class *pClass, wxHelpController *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HelpControllerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HelpController();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxHelpController *GetEntity() {
		return dynamic_cast<wxHelpController *>(_pEntity);
	}
	inline wxHelpController *ReleaseEntity() {
		wxHelpController *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHelpController");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
