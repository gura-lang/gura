//----------------------------------------------------------------------------
// wxDataViewTreeCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWTREECTRL_H__
#define __CLASS_WX_DATAVIEWTREECTRL_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewTreeCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewTreeCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewTreeCtrl
//----------------------------------------------------------------------------
class Object_wx_DataViewTreeCtrl : public Object_wx_DataViewCtrl {
public:
	Gura_DeclareObjectAccessor(wx_DataViewTreeCtrl)
public:
	inline Object_wx_DataViewTreeCtrl(wxDataViewTreeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewCtrl(Gura_UserClass(wx_DataViewTreeCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewTreeCtrl(Class *pClass, wxDataViewTreeCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewCtrl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewTreeCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewTreeCtrl *GetEntity() {
		return static_cast<wxDataViewTreeCtrl *>(_pEntity);
	}
	inline wxDataViewTreeCtrl *ReleaseEntity() {
		wxDataViewTreeCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewTreeCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
