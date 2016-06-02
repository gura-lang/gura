//----------------------------------------------------------------------------
// wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTPARAGRAPHSTYLEDEFINITION_H__
#define __CLASS_WX_RICHTEXTPARAGRAPHSTYLEDEFINITION_H__
#include <wx/richtext/richtextstyles.h>

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
		return static_cast<wxRichTextParagraphStyleDefinition *>(_pEntity);
	}
	inline wxRichTextParagraphStyleDefinition *ReleaseEntity() {
		wxRichTextParagraphStyleDefinition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextParagraphStyleDefinition");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
