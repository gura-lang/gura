//----------------------------------------------------------------------------
// wxPlatformInfo
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PLATFORMINFO_H__
#define __CLASS_WX_PLATFORMINFO_H__
#include <wx/platinfo.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPlatformInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PlatformInfo);

//----------------------------------------------------------------------------
// Object declaration for wxPlatformInfo
//----------------------------------------------------------------------------
class Object_wx_PlatformInfo : public Object {
protected:
	wxPlatformInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PlatformInfo)
public:
	inline Object_wx_PlatformInfo(wxPlatformInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PlatformInfo(Class *pClass, wxPlatformInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PlatformInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPlatformInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPlatformInfo *GetEntity() {
		return static_cast<wxPlatformInfo *>(_pEntity);
	}
	inline wxPlatformInfo *ReleaseEntity() {
		wxPlatformInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPlatformInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
