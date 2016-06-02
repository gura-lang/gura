//----------------------------------------------------------------------------
// wxRichTextImageBlock
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTIMAGEBLOCK_H__
#define __CLASS_WX_RICHTEXTIMAGEBLOCK_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextImageBlock
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextImageBlock);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextImageBlock
//----------------------------------------------------------------------------
class Object_wx_RichTextImageBlock : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextImageBlock)
public:
	inline Object_wx_RichTextImageBlock(wxRichTextImageBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextImageBlock), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextImageBlock(Class *pClass, wxRichTextImageBlock *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextImageBlock();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextImageBlock *GetEntity() {
		return static_cast<wxRichTextImageBlock *>(_pEntity);
	}
	inline wxRichTextImageBlock *ReleaseEntity() {
		wxRichTextImageBlock *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextImageBlock");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
