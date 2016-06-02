//----------------------------------------------------------------------------
// wxUIActionSimulator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_UIACTIONSIMULATOR_H__
#define __CLASS_WX_UIACTIONSIMULATOR_H__
#include <wx/uiaction.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxUIActionSimulator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_UIActionSimulator);

//----------------------------------------------------------------------------
// Object declaration for wxUIActionSimulator
//----------------------------------------------------------------------------
class Object_wx_UIActionSimulator : public Object {
protected:
	wxUIActionSimulator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_UIActionSimulator)
public:
	inline Object_wx_UIActionSimulator(wxUIActionSimulator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_UIActionSimulator(Class *pClass, wxUIActionSimulator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_UIActionSimulator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxUIActionSimulator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxUIActionSimulator *GetEntity() {
		return static_cast<wxUIActionSimulator *>(_pEntity);
	}
	inline wxUIActionSimulator *ReleaseEntity() {
		wxUIActionSimulator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxUIActionSimulator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
