//----------------------------------------------------------------------------
// wxDDEServer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DDESERVER_H__
#define __CLASS_WX_DDESERVER_H__
#include <wx/dde.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDDEServer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DDEServer);

//----------------------------------------------------------------------------
// Object declaration for wxDDEServer
//----------------------------------------------------------------------------
class Object_wx_DDEServer : public Object {
protected:
	wxDDEServer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DDEServer)
public:
	inline Object_wx_DDEServer(wxDDEServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DDEServer(Class *pClass, wxDDEServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DDEServer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDDEServer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDDEServer *GetEntity() {
		return static_cast<wxDDEServer *>(_pEntity);
	}
	inline wxDDEServer *ReleaseEntity() {
		wxDDEServer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDDEServer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
