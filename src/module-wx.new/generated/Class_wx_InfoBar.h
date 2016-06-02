//----------------------------------------------------------------------------
// wxInfoBar
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_INFOBAR_H__
#define __CLASS_WX_INFOBAR_H__
#include <wx/infobar.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxInfoBar
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_InfoBar);

//----------------------------------------------------------------------------
// Object declaration for wxInfoBar
//----------------------------------------------------------------------------
class Object_wx_InfoBar : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_InfoBar)
public:
	inline Object_wx_InfoBar(wxInfoBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_InfoBar), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_InfoBar(Class *pClass, wxInfoBar *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_InfoBar();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxInfoBar *GetEntity() {
		return static_cast<wxInfoBar *>(_pEntity);
	}
	inline wxInfoBar *ReleaseEntity() {
		wxInfoBar *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxInfoBar");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
