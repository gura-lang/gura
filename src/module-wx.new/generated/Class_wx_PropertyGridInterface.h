//----------------------------------------------------------------------------
// wxPropertyGridInterface
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPERTYGRIDINTERFACE_H__
#define __CLASS_WX_PROPERTYGRIDINTERFACE_H__
#include <wx/propgrid/propgridiface.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropertyGridInterface
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropertyGridInterface);

//----------------------------------------------------------------------------
// Object declaration for wxPropertyGridInterface
//----------------------------------------------------------------------------
class Object_wx_PropertyGridInterface : public Object {
protected:
	wxPropertyGridInterface *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PropertyGridInterface)
public:
	inline Object_wx_PropertyGridInterface(wxPropertyGridInterface *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PropertyGridInterface(Class *pClass, wxPropertyGridInterface *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PropertyGridInterface();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPropertyGridInterface *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPropertyGridInterface *GetEntity() {
		return static_cast<wxPropertyGridInterface *>(_pEntity);
	}
	inline wxPropertyGridInterface *ReleaseEntity() {
		wxPropertyGridInterface *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPropertyGridInterface");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
