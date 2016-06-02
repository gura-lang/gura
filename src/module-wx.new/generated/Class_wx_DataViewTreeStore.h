//----------------------------------------------------------------------------
// wxDataViewTreeStore
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWTREESTORE_H__
#define __CLASS_WX_DATAVIEWTREESTORE_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewTreeStore
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewTreeStore);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewTreeStore
//----------------------------------------------------------------------------
class Object_wx_DataViewTreeStore : public Object_wx_DataViewModel {
public:
	Gura_DeclareObjectAccessor(wx_DataViewTreeStore)
public:
	inline Object_wx_DataViewTreeStore(wxDataViewTreeStore *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewModel(Gura_UserClass(wx_DataViewTreeStore), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DataViewTreeStore(Class *pClass, wxDataViewTreeStore *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_DataViewModel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DataViewTreeStore();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDataViewTreeStore *GetEntity() {
		return static_cast<wxDataViewTreeStore *>(_pEntity);
	}
	inline wxDataViewTreeStore *ReleaseEntity() {
		wxDataViewTreeStore *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDataViewTreeStore");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
