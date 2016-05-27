//----------------------------------------------------------------------------
// wxPreferencesPage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PREFERENCESPAGE_H__
#define __CLASS_WX_PREFERENCESPAGE_H__
#include <wx/preferences.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPreferencesPage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PreferencesPage);

//----------------------------------------------------------------------------
// Object declaration for wxPreferencesPage
//----------------------------------------------------------------------------
class Object_wx_PreferencesPage : public Object {
protected:
	wxPreferencesPage *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_PreferencesPage)
public:
	inline Object_wx_PreferencesPage(wxPreferencesPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_PreferencesPage(Class *pClass, wxPreferencesPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_PreferencesPage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPreferencesPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPreferencesPage *GetEntity() {
		return static_cast<wxPreferencesPage *>(_pEntity);
	}
	inline wxPreferencesPage *ReleaseEntity() {
		wxPreferencesPage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPreferencesPage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
