//----------------------------------------------------------------------------
// wxRichTextStyleListBox
// extracted from richtextstylelistbox.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTSTYLELISTBOX_H__
#define __OBJECT_WX_RICHTEXTSTYLELISTBOX_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextStyleListBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextStyleListBox);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextStyleListBox
//----------------------------------------------------------------------------
class Object_wx_RichTextStyleListBox : public Object_wx_HtmlListBox {
public:
	Gura_DeclareObjectAccessor(wx_RichTextStyleListBox)
public:
	inline Object_wx_RichTextStyleListBox(wxRichTextStyleListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlListBox(Gura_UserClass(wx_RichTextStyleListBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextStyleListBox(Class *pClass, wxRichTextStyleListBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HtmlListBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextStyleListBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextStyleListBox *GetEntity() {
		return dynamic_cast<wxRichTextStyleListBox *>(_pEntity);
	}
	inline wxRichTextStyleListBox *ReleaseEntity() {
		wxRichTextStyleListBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextStyleListBox");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
