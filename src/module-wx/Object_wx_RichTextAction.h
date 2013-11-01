//----------------------------------------------------------------------------
// wxRichTextAction
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RICHTEXTACTION_H__
#define __OBJECT_WX_RICHTEXTACTION_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextAction
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextAction);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextAction
//----------------------------------------------------------------------------
class Object_wx_RichTextAction : public Object {
protected:
	wxRichTextAction *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextAction)
public:
	inline Object_wx_RichTextAction(wxRichTextAction *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RichTextAction)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextAction(Class *pClass, wxRichTextAction *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextAction();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextAction *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRichTextAction *GetEntity() { return _pEntity; }
	inline wxRichTextAction *ReleaseEntity() {
		wxRichTextAction *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRichTextAction");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
