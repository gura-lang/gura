//----------------------------------------------------------------------------
// wxPageSetupDialogData
// extracted from pagedlg.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_PAGESETUPDIALOGDATA_H__
#define __OBJECT_WX_PAGESETUPDIALOGDATA_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPageSetupDialogData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PageSetupDialogData);

//----------------------------------------------------------------------------
// Object declaration for wxPageSetupDialogData
//----------------------------------------------------------------------------
class Object_wx_PageSetupDialogData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PageSetupDialogData)
public:
	inline Object_wx_PageSetupDialogData(wxPageSetupDialogData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PageSetupDialogData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PageSetupDialogData(Class *pClass, wxPageSetupDialogData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PageSetupDialogData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPageSetupDialogData *GetEntity() {
		return dynamic_cast<wxPageSetupDialogData *>(_pEntity);
	}
	inline wxPageSetupDialogData *ReleaseEntity() {
		wxPageSetupDialogData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxPageSetupDialogData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
