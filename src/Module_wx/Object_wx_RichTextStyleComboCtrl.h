//----------------------------------------------------------------------------
// wxRichTextStyleComboCtrl
// extracted from richtextstylelistbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTSTYLECOMBOCTRL_H__
#define __OBJECT_WX_RICHTEXTSTYLECOMBOCTRL_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextStyleComboCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextStyleComboCtrl
//----------------------------------------------------------------------------
class Object_wx_RichTextStyleComboCtrl : public Object_wx_ComboCtrl {
public:
	Gura_DeclareObjectAccessor(wx_RichTextStyleComboCtrl)
public:
	inline Object_wx_RichTextStyleComboCtrl(wxRichTextStyleComboCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ComboCtrl(Gura_UserClass(wx_RichTextStyleComboCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextStyleComboCtrl(Class *pClass, wxRichTextStyleComboCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ComboCtrl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextStyleComboCtrl();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextStyleComboCtrl *GetEntity() {
		return dynamic_cast<wxRichTextStyleComboCtrl *>(_pEntity);
	}
	inline wxRichTextStyleComboCtrl *ReleaseEntity() {
		wxRichTextStyleComboCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextStyleComboCtrl");
		return true;
	}
};

}}

#endif
