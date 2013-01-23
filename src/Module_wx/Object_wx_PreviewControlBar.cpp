//----------------------------------------------------------------------------
// wxPreviewControlBar
// extracted from prevwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PreviewControlBar: public wxPreviewControlBar, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PreviewControlBar *_pObj;
public:
	inline wx_PreviewControlBar(wxPrintPreview* preview, long buttons, wxWindow* parent, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPreviewControlBar(preview, buttons, parent, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_PreviewControlBar();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PreviewControlBar *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PreviewControlBar::~wx_PreviewControlBar()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PreviewControlBar::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(PreviewControlBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
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
	Object_wx_PreviewControlBar *pObj = Object_wx_PreviewControlBar::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PreviewControlBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_PreviewControlBar, CreateButtons)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewControlBar, CreateButtons)
{
	Object_wx_PreviewControlBar *pSelf = Object_wx_PreviewControlBar::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->CreateButtons();
	return Value::Null;
}

Gura_DeclareMethod(wx_PreviewControlBar, GetPrintPreview)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PreviewControlBar, GetPrintPreview)
{
	Object_wx_PreviewControlBar *pSelf = Object_wx_PreviewControlBar::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintPreview *rtn = (wxPrintPreview *)pSelf->GetEntity()->GetPrintPreview();
	return ReturnValue(env, sig, args, Value(new Object_wx_PrintPreview(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PreviewControlBar, GetZoomControl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PreviewControlBar, GetZoomControl)
{
	Object_wx_PreviewControlBar *pSelf = Object_wx_PreviewControlBar::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetZoomControl();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PreviewControlBar, SetZoomControl)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewControlBar, SetZoomControl)
{
	Object_wx_PreviewControlBar *pSelf = Object_wx_PreviewControlBar::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int percent = args.GetInt(0);
	pSelf->GetEntity()->SetZoomControl(percent);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPreviewControlBar
//----------------------------------------------------------------------------
Object_wx_PreviewControlBar::~Object_wx_PreviewControlBar()
{
}

Object *Object_wx_PreviewControlBar::Clone() const
{
	return NULL;
}

String Object_wx_PreviewControlBar::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PreviewControlBar:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PreviewControlBar::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PreviewControlBar);
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewControlBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewControlBar)
{
	Gura_AssignMethod(wx_PreviewControlBar, CreateButtons);
	Gura_AssignMethod(wx_PreviewControlBar, GetPrintPreview);
	Gura_AssignMethod(wx_PreviewControlBar, GetZoomControl);
	Gura_AssignMethod(wx_PreviewControlBar, SetZoomControl);
}

Gura_ImplementDescendantCreator(wx_PreviewControlBar)
{
	return new Object_wx_PreviewControlBar((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
