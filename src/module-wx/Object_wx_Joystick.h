//----------------------------------------------------------------------------
// wxJoystick
// extracted from joystick.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_JOYSTICK_H__
#define __OBJECT_WX_JOYSTICK_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxJoystick *GetEntity() {
		return dynamic_cast<wxJoystick *>(_pEntity);
	}
	inline wxJoystick *ReleaseEntity() {
		wxJoystick *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxJoystick");
		return true;
	}
};

}}

#endif
