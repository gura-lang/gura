//----------------------------------------------------------------------------
// wxDebugReportUpload
// extracted from debugrptup.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DEBUGREPORTUPLOAD_H__
#define __OBJECT_WX_DEBUGREPORTUPLOAD_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DebugReportUpload);

//----------------------------------------------------------------------------
// Object declaration for wxDebugReportUpload
//----------------------------------------------------------------------------
class Object_wx_DebugReportUpload : public Object_wx_DebugReportCompress {
public:
	Gura_DeclareObjectAccessor(wx_DebugReportUpload)
public:
	inline Object_wx_DebugReportUpload(wxDebugReportUpload *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DebugReportCompress(Gura_UserClass(wx_DebugReportUpload), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DebugReportUpload(Class *pClass, wxDebugReportUpload *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DebugReportCompress(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DebugReportUpload();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDebugReportUpload *GetEntity() {
		return dynamic_cast<wxDebugReportUpload *>(_pEntity);
	}
	inline wxDebugReportUpload *ReleaseEntity() {
		wxDebugReportUpload *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDebugReportUpload");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
