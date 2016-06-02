//----------------------------------------------------------------------------
// wxSpinCtrlDouble
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SPINCTRLDOUBLE_H__
#define __CLASS_WX_SPINCTRLDOUBLE_H__
#include <wx/spinctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSpinCtrlDouble
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SpinCtrlDouble);

//----------------------------------------------------------------------------
// Object declaration for wxSpinCtrlDouble
//----------------------------------------------------------------------------
class Object_wx_SpinCtrlDouble : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_SpinCtrlDouble)
public:
	inline Object_wx_SpinCtrlDouble(wxSpinCtrlDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_SpinCtrlDouble), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SpinCtrlDouble(Class *pClass, wxSpinCtrlDouble *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SpinCtrlDouble();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSpinCtrlDouble *GetEntity() {
		return static_cast<wxSpinCtrlDouble *>(_pEntity);
	}
	inline wxSpinCtrlDouble *ReleaseEntity() {
		wxSpinCtrlDouble *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSpinCtrlDouble");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
