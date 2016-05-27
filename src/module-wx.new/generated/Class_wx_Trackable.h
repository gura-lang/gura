//----------------------------------------------------------------------------
// wxTrackable
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TRACKABLE_H__
#define __CLASS_WX_TRACKABLE_H__
#include <wx/tracker.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTrackable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Trackable);

//----------------------------------------------------------------------------
// Object declaration for wxTrackable
//----------------------------------------------------------------------------
class Object_wx_Trackable : public Object {
protected:
	wxTrackable *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Trackable)
public:
	inline Object_wx_Trackable(wxTrackable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Trackable(Class *pClass, wxTrackable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Trackable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTrackable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTrackable *GetEntity() {
		return static_cast<wxTrackable *>(_pEntity);
	}
	inline wxTrackable *ReleaseEntity() {
		wxTrackable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTrackable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
