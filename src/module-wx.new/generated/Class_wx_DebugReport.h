//----------------------------------------------------------------------------
// wxDebugReport
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DEBUGREPORT_H__
#define __CLASS_WX_DEBUGREPORT_H__
#include <wx/debugrpt.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDebugReport
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DebugReport);

//----------------------------------------------------------------------------
// Object declaration for wxDebugReport
//----------------------------------------------------------------------------
class Object_wx_DebugReport : public Object {
protected:
	wxDebugReport *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DebugReport)
public:
	inline Object_wx_DebugReport(wxDebugReport *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DebugReport(Class *pClass, wxDebugReport *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DebugReport();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDebugReport *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDebugReport *GetEntity() {
		return static_cast<wxDebugReport *>(_pEntity);
	}
	inline wxDebugReport *ReleaseEntity() {
		wxDebugReport *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDebugReport");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
