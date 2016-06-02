//----------------------------------------------------------------------------
// wxPanel
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PANEL_H__
#define __CLASS_WX_PANEL_H__
#include <wx/panel.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPanel
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Panel);

//----------------------------------------------------------------------------
// Object declaration for wxPanel
//----------------------------------------------------------------------------
class Object_wx_Panel : public Object_wx_Window {
public:
	Gura_DeclareObjectAccessor(wx_Panel)
public:
	inline Object_wx_Panel(wxPanel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(Gura_UserClass(wx_Panel), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Panel(Class *pClass, wxPanel *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Window(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Panel();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPanel *GetEntity() {
		return static_cast<wxPanel *>(_pEntity);
	}
	inline wxPanel *ReleaseEntity() {
		wxPanel *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPanel");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
