//----------------------------------------------------------------------------
// wxRichTextXMLHandler
// extracted from richtextxmlhandler.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTXMLHANDLER_H__
#define __OBJECT_WX_RICHTEXTXMLHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextXMLHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextXMLHandler);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextXMLHandler
//----------------------------------------------------------------------------
class Object_wx_RichTextXMLHandler : public Object_wx_RichTextFileHandler {
public:
	Gura_DeclareObjectAccessor(wx_RichTextXMLHandler)
public:
	inline Object_wx_RichTextXMLHandler(wxRichTextXMLHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFileHandler(Gura_UserClass(wx_RichTextXMLHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextXMLHandler(Class *pClass, wxRichTextXMLHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextFileHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextXMLHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextXMLHandler *GetEntity() {
		return dynamic_cast<wxRichTextXMLHandler *>(_pEntity);
	}
	inline wxRichTextXMLHandler *ReleaseEntity() {
		wxRichTextXMLHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextXMLHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
