//----------------------------------------------------------------------------
// wxDataViewListStore
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWLISTSTORE_H__
#define __CLASS_WX_DATAVIEWLISTSTORE_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewListStore
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewListStore);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewListStore
//----------------------------------------------------------------------------
class Object_wx_DataViewListStore : public Object_wx_DataViewIndexListModel {
public:
	Gura_DeclareObjectAccessor(wx_DataViewListStore)
public:
	inline Object_wx_DataViewListStore(wxDataViewListStore *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewIndexListModel(Gura_UserClass(wx_DataViewListStore), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewListStore(Class *pClass, wxDataViewListStore *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewIndexListModel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewListStore();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewListStore *GetEntity() {
		return static_cast<wxDataViewListStore *>(_pEntity);
	}
	inline wxDataViewListStore *ReleaseEntity() {
		wxDataViewListStore *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewListStore");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
