//----------------------------------------------------------------------------
// wxRichTextFileHandler
// extracted from richtextfilehandler.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTFILEHANDLER_H__
#define __CLASS_WX_RICHTEXTFILEHANDLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextFileHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextFileHandler);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextFileHandler
//----------------------------------------------------------------------------
class Object_wx_RichTextFileHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_RichTextFileHandler)
public:
	inline Object_wx_RichTextFileHandler(wxRichTextFileHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_RichTextFileHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextFileHandler(Class *pClass, wxRichTextFileHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextFileHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRichTextFileHandler *GetEntity() {
		return dynamic_cast<wxRichTextFileHandler *>(_pEntity);
	}
	inline wxRichTextFileHandler *ReleaseEntity() {
		wxRichTextFileHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextFileHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
