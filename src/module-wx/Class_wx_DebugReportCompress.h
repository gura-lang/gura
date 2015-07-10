//----------------------------------------------------------------------------
// wxDebugReportCompress
// extracted from debugrptz.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DEBUGREPORTCOMPRESS_H__
#define __CLASS_WX_DEBUGREPORTCOMPRESS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDebugReportCompress
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DebugReportCompress);

//----------------------------------------------------------------------------
// Object declaration for wxDebugReportCompress
//----------------------------------------------------------------------------
class Object_wx_DebugReportCompress : public Object_wx_DebugReport {
public:
	Gura_DeclareObjectAccessor(wx_DebugReportCompress)
public:
	inline Object_wx_DebugReportCompress(wxDebugReportCompress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DebugReport(Gura_UserClass(wx_DebugReportCompress), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DebugReportCompress(Class *pClass, wxDebugReportCompress *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DebugReport(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DebugReportCompress();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDebugReportCompress *GetEntity() {
		return dynamic_cast<wxDebugReportCompress *>(_pEntity);
	}
	inline wxDebugReportCompress *ReleaseEntity() {
		wxDebugReportCompress *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDebugReportCompress");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
