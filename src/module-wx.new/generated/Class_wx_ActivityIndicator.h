//----------------------------------------------------------------------------
// wxActivityIndicator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ACTIVITYINDICATOR_H__
#define __CLASS_WX_ACTIVITYINDICATOR_H__
#include <wx/activityindicator.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxActivityIndicator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ActivityIndicator);

//----------------------------------------------------------------------------
// Object declaration for wxActivityIndicator
//----------------------------------------------------------------------------
class Object_wx_ActivityIndicator : public Object {
protected:
	wxActivityIndicator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ActivityIndicator)
public:
	inline Object_wx_ActivityIndicator(wxActivityIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ActivityIndicator(Class *pClass, wxActivityIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ActivityIndicator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxActivityIndicator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxActivityIndicator *GetEntity() {
		return static_cast<wxActivityIndicator *>(_pEntity);
	}
	inline wxActivityIndicator *ReleaseEntity() {
		wxActivityIndicator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxActivityIndicator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
