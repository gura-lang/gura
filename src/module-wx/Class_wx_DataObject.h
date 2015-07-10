//----------------------------------------------------------------------------
// wxDataObject
// extracted from dataobj.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAOBJECT_H__
#define __CLASS_WX_DATAOBJECT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataObject);

//----------------------------------------------------------------------------
// Object declaration for wxDataObject
//----------------------------------------------------------------------------
class Object_wx_DataObject : public Object {
protected:
	wxDataObject *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DataObject)
public:
	inline Object_wx_DataObject(wxDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DataObject)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataObject(Class *pClass, wxDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDataObject *GetEntity() { return _pEntity; }
	inline wxDataObject *ReleaseEntity() {
		wxDataObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
