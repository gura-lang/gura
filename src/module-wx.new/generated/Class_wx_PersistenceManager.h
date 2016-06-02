//----------------------------------------------------------------------------
// wxPersistenceManager
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PERSISTENCEMANAGER_H__
#define __CLASS_WX_PERSISTENCEMANAGER_H__
#include <wx/persist.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPersistenceManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PersistenceManager);

//----------------------------------------------------------------------------
// Object declaration for wxPersistenceManager
//----------------------------------------------------------------------------
class Object_wx_PersistenceManager : public Object {
protected:
	wxPersistenceManager *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PersistenceManager)
public:
	inline Object_wx_PersistenceManager(wxPersistenceManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PersistenceManager(Class *pClass, wxPersistenceManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PersistenceManager();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPersistenceManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPersistenceManager *GetEntity() {
		return static_cast<wxPersistenceManager *>(_pEntity);
	}
	inline wxPersistenceManager *ReleaseEntity() {
		wxPersistenceManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPersistenceManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
