//----------------------------------------------------------------------------
// wxTreeItemId
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TREEITEMID_H__
#define __CLASS_WX_TREEITEMID_H__
#include <wx/treebase.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeItemId
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeItemId);

//----------------------------------------------------------------------------
// Object declaration for wxTreeItemId
//----------------------------------------------------------------------------
class Object_wx_TreeItemId : public Object {
protected:
	wxTreeItemId *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TreeItemId)
public:
	inline Object_wx_TreeItemId(wxTreeItemId *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TreeItemId(Class *pClass, wxTreeItemId *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TreeItemId();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTreeItemId *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTreeItemId *GetEntity() {
		return static_cast<wxTreeItemId *>(_pEntity);
	}
	inline wxTreeItemId *ReleaseEntity() {
		wxTreeItemId *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTreeItemId");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
