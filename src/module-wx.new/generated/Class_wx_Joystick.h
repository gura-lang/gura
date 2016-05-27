//----------------------------------------------------------------------------
// wxJoystick
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_JOYSTICK_H__
#define __CLASS_WX_JOYSTICK_H__
#include <wx/joystick.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxJoystick
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Joystick);

//----------------------------------------------------------------------------
// Object declaration for wxJoystick
//----------------------------------------------------------------------------
class Object_wx_Joystick : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Joystick)
public:
	inline Object_wx_Joystick(wxJoystick *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Joystick), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Joystick(Class *pClass, wxJoystick *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Joystick();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxJoystick *GetEntity() {
		return static_cast<wxJoystick *>(_pEntity);
	}
	inline wxJoystick *ReleaseEntity() {
		wxJoystick *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxJoystick");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
