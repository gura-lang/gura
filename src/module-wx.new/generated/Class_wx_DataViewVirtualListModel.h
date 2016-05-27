//----------------------------------------------------------------------------
// wxDataViewVirtualListModel
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWVIRTUALLISTMODEL_H__
#define __CLASS_WX_DATAVIEWVIRTUALLISTMODEL_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewVirtualListModel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewVirtualListModel);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewVirtualListModel
//----------------------------------------------------------------------------
class Object_wx_DataViewVirtualListModel : public Object_wx_DataViewListModel {
public:
	Gura_DeclareObjectAccessor(wx_DataViewVirtualListModel)
public:
	inline Object_wx_DataViewVirtualListModel(wxDataViewVirtualListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewListModel(Gura_UserClass(wx_DataViewVirtualListModel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewVirtualListModel(Class *pClass, wxDataViewVirtualListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewListModel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewVirtualListModel();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewVirtualListModel *GetEntity() {
		return static_cast<wxDataViewVirtualListModel *>(_pEntity);
	}
	inline wxDataViewVirtualListModel *ReleaseEntity() {
		wxDataViewVirtualListModel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewVirtualListModel");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
