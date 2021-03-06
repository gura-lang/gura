//----------------------------------------------------------------------------
// wxWindowUpdateLocker
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOWUPDATELOCKER_H__
#define __CLASS_WX_WINDOWUPDATELOCKER_H__
#include <wx/wupdlock.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WindowUpdateLocker);

//----------------------------------------------------------------------------
// Object declaration for wxWindowUpdateLocker
//----------------------------------------------------------------------------
class Object_wx_WindowUpdateLocker : public Object {
protected:
	wxWindowUpdateLocker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_WindowUpdateLocker)
public:
	inline Object_wx_WindowUpdateLocker(wxWindowUpdateLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_WindowUpdateLocker(Class *pClass, wxWindowUpdateLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_WindowUpdateLocker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxWindowUpdateLocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxWindowUpdateLocker *GetEntity() {
		return static_cast<wxWindowUpdateLocker *>(_pEntity);
	}
	inline wxWindowUpdateLocker *ReleaseEntity() {
		wxWindowUpdateLocker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWindowUpdateLocker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
