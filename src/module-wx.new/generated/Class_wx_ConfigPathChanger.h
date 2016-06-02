//----------------------------------------------------------------------------
// wxConfigPathChanger
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CONFIGPATHCHANGER_H__
#define __CLASS_WX_CONFIGPATHCHANGER_H__
#include <wx/config.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxConfigPathChanger
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ConfigPathChanger);

//----------------------------------------------------------------------------
// Object declaration for wxConfigPathChanger
//----------------------------------------------------------------------------
class Object_wx_ConfigPathChanger : public Object {
protected:
	wxConfigPathChanger *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ConfigPathChanger)
public:
	inline Object_wx_ConfigPathChanger(wxConfigPathChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ConfigPathChanger(Class *pClass, wxConfigPathChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ConfigPathChanger();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxConfigPathChanger *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxConfigPathChanger *GetEntity() {
		return static_cast<wxConfigPathChanger *>(_pEntity);
	}
	inline wxConfigPathChanger *ReleaseEntity() {
		wxConfigPathChanger *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxConfigPathChanger");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
