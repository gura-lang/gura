//----------------------------------------------------------------------------
// wxRichTextParagraphLayoutBox
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTPARAGRAPHLAYOUTBOX_H__
#define __OBJECT_WX_RICHTEXTPARAGRAPHLAYOUTBOX_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextParagraphLayoutBox);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
class Object_wx_RichTextParagraphLayoutBox : public Object {
protected:
	wxRichTextParagraphLayoutBox *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextParagraphLayoutBox)
public:
	inline Object_wx_RichTextParagraphLayoutBox(wxRichTextParagraphLayoutBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RichTextParagraphLayoutBox)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextParagraphLayoutBox(Class *pClass, wxRichTextParagraphLayoutBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextParagraphLayoutBox();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxRichTextParagraphLayoutBox *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRichTextParagraphLayoutBox *GetEntity() { return _pEntity; }
	inline wxRichTextParagraphLayoutBox *ReleaseEntity() {
		wxRichTextParagraphLayoutBox *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextParagraphLayoutBox");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
