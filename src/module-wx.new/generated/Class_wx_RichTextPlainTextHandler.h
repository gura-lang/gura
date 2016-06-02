//----------------------------------------------------------------------------
// wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTPLAINTEXTHANDLER_H__
#define __CLASS_WX_RICHTEXTPLAINTEXTHANDLER_H__
#include <wx/richtext/richtextbuffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextPlainTextHandler);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
class Object_wx_RichTextPlainTextHandler : public Object_wx_RichTextFileHandler {
public:
	Gura_DeclareObjectAccessor(wx_RichTextPlainTextHandler)
public:
	inline Object_wx_RichTextPlainTextHandler(wxRichTextPlainTextHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFileHandler(Gura_UserClass(wx_RichTextPlainTextHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextPlainTextHandler(Class *pClass, wxRichTextPlainTextHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFileHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextPlainTextHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextPlainTextHandler *GetEntity() {
		return static_cast<wxRichTextPlainTextHandler *>(_pEntity);
	}
	inline wxRichTextPlainTextHandler *ReleaseEntity() {
		wxRichTextPlainTextHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRichTextPlainTextHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
