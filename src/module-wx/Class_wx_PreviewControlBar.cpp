//----------------------------------------------------------------------------
// wxPreviewControlBar
// extracted from prevwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PreviewControlBar: public wxPreviewControlBar, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PreviewControlBar *_pObj;
public:
	inline wx_PreviewControlBar(wxPrintPreview* preview, long buttons, wxWindow* parent, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPreviewControlBar(preview, buttons, parent, pos, size, style, name), _pObj(nullptr) {}
	~wx_PreviewControlBar();
	inline void AssocWithGura(Object_wx_PreviewControlBar *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PreviewControlBar::~wx_PreviewControlBar()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PreviewControlBar::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(PreviewControlBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PreviewControlBar));
	DeclareArg(env, "preview", VTYPE_wx_PrintPreview, OCCUR_Once);
	DeclareArg(env, "buttons", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PreviewControlBar)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPrintPreview *preview = Object_wx_PrintPreview::GetObject(args, 0)->GetEntity();
	long buttons = args.GetLong(1);
	wxWindow *parent = Object_wx_Window::GetObject(args, 2)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("panel");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_PreviewControlBar *pEntity = new wx_PreviewControlBar(preview, buttons, parent, *pos, *size, style, name);
	Object_wx_PreviewControlBar *pObj = Object_wx_PreviewControlBar::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PreviewControlBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_PreviewControlBar, CreateButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, CreateButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->CreateButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewControlBar, GetPrintPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PreviewControlBar, GetPrintPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintPreview *rtn = (wxPrintPreview *)pThis->GetEntity()->GetPrintPreview();
	return ReturnValue(env, args, Value(new Object_wx_PrintPreview(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PreviewControlBar, GetZoomControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PreviewControlBar, GetZoomControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetZoomControl();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PreviewControlBar, SetZoomControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewControlBar, SetZoomControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewControlBar *pThis = Object_wx_PreviewControlBar::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int percent = args.GetInt(0);
	pThis->GetEntity()->SetZoomControl(percent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxPreviewControlBar
//----------------------------------------------------------------------------
Object_wx_PreviewControlBar::~Object_wx_PreviewControlBar()
{
}

Object *Object_wx_PreviewControlBar::Clone() const
{
	return nullptr;
}

String Object_wx_PreviewControlBar::ToString(bool exprFlag)
{
	String rtn("<wx.PreviewControlBar:");
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
// Class implementation for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewControlBar)
{
	Gura_AssignFunction(PreviewControlBar);
	Gura_AssignMethod(wx_PreviewControlBar, CreateButtons);
	Gura_AssignMethod(wx_PreviewControlBar, GetPrintPreview);
	Gura_AssignMethod(wx_PreviewControlBar, GetZoomControl);
	Gura_AssignMethod(wx_PreviewControlBar, SetZoomControl);
}

Gura_ImplementDescendantCreator(wx_PreviewControlBar)
{
	return new Object_wx_PreviewControlBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
