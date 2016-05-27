//----------------------------------------------------------------------------
// wxAuiDockArt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUIDOCKART_H__
#define __CLASS_WX_AUIDOCKART_H__
#include <wx/aui/dockart.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiDockArt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiDockArt);

//----------------------------------------------------------------------------
// Object declaration for wxAuiDockArt
//----------------------------------------------------------------------------
class Object_wx_AuiDockArt : public Object {
protected:
	wxAuiDockArt *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AuiDockArt)
public:
	inline Object_wx_AuiDockArt(wxAuiDockArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AuiDockArt(Class *pClass, wxAuiDockArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AuiDockArt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAuiDockArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAuiDockArt *GetEntity() {
		return static_cast<wxAuiDockArt *>(_pEntity);
	}
	inline wxAuiDockArt *ReleaseEntity() {
		wxAuiDockArt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiDockArt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
