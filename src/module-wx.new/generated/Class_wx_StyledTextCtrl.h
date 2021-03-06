//----------------------------------------------------------------------------
// wxStyledTextCtrl
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STYLEDTEXTCTRL_H__
#define __CLASS_WX_STYLEDTEXTCTRL_H__
#include <wx/stc/stc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStyledTextCtrl
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StyledTextCtrl);

//----------------------------------------------------------------------------
// Object declaration for wxStyledTextCtrl
//----------------------------------------------------------------------------
class Object_wx_StyledTextCtrl : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_StyledTextCtrl)
public:
	inline Object_wx_StyledTextCtrl(wxStyledTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_StyledTextCtrl), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StyledTextCtrl(Class *pClass, wxStyledTextCtrl *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StyledTextCtrl();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStyledTextCtrl *GetEntity() {
		return static_cast<wxStyledTextCtrl *>(_pEntity);
	}
	inline wxStyledTextCtrl *ReleaseEntity() {
		wxStyledTextCtrl *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStyledTextCtrl");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
