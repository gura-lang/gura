//----------------------------------------------------------------------------
// wxRichTextStdRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTSTDRENDERER_H__
#define __CLASS_WX_RICHTEXTSTDRENDERER_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextStdRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextStdRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextStdRenderer
//----------------------------------------------------------------------------
class Object_wx_RichTextStdRenderer : public Object_wx_RichTextRenderer {
public:
	Gura_DeclareObjectAccessor(wx_RichTextStdRenderer)
public:
	inline Object_wx_RichTextStdRenderer(wxRichTextStdRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextRenderer(Gura_UserClass(wx_RichTextStdRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextStdRenderer(Class *pClass, wxRichTextStdRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextStdRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextStdRenderer *GetEntity() {
		return static_cast<wxRichTextStdRenderer *>(_pEntity);
	}
	inline wxRichTextStdRenderer *ReleaseEntity() {
		wxRichTextStdRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextStdRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
