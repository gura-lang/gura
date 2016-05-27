//----------------------------------------------------------------------------
// wxProtocolLog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROTOCOLLOG_H__
#define __CLASS_WX_PROTOCOLLOG_H__
#include <wx/protocol/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxProtocolLog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ProtocolLog);

//----------------------------------------------------------------------------
// Object declaration for wxProtocolLog
//----------------------------------------------------------------------------
class Object_wx_ProtocolLog : public Object {
protected:
	wxProtocolLog *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ProtocolLog)
public:
	inline Object_wx_ProtocolLog(wxProtocolLog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ProtocolLog(Class *pClass, wxProtocolLog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ProtocolLog();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxProtocolLog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxProtocolLog *GetEntity() {
		return static_cast<wxProtocolLog *>(_pEntity);
	}
	inline wxProtocolLog *ReleaseEntity() {
		wxProtocolLog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxProtocolLog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
