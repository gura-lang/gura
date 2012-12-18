//----------------------------------------------------------------------------
// wxColourDialog
// extracted from colordlg.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_COLOURDIALOG_H__
#define __OBJECT_WX_COLOURDIALOG_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxColourDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ColourDialog);

//----------------------------------------------------------------------------
// Object declaration for wxColourDialog
//----------------------------------------------------------------------------
class Object_wx_ColourDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_ColourDialog)
public:
	inline Object_wx_ColourDialog(wxColourDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_ColourDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ColourDialog(Class *pClass, wxColourDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ColourDialog();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxColourDialog *GetEntity() {
		return dynamic_cast<wxColourDialog *>(_pEntity);
	}
	inline wxColourDialog *ReleaseEntity() {
		wxColourDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxColourDialog");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
