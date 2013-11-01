//----------------------------------------------------------------------------
// wxSingleInstanceChecker
// extracted from snglinst.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SINGLEINSTANCECHECKER_H__
#define __CLASS_WX_SINGLEINSTANCECHECKER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SingleInstanceChecker);

//----------------------------------------------------------------------------
// Object declaration for wxSingleInstanceChecker
//----------------------------------------------------------------------------
class Object_wx_SingleInstanceChecker : public Object {
protected:
	wxSingleInstanceChecker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SingleInstanceChecker)
public:
	inline Object_wx_SingleInstanceChecker(wxSingleInstanceChecker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_SingleInstanceChecker)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SingleInstanceChecker(Class *pClass, wxSingleInstanceChecker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SingleInstanceChecker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSingleInstanceChecker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxSingleInstanceChecker *GetEntity() { return _pEntity; }
	inline wxSingleInstanceChecker *ReleaseEntity() {
		wxSingleInstanceChecker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSingleInstanceChecker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
