//----------------------------------------------------------------------------
// wxPrintDialogData
// extracted from print.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PRINTDIALOGDATA_H__
#define __OBJECT_WX_PRINTDIALOGDATA_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPrintDialogData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PrintDialogData);

//----------------------------------------------------------------------------
// Object declaration for wxPrintDialogData
//----------------------------------------------------------------------------
class Object_wx_PrintDialogData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PrintDialogData)
public:
	inline Object_wx_PrintDialogData(wxPrintDialogData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PrintDialogData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PrintDialogData(Class *pClass, wxPrintDialogData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PrintDialogData();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxPrintDialogData *GetEntity() {
		return dynamic_cast<wxPrintDialogData *>(_pEntity);
	}
	inline wxPrintDialogData *ReleaseEntity() {
		wxPrintDialogData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPrintDialogData");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
