//----------------------------------------------------------------------------
// wxPropagateOnce
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPAGATEONCE_H__
#define __CLASS_WX_PROPAGATEONCE_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropagateOnce
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropagateOnce);

//----------------------------------------------------------------------------
// Object declaration for wxPropagateOnce
//----------------------------------------------------------------------------
class Object_wx_PropagateOnce : public Object {
protected:
	wxPropagateOnce *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PropagateOnce)
public:
	inline Object_wx_PropagateOnce(wxPropagateOnce *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PropagateOnce(Class *pClass, wxPropagateOnce *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PropagateOnce();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPropagateOnce *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPropagateOnce *GetEntity() {
		return static_cast<wxPropagateOnce *>(_pEntity);
	}
	inline wxPropagateOnce *ReleaseEntity() {
		wxPropagateOnce *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPropagateOnce");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
