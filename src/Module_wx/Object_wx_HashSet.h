//----------------------------------------------------------------------------
// wxHashSet
// extracted from hashset.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HASHSET_H__
#define __OBJECT_WX_HASHSET_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHashSet
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HashSet);

//----------------------------------------------------------------------------
// Object declaration for wxHashSet
//----------------------------------------------------------------------------
class Object_wx_HashSet : public Object {
protected:
	wxHashSet *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HashSet)
public:
	inline Object_wx_HashSet(wxHashSet *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_HashSet)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HashSet(Class *pClass, wxHashSet *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HashSet();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxHashSet *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxHashSet *GetEntity() { return _pEntity; }
	inline wxHashSet *ReleaseEntity() {
		wxHashSet *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHashSet");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
