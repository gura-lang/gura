//----------------------------------------------------------------------------
// wxGBPosition
// extracted from gbposition.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GBPOSITION_H__
#define __OBJECT_WX_GBPOSITION_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGBPosition
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GBPosition);

//----------------------------------------------------------------------------
// Object declaration for wxGBPosition
//----------------------------------------------------------------------------
class Object_wx_GBPosition : public Object {
protected:
	wxGBPosition *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GBPosition)
public:
	inline Object_wx_GBPosition(wxGBPosition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_GBPosition)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GBPosition(Class *pClass, wxGBPosition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GBPosition();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGBPosition *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxGBPosition *GetEntity() { return _pEntity; }
	inline wxGBPosition *ReleaseEntity() {
		wxGBPosition *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGBPosition");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
