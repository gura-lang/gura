//----------------------------------------------------------------------------
// wxComboPopup
// extracted from combopopup.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_COMBOPOPUP_H__
#define __CLASS_WX_COMBOPOPUP_H__

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
				Object(Gura_UserClass(wx_ComboPopup)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ComboPopup(Class *pClass, wxComboPopup *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ComboPopup();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxComboPopup *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxComboPopup *GetEntity() { return _pEntity; }
	inline wxComboPopup *ReleaseEntity() {
		wxComboPopup *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxComboPopup");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
