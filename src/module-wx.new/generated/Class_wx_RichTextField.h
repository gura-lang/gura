//----------------------------------------------------------------------------
// wxRichTextField
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTFIELD_H__
#define __CLASS_WX_RICHTEXTFIELD_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextField
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextField);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextField
//----------------------------------------------------------------------------
class Object_wx_RichTextField : public Object_wx_RichTextParagraphLayoutBox {
public:
	Gura_DeclareObjectAccessor(wx_RichTextField)
public:
	inline Object_wx_RichTextField(wxRichTextField *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphLayoutBox(Gura_UserClass(wx_RichTextField), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextField(Class *pClass, wxRichTextField *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphLayoutBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextField();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextField *GetEntity() {
		return static_cast<wxRichTextField *>(_pEntity);
	}
	inline wxRichTextField *ReleaseEntity() {
		wxRichTextField *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextField");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
