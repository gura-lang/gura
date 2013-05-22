//----------------------------------------------------------------------------
// wxRichTextBuffer
// extracted from richtextbuffer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTBUFFER_H__
#define __OBJECT_WX_RICHTEXTBUFFER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextBuffer
//----------------------------------------------------------------------------
class Object_wx_RichTextBuffer : public Object_wx_RichTextParagraphLayoutBox {
public:
	Gura_DeclareObjectAccessor(wx_RichTextBuffer)
public:
	inline Object_wx_RichTextBuffer(wxRichTextBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphLayoutBox(Gura_UserClass(wx_RichTextBuffer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RichTextBuffer(Class *pClass, wxRichTextBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RichTextParagraphLayoutBox(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RichTextBuffer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRichTextBuffer *GetEntity() {
		return dynamic_cast<wxRichTextBuffer *>(_pEntity);
	}
	inline wxRichTextBuffer *ReleaseEntity() {
		wxRichTextBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextBuffer");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
