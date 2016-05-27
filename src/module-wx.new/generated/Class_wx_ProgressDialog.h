//----------------------------------------------------------------------------
// wxProgressDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROGRESSDIALOG_H__
#define __CLASS_WX_PROGRESSDIALOG_H__
#include <wx/progdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxProgressDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ProgressDialog);

//----------------------------------------------------------------------------
// Object declaration for wxProgressDialog
//----------------------------------------------------------------------------
class Object_wx_ProgressDialog : public Object_wx_GenericProgressDialog {
public:
	Gura_DeclareObjectAccessor(wx_ProgressDialog)
public:
	inline Object_wx_ProgressDialog(wxProgressDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GenericProgressDialog(Gura_UserClass(wx_ProgressDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ProgressDialog(Class *pClass, wxProgressDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GenericProgressDialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ProgressDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxProgressDialog *GetEntity() {
		return static_cast<wxProgressDialog *>(_pEntity);
	}
	inline wxProgressDialog *ReleaseEntity() {
		wxProgressDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxProgressDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
