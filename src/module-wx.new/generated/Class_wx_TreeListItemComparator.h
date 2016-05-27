//----------------------------------------------------------------------------
// wxTreeListItemComparator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREELISTITEMCOMPARATOR_H__
#define __CLASS_WX_TREELISTITEMCOMPARATOR_H__
#include <wx/treelist.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeListItemComparator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeListItemComparator);

//----------------------------------------------------------------------------
// Object declaration for wxTreeListItemComparator
//----------------------------------------------------------------------------
class Object_wx_TreeListItemComparator : public Object {
protected:
	wxTreeListItemComparator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TreeListItemComparator)
public:
	inline Object_wx_TreeListItemComparator(wxTreeListItemComparator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TreeListItemComparator(Class *pClass, wxTreeListItemComparator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TreeListItemComparator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTreeListItemComparator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTreeListItemComparator *GetEntity() {
		return static_cast<wxTreeListItemComparator *>(_pEntity);
	}
	inline wxTreeListItemComparator *ReleaseEntity() {
		wxTreeListItemComparator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTreeListItemComparator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
