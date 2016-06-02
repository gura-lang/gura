//----------------------------------------------------------------------------
// wxDataViewModel
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWMODEL_H__
#define __CLASS_WX_DATAVIEWMODEL_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewModel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewModel);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewModel
//----------------------------------------------------------------------------
class Object_wx_DataViewModel : public Object_wx_RefCounter {
public:
	Gura_DeclareObjectAccessor(wx_DataViewModel)
public:
	inline Object_wx_DataViewModel(wxDataViewModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RefCounter(Gura_UserClass(wx_DataViewModel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewModel(Class *pClass, wxDataViewModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_RefCounter(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewModel();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewModel *GetEntity() {
		return static_cast<wxDataViewModel *>(_pEntity);
	}
	inline wxDataViewModel *ReleaseEntity() {
		wxDataViewModel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewModel");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
