//----------------------------------------------------------------------------
// wxClientDataContainer
// extracted from clientdat.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIENTDATACONTAINER_H__
#define __CLASS_WX_CLIENTDATACONTAINER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClientDataContainer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClientDataContainer);

//----------------------------------------------------------------------------
// Object declaration for wxClientDataContainer
//----------------------------------------------------------------------------
class Object_wx_ClientDataContainer : public Object {
protected:
	wxClientDataContainer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ClientDataContainer)
public:
	inline Object_wx_ClientDataContainer(wxClientDataContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ClientDataContainer)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ClientDataContainer(Class *pClass, wxClientDataContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ClientDataContainer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxClientDataContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxClientDataContainer *GetEntity() { return _pEntity; }
	inline wxClientDataContainer *ReleaseEntity() {
		wxClientDataContainer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxClientDataContainer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
