//----------------------------------------------------------------------------
// wxFontDialog
// extracted from fontdlg.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FONTDIALOG_H__
#define __CLASS_WX_FONTDIALOG_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontDialog);

//----------------------------------------------------------------------------
// Object declaration for wxFontDialog
//----------------------------------------------------------------------------
class Object_wx_FontDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_FontDialog)
public:
	inline Object_wx_FontDialog(wxFontDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_FontDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FontDialog(Class *pClass, wxFontDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FontDialog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFontDialog *GetEntity() {
		return dynamic_cast<wxFontDialog *>(_pEntity);
	}
	inline wxFontDialog *ReleaseEntity() {
		wxFontDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFontDialog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
