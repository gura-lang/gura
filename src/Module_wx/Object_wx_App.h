//----------------------------------------------------------------------------
// wxApp
// extracted from app.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_APP_H__
#define __OBJECT_WX_APP_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxApp
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_App);

//----------------------------------------------------------------------------
// Object declaration for wxApp
//----------------------------------------------------------------------------
class Object_wx_App : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_App)
public:
	inline Object_wx_App(wxApp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_App), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_App(Class *pClass, wxApp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_App();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxApp *GetEntity() {
		return dynamic_cast<wxApp *>(_pEntity);
	}
	inline wxApp *ReleaseEntity() {
		wxApp *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxApp");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
