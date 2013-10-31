//----------------------------------------------------------------------------
// wxDebugReportPreview
// extracted from debugrptpvw.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DEBUGREPORTPREVIEW_H__
#define __OBJECT_WX_DEBUGREPORTPREVIEW_H__

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
				Object(Gura_UserClass(wx_DebugReportPreview)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DebugReportPreview(Class *pClass, wxDebugReportPreview *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DebugReportPreview();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDebugReportPreview *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDebugReportPreview *GetEntity() { return _pEntity; }
	inline wxDebugReportPreview *ReleaseEntity() {
		wxDebugReportPreview *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDebugReportPreview");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
