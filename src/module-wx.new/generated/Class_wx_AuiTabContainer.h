//----------------------------------------------------------------------------
// wxAuiTabContainer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_AUITABCONTAINER_H__
#define __CLASS_WX_AUITABCONTAINER_H__
#include <wx/aui/auibook.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAuiTabContainer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AuiTabContainer);

//----------------------------------------------------------------------------
// Object declaration for wxAuiTabContainer
//----------------------------------------------------------------------------
class Object_wx_AuiTabContainer : public Object {
protected:
	wxAuiTabContainer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AuiTabContainer)
public:
	inline Object_wx_AuiTabContainer(wxAuiTabContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AuiTabContainer(Class *pClass, wxAuiTabContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AuiTabContainer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAuiTabContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAuiTabContainer *GetEntity() {
		return static_cast<wxAuiTabContainer *>(_pEntity);
	}
	inline wxAuiTabContainer *ReleaseEntity() {
		wxAuiTabContainer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAuiTabContainer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
