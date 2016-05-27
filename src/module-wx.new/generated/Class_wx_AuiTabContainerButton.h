//----------------------------------------------------------------------------
// wxAuiTabContainerButton
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUITABCONTAINERBUTTON_H__
#define __CLASS_WX_AUITABCONTAINERBUTTON_H__
#include <wx/aui/auibook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiTabContainerButton
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiTabContainerButton);

//----------------------------------------------------------------------------
// Object declaration for wxAuiTabContainerButton
//----------------------------------------------------------------------------
class Object_wx_AuiTabContainerButton : public Object {
protected:
	wxAuiTabContainerButton *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AuiTabContainerButton)
public:
	inline Object_wx_AuiTabContainerButton(wxAuiTabContainerButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AuiTabContainerButton(Class *pClass, wxAuiTabContainerButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AuiTabContainerButton();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAuiTabContainerButton *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAuiTabContainerButton *GetEntity() {
		return static_cast<wxAuiTabContainerButton *>(_pEntity);
	}
	inline wxAuiTabContainerButton *ReleaseEntity() {
		wxAuiTabContainerButton *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiTabContainerButton");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
