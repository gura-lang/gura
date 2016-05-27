//----------------------------------------------------------------------------
// wxAuiToolBarArt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUITOOLBARART_H__
#define __CLASS_WX_AUITOOLBARART_H__
#include <wx/aui/auibar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiToolBarArt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiToolBarArt);

//----------------------------------------------------------------------------
// Object declaration for wxAuiToolBarArt
//----------------------------------------------------------------------------
class Object_wx_AuiToolBarArt : public Object {
protected:
	wxAuiToolBarArt *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AuiToolBarArt)
public:
	inline Object_wx_AuiToolBarArt(wxAuiToolBarArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AuiToolBarArt(Class *pClass, wxAuiToolBarArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AuiToolBarArt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAuiToolBarArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAuiToolBarArt *GetEntity() {
		return static_cast<wxAuiToolBarArt *>(_pEntity);
	}
	inline wxAuiToolBarArt *ReleaseEntity() {
		wxAuiToolBarArt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiToolBarArt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
