//----------------------------------------------------------------------------
// wxDCBrushChanger
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DCBRUSHCHANGER_H__
#define __CLASS_WX_DCBRUSHCHANGER_H__
#include <wx/dc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDCBrushChanger
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DCBrushChanger);

//----------------------------------------------------------------------------
// Object declaration for wxDCBrushChanger
//----------------------------------------------------------------------------
class Object_wx_DCBrushChanger : public Object {
protected:
	wxDCBrushChanger *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DCBrushChanger)
public:
	inline Object_wx_DCBrushChanger(wxDCBrushChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DCBrushChanger(Class *pClass, wxDCBrushChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DCBrushChanger();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDCBrushChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDCBrushChanger *GetEntity() {
		return static_cast<wxDCBrushChanger *>(_pEntity);
	}
	inline wxDCBrushChanger *ReleaseEntity() {
		wxDCBrushChanger *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDCBrushChanger");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
