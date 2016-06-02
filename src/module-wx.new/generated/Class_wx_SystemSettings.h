//----------------------------------------------------------------------------
// wxSystemSettings
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SYSTEMSETTINGS_H__
#define __CLASS_WX_SYSTEMSETTINGS_H__
#include <wx/settings.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSystemSettings
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SystemSettings);

//----------------------------------------------------------------------------
// Object declaration for wxSystemSettings
//----------------------------------------------------------------------------
class Object_wx_SystemSettings : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_SystemSettings)
public:
	inline Object_wx_SystemSettings(wxSystemSettings *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_SystemSettings), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SystemSettings(Class *pClass, wxSystemSettings *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SystemSettings();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSystemSettings *GetEntity() {
		return static_cast<wxSystemSettings *>(_pEntity);
	}
	inline wxSystemSettings *ReleaseEntity() {
		wxSystemSettings *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSystemSettings");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
