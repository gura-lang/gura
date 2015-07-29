//----------------------------------------------------------------------------
// wxDisplay
// extracted from display.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Display: public wxDisplay, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Display *_pObj;
public:
	inline wx_Display(unsigned index) : wxDisplay(index), _pObj(nullptr) {}
	~wx_Display();
	inline void AssocWithGura(Object_wx_Display *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Display::~wx_Display()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Display::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDisplay
//----------------------------------------------------------------------------
Gura_DeclareFunction(Display)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Display));
	DeclareArg(env, "index", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Display)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	unsigned index = 0;
	if (args.IsValid(0)) index = args.GetInt(0);
	wx_Display *pEntity = new wx_Display(index);
	Object_wx_Display *pObj = Object_wx_Display::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Display(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Display, ChangeMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "mode", VTYPE_wx_VideoMode, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, ChangeMode)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxVideoMode *mode = (wxVideoMode *)(&wxDefaultVideoMode);
	if (args.IsValid(0)) mode = Object_wx_VideoMode::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->ChangeMode(*mode);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Display, GetClientArea)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, GetClientArea)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetClientArea();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Display, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Display, GetCount)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	unsigned rtn = wxDisplay::GetCount();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Display, GetCurrentMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, GetCurrentMode)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxVideoMode rtn = pThis->GetEntity()->GetCurrentMode();
	return ReturnValue(env, args, Value(new Object_wx_VideoMode(new wxVideoMode(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Display, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, GetDepth)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDepth();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Display, GetFromPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Display, GetFromPoint)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int rtn = wxDisplay::GetFromPoint(*pt);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Display, GetFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Display, GetFromWindow)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int rtn = wxDisplay::GetFromWindow(win);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Display, GetGeometry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, GetGeometry)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetGeometry();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Display, GetModes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "mode", VTYPE_wx_VideoMode, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, GetModes)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxVideoMode *mode = (wxVideoMode *)(&wxDefaultVideoMode);
	if (args.IsValid(0)) mode = Object_wx_VideoMode::GetObject(args, 0)->GetEntity();
	wxArrayVideoModes rtn = pThis->GetEntity()->GetModes(*mode);
	return ReturnValue(env, args, Value(new Object_wx_ArrayVideoModes(new wxArrayVideoModes(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Display, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, GetName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetName();
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Display, IsPrimary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Display, IsPrimary)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Display *pThis = Object_wx_Display::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPrimary();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDisplay
//----------------------------------------------------------------------------
Object_wx_Display::~Object_wx_Display()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Display::Clone() const
{
	return nullptr;
}

String Object_wx_Display::ToString(bool exprFlag)
{
	String rtn("<wx.Display:");
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
// Class implementation for wxDisplay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Display)
{
	Gura_AssignFunction(Display);
	Gura_AssignMethod(wx_Display, ChangeMode);
	Gura_AssignMethod(wx_Display, GetClientArea);
	Gura_AssignMethod(wx_Display, GetCount);
	Gura_AssignMethod(wx_Display, GetCurrentMode);
	Gura_AssignMethod(wx_Display, GetDepth);
	Gura_AssignMethod(wx_Display, GetFromPoint);
	Gura_AssignMethod(wx_Display, GetFromWindow);
	Gura_AssignMethod(wx_Display, GetGeometry);
	Gura_AssignMethod(wx_Display, GetModes);
	Gura_AssignMethod(wx_Display, GetName);
	Gura_AssignMethod(wx_Display, IsPrimary);
}

Gura_ImplementDescendantCreator(wx_Display)
{
	return new Object_wx_Display((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
