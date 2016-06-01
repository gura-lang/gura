//----------------------------------------------------------------------------
// wxAddRemoveCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ADDREMOVECTRL_H__
#define __CLASS_WX_ADDREMOVECTRL_H__
#include <wx/addremovectrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AddRemoveCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxAddRemoveCtrl
//----------------------------------------------------------------------------
class Object_wx_AddRemoveCtrl : public Object {
protected:
	wxAddRemoveCtrl *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AddRemoveCtrl)
public:
	inline Object_wx_AddRemoveCtrl(wxAddRemoveCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AddRemoveCtrl(Class *pClass, wxAddRemoveCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AddRemoveCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAddRemoveCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAddRemoveCtrl *GetEntity() {
		return static_cast<wxAddRemoveCtrl *>(_pEntity);
	}
	inline wxAddRemoveCtrl *ReleaseEntity() {
		wxAddRemoveCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAddRemoveCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
