//----------------------------------------------------------------------------
// wxAuiToolBarItem
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUITOOLBARITEM_H__
#define __CLASS_WX_AUITOOLBARITEM_H__
#include <wx/aui/auibar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiToolBarItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiToolBarItem);

//----------------------------------------------------------------------------
// Object declaration for wxAuiToolBarItem
//----------------------------------------------------------------------------
class Object_wx_AuiToolBarItem : public Object {
protected:
	wxAuiToolBarItem *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AuiToolBarItem)
public:
	inline Object_wx_AuiToolBarItem(wxAuiToolBarItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AuiToolBarItem(Class *pClass, wxAuiToolBarItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AuiToolBarItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAuiToolBarItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAuiToolBarItem *GetEntity() {
		return static_cast<wxAuiToolBarItem *>(_pEntity);
	}
	inline wxAuiToolBarItem *ReleaseEntity() {
		wxAuiToolBarItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAuiToolBarItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
