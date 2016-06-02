//----------------------------------------------------------------------------
// wxRealPoint
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REALPOINT_H__
#define __CLASS_WX_REALPOINT_H__
#include <wx/gdicmn.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRealPoint
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RealPoint);

//----------------------------------------------------------------------------
// Object declaration for wxRealPoint
//----------------------------------------------------------------------------
class Object_wx_RealPoint : public Object {
protected:
	wxRealPoint *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RealPoint)
public:
	inline Object_wx_RealPoint(wxRealPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RealPoint(Class *pClass, wxRealPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RealPoint();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRealPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRealPoint *GetEntity() {
		return static_cast<wxRealPoint *>(_pEntity);
	}
	inline wxRealPoint *ReleaseEntity() {
		wxRealPoint *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRealPoint");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
