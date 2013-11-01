//----------------------------------------------------------------------------
// wxRichTextRange
// extracted from richtextrange.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTRANGE_H__
#define __OBJECT_WX_RICHTEXTRANGE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextRange
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextRange);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextRange
//----------------------------------------------------------------------------
class Object_wx_RichTextRange : public Object {
protected:
	wxRichTextRange *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextRange)
public:
	inline Object_wx_RichTextRange(wxRichTextRange *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RichTextRange)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextRange(Class *pClass, wxRichTextRange *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextRange();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextRange *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRichTextRange *GetEntity() { return _pEntity; }
	inline wxRichTextRange *ReleaseEntity() {
		wxRichTextRange *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextRange");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
