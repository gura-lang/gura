//----------------------------------------------------------------------------
// wxDCOverlay
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DCOVERLAY_H__
#define __CLASS_WX_DCOVERLAY_H__
#include <wx/overlay.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDCOverlay
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DCOverlay);

//----------------------------------------------------------------------------
// Object declaration for wxDCOverlay
//----------------------------------------------------------------------------
class Object_wx_DCOverlay : public Object {
protected:
	wxDCOverlay *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DCOverlay)
public:
	inline Object_wx_DCOverlay(wxDCOverlay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DCOverlay(Class *pClass, wxDCOverlay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DCOverlay();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDCOverlay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDCOverlay *GetEntity() {
		return static_cast<wxDCOverlay *>(_pEntity);
	}
	inline wxDCOverlay *ReleaseEntity() {
		wxDCOverlay *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDCOverlay");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
