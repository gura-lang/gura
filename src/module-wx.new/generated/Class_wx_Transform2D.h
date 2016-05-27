//----------------------------------------------------------------------------
// wxTransform2D
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TRANSFORM2D_H__
#define __CLASS_WX_TRANSFORM2D_H__
#include <wx/geometry.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTransform2D
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Transform2D);

//----------------------------------------------------------------------------
// Object declaration for wxTransform2D
//----------------------------------------------------------------------------
class Object_wx_Transform2D : public Object {
protected:
	wxTransform2D *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Transform2D)
public:
	inline Object_wx_Transform2D(wxTransform2D *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Transform2D(Class *pClass, wxTransform2D *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Transform2D();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTransform2D *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTransform2D *GetEntity() {
		return static_cast<wxTransform2D *>(_pEntity);
	}
	inline wxTransform2D *ReleaseEntity() {
		wxTransform2D *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTransform2D");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
