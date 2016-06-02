//----------------------------------------------------------------------------
// wxMouseState
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MOUSESTATE_H__
#define __CLASS_WX_MOUSESTATE_H__
#include <wx/mousestate.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMouseState
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MouseState);

//----------------------------------------------------------------------------
// Object declaration for wxMouseState
//----------------------------------------------------------------------------
class Object_wx_MouseState : public Object_wx_KeyboardState {
public:
	Gura_DeclareObjectAccessor(wx_MouseState)
public:
	inline Object_wx_MouseState(wxMouseState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_KeyboardState(Gura_UserClass(wx_MouseState), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MouseState(Class *pClass, wxMouseState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_KeyboardState(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MouseState();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMouseState *GetEntity() {
		return static_cast<wxMouseState *>(_pEntity);
	}
	inline wxMouseState *ReleaseEntity() {
		wxMouseState *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMouseState");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
