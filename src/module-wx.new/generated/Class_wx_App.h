//----------------------------------------------------------------------------
// wxApp
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_APP_H__
#define __CLASS_WX_APP_H__
#include <wx/app.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxApp
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_App);

//----------------------------------------------------------------------------
// Object declaration for wxApp
//----------------------------------------------------------------------------
class Object_wx_App : public Object_wx_AppConsole {
public:
	Gura_DeclareObjectAccessor(wx_App)
public:
	inline Object_wx_App(wxApp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AppConsole(Gura_UserClass(wx_App), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_App(Class *pClass, wxApp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_AppConsole(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_App();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxApp *GetEntity() {
		return static_cast<wxApp *>(_pEntity);
	}
	inline wxApp *ReleaseEntity() {
		wxApp *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxApp");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
