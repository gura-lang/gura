//----------------------------------------------------------------------------
// wxRichTextObject
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RICHTEXTOBJECT_H__
#define __CLASS_WX_RICHTEXTOBJECT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRichTextObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RichTextObject);

//----------------------------------------------------------------------------
// Object declaration for wxRichTextObject
//----------------------------------------------------------------------------
class Object_wx_RichTextObject : public Object {
protected:
	wxRichTextObject *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RichTextObject)
public:
	inline Object_wx_RichTextObject(wxRichTextObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RichTextObject)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RichTextObject(Class *pClass, wxRichTextObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RichTextObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRichTextObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRichTextObject *GetEntity() { return _pEntity; }
	inline wxRichTextObject *ReleaseEntity() {
		wxRichTextObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRichTextObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
