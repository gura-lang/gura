//----------------------------------------------------------------------------
// wxLogGui
// extracted from log.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LOGGUI_H__
#define __OBJECT_WX_LOGGUI_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxLogGui *GetEntity() {
		return dynamic_cast<wxLogGui *>(_pEntity);
	}
	inline wxLogGui *ReleaseEntity() {
		wxLogGui *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxLogGui");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
