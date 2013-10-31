//----------------------------------------------------------------------------
// wxSymbolPickerDialog
// extracted from symbolpickerdialog.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SYMBOLPICKERDIALOG_H__
#define __OBJECT_WX_SYMBOLPICKERDIALOG_H__

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSymbolPickerDialog *GetEntity() {
		return dynamic_cast<wxSymbolPickerDialog *>(_pEntity);
	}
	inline wxSymbolPickerDialog *ReleaseEntity() {
		wxSymbolPickerDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSymbolPickerDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
