//----------------------------------------------------------------------------
// wxGraphicsGradientStops
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRAPHICSGRADIENTSTOPS_H__
#define __CLASS_WX_GRAPHICSGRADIENTSTOPS_H__
#include <wx/graphics.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGraphicsGradientStops
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GraphicsGradientStops);

//----------------------------------------------------------------------------
// Object declaration for wxGraphicsGradientStops
//----------------------------------------------------------------------------
class Object_wx_GraphicsGradientStops : public Object {
protected:
	wxGraphicsGradientStops *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GraphicsGradientStops)
public:
	inline Object_wx_GraphicsGradientStops(wxGraphicsGradientStops *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GraphicsGradientStops(Class *pClass, wxGraphicsGradientStops *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GraphicsGradientStops();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGraphicsGradientStops *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGraphicsGradientStops *GetEntity() {
		return static_cast<wxGraphicsGradientStops *>(_pEntity);
	}
	inline wxGraphicsGradientStops *ReleaseEntity() {
		wxGraphicsGradientStops *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGraphicsGradientStops");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
