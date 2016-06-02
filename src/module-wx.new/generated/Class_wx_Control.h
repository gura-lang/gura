//----------------------------------------------------------------------------
// wxControl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CONTROL_H__
#define __CLASS_WX_CONTROL_H__
#include <wx/control.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxControl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Control);

//----------------------------------------------------------------------------
// Object declaration for wxControl
//----------------------------------------------------------------------------
class Object_wx_Control : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_Control)
public:
	inline Object_wx_Control(wxControl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_Control), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Control(Class *pClass, wxControl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Control();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxControl *GetEntity() {
		return static_cast<wxControl *>(_pEntity);
	}
	inline wxControl *ReleaseEntity() {
		wxControl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxControl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
