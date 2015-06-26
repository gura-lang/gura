//----------------------------------------------------------------------------
// wxMessageDialog
// extracted from msgdlg.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MESSAGEDIALOG_H__
#define __CLASS_WX_MESSAGEDIALOG_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMessageDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MessageDialog);

//----------------------------------------------------------------------------
// Object declaration for wxMessageDialog
//----------------------------------------------------------------------------
class Object_wx_MessageDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_MessageDialog)
public:
	inline Object_wx_MessageDialog(wxMessageDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_MessageDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MessageDialog(Class *pClass, wxMessageDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MessageDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMessageDialog *GetEntity() {
		return dynamic_cast<wxMessageDialog *>(_pEntity);
	}
	inline wxMessageDialog *ReleaseEntity() {
		wxMessageDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMessageDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
