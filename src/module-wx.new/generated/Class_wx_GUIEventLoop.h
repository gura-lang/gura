//----------------------------------------------------------------------------
// wxGUIEventLoop
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GUIEVENTLOOP_H__
#define __CLASS_WX_GUIEVENTLOOP_H__
#include <wx/evtloop.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGUIEventLoop
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GUIEventLoop);

//----------------------------------------------------------------------------
// Object declaration for wxGUIEventLoop
//----------------------------------------------------------------------------
class Object_wx_GUIEventLoop : public Object_wx_EventLoopBase {
public:
	Gura_DeclareObjectAccessor(wx_GUIEventLoop)
public:
	inline Object_wx_GUIEventLoop(wxGUIEventLoop *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EventLoopBase(Gura_UserClass(wx_GUIEventLoop), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GUIEventLoop(Class *pClass, wxGUIEventLoop *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EventLoopBase(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GUIEventLoop();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGUIEventLoop *GetEntity() {
		return static_cast<wxGUIEventLoop *>(_pEntity);
	}
	inline wxGUIEventLoop *ReleaseEntity() {
		wxGUIEventLoop *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGUIEventLoop");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
