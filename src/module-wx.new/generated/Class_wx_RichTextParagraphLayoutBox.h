//----------------------------------------------------------------------------
// wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTPARAGRAPHLAYOUTBOX_H__
#define __CLASS_WX_RICHTEXTPARAGRAPHLAYOUTBOX_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextParagraphLayoutBox);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
class Object_wx_RichTextParagraphLayoutBox : public Object_wx_RichTextCompositeObject {
public:
	Gura_DeclareObjectAccessor(wx_RichTextParagraphLayoutBox)
public:
	inline Object_wx_RichTextParagraphLayoutBox(wxRichTextParagraphLayoutBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextCompositeObject(Gura_UserClass(wx_RichTextParagraphLayoutBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextParagraphLayoutBox(Class *pClass, wxRichTextParagraphLayoutBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextCompositeObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextParagraphLayoutBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextParagraphLayoutBox *GetEntity() {
		return static_cast<wxRichTextParagraphLayoutBox *>(_pEntity);
	}
	inline wxRichTextParagraphLayoutBox *ReleaseEntity() {
		wxRichTextParagraphLayoutBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextParagraphLayoutBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
