//----------------------------------------------------------------------------
// wxRichTextDrawingContext
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTDRAWINGCONTEXT_H__
#define __CLASS_WX_RICHTEXTDRAWINGCONTEXT_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextDrawingContext
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextDrawingContext);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextDrawingContext
//----------------------------------------------------------------------------
class Object_wx_RichTextDrawingContext : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextDrawingContext)
public:
	inline Object_wx_RichTextDrawingContext(wxRichTextDrawingContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextDrawingContext), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextDrawingContext(Class *pClass, wxRichTextDrawingContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextDrawingContext();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextDrawingContext *GetEntity() {
		return static_cast<wxRichTextDrawingContext *>(_pEntity);
	}
	inline wxRichTextDrawingContext *ReleaseEntity() {
		wxRichTextDrawingContext *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextDrawingContext");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
