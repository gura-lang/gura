//----------------------------------------------------------------------------
// wxScopedArray
// extracted from scpdarry.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SCOPEDARRAY_H__
#define __OBJECT_WX_SCOPEDARRAY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScopedArray
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScopedArray);

//----------------------------------------------------------------------------
// Object declaration for wxScopedArray
//----------------------------------------------------------------------------
class Object_wx_ScopedArray : public Object {
protected:
	wxScopedArray *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ScopedArray)
public:
	inline Object_wx_ScopedArray(wxScopedArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ScopedArray)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ScopedArray(Class *pClass, wxScopedArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ScopedArray();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxScopedArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxScopedArray *GetEntity() { return _pEntity; }
	inline wxScopedArray *ReleaseEntity() {
		wxScopedArray *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxScopedArray");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
