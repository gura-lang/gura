//----------------------------------------------------------------------------
// wxComboPopup
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COMBOPOPUP_H__
#define __CLASS_WX_COMBOPOPUP_H__
#include <wx/combo.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxComboPopup
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ComboPopup);

//----------------------------------------------------------------------------
// Object declaration for wxComboPopup
//----------------------------------------------------------------------------
class Object_wx_ComboPopup : public Object {
protected:
	wxComboPopup *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ComboPopup)
public:
	inline Object_wx_ComboPopup(wxComboPopup *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ComboPopup(Class *pClass, wxComboPopup *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ComboPopup();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxComboPopup *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxComboPopup *GetEntity() {
		return static_cast<wxComboPopup *>(_pEntity);
	}
	inline wxComboPopup *ReleaseEntity() {
		wxComboPopup *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxComboPopup");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
