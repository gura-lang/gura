//----------------------------------------------------------------------------
// wxDataViewIndexListModel
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWINDEXLISTMODEL_H__
#define __CLASS_WX_DATAVIEWINDEXLISTMODEL_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewIndexListModel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewIndexListModel);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewIndexListModel
//----------------------------------------------------------------------------
class Object_wx_DataViewIndexListModel : public Object_wx_DataViewListModel {
public:
	Gura_DeclareObjectAccessor(wx_DataViewIndexListModel)
public:
	inline Object_wx_DataViewIndexListModel(wxDataViewIndexListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewListModel(Gura_UserClass(wx_DataViewIndexListModel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewIndexListModel(Class *pClass, wxDataViewIndexListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewListModel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewIndexListModel();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewIndexListModel *GetEntity() {
		return static_cast<wxDataViewIndexListModel *>(_pEntity);
	}
	inline wxDataViewIndexListModel *ReleaseEntity() {
		wxDataViewIndexListModel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewIndexListModel");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
