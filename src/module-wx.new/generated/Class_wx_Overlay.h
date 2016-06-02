//----------------------------------------------------------------------------
// wxOverlay
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_OVERLAY_H__
#define __CLASS_WX_OVERLAY_H__
#include <wx/overlay.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxOverlay
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Overlay);

//----------------------------------------------------------------------------
// Object declaration for wxOverlay
//----------------------------------------------------------------------------
class Object_wx_Overlay : public Object {
protected:
	wxOverlay *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Overlay)
public:
	inline Object_wx_Overlay(wxOverlay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Overlay(Class *pClass, wxOverlay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Overlay();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxOverlay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxOverlay *GetEntity() {
		return static_cast<wxOverlay *>(_pEntity);
	}
	inline wxOverlay *ReleaseEntity() {
		wxOverlay *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxOverlay");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
