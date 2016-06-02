//----------------------------------------------------------------------------
// wxSymbolPickerDialog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SYMBOLPICKERDIALOG_H__
#define __CLASS_WX_SYMBOLPICKERDIALOG_H__
#include <wx/richtext/richtextsymboldlg.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SymbolPickerDialog);

//----------------------------------------------------------------------------
// Object declaration for wxSymbolPickerDialog
//----------------------------------------------------------------------------
class Object_wx_SymbolPickerDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_SymbolPickerDialog)
public:
	inline Object_wx_SymbolPickerDialog(wxSymbolPickerDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_SymbolPickerDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SymbolPickerDialog(Class *pClass, wxSymbolPickerDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SymbolPickerDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSymbolPickerDialog *GetEntity() {
		return static_cast<wxSymbolPickerDialog *>(_pEntity);
	}
	inline wxSymbolPickerDialog *ReleaseEntity() {
		wxSymbolPickerDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSymbolPickerDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
