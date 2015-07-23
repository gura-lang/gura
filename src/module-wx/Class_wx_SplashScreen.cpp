//----------------------------------------------------------------------------
// wxSplashScreen
// extracted from splash.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SplashScreen: public wxSplashScreen, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_SplashScreen *_pObj;
public:
	inline wx_SplashScreen(const wxBitmap& bitmap, long splashStyle, int milliseconds, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxSplashScreen(bitmap, splashStyle, milliseconds, parent, id, pos, size, style), _pSig(nullptr), _pObj(nullptr) {}
	~wx_SplashScreen();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SplashScreen *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SplashScreen::~wx_SplashScreen()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SplashScreen::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSplashScreen
//----------------------------------------------------------------------------
Gura_DeclareFunction(SplashScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SplashScreen));
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "splashStyle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SplashScreen)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	long splashStyle = args.GetLong(1);
	int milliseconds = args.GetInt(2);
	wxWindow *parent = Object_wx_Window::GetObject(args, 3)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(4));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) pos = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(6)) size = Object_wx_Size::GetObject(args, 6)->GetEntity();
	long style = wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR|wxSTAY_ON_TOP;
	if (args.IsValid(7)) style = args.GetLong(7);
	wx_SplashScreen *pEntity = new wx_SplashScreen(*bitmap, splashStyle, milliseconds, parent, id, *pos, *size, style);
	Object_wx_SplashScreen *pObj = Object_wx_SplashScreen::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SplashScreen(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_SplashScreen, OnCloseWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplashScreen, OnCloseWindow)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnCloseWindow(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_SplashScreen, GetSplashStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplashScreen, GetSplashStyle)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetSplashStyle();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SplashScreen, GetSplashWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplashScreen, GetSplashWindow)
{
#if 0
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSplashScreenWindow *rtn = (wxSplashScreenWindow *)pThis->GetEntity()->GetSplashWindow();
	return ReturnValue(env, args, Value(new Object_wx_SplashScreenWindow(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SplashScreen, GetTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SplashScreen, GetTimeout)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTimeout();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSplashScreen
//----------------------------------------------------------------------------
Object_wx_SplashScreen::~Object_wx_SplashScreen()
{
}

Object *Object_wx_SplashScreen::Clone() const
{
	return nullptr;
}

String Object_wx_SplashScreen::ToString(bool exprFlag)
{
	String rtn("<wx.SplashScreen:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxSplashScreen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplashScreen)
{
	Gura_AssignFunction(SplashScreen);
	Gura_AssignMethod(wx_SplashScreen, OnCloseWindow);
	Gura_AssignMethod(wx_SplashScreen, GetSplashStyle);
	Gura_AssignMethod(wx_SplashScreen, GetSplashWindow);
	Gura_AssignMethod(wx_SplashScreen, GetTimeout);
}

Gura_ImplementDescendantCreator(wx_SplashScreen)
{
	return new Object_wx_SplashScreen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
