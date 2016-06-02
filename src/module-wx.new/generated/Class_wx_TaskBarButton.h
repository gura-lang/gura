//----------------------------------------------------------------------------
// wxTaskBarButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TASKBARBUTTON_H__
#define __CLASS_WX_TASKBARBUTTON_H__
#include <wx/taskbarbutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTaskBarButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TaskBarButton);

//----------------------------------------------------------------------------
// Object declaration for wxTaskBarButton
//----------------------------------------------------------------------------
class Object_wx_TaskBarButton : public Object {
protected:
	wxTaskBarButton *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TaskBarButton)
public:
	inline Object_wx_TaskBarButton(wxTaskBarButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TaskBarButton(Class *pClass, wxTaskBarButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TaskBarButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTaskBarButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTaskBarButton *GetEntity() {
		return static_cast<wxTaskBarButton *>(_pEntity);
	}
	inline wxTaskBarButton *ReleaseEntity() {
		wxTaskBarButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTaskBarButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
