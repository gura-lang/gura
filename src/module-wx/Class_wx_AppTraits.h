//----------------------------------------------------------------------------
// wxAppTraits
// extracted from apptraits.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_APPTRAITS_H__
#define __OBJECT_WX_APPTRAITS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAppTraits
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AppTraits);

//----------------------------------------------------------------------------
// Object declaration for wxAppTraits
//----------------------------------------------------------------------------
class Object_wx_AppTraits : public Object {
protected:
	wxAppTraits *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AppTraits)
public:
	inline Object_wx_AppTraits(wxAppTraits *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AppTraits)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AppTraits(Class *pClass, wxAppTraits *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AppTraits();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAppTraits *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxAppTraits *GetEntity() { return _pEntity; }
	inline wxAppTraits *ReleaseEntity() {
		wxAppTraits *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAppTraits");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
