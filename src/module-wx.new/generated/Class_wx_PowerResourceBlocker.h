//----------------------------------------------------------------------------
// wxPowerResourceBlocker
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POWERRESOURCEBLOCKER_H__
#define __CLASS_WX_POWERRESOURCEBLOCKER_H__
#include <wx/power.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPowerResourceBlocker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PowerResourceBlocker);

//----------------------------------------------------------------------------
// Object declaration for wxPowerResourceBlocker
//----------------------------------------------------------------------------
class Object_wx_PowerResourceBlocker : public Object {
protected:
	wxPowerResourceBlocker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PowerResourceBlocker)
public:
	inline Object_wx_PowerResourceBlocker(wxPowerResourceBlocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PowerResourceBlocker(Class *pClass, wxPowerResourceBlocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PowerResourceBlocker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPowerResourceBlocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPowerResourceBlocker *GetEntity() {
		return static_cast<wxPowerResourceBlocker *>(_pEntity);
	}
	inline wxPowerResourceBlocker *ReleaseEntity() {
		wxPowerResourceBlocker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPowerResourceBlocker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
