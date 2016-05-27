//----------------------------------------------------------------------------
// wxLogNull
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGNULL_H__
#define __CLASS_WX_LOGNULL_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogNull
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogNull);

//----------------------------------------------------------------------------
// Object declaration for wxLogNull
//----------------------------------------------------------------------------
class Object_wx_LogNull : public Object {
protected:
	wxLogNull *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_LogNull)
public:
	inline Object_wx_LogNull(wxLogNull *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_LogNull(Class *pClass, wxLogNull *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_LogNull();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxLogNull *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxLogNull *GetEntity() {
		return static_cast<wxLogNull *>(_pEntity);
	}
	inline wxLogNull *ReleaseEntity() {
		wxLogNull *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLogNull");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
