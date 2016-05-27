//----------------------------------------------------------------------------
// wxPrintAbortDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PRINTABORTDIALOG_H__
#define __CLASS_WX_PRINTABORTDIALOG_H__
#include <wx/print.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPrintAbortDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PrintAbortDialog);

//----------------------------------------------------------------------------
// Object declaration for wxPrintAbortDialog
//----------------------------------------------------------------------------
class Object_wx_PrintAbortDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_PrintAbortDialog)
public:
	inline Object_wx_PrintAbortDialog(wxPrintAbortDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_PrintAbortDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PrintAbortDialog(Class *pClass, wxPrintAbortDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PrintAbortDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPrintAbortDialog *GetEntity() {
		return static_cast<wxPrintAbortDialog *>(_pEntity);
	}
	inline wxPrintAbortDialog *ReleaseEntity() {
		wxPrintAbortDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPrintAbortDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
