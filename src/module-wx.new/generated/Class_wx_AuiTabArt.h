//----------------------------------------------------------------------------
// wxAuiTabArt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUITABART_H__
#define __CLASS_WX_AUITABART_H__
#include <wx/aui/auibook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiTabArt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiTabArt);

//----------------------------------------------------------------------------
// Object declaration for wxAuiTabArt
//----------------------------------------------------------------------------
class Object_wx_AuiTabArt : public Object {
protected:
	wxAuiTabArt *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AuiTabArt)
public:
	inline Object_wx_AuiTabArt(wxAuiTabArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AuiTabArt(Class *pClass, wxAuiTabArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AuiTabArt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAuiTabArt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAuiTabArt *GetEntity() {
		return static_cast<wxAuiTabArt *>(_pEntity);
	}
	inline wxAuiTabArt *ReleaseEntity() {
		wxAuiTabArt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiTabArt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
