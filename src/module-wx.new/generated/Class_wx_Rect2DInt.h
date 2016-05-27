//----------------------------------------------------------------------------
// wxRect2DInt
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RECT2DINT_H__
#define __CLASS_WX_RECT2DINT_H__
#include <wx/geometry.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRect2DInt
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Rect2DInt);

//----------------------------------------------------------------------------
// Object declaration for wxRect2DInt
//----------------------------------------------------------------------------
class Object_wx_Rect2DInt : public Object {
protected:
	wxRect2DInt *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Rect2DInt)
public:
	inline Object_wx_Rect2DInt(wxRect2DInt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Rect2DInt(Class *pClass, wxRect2DInt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Rect2DInt();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRect2DInt *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRect2DInt *GetEntity() {
		return static_cast<wxRect2DInt *>(_pEntity);
	}
	inline wxRect2DInt *ReleaseEntity() {
		wxRect2DInt *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRect2DInt");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
