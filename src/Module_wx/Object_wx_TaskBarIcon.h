//----------------------------------------------------------------------------
// wxTaskBarIcon
// extracted from taskbar.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TASKBARICON_H__
#define __OBJECT_WX_TASKBARICON_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTaskBarIcon
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TaskBarIcon);

//----------------------------------------------------------------------------
// Object declaration for wxTaskBarIcon
//----------------------------------------------------------------------------
class Object_wx_TaskBarIcon : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_TaskBarIcon)
public:
	inline Object_wx_TaskBarIcon(wxTaskBarIcon *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_TaskBarIcon), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TaskBarIcon(Class *pClass, wxTaskBarIcon *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TaskBarIcon();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTaskBarIcon *GetEntity() {
		return dynamic_cast<wxTaskBarIcon *>(_pEntity);
	}
	inline wxTaskBarIcon *ReleaseEntity() {
		wxTaskBarIcon *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTaskBarIcon");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
