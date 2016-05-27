//----------------------------------------------------------------------------
// wxLogGui
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGGUI_H__
#define __CLASS_WX_LOGGUI_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogGui
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogGui);

//----------------------------------------------------------------------------
// Object declaration for wxLogGui
//----------------------------------------------------------------------------
class Object_wx_LogGui : public Object_wx_Log {
public:
	Gura_DeclareObjectAccessor(wx_LogGui)
public:
	inline Object_wx_LogGui(wxLogGui *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(Gura_UserClass(wx_LogGui), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogGui(Class *pClass, wxLogGui *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Log(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogGui();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogGui *GetEntity() {
		return static_cast<wxLogGui *>(_pEntity);
	}
	inline wxLogGui *ReleaseEntity() {
		wxLogGui *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLogGui");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
