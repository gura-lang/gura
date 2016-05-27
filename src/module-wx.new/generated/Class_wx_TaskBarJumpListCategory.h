//----------------------------------------------------------------------------
// wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TASKBARJUMPLISTCATEGORY_H__
#define __CLASS_WX_TASKBARJUMPLISTCATEGORY_H__
#include <wx/taskbarbutton.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TaskBarJumpListCategory);

//----------------------------------------------------------------------------
// Object declaration for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
class Object_wx_TaskBarJumpListCategory : public Object {
protected:
	wxTaskBarJumpListCategory *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TaskBarJumpListCategory)
public:
	inline Object_wx_TaskBarJumpListCategory(wxTaskBarJumpListCategory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TaskBarJumpListCategory(Class *pClass, wxTaskBarJumpListCategory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TaskBarJumpListCategory();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTaskBarJumpListCategory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxTaskBarJumpListCategory *GetEntity() {
		return static_cast<wxTaskBarJumpListCategory *>(_pEntity);
	}
	inline wxTaskBarJumpListCategory *ReleaseEntity() {
		wxTaskBarJumpListCategory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxTaskBarJumpListCategory");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
