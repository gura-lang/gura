//----------------------------------------------------------------------------
// wxTreeItemData
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREEITEMDATA_H__
#define __CLASS_WX_TREEITEMDATA_H__
#include <wx/treebase.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeItemData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeItemData);

//----------------------------------------------------------------------------
// Object declaration for wxTreeItemData
//----------------------------------------------------------------------------
class Object_wx_TreeItemData : public Object_wx_ClientData {
public:
	Gura_DeclareObjectAccessor(wx_TreeItemData)
public:
	inline Object_wx_TreeItemData(wxTreeItemData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientData(Gura_UserClass(wx_TreeItemData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TreeItemData(Class *pClass, wxTreeItemData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientData(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TreeItemData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTreeItemData *GetEntity() {
		return static_cast<wxTreeItemData *>(_pEntity);
	}
	inline wxTreeItemData *ReleaseEntity() {
		wxTreeItemData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTreeItemData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
