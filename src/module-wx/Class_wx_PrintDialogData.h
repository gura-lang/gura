//----------------------------------------------------------------------------
// wxPrintDialogData
// extracted from print.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PRINTDIALOGDATA_H__
#define __CLASS_WX_PRINTDIALOGDATA_H__

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline wxPrintDialogData *GetEntity() {
		return dynamic_cast<wxPrintDialogData *>(_pEntity);
	}
	inline wxPrintDialogData *ReleaseEntity() {
		wxPrintDialogData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPrintDialogData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
