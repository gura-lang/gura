//----------------------------------------------------------------------------
// wxTaskBarJumpListItem
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TASKBARJUMPLISTITEM_H__
#define __CLASS_WX_TASKBARJUMPLISTITEM_H__
#include <wx/taskbarbutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTaskBarJumpListItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TaskBarJumpListItem);

//----------------------------------------------------------------------------
// Object declaration for wxTaskBarJumpListItem
//----------------------------------------------------------------------------
class Object_wx_TaskBarJumpListItem : public Object {
protected:
	wxTaskBarJumpListItem *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TaskBarJumpListItem)
public:
	inline Object_wx_TaskBarJumpListItem(wxTaskBarJumpListItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TaskBarJumpListItem(Class *pClass, wxTaskBarJumpListItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TaskBarJumpListItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTaskBarJumpListItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTaskBarJumpListItem *GetEntity() {
		return static_cast<wxTaskBarJumpListItem *>(_pEntity);
	}
	inline wxTaskBarJumpListItem *ReleaseEntity() {
		wxTaskBarJumpListItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTaskBarJumpListItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
