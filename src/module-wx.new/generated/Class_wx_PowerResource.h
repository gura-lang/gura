//----------------------------------------------------------------------------
// wxPowerResource
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POWERRESOURCE_H__
#define __CLASS_WX_POWERRESOURCE_H__
#include <wx/power.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPowerResource
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PowerResource);

//----------------------------------------------------------------------------
// Object declaration for wxPowerResource
//----------------------------------------------------------------------------
class Object_wx_PowerResource : public Object {
protected:
	wxPowerResource *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PowerResource)
public:
	inline Object_wx_PowerResource(wxPowerResource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PowerResource(Class *pClass, wxPowerResource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PowerResource();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPowerResource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPowerResource *GetEntity() {
		return static_cast<wxPowerResource *>(_pEntity);
	}
	inline wxPowerResource *ReleaseEntity() {
		wxPowerResource *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPowerResource");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
