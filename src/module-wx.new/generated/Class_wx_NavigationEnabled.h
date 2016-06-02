//----------------------------------------------------------------------------
// wxNavigationEnabled
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NAVIGATIONENABLED_H__
#define __CLASS_WX_NAVIGATIONENABLED_H__
#include <wx/containr.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNavigationEnabled
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NavigationEnabled);

//----------------------------------------------------------------------------
// Object declaration for wxNavigationEnabled
//----------------------------------------------------------------------------
class Object_wx_NavigationEnabled : public Object {
protected:
	wxNavigationEnabled *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_NavigationEnabled)
public:
	inline Object_wx_NavigationEnabled(wxNavigationEnabled *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_NavigationEnabled(Class *pClass, wxNavigationEnabled *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_NavigationEnabled();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxNavigationEnabled *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxNavigationEnabled *GetEntity() {
		return static_cast<wxNavigationEnabled *>(_pEntity);
	}
	inline wxNavigationEnabled *ReleaseEntity() {
		wxNavigationEnabled *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxNavigationEnabled");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
