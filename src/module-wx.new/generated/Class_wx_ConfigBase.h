//----------------------------------------------------------------------------
// wxConfigBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CONFIGBASE_H__
#define __CLASS_WX_CONFIGBASE_H__
#include <wx/config.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxConfigBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ConfigBase);

//----------------------------------------------------------------------------
// Object declaration for wxConfigBase
//----------------------------------------------------------------------------
class Object_wx_ConfigBase : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ConfigBase)
public:
	inline Object_wx_ConfigBase(wxConfigBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ConfigBase), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ConfigBase(Class *pClass, wxConfigBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ConfigBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxConfigBase *GetEntity() {
		return static_cast<wxConfigBase *>(_pEntity);
	}
	inline wxConfigBase *ReleaseEntity() {
		wxConfigBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxConfigBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
