//----------------------------------------------------------------------------
// wxDataViewListCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWLISTCTRL_H__
#define __CLASS_WX_DATAVIEWLISTCTRL_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewListCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewListCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewListCtrl
//----------------------------------------------------------------------------
class Object_wx_DataViewListCtrl : public Object_wx_DataViewCtrl {
public:
	Gura_DeclareObjectAccessor(wx_DataViewListCtrl)
public:
	inline Object_wx_DataViewListCtrl(wxDataViewListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewCtrl(Gura_UserClass(wx_DataViewListCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewListCtrl(Class *pClass, wxDataViewListCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewCtrl(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewListCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewListCtrl *GetEntity() {
		return static_cast<wxDataViewListCtrl *>(_pEntity);
	}
	inline wxDataViewListCtrl *ReleaseEntity() {
		wxDataViewListCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewListCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
