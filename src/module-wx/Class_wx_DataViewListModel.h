//----------------------------------------------------------------------------
// wxDataViewListModel
// extracted from dataviewmodel.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWLISTMODEL_H__
#define __CLASS_WX_DATAVIEWLISTMODEL_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewListModel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewListModel);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewListModel
//----------------------------------------------------------------------------
class Object_wx_DataViewListModel : public Object_wx_DataViewModel {
public:
	Gura_DeclareObjectAccessor(wx_DataViewListModel)
public:
	inline Object_wx_DataViewListModel(wxDataViewListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewModel(Gura_UserClass(wx_DataViewListModel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewListModel(Class *pClass, wxDataViewListModel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewModel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewListModel();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewListModel *GetEntity() {
		return dynamic_cast<wxDataViewListModel *>(_pEntity);
	}
	inline wxDataViewListModel *ReleaseEntity() {
		wxDataViewListModel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewListModel");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
