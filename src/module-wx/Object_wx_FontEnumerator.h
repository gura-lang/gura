//----------------------------------------------------------------------------
// wxFontEnumerator
// extracted from fontenum.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FONTENUMERATOR_H__
#define __OBJECT_WX_FONTENUMERATOR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFontEnumerator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FontEnumerator);

//----------------------------------------------------------------------------
// Object declaration for wxFontEnumerator
//----------------------------------------------------------------------------
class Object_wx_FontEnumerator : public Object {
protected:
	wxFontEnumerator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_FontEnumerator)
public:
	inline Object_wx_FontEnumerator(wxFontEnumerator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_FontEnumerator)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_FontEnumerator(Class *pClass, wxFontEnumerator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_FontEnumerator();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxFontEnumerator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxFontEnumerator *GetEntity() { return _pEntity; }
	inline wxFontEnumerator *ReleaseEntity() {
		wxFontEnumerator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFontEnumerator");
		return true;
	}
};

}}

#endif
