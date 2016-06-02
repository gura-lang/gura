//----------------------------------------------------------------------------
// wxRichTextDrawingHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTDRAWINGHANDLER_H__
#define __CLASS_WX_RICHTEXTDRAWINGHANDLER_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextDrawingHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextDrawingHandler);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextDrawingHandler
//----------------------------------------------------------------------------
class Object_wx_RichTextDrawingHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextDrawingHandler)
public:
	inline Object_wx_RichTextDrawingHandler(wxRichTextDrawingHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextDrawingHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextDrawingHandler(Class *pClass, wxRichTextDrawingHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextDrawingHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextDrawingHandler *GetEntity() {
		return static_cast<wxRichTextDrawingHandler *>(_pEntity);
	}
	inline wxRichTextDrawingHandler *ReleaseEntity() {
		wxRichTextDrawingHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextDrawingHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
