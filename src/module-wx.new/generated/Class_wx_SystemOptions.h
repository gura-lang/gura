//----------------------------------------------------------------------------
// wxSystemOptions
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SYSTEMOPTIONS_H__
#define __CLASS_WX_SYSTEMOPTIONS_H__
#include <wx/sysopt.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSystemOptions
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SystemOptions);

//----------------------------------------------------------------------------
// Object declaration for wxSystemOptions
//----------------------------------------------------------------------------
class Object_wx_SystemOptions : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_SystemOptions)
public:
	inline Object_wx_SystemOptions(wxSystemOptions *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_SystemOptions), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SystemOptions(Class *pClass, wxSystemOptions *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SystemOptions();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSystemOptions *GetEntity() {
		return static_cast<wxSystemOptions *>(_pEntity);
	}
	inline wxSystemOptions *ReleaseEntity() {
		wxSystemOptions *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSystemOptions");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
