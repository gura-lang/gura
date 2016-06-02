//----------------------------------------------------------------------------
// wxListItemAttr
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LISTITEMATTR_H__
#define __CLASS_WX_LISTITEMATTR_H__
#include <wx/listctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListItemAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListItemAttr);

//----------------------------------------------------------------------------
// Object declaration for wxListItemAttr
//----------------------------------------------------------------------------
class Object_wx_ListItemAttr : public Object {
protected:
	wxListItemAttr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ListItemAttr)
public:
	inline Object_wx_ListItemAttr(wxListItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ListItemAttr(Class *pClass, wxListItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ListItemAttr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxListItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxListItemAttr *GetEntity() {
		return static_cast<wxListItemAttr *>(_pEntity);
	}
	inline wxListItemAttr *ReleaseEntity() {
		wxListItemAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxListItemAttr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
