//----------------------------------------------------------------------------
// wxMimeTypesManager
// extracted from mimetype.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MIMETYPESMANAGER_H__
#define __OBJECT_WX_MIMETYPESMANAGER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMimeTypesManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MimeTypesManager);

//----------------------------------------------------------------------------
// Object declaration for wxMimeTypesManager
//----------------------------------------------------------------------------
class Object_wx_MimeTypesManager : public Object {
protected:
	wxMimeTypesManager *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MimeTypesManager)
public:
	inline Object_wx_MimeTypesManager(wxMimeTypesManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_MimeTypesManager)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MimeTypesManager(Class *pClass, wxMimeTypesManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MimeTypesManager();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxMimeTypesManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxMimeTypesManager *GetEntity() { return _pEntity; }
	inline wxMimeTypesManager *ReleaseEntity() {
		wxMimeTypesManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMimeTypesManager");
		return true;
	}
};

}}

#endif
