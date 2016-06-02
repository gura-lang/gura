//----------------------------------------------------------------------------
// wxExtHelpController
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_EXTHELPCONTROLLER_H__
#define __CLASS_WX_EXTHELPCONTROLLER_H__
#include <wx/generic/helpext.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxExtHelpController
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ExtHelpController);

//----------------------------------------------------------------------------
// Object declaration for wxExtHelpController
//----------------------------------------------------------------------------
class Object_wx_ExtHelpController : public Object_wx_HelpControllerBase {
public:
	Gura_DeclareObjectAccessor(wx_ExtHelpController)
public:
	inline Object_wx_ExtHelpController(wxExtHelpController *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HelpControllerBase(Gura_UserClass(wx_ExtHelpController), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ExtHelpController(Class *pClass, wxExtHelpController *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HelpControllerBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ExtHelpController();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxExtHelpController *GetEntity() {
		return static_cast<wxExtHelpController *>(_pEntity);
	}
	inline wxExtHelpController *ReleaseEntity() {
		wxExtHelpController *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxExtHelpController");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
