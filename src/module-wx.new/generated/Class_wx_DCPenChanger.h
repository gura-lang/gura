//----------------------------------------------------------------------------
// wxDCPenChanger
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DCPENCHANGER_H__
#define __CLASS_WX_DCPENCHANGER_H__
#include <wx/dc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDCPenChanger
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DCPenChanger);

//----------------------------------------------------------------------------
// Object declaration for wxDCPenChanger
//----------------------------------------------------------------------------
class Object_wx_DCPenChanger : public Object {
protected:
	wxDCPenChanger *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DCPenChanger)
public:
	inline Object_wx_DCPenChanger(wxDCPenChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DCPenChanger(Class *pClass, wxDCPenChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DCPenChanger();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDCPenChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDCPenChanger *GetEntity() {
		return static_cast<wxDCPenChanger *>(_pEntity);
	}
	inline wxDCPenChanger *ReleaseEntity() {
		wxDCPenChanger *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDCPenChanger");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
