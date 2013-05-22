//----------------------------------------------------------------------------
// wxRealPoint
// extracted from realpoin.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_REALPOINT_H__
#define __OBJECT_WX_REALPOINT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRealPoint
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RealPoint);

//----------------------------------------------------------------------------
// Object declaration for wxRealPoint
//----------------------------------------------------------------------------
class Object_wx_RealPoint : public Object {
protected:
	wxRealPoint *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RealPoint)
public:
	inline Object_wx_RealPoint(wxRealPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RealPoint)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RealPoint(Class *pClass, wxRealPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RealPoint();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxRealPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRealPoint *GetEntity() { return _pEntity; }
	inline wxRealPoint *ReleaseEntity() {
		wxRealPoint *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRealPoint");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
