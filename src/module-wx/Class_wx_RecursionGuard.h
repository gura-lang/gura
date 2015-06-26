//----------------------------------------------------------------------------
// wxRecursionGuard
// extracted from recguard.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RECURSIONGUARD_H__
#define __CLASS_WX_RECURSIONGUARD_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RecursionGuard);

//----------------------------------------------------------------------------
// Object declaration for wxRecursionGuard
//----------------------------------------------------------------------------
class Object_wx_RecursionGuard : public Object {
protected:
	wxRecursionGuard *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RecursionGuard)
public:
	inline Object_wx_RecursionGuard(wxRecursionGuard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RecursionGuard)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RecursionGuard(Class *pClass, wxRecursionGuard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RecursionGuard();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRecursionGuard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRecursionGuard *GetEntity() { return _pEntity; }
	inline wxRecursionGuard *ReleaseEntity() {
		wxRecursionGuard *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRecursionGuard");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
