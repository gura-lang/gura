//----------------------------------------------------------------------------
// wxPrintDialog
// extracted from print.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PRINTDIALOG_H__
#define __OBJECT_WX_PRINTDIALOG_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPrintDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PrintDialog);

//----------------------------------------------------------------------------
// Object declaration for wxPrintDialog
//----------------------------------------------------------------------------
class Object_wx_PrintDialog : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PrintDialog)
public:
	inline Object_wx_PrintDialog(wxPrintDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PrintDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PrintDialog(Class *pClass, wxPrintDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PrintDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPrintDialog *GetEntity() {
		return dynamic_cast<wxPrintDialog *>(_pEntity);
	}
	inline wxPrintDialog *ReleaseEntity() {
		wxPrintDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPrintDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
