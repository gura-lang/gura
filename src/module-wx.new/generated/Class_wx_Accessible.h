//----------------------------------------------------------------------------
// wxAccessible
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ACCESSIBLE_H__
#define __CLASS_WX_ACCESSIBLE_H__
#include <wx/access.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAccessible
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Accessible);

//----------------------------------------------------------------------------
// Object declaration for wxAccessible
//----------------------------------------------------------------------------
class Object_wx_Accessible : public Object {
protected:
	wxAccessible *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Accessible)
public:
	inline Object_wx_Accessible(wxAccessible *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Accessible(Class *pClass, wxAccessible *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Accessible();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAccessible *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAccessible *GetEntity() {
		return static_cast<wxAccessible *>(_pEntity);
	}
	inline wxAccessible *ReleaseEntity() {
		wxAccessible *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAccessible");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
