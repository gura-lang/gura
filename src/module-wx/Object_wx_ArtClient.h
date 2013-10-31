//----------------------------------------------------------------------------
// wxArtClient
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ARTCLIENT_H__
#define __OBJECT_WX_ARTCLIENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxArtClient
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ArtClient);

//----------------------------------------------------------------------------
// Object declaration for wxArtClient
//----------------------------------------------------------------------------
class Object_wx_ArtClient : public Object {
protected:
	wxArtClient *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ArtClient)
public:
	inline Object_wx_ArtClient(wxArtClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ArtClient)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ArtClient(Class *pClass, wxArtClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ArtClient();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxArtClient *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxArtClient *GetEntity() { return _pEntity; }
	inline wxArtClient *ReleaseEntity() {
		wxArtClient *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxArtClient");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
