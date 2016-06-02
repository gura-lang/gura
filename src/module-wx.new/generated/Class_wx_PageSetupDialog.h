//----------------------------------------------------------------------------
// wxPageSetupDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PAGESETUPDIALOG_H__
#define __CLASS_WX_PAGESETUPDIALOG_H__
#include <wx/printdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPageSetupDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PageSetupDialog);

//----------------------------------------------------------------------------
// Object declaration for wxPageSetupDialog
//----------------------------------------------------------------------------
class Object_wx_PageSetupDialog : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PageSetupDialog)
public:
	inline Object_wx_PageSetupDialog(wxPageSetupDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PageSetupDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PageSetupDialog(Class *pClass, wxPageSetupDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PageSetupDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPageSetupDialog *GetEntity() {
		return static_cast<wxPageSetupDialog *>(_pEntity);
	}
	inline wxPageSetupDialog *ReleaseEntity() {
		wxPageSetupDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPageSetupDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
