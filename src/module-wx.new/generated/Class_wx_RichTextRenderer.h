//----------------------------------------------------------------------------
// wxRichTextRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTRENDERER_H__
#define __CLASS_WX_RICHTEXTRENDERER_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextRenderer
//----------------------------------------------------------------------------
class Object_wx_RichTextRenderer : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextRenderer)
public:
	inline Object_wx_RichTextRenderer(wxRichTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextRenderer(Class *pClass, wxRichTextRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextRenderer *GetEntity() {
		return static_cast<wxRichTextRenderer *>(_pEntity);
	}
	inline wxRichTextRenderer *ReleaseEntity() {
		wxRichTextRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
