//----------------------------------------------------------------------------
// wxRecursionGuardFlag
// extracted from recguard.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RECURSIONGUARDFLAG_H__
#define __OBJECT_WX_RECURSIONGUARDFLAG_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RecursionGuardFlag);

//----------------------------------------------------------------------------
// Object declaration for wxRecursionGuardFlag
//----------------------------------------------------------------------------
class Object_wx_RecursionGuardFlag : public Object {
protected:
	wxRecursionGuardFlag *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RecursionGuardFlag)
public:
	inline Object_wx_RecursionGuardFlag(wxRecursionGuardFlag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RecursionGuardFlag)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RecursionGuardFlag(Class *pClass, wxRecursionGuardFlag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RecursionGuardFlag();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxRecursionGuardFlag *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRecursionGuardFlag *GetEntity() { return _pEntity; }
	inline wxRecursionGuardFlag *ReleaseEntity() {
		wxRecursionGuardFlag *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRecursionGuardFlag");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
