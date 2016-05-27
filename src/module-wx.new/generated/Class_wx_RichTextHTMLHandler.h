//----------------------------------------------------------------------------
// wxRichTextHTMLHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTHTMLHANDLER_H__
#define __CLASS_WX_RICHTEXTHTMLHANDLER_H__
#include <wx/richtext/richtexthtml.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextHTMLHandler);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
class Object_wx_RichTextHTMLHandler : public Object_wx_RichTextFileHandler {
public:
	Gura_DeclareObjectAccessor(wx_RichTextHTMLHandler)
public:
	inline Object_wx_RichTextHTMLHandler(wxRichTextHTMLHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFileHandler(Gura_UserClass(wx_RichTextHTMLHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextHTMLHandler(Class *pClass, wxRichTextHTMLHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFileHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextHTMLHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextHTMLHandler *GetEntity() {
		return static_cast<wxRichTextHTMLHandler *>(_pEntity);
	}
	inline wxRichTextHTMLHandler *ReleaseEntity() {
		wxRichTextHTMLHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextHTMLHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
