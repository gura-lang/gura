//----------------------------------------------------------------------------
// wxTextCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TEXTCTRL_H__
#define __CLASS_WX_TEXTCTRL_H__
#include <wx/textctrl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TextCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxTextCtrl
//----------------------------------------------------------------------------
class Object_wx_TextCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_TextCtrl)
public:
	inline Object_wx_TextCtrl(wxTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_TextCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TextCtrl(Class *pClass, wxTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TextCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxTextCtrl *GetEntity() {
		return static_cast<wxTextCtrl *>(_pEntity);
	}
	inline wxTextCtrl *ReleaseEntity() {
		wxTextCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxTextCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
