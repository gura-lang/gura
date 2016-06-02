//----------------------------------------------------------------------------
// wxDCTextColourChanger
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DCTEXTCOLOURCHANGER_H__
#define __CLASS_WX_DCTEXTCOLOURCHANGER_H__
#include <wx/dc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDCTextColourChanger
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DCTextColourChanger);

//----------------------------------------------------------------------------
// Object declaration for wxDCTextColourChanger
//----------------------------------------------------------------------------
class Object_wx_DCTextColourChanger : public Object {
protected:
	wxDCTextColourChanger *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DCTextColourChanger)
public:
	inline Object_wx_DCTextColourChanger(wxDCTextColourChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DCTextColourChanger(Class *pClass, wxDCTextColourChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DCTextColourChanger();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDCTextColourChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDCTextColourChanger *GetEntity() {
		return static_cast<wxDCTextColourChanger *>(_pEntity);
	}
	inline wxDCTextColourChanger *ReleaseEntity() {
		wxDCTextColourChanger *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDCTextColourChanger");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
