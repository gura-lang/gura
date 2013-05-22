//----------------------------------------------------------------------------
// wxDir
// extracted from dir.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DIR_H__
#define __OBJECT_WX_DIR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDir
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Dir);

//----------------------------------------------------------------------------
// Object declaration for wxDir
//----------------------------------------------------------------------------
class Object_wx_Dir : public Object {
protected:
	wxDir *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Dir)
public:
	inline Object_wx_Dir(wxDir *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Dir)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Dir(Class *pClass, wxDir *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Dir();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDir *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDir *GetEntity() { return _pEntity; }
	inline wxDir *ReleaseEntity() {
		wxDir *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDir");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
