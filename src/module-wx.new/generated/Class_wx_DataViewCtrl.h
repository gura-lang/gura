//----------------------------------------------------------------------------
// wxDataViewCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWCTRL_H__
#define __CLASS_WX_DATAVIEWCTRL_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewCtrl
//----------------------------------------------------------------------------
class Object_wx_DataViewCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_DataViewCtrl)
public:
	inline Object_wx_DataViewCtrl(wxDataViewCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_DataViewCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewCtrl(Class *pClass, wxDataViewCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewCtrl *GetEntity() {
		return static_cast<wxDataViewCtrl *>(_pEntity);
	}
	inline wxDataViewCtrl *ReleaseEntity() {
		wxDataViewCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
