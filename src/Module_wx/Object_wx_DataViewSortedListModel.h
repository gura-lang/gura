//----------------------------------------------------------------------------
// wxDataViewSortedListModel
// extracted from dataviewmodel.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATAVIEWSORTEDLISTMODEL_H__
#define __OBJECT_WX_DATAVIEWSORTEDLISTMODEL_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewSortedListModel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewSortedListModel);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewSortedListModel
//----------------------------------------------------------------------------
class Object_wx_DataViewSortedListModel : public Object_wx_DataViewListModel {
public:
	Gura_DeclareObjectAccessor(wx_DataViewSortedListModel)
public:
	inline Object_wx_DataViewSortedListModel(wxDataViewSortedListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewListModel(Gura_UserClass(wx_DataViewSortedListModel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewSortedListModel(Class *pClass, wxDataViewSortedListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewListModel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewSortedListModel();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDataViewSortedListModel *GetEntity() {
		return dynamic_cast<wxDataViewSortedListModel *>(_pEntity);
	}
	inline wxDataViewSortedListModel *ReleaseEntity() {
		wxDataViewSortedListModel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDataViewSortedListModel");
		return true;
	}
};

}}

#endif
