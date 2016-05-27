//----------------------------------------------------------------------------
// wxModalDialogHook
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MODALDIALOGHOOK_H__
#define __CLASS_WX_MODALDIALOGHOOK_H__
#include <wx/modalhook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxModalDialogHook
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ModalDialogHook);

//----------------------------------------------------------------------------
// Object declaration for wxModalDialogHook
//----------------------------------------------------------------------------
class Object_wx_ModalDialogHook : public Object {
protected:
	wxModalDialogHook *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ModalDialogHook)
public:
	inline Object_wx_ModalDialogHook(wxModalDialogHook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ModalDialogHook(Class *pClass, wxModalDialogHook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ModalDialogHook();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxModalDialogHook *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxModalDialogHook *GetEntity() {
		return static_cast<wxModalDialogHook *>(_pEntity);
	}
	inline wxModalDialogHook *ReleaseEntity() {
		wxModalDialogHook *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxModalDialogHook");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
