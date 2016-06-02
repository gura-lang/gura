//----------------------------------------------------------------------------
// wxTaskBarJumpList
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TASKBARJUMPLIST_H__
#define __CLASS_WX_TASKBARJUMPLIST_H__
#include <wx/taskbarbutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTaskBarJumpList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TaskBarJumpList);

//----------------------------------------------------------------------------
// Object declaration for wxTaskBarJumpList
//----------------------------------------------------------------------------
class Object_wx_TaskBarJumpList : public Object {
protected:
	wxTaskBarJumpList *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TaskBarJumpList)
public:
	inline Object_wx_TaskBarJumpList(wxTaskBarJumpList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TaskBarJumpList(Class *pClass, wxTaskBarJumpList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TaskBarJumpList();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTaskBarJumpList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTaskBarJumpList *GetEntity() {
		return static_cast<wxTaskBarJumpList *>(_pEntity);
	}
	inline wxTaskBarJumpList *ReleaseEntity() {
		wxTaskBarJumpList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTaskBarJumpList");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
