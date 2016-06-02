//----------------------------------------------------------------------------
// wxToolBar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TOOLBAR_H__
#define __CLASS_WX_TOOLBAR_H__
#include <wx/toolbar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToolBar);

//----------------------------------------------------------------------------
// Object declaration for wxToolBar
//----------------------------------------------------------------------------
class Object_wx_ToolBar : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_ToolBar)
public:
	inline Object_wx_ToolBar(wxToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_ToolBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ToolBar(Class *pClass, wxToolBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ToolBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxToolBar *GetEntity() {
		return static_cast<wxToolBar *>(_pEntity);
	}
	inline wxToolBar *ReleaseEntity() {
		wxToolBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxToolBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
