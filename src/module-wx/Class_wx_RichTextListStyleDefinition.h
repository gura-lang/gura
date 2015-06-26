//----------------------------------------------------------------------------
// wxRichTextListStyleDefinition
// extracted from richtextliststyledefinition.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTLISTSTYLEDEFINITION_H__
#define __CLASS_WX_RICHTEXTLISTSTYLEDEFINITION_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextListStyleDefinition);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
class Object_wx_RichTextListStyleDefinition : public Object_wx_RichTextParagraphStyleDefinition {
public:
	Gura_DeclareObjectAccessor(wx_RichTextListStyleDefinition)
public:
	inline Object_wx_RichTextListStyleDefinition(wxRichTextListStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphStyleDefinition(Gura_UserClass(wx_RichTextListStyleDefinition), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextListStyleDefinition(Class *pClass, wxRichTextListStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphStyleDefinition(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextListStyleDefinition();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextListStyleDefinition *GetEntity() {
		return dynamic_cast<wxRichTextListStyleDefinition *>(_pEntity);
	}
	inline wxRichTextListStyleDefinition *ReleaseEntity() {
		wxRichTextListStyleDefinition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextListStyleDefinition");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
