//----------------------------------------------------------------------------
// wxGenericProgressDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GENERICPROGRESSDIALOG_H__
#define __CLASS_WX_GENERICPROGRESSDIALOG_H__
#include <wx/progdlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGenericProgressDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GenericProgressDialog);

//----------------------------------------------------------------------------
// Object declaration for wxGenericProgressDialog
//----------------------------------------------------------------------------
class Object_wx_GenericProgressDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_GenericProgressDialog)
public:
	inline Object_wx_GenericProgressDialog(wxGenericProgressDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_GenericProgressDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GenericProgressDialog(Class *pClass, wxGenericProgressDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GenericProgressDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGenericProgressDialog *GetEntity() {
		return static_cast<wxGenericProgressDialog *>(_pEntity);
	}
	inline wxGenericProgressDialog *ReleaseEntity() {
		wxGenericProgressDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGenericProgressDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
