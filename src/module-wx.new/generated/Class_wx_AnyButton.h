//----------------------------------------------------------------------------
// wxAnyButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ANYBUTTON_H__
#define __CLASS_WX_ANYBUTTON_H__
#include <wx/anybutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAnyButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AnyButton);

//----------------------------------------------------------------------------
// Object declaration for wxAnyButton
//----------------------------------------------------------------------------
class Object_wx_AnyButton : public Object {
protected:
	wxAnyButton *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AnyButton)
public:
	inline Object_wx_AnyButton(wxAnyButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AnyButton(Class *pClass, wxAnyButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AnyButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAnyButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAnyButton *GetEntity() {
		return static_cast<wxAnyButton *>(_pEntity);
	}
	inline wxAnyButton *ReleaseEntity() {
		wxAnyButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAnyButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
