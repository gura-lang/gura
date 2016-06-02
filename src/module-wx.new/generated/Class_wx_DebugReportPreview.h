//----------------------------------------------------------------------------
// wxDebugReportPreview
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DEBUGREPORTPREVIEW_H__
#define __CLASS_WX_DEBUGREPORTPREVIEW_H__
#include <wx/debugrpt.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDebugReportPreview
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DebugReportPreview);

//----------------------------------------------------------------------------
// Object declaration for wxDebugReportPreview
//----------------------------------------------------------------------------
class Object_wx_DebugReportPreview : public Object {
protected:
	wxDebugReportPreview *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DebugReportPreview)
public:
	inline Object_wx_DebugReportPreview(wxDebugReportPreview *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DebugReportPreview(Class *pClass, wxDebugReportPreview *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DebugReportPreview();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDebugReportPreview *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDebugReportPreview *GetEntity() {
		return static_cast<wxDebugReportPreview *>(_pEntity);
	}
	inline wxDebugReportPreview *ReleaseEntity() {
		wxDebugReportPreview *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDebugReportPreview");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
