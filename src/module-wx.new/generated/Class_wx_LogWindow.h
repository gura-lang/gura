//----------------------------------------------------------------------------
// wxLogWindow
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOGWINDOW_H__
#define __CLASS_WX_LOGWINDOW_H__
#include <wx/log.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLogWindow
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LogWindow);

//----------------------------------------------------------------------------
// Object declaration for wxLogWindow
//----------------------------------------------------------------------------
class Object_wx_LogWindow : public Object_wx_LogInterposer {
public:
	Gura_DeclareObjectAccessor(wx_LogWindow)
public:
	inline Object_wx_LogWindow(wxLogWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogInterposer(Gura_UserClass(wx_LogWindow), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_LogWindow(Class *pClass, wxLogWindow *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_LogInterposer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_LogWindow();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxLogWindow *GetEntity() {
		return static_cast<wxLogWindow *>(_pEntity);
	}
	inline wxLogWindow *ReleaseEntity() {
		wxLogWindow *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxLogWindow");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
