//----------------------------------------------------------------------------
// wxLog
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOG_H__
#define __CLASS_WX_LOG_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLog
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Log);

//----------------------------------------------------------------------------
// Object declaration for wxLog
//----------------------------------------------------------------------------
class Object_wx_Log : public Object {
protected:
	wxLog *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Log)
public:
	inline Object_wx_Log(wxLog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Log(Class *pClass, wxLog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Log();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxLog *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxLog *GetEntity() {
		return static_cast<wxLog *>(_pEntity);
	}
	inline wxLog *ReleaseEntity() {
		wxLog *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLog");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
