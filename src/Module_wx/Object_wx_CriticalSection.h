//----------------------------------------------------------------------------
// wxCriticalSection
// extracted from critsect.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CRITICALSECTION_H__
#define __OBJECT_WX_CRITICALSECTION_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCriticalSection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CriticalSection);

//----------------------------------------------------------------------------
// Object declaration for wxCriticalSection
//----------------------------------------------------------------------------
class Object_wx_CriticalSection : public Object {
protected:
	wxCriticalSection *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CriticalSection)
public:
	inline Object_wx_CriticalSection(wxCriticalSection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_CriticalSection)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CriticalSection(Class *pClass, wxCriticalSection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CriticalSection();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxCriticalSection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxCriticalSection *GetEntity() { return _pEntity; }
	inline wxCriticalSection *ReleaseEntity() {
		wxCriticalSection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCriticalSection");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
