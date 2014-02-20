//----------------------------------------------------------------------------
// wxRichTextCtrl
// extracted from richtextctrl.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTCTRL_H__
#define __CLASS_WX_RICHTEXTCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextCtrl
//----------------------------------------------------------------------------
class Object_wx_RichTextCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_RichTextCtrl)
public:
	inline Object_wx_RichTextCtrl(wxRichTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_RichTextCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextCtrl(Class *pClass, wxRichTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextCtrl *GetEntity() {
		return dynamic_cast<wxRichTextCtrl *>(_pEntity);
	}
	inline wxRichTextCtrl *ReleaseEntity() {
		wxRichTextCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
