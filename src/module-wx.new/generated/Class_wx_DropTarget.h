//----------------------------------------------------------------------------
// wxDropTarget
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DROPTARGET_H__
#define __CLASS_WX_DROPTARGET_H__
#include <wx/dnd.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDropTarget
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DropTarget);

//----------------------------------------------------------------------------
// Object declaration for wxDropTarget
//----------------------------------------------------------------------------
class Object_wx_DropTarget : public Object {
protected:
	wxDropTarget *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DropTarget)
public:
	inline Object_wx_DropTarget(wxDropTarget *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DropTarget(Class *pClass, wxDropTarget *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DropTarget();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDropTarget *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDropTarget *GetEntity() {
		return static_cast<wxDropTarget *>(_pEntity);
	}
	inline wxDropTarget *ReleaseEntity() {
		wxDropTarget *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxDropTarget");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
