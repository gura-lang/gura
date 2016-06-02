//----------------------------------------------------------------------------
// wxRichTextParagraph
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTPARAGRAPH_H__
#define __CLASS_WX_RICHTEXTPARAGRAPH_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextParagraph
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextParagraph);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextParagraph
//----------------------------------------------------------------------------
class Object_wx_RichTextParagraph : public Object_wx_RichTextCompositeObject {
public:
	Gura_DeclareObjectAccessor(wx_RichTextParagraph)
public:
	inline Object_wx_RichTextParagraph(wxRichTextParagraph *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextCompositeObject(Gura_UserClass(wx_RichTextParagraph), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextParagraph(Class *pClass, wxRichTextParagraph *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextCompositeObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextParagraph();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextParagraph *GetEntity() {
		return static_cast<wxRichTextParagraph *>(_pEntity);
	}
	inline wxRichTextParagraph *ReleaseEntity() {
		wxRichTextParagraph *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextParagraph");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
