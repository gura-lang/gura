//----------------------------------------------------------------------------
// wxSingleChoiceDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SINGLECHOICEDIALOG_H__
#define __CLASS_WX_SINGLECHOICEDIALOG_H__
#include <wx/choicdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSingleChoiceDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SingleChoiceDialog);

//----------------------------------------------------------------------------
// Object declaration for wxSingleChoiceDialog
//----------------------------------------------------------------------------
class Object_wx_SingleChoiceDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_SingleChoiceDialog)
public:
	inline Object_wx_SingleChoiceDialog(wxSingleChoiceDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_SingleChoiceDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SingleChoiceDialog(Class *pClass, wxSingleChoiceDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SingleChoiceDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSingleChoiceDialog *GetEntity() {
		return static_cast<wxSingleChoiceDialog *>(_pEntity);
	}
	inline wxSingleChoiceDialog *ReleaseEntity() {
		wxSingleChoiceDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSingleChoiceDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
