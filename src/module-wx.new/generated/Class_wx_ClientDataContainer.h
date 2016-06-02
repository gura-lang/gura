//----------------------------------------------------------------------------
// wxClientDataContainer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLIENTDATACONTAINER_H__
#define __CLASS_WX_CLIENTDATACONTAINER_H__
#include <wx/clntdata.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClientDataContainer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClientDataContainer);

//----------------------------------------------------------------------------
// Object declaration for wxClientDataContainer
//----------------------------------------------------------------------------
class Object_wx_ClientDataContainer : public Object {
protected:
	wxClientDataContainer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ClientDataContainer)
public:
	inline Object_wx_ClientDataContainer(wxClientDataContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ClientDataContainer(Class *pClass, wxClientDataContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ClientDataContainer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxClientDataContainer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxClientDataContainer *GetEntity() {
		return static_cast<wxClientDataContainer *>(_pEntity);
	}
	inline wxClientDataContainer *ReleaseEntity() {
		wxClientDataContainer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxClientDataContainer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
