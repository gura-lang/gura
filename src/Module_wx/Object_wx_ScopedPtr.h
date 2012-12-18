//----------------------------------------------------------------------------
// wxScopedPtr
// extracted from scpdptr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SCOPEDPTR_H__
#define __OBJECT_WX_SCOPEDPTR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScopedPtr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScopedPtr);

//----------------------------------------------------------------------------
// Object declaration for wxScopedPtr
//----------------------------------------------------------------------------
class Object_wx_ScopedPtr : public Object {
protected:
	wxScopedPtr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ScopedPtr)
public:
	inline Object_wx_ScopedPtr(wxScopedPtr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ScopedPtr)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ScopedPtr(Class *pClass, wxScopedPtr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ScopedPtr();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxScopedPtr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxScopedPtr *GetEntity() { return _pEntity; }
	inline wxScopedPtr *ReleaseEntity() {
		wxScopedPtr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxScopedPtr");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
