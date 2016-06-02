//----------------------------------------------------------------------------
// wxRichTextPlainText
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTPLAINTEXT_H__
#define __CLASS_WX_RICHTEXTPLAINTEXT_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextPlainText
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextPlainText);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextPlainText
//----------------------------------------------------------------------------
class Object_wx_RichTextPlainText : public Object_wx_RichTextObject {
public:
	Gura_DeclareObjectAccessor(wx_RichTextPlainText)
public:
	inline Object_wx_RichTextPlainText(wxRichTextPlainText *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextObject(Gura_UserClass(wx_RichTextPlainText), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextPlainText(Class *pClass, wxRichTextPlainText *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextPlainText();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextPlainText *GetEntity() {
		return static_cast<wxRichTextPlainText *>(_pEntity);
	}
	inline wxRichTextPlainText *ReleaseEntity() {
		wxRichTextPlainText *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextPlainText");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
