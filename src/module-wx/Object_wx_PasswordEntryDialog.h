//----------------------------------------------------------------------------
// wxPasswordEntryDialog
// extracted from passdlg.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PASSWORDENTRYDIALOG_H__
#define __OBJECT_WX_PASSWORDENTRYDIALOG_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PasswordEntryDialog);

//----------------------------------------------------------------------------
// Object declaration for wxPasswordEntryDialog
//----------------------------------------------------------------------------
class Object_wx_PasswordEntryDialog : public Object_wx_TextEntryDialog {
public:
	Gura_DeclareObjectAccessor(wx_PasswordEntryDialog)
public:
	inline Object_wx_PasswordEntryDialog(wxPasswordEntryDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextEntryDialog(Gura_UserClass(wx_PasswordEntryDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PasswordEntryDialog(Class *pClass, wxPasswordEntryDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_TextEntryDialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PasswordEntryDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPasswordEntryDialog *GetEntity() {
		return dynamic_cast<wxPasswordEntryDialog *>(_pEntity);
	}
	inline wxPasswordEntryDialog *ReleaseEntity() {
		wxPasswordEntryDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPasswordEntryDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
