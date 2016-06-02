//----------------------------------------------------------------------------
// wxRichTextImage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTIMAGE_H__
#define __CLASS_WX_RICHTEXTIMAGE_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextImage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextImage);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextImage
//----------------------------------------------------------------------------
class Object_wx_RichTextImage : public Object_wx_RichTextObject {
public:
	Gura_DeclareObjectAccessor(wx_RichTextImage)
public:
	inline Object_wx_RichTextImage(wxRichTextImage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextObject(Gura_UserClass(wx_RichTextImage), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextImage(Class *pClass, wxRichTextImage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextImage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextImage *GetEntity() {
		return static_cast<wxRichTextImage *>(_pEntity);
	}
	inline wxRichTextImage *ReleaseEntity() {
		wxRichTextImage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextImage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
