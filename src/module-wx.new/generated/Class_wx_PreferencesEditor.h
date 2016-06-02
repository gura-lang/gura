//----------------------------------------------------------------------------
// wxPreferencesEditor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PREFERENCESEDITOR_H__
#define __CLASS_WX_PREFERENCESEDITOR_H__
#include <wx/preferences.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPreferencesEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PreferencesEditor);

//----------------------------------------------------------------------------
// Object declaration for wxPreferencesEditor
//----------------------------------------------------------------------------
class Object_wx_PreferencesEditor : public Object {
protected:
	wxPreferencesEditor *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PreferencesEditor)
public:
	inline Object_wx_PreferencesEditor(wxPreferencesEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PreferencesEditor(Class *pClass, wxPreferencesEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PreferencesEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPreferencesEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPreferencesEditor *GetEntity() {
		return static_cast<wxPreferencesEditor *>(_pEntity);
	}
	inline wxPreferencesEditor *ReleaseEntity() {
		wxPreferencesEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPreferencesEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
