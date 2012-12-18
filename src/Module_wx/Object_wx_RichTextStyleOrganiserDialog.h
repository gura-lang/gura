//----------------------------------------------------------------------------
// wxRichTextStyleOrganiserDialog
// extracted from richtextstyleorganiserdialog.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTSTYLEORGANISERDIALOG_H__
#define __OBJECT_WX_RICHTEXTSTYLEORGANISERDIALOG_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextStyleOrganiserDialog);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
class Object_wx_RichTextStyleOrganiserDialog : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_RichTextStyleOrganiserDialog)
public:
	inline Object_wx_RichTextStyleOrganiserDialog(wxRichTextStyleOrganiserDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_RichTextStyleOrganiserDialog), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextStyleOrganiserDialog(Class *pClass, wxRichTextStyleOrganiserDialog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextStyleOrganiserDialog();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextStyleOrganiserDialog *GetEntity() {
		return dynamic_cast<wxRichTextStyleOrganiserDialog *>(_pEntity);
	}
	inline wxRichTextStyleOrganiserDialog *ReleaseEntity() {
		wxRichTextStyleOrganiserDialog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextStyleOrganiserDialog");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
