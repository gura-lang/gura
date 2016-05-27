//----------------------------------------------------------------------------
// wxMultiChoiceDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MULTICHOICEDIALOG_H__
#define __CLASS_WX_MULTICHOICEDIALOG_H__
#include <wx/choicdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MultiChoiceDialog);

//----------------------------------------------------------------------------
// Object declaration for wxMultiChoiceDialog
//----------------------------------------------------------------------------
class Object_wx_MultiChoiceDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_MultiChoiceDialog)
public:
	inline Object_wx_MultiChoiceDialog(wxMultiChoiceDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_MultiChoiceDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MultiChoiceDialog(Class *pClass, wxMultiChoiceDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MultiChoiceDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMultiChoiceDialog *GetEntity() {
		return static_cast<wxMultiChoiceDialog *>(_pEntity);
	}
	inline wxMultiChoiceDialog *ReleaseEntity() {
		wxMultiChoiceDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMultiChoiceDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
