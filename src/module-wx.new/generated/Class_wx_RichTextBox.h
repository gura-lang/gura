//----------------------------------------------------------------------------
// wxRichTextBox
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTBOX_H__
#define __CLASS_WX_RICHTEXTBOX_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextBox);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextBox
//----------------------------------------------------------------------------
class Object_wx_RichTextBox : public Object_wx_RichTextParagraphLayoutBox {
public:
	Gura_DeclareObjectAccessor(wx_RichTextBox)
public:
	inline Object_wx_RichTextBox(wxRichTextBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphLayoutBox(Gura_UserClass(wx_RichTextBox), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextBox(Class *pClass, wxRichTextBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphLayoutBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextBox();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextBox *GetEntity() {
		return static_cast<wxRichTextBox *>(_pEntity);
	}
	inline wxRichTextBox *ReleaseEntity() {
		wxRichTextBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextBox");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
