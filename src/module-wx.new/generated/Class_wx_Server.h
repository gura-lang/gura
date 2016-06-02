//----------------------------------------------------------------------------
// wxServer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SERVER_H__
#define __CLASS_WX_SERVER_H__
#include <wx/ipc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxServer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Server);

//----------------------------------------------------------------------------
// Object declaration for wxServer
//----------------------------------------------------------------------------
class Object_wx_Server : public Object {
protected:
	wxServer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Server)
public:
	inline Object_wx_Server(wxServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Server(Class *pClass, wxServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Server();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxServer *GetEntity() {
		return static_cast<wxServer *>(_pEntity);
	}
	inline wxServer *ReleaseEntity() {
		wxServer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxServer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
