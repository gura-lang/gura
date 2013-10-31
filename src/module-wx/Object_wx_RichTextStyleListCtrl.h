//----------------------------------------------------------------------------
// wxRichTextStyleListCtrl
// extracted from richtextstylelistbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTSTYLELISTCTRL_H__
#define __OBJECT_WX_RICHTEXTSTYLELISTCTRL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextStyleListCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextStyleListCtrl
//----------------------------------------------------------------------------
class Object_wx_RichTextStyleListCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_RichTextStyleListCtrl)
public:
	inline Object_wx_RichTextStyleListCtrl(wxRichTextStyleListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_RichTextStyleListCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextStyleListCtrl(Class *pClass, wxRichTextStyleListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextStyleListCtrl();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextStyleListCtrl *GetEntity() {
		return dynamic_cast<wxRichTextStyleListCtrl *>(_pEntity);
	}
	inline wxRichTextStyleListCtrl *ReleaseEntity() {
		wxRichTextStyleListCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextStyleListCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
