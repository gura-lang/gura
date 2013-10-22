//----------------------------------------------------------------------------
// wxAuiDockArt
// extracted from auidockart.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(DrawBackground);
Gura_DeclarePrivUserSymbol(DrawBorder);
Gura_DeclarePrivUserSymbol(DrawCaption);
Gura_DeclarePrivUserSymbol(DrawGripper);
Gura_DeclarePrivUserSymbol(DrawPaneButton);
Gura_DeclarePrivUserSymbol(DrawSash);
Gura_DeclarePrivUserSymbol(GetColor);
Gura_DeclarePrivUserSymbol(GetColour);
Gura_DeclarePrivUserSymbol(GetFont);
Gura_DeclarePrivUserSymbol(GetMetric);
Gura_DeclarePrivUserSymbol(SetColor);
Gura_DeclarePrivUserSymbol(SetColour);
Gura_DeclarePrivUserSymbol(SetFont);
Gura_DeclarePrivUserSymbol(SetMetric);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AuiDockArt: public wxAuiDockArt, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AuiDockArt *_pObj;
public:
	//inline wx_AuiDockArt() : wxAuiDockArt(), _sig(NULL), _pObj(NULL) {}
	//virtual void DrawBackground(wxDC& dc, wxWindow* window, int orientation, const wxRect& rect);
	//virtual void DrawBorder(wxDC& dc, wxWindow* window, const wxRect& rect, wxAuiPaneInfo& pane);
	//virtual void DrawCaption(wxDC& dc, wxWindow* window, const wxString& text, const wxRect& rect, wxAuiPaneInfo& pane);
	//virtual void DrawGripper(wxDC& dc, wxWindow* window, const wxRect& rect, wxAuiPaneInfo& pane);
	//virtual void DrawPaneButton(wxDC& dc, wxWindow* window, int button, int button_state, const wxRect& rect, wxAuiPaneInfo& pane);
	//virtual void DrawSash(wxDC& dc, wxWindow* window, int orientation, const wxRect& rect);
	//virtual wxColour GetColor(int id);
	//virtual wxColour GetColour(int id);
	//virtual wxFont GetFont(int id);
	//virtual int GetMetric(int id);
	//virtual void SetColor(int id, const wxColour& color);
	//virtual void SetColour(int id, const wxColor& colour);
	//virtual void SetFont(int id, const wxFont& font);
	//virtual void SetMetric(int id, int new_val);
	~wx_AuiDockArt();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AuiDockArt *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AuiDockArt::~wx_AuiDockArt()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AuiDockArt::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiDockArt
//----------------------------------------------------------------------------
Gura_DeclareFunction(AuiDockArtEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_AuiDockArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(AuiDockArtEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_AuiDockArt *pEntity = new wx_AuiDockArt();
	Object_wx_AuiDockArt *pObj = Object_wx_AuiDockArt::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_AuiDockArt(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawBackground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawBackground)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(args, 1)->GetEntity();
	int orientation = args.GetInt(2);
	wxRect *rect = Object_wx_Rect::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->DrawBackground(*dc, window, orientation, *rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawBorder)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawBorder)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->DrawBorder(*dc, window, *rect, *pane);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawCaption)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawCaption)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(2));
	wxRect *rect = Object_wx_Rect::GetObject(args, 3)->GetEntity();
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->DrawCaption(*dc, window, text, *rect, *pane);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawGripper)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawGripper)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->DrawGripper(*dc, window, *rect, *pane);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawPaneButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "button_state", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "pane", VTYPE_wx_AuiPaneInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawPaneButton)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(args, 1)->GetEntity();
	int button = args.GetInt(2);
	int button_state = args.GetInt(3);
	wxRect *rect = Object_wx_Rect::GetObject(args, 4)->GetEntity();
	wxAuiPaneInfo *pane = Object_wx_AuiPaneInfo::GetObject(args, 5)->GetEntity();
	pThis->GetEntity()->DrawPaneButton(*dc, window, button, button_state, *rect, *pane);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawSash)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawSash)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxWindow *window = Object_wx_Window::GetObject(args, 1)->GetEntity();
	int orientation = args.GetInt(2);
	wxRect *rect = Object_wx_Rect::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->DrawSash(*dc, window, orientation, *rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, GetColor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiDockArt, GetColor)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxColour rtn = pThis->GetEntity()->GetColor(id);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiDockArt, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiDockArt, GetColour)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxColour rtn = pThis->GetEntity()->GetColour(id);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiDockArt, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiDockArt, GetFont)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxFont rtn = pThis->GetEntity()->GetFont(id);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_AuiDockArt, GetMetric)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_AuiDockArt, GetMetric)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetMetric(id);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_AuiDockArt, SetColor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "color", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, SetColor)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxColour *color = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetColor(id, *color);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, SetColour)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxColor *colour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetColour(id, *colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, SetFont)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	wxFont *font = Object_wx_Font::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetFont(id, *font);
	return Value::Null;
}

Gura_DeclareMethod(wx_AuiDockArt, SetMetric)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "new_val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, SetMetric)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	int new_val = args.GetInt(1);
	pThis->GetEntity()->SetMetric(id, new_val);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxAuiDockArt
//----------------------------------------------------------------------------
Object_wx_AuiDockArt::~Object_wx_AuiDockArt()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_AuiDockArt::Clone() const
{
	return NULL;
}

String Object_wx_AuiDockArt::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AuiDockArt:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiDockArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiDockArt)
{
	Gura_RealizeUserSymbol(DrawBackground);
	Gura_RealizeUserSymbol(DrawBorder);
	Gura_RealizeUserSymbol(DrawCaption);
	Gura_RealizeUserSymbol(DrawGripper);
	Gura_RealizeUserSymbol(DrawPaneButton);
	Gura_RealizeUserSymbol(DrawSash);
	Gura_RealizeUserSymbol(GetColor);
	Gura_RealizeUserSymbol(GetColour);
	Gura_RealizeUserSymbol(GetFont);
	Gura_RealizeUserSymbol(GetMetric);
	Gura_RealizeUserSymbol(SetColor);
	Gura_RealizeUserSymbol(SetColour);
	Gura_RealizeUserSymbol(SetFont);
	Gura_RealizeUserSymbol(SetMetric);
	Gura_AssignFunction(AuiDockArtEmpty);
	Gura_AssignMethod(wx_AuiDockArt, DrawBackground);
	Gura_AssignMethod(wx_AuiDockArt, DrawBorder);
	Gura_AssignMethod(wx_AuiDockArt, DrawCaption);
	Gura_AssignMethod(wx_AuiDockArt, DrawGripper);
	Gura_AssignMethod(wx_AuiDockArt, DrawPaneButton);
	Gura_AssignMethod(wx_AuiDockArt, DrawSash);
	Gura_AssignMethod(wx_AuiDockArt, GetColor);
	Gura_AssignMethod(wx_AuiDockArt, GetColour);
	Gura_AssignMethod(wx_AuiDockArt, GetFont);
	Gura_AssignMethod(wx_AuiDockArt, GetMetric);
	Gura_AssignMethod(wx_AuiDockArt, SetColor);
	Gura_AssignMethod(wx_AuiDockArt, SetColour);
	Gura_AssignMethod(wx_AuiDockArt, SetFont);
	Gura_AssignMethod(wx_AuiDockArt, SetMetric);
}

Gura_ImplementDescendantCreator(wx_AuiDockArt)
{
	return new Object_wx_AuiDockArt((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
