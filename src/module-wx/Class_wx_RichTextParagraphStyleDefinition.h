//----------------------------------------------------------------------------
// wxRichTextParagraphStyleDefinition
// extracted from richtextparagraphstyledefinition.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTPARAGRAPHSTYLEDEFINITION_H__
#define __OBJECT_WX_RICHTEXTPARAGRAPHSTYLEDEFINITION_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextParagraphStyleDefinition);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
class Object_wx_RichTextParagraphStyleDefinition : public Object_wx_RichTextStyleDefinition {
public:
	Gura_DeclareObjectAccessor(wx_RichTextParagraphStyleDefinition)
public:
	inline Object_wx_RichTextParagraphStyleDefinition(wxRichTextParagraphStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextStyleDefinition(Gura_UserClass(wx_RichTextParagraphStyleDefinition), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextParagraphStyleDefinition(Class *pClass, wxRichTextParagraphStyleDefinition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextStyleDefinition(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextParagraphStyleDefinition();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextParagraphStyleDefinition *GetEntity() {
		return dynamic_cast<wxRichTextParagraphStyleDefinition *>(_pEntity);
	}
	inline wxRichTextParagraphStyleDefinition *ReleaseEntity() {
		wxRichTextParagraphStyleDefinition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextParagraphStyleDefinition");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
