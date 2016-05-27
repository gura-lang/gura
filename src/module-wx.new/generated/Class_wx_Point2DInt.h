//----------------------------------------------------------------------------
// wxPoint2DInt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POINT2DINT_H__
#define __CLASS_WX_POINT2DINT_H__
#include <wx/geometry.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPoint2DInt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Point2DInt);

//----------------------------------------------------------------------------
// Object declaration for wxPoint2DInt
//----------------------------------------------------------------------------
class Object_wx_Point2DInt : public Object {
protected:
	wxPoint2DInt *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Point2DInt)
public:
	inline Object_wx_Point2DInt(wxPoint2DInt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Point2DInt(Class *pClass, wxPoint2DInt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Point2DInt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPoint2DInt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPoint2DInt *GetEntity() {
		return static_cast<wxPoint2DInt *>(_pEntity);
	}
	inline wxPoint2DInt *ReleaseEntity() {
		wxPoint2DInt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPoint2DInt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
