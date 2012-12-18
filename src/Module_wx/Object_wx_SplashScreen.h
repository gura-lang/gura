//----------------------------------------------------------------------------
// wxSplashScreen
// extracted from splash.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SPLASHSCREEN_H__
#define __OBJECT_WX_SPLASHSCREEN_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSplashScreen
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SplashScreen);

//----------------------------------------------------------------------------
// Object declaration for wxSplashScreen
//----------------------------------------------------------------------------
class Object_wx_SplashScreen : public Object_wx_Frame {
public:
	Gura_DeclareObjectAccessor(wx_SplashScreen)
public:
	inline Object_wx_SplashScreen(wxSplashScreen *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(Gura_UserClass(wx_SplashScreen), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SplashScreen(Class *pClass, wxSplashScreen *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Frame(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SplashScreen();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSplashScreen *GetEntity() {
		return dynamic_cast<wxSplashScreen *>(_pEntity);
	}
	inline wxSplashScreen *ReleaseEntity() {
		wxSplashScreen *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSplashScreen");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
