//----------------------------------------------------------------------------
// wxAny
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ANY_H__
#define __CLASS_WX_ANY_H__
#include <wx/any.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAny
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Any);

//----------------------------------------------------------------------------
// Object declaration for wxAny
//----------------------------------------------------------------------------
class Object_wx_Any : public Object {
protected:
	wxAny *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Any)
public:
	inline Object_wx_Any(wxAny *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Any(Class *pClass, wxAny *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Any();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAny *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAny *GetEntity() {
		return static_cast<wxAny *>(_pEntity);
	}
	inline wxAny *ReleaseEntity() {
		wxAny *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAny");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
