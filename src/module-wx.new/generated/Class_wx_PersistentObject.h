//----------------------------------------------------------------------------
// wxPersistentObject
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PERSISTENTOBJECT_H__
#define __CLASS_WX_PERSISTENTOBJECT_H__
#include <wx/persist.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPersistentObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PersistentObject);

//----------------------------------------------------------------------------
// Object declaration for wxPersistentObject
//----------------------------------------------------------------------------
class Object_wx_PersistentObject : public Object {
protected:
	wxPersistentObject *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PersistentObject)
public:
	inline Object_wx_PersistentObject(wxPersistentObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PersistentObject(Class *pClass, wxPersistentObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PersistentObject();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPersistentObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPersistentObject *GetEntity() {
		return static_cast<wxPersistentObject *>(_pEntity);
	}
	inline wxPersistentObject *ReleaseEntity() {
		wxPersistentObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPersistentObject");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
