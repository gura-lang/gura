//----------------------------------------------------------------------------
// wxAppConsole
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_APPCONSOLE_H__
#define __CLASS_WX_APPCONSOLE_H__
#include <wx/app.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAppConsole
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AppConsole);

//----------------------------------------------------------------------------
// Object declaration for wxAppConsole
//----------------------------------------------------------------------------
class Object_wx_AppConsole : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_AppConsole)
public:
	inline Object_wx_AppConsole(wxAppConsole *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_AppConsole), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_AppConsole(Class *pClass, wxAppConsole *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_AppConsole();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxAppConsole *GetEntity() {
		return static_cast<wxAppConsole *>(_pEntity);
	}
	inline wxAppConsole *ReleaseEntity() {
		wxAppConsole *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAppConsole");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
