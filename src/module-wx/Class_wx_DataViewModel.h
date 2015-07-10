//----------------------------------------------------------------------------
// wxDataViewModel
// extracted from dataviewmodel.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWMODEL_H__
#define __CLASS_WX_DATAVIEWMODEL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewModel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewModel);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewModel
//----------------------------------------------------------------------------
class Object_wx_DataViewModel : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DataViewModel)
public:
	inline Object_wx_DataViewModel(wxDataViewModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DataViewModel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewModel(Class *pClass, wxDataViewModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewModel();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewModel *GetEntity() {
		return dynamic_cast<wxDataViewModel *>(_pEntity);
	}
	inline wxDataViewModel *ReleaseEntity() {
		wxDataViewModel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewModel");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
