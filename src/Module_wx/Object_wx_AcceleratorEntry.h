//----------------------------------------------------------------------------
// wxAcceleratorEntry
// extracted from accel.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ACCELERATORENTRY_H__
#define __OBJECT_WX_ACCELERATORENTRY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAcceleratorEntry
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AcceleratorEntry);

//----------------------------------------------------------------------------
// Object declaration for wxAcceleratorEntry
//----------------------------------------------------------------------------
class Object_wx_AcceleratorEntry : public Object {
protected:
	wxAcceleratorEntry *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AcceleratorEntry)
public:
	inline Object_wx_AcceleratorEntry(wxAcceleratorEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AcceleratorEntry)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AcceleratorEntry(Class *pClass, wxAcceleratorEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AcceleratorEntry();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxAcceleratorEntry *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxAcceleratorEntry *GetEntity() { return _pEntity; }
	inline wxAcceleratorEntry *ReleaseEntity() {
		wxAcceleratorEntry *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAcceleratorEntry");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
