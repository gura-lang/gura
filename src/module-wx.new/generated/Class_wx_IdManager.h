//----------------------------------------------------------------------------
// wxIdManager
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_IDMANAGER_H__
#define __CLASS_WX_IDMANAGER_H__
#include <wx/windowid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIdManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IdManager);

//----------------------------------------------------------------------------
// Object declaration for wxIdManager
//----------------------------------------------------------------------------
class Object_wx_IdManager : public Object {
protected:
	wxIdManager *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_IdManager)
public:
	inline Object_wx_IdManager(wxIdManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_IdManager(Class *pClass, wxIdManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_IdManager();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxIdManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxIdManager *GetEntity() {
		return static_cast<wxIdManager *>(_pEntity);
	}
	inline wxIdManager *ReleaseEntity() {
		wxIdManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxIdManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
