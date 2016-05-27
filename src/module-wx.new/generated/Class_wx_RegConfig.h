//----------------------------------------------------------------------------
// wxRegConfig
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REGCONFIG_H__
#define __CLASS_WX_REGCONFIG_H__
#include <wx/msw/regconf.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRegConfig
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RegConfig);

//----------------------------------------------------------------------------
// Object declaration for wxRegConfig
//----------------------------------------------------------------------------
class Object_wx_RegConfig : public Object_wx_ConfigBase {
public:
	Gura_DeclareObjectAccessor(wx_RegConfig)
public:
	inline Object_wx_RegConfig(wxRegConfig *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConfigBase(Gura_UserClass(wx_RegConfig), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_RegConfig(Class *pClass, wxRegConfig *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ConfigBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_RegConfig();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxRegConfig *GetEntity() {
		return static_cast<wxRegConfig *>(_pEntity);
	}
	inline wxRegConfig *ReleaseEntity() {
		wxRegConfig *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRegConfig");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
