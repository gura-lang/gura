//----------------------------------------------------------------------------
// wxDialUpManager
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIALUPMANAGER_H__
#define __CLASS_WX_DIALUPMANAGER_H__
#include <wx/dialup.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDialUpManager
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DialUpManager);

//----------------------------------------------------------------------------
// Object declaration for wxDialUpManager
//----------------------------------------------------------------------------
class Object_wx_DialUpManager : public Object {
protected:
	wxDialUpManager *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DialUpManager)
public:
	inline Object_wx_DialUpManager(wxDialUpManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DialUpManager(Class *pClass, wxDialUpManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DialUpManager();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDialUpManager *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDialUpManager *GetEntity() {
		return static_cast<wxDialUpManager *>(_pEntity);
	}
	inline wxDialUpManager *ReleaseEntity() {
		wxDialUpManager *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDialUpManager");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
