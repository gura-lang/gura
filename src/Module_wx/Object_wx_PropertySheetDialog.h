//----------------------------------------------------------------------------
// wxPropertySheetDialog
// extracted from propdlg.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PROPERTYSHEETDIALOG_H__
#define __OBJECT_WX_PROPERTYSHEETDIALOG_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropertySheetDialog);

//----------------------------------------------------------------------------
// Object declaration for wxPropertySheetDialog
//----------------------------------------------------------------------------
class Object_wx_PropertySheetDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_PropertySheetDialog)
public:
	inline Object_wx_PropertySheetDialog(wxPropertySheetDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_PropertySheetDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PropertySheetDialog(Class *pClass, wxPropertySheetDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PropertySheetDialog();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPropertySheetDialog *GetEntity() {
		return dynamic_cast<wxPropertySheetDialog *>(_pEntity);
	}
	inline wxPropertySheetDialog *ReleaseEntity() {
		wxPropertySheetDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPropertySheetDialog");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
