//----------------------------------------------------------------------------
// wxPropertySheetDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPERTYSHEETDIALOG_H__
#define __CLASS_WX_PROPERTYSHEETDIALOG_H__
#include <wx/propdlg.h>

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxPropertySheetDialog *GetEntity() {
		return static_cast<wxPropertySheetDialog *>(_pEntity);
	}
	inline wxPropertySheetDialog *ReleaseEntity() {
		wxPropertySheetDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPropertySheetDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
