//----------------------------------------------------------------------------
// wxTextAttr
// extracted from textattr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TEXTATTR_H__
#define __OBJECT_WX_TEXTATTR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextAttr);

//----------------------------------------------------------------------------
// Object declaration for wxTextAttr
//----------------------------------------------------------------------------
class Object_wx_TextAttr : public Object {
protected:
	wxTextAttr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TextAttr)
public:
	inline Object_wx_TextAttr(wxTextAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_TextAttr)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TextAttr(Class *pClass, wxTextAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TextAttr();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxTextAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxTextAttr *GetEntity() { return _pEntity; }
	inline wxTextAttr *ReleaseEntity() {
		wxTextAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTextAttr");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
