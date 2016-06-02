//----------------------------------------------------------------------------
// wxCustomBackgroundWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CUSTOMBACKGROUNDWINDOW_H__
#define __CLASS_WX_CUSTOMBACKGROUNDWINDOW_H__
#include <wx/custombgwin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCustomBackgroundWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CustomBackgroundWindow);

//----------------------------------------------------------------------------
// Object declaration for wxCustomBackgroundWindow
//----------------------------------------------------------------------------
class Object_wx_CustomBackgroundWindow : public Object {
protected:
	wxCustomBackgroundWindow *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CustomBackgroundWindow)
public:
	inline Object_wx_CustomBackgroundWindow(wxCustomBackgroundWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CustomBackgroundWindow(Class *pClass, wxCustomBackgroundWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CustomBackgroundWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCustomBackgroundWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxCustomBackgroundWindow *GetEntity() {
		return static_cast<wxCustomBackgroundWindow *>(_pEntity);
	}
	inline wxCustomBackgroundWindow *ReleaseEntity() {
		wxCustomBackgroundWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCustomBackgroundWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
