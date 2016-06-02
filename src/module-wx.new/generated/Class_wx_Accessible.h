//----------------------------------------------------------------------------
// wxAccessible
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ACCESSIBLE_H__
#define __CLASS_WX_ACCESSIBLE_H__
#include <wx/access.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAccessible
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Accessible);

//----------------------------------------------------------------------------
// Object declaration for wxAccessible
//----------------------------------------------------------------------------
class Object_wx_Accessible : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Accessible)
public:
	inline Object_wx_Accessible(wxAccessible *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Accessible), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Accessible(Class *pClass, wxAccessible *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Accessible();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAccessible *GetEntity() {
		return static_cast<wxAccessible *>(_pEntity);
	}
	inline wxAccessible *ReleaseEntity() {
		wxAccessible *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxAccessible");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
