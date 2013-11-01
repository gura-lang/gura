//----------------------------------------------------------------------------
// wxDebugReportPreviewStd
// extracted from debugrptpvwstd.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DEBUGREPORTPREVIEWSTD_H__
#define __CLASS_WX_DEBUGREPORTPREVIEWSTD_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DebugReportPreviewStd);

//----------------------------------------------------------------------------
// Object declaration for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
class Object_wx_DebugReportPreviewStd : public Object_wx_DebugReportPreview {
public:
	Gura_DeclareObjectAccessor(wx_DebugReportPreviewStd)
public:
	inline Object_wx_DebugReportPreviewStd(wxDebugReportPreviewStd *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DebugReportPreview(Gura_UserClass(wx_DebugReportPreviewStd), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DebugReportPreviewStd(Class *pClass, wxDebugReportPreviewStd *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DebugReportPreview(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DebugReportPreviewStd();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDebugReportPreviewStd *GetEntity() {
		return dynamic_cast<wxDebugReportPreviewStd *>(_pEntity);
	}
	inline wxDebugReportPreviewStd *ReleaseEntity() {
		wxDebugReportPreviewStd *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDebugReportPreviewStd");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
