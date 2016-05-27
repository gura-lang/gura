//----------------------------------------------------------------------------
// wxTreeListItem
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREELISTITEM_H__
#define __CLASS_WX_TREELISTITEM_H__
#include <wx/treelist.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeListItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeListItem);

//----------------------------------------------------------------------------
// Object declaration for wxTreeListItem
//----------------------------------------------------------------------------
class Object_wx_TreeListItem : public Object {
protected:
	wxTreeListItem *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TreeListItem)
public:
	inline Object_wx_TreeListItem(wxTreeListItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TreeListItem(Class *pClass, wxTreeListItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TreeListItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTreeListItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTreeListItem *GetEntity() {
		return static_cast<wxTreeListItem *>(_pEntity);
	}
	inline wxTreeListItem *ReleaseEntity() {
		wxTreeListItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTreeListItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
