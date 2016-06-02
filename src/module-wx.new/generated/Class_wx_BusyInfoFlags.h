//----------------------------------------------------------------------------
// wxBusyInfoFlags
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BUSYINFOFLAGS_H__
#define __CLASS_WX_BUSYINFOFLAGS_H__
#include <wx/busyinfo.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBusyInfoFlags
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BusyInfoFlags);

//----------------------------------------------------------------------------
// Object declaration for wxBusyInfoFlags
//----------------------------------------------------------------------------
class Object_wx_BusyInfoFlags : public Object {
protected:
	wxBusyInfoFlags *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_BusyInfoFlags)
public:
	inline Object_wx_BusyInfoFlags(wxBusyInfoFlags *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_BusyInfoFlags(Class *pClass, wxBusyInfoFlags *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_BusyInfoFlags();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxBusyInfoFlags *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxBusyInfoFlags *GetEntity() {
		return static_cast<wxBusyInfoFlags *>(_pEntity);
	}
	inline wxBusyInfoFlags *ReleaseEntity() {
		wxBusyInfoFlags *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxBusyInfoFlags");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
