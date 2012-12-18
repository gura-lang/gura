//----------------------------------------------------------------------------
// wxHtmlCell
// extracted from htcell.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(AdjustPagebreak);
Gura_DeclarePrivUserSymbol(Draw);
Gura_DeclarePrivUserSymbol(DrawInvisible);
Gura_DeclarePrivUserSymbol(Find);
Gura_DeclarePrivUserSymbol(GetId);
Gura_DeclarePrivUserSymbol(GetLink);
Gura_DeclarePrivUserSymbol(GetMouseCursor);
Gura_DeclarePrivUserSymbol(Layout);
Gura_DeclarePrivUserSymbol(ProcessMouseClick);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlCell: public wxHtmlCell, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlCell *_pObj;
public:
	inline wx_HtmlCell() : wxHtmlCell(), _sig(NULL), _pObj(NULL) {}
	//virtual bool AdjustPagebreak(int * pagebreak);
	//virtual void Draw(wxDC& dc, int x, int y, int view_y1, int view_y2);
	//virtual void DrawInvisible(wxDC& dc, int x, int y);
	//virtual const wxHtmlCell* Find(int condition, const void* param);
	//virtual wxString GetId();
	//virtual wxHtmlLinkInfo* GetLink(int x, int y);
	//virtual wxCursor GetMouseCursor(wxHtmlWindowInterface* window);
	//virtual void Layout(int w);
	//virtual bool ProcessMouseClick(wxHtmlWindowInterface* window, const wxPoint& pos, const wxMouseEvent& event);
	~wx_HtmlCell();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlCell *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlCell::~wx_HtmlCell()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlCell::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlCell
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlCellEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlCellEmpty)
{
	wx_HtmlCell *pEntity = new wx_HtmlCell();
	Object_wx_HtmlCell *pObj = Object_wx_HtmlCell::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_HtmlCell(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_HtmlCell, AdjustPagebreak)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pagebreak", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, AdjustPagebreak)
{
#if 0
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pagebreak = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->AdjustPagebreak(pagebreak);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, Draw)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "view_y1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "view_y2", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlCell, Draw)
{
#if 0
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int view_y1 = args.GetInt(3);
	int view_y2 = args.GetInt(4);
	pSelf->GetEntity()->Draw(*dc, x, y, view_y1, view_y2);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, DrawInvisible)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlCell, DrawInvisible)
{
#if 0
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	pSelf->GetEntity()->DrawInvisible(*dc, x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, Find)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "condition", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, Find)
{
#if 0
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int condition = args.GetInt(0);
	int param = args.GetInt(1);
	wxHtmlCell *rtn = (wxHtmlCell *)pSelf->GetEntity()->Find(condition, param);
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlCell(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, GetDescent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetDescent)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetDescent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetFirstChild)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetFirstChild)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlCell *rtn = (wxHtmlCell *)pSelf->GetEntity()->GetFirstChild();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetHeight)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetId)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetId();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlCell, GetLink)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetLink)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = 0;
	if (args.IsValid(0)) x = args.GetInt(0);
	int y = 0;
	if (args.IsValid(1)) y = args.GetInt(1);
	wxHtmlLinkInfo *rtn = (wxHtmlLinkInfo *)pSelf->GetEntity()->GetLink(x, y);
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlLinkInfo(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetMouseCursor)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_HtmlWindowInterface, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetMouseCursor)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlWindowInterface *window = Object_wx_HtmlWindowInterface::GetObject(args, 0)->GetEntity();
	wxCursor rtn = pSelf->GetEntity()->GetMouseCursor(window);
	return ReturnValue(env, sig, args, Value(new Object_wx_Cursor(new wxCursor(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlCell, GetNext)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetNext)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlCell *rtn = (wxHtmlCell *)pSelf->GetEntity()->GetNext();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetParent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetParent)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pSelf->GetEntity()->GetParent();
	return ReturnValue(env, sig, args, Value(new Object_wx_HtmlContainerCell(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetPosX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetPosX)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetPosX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetPosY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetPosY)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetPosY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetWidth)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, Layout)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, Layout)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int w = args.GetInt(0);
	pSelf->GetEntity()->Layout(w);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, ProcessMouseClick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_HtmlWindowInterface, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_MouseEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, ProcessMouseClick)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlWindowInterface *window = Object_wx_HtmlWindowInterface::GetObject(args, 0)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	wxMouseEvent *event = Object_wx_MouseEvent::GetObject(args, 2)->GetEntity();
	bool rtn = pSelf->GetEntity()->ProcessMouseClick(window, *pos, *event);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, SetId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetId)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString id = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, SetLink)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "link", VTYPE_wx_HtmlLinkInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetLink)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlLinkInfo *link = Object_wx_HtmlLinkInfo::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetLink(*link);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, SetNext)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cell", VTYPE_wx_HtmlCell, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetNext)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlCell *cell = Object_wx_HtmlCell::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetNext(cell);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, SetParent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "p", VTYPE_wx_HtmlContainerCell, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetParent)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxHtmlContainerCell *p = Object_wx_HtmlContainerCell::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetParent(p);
	return Value::Null;
}

Gura_DeclareMethod(wx_HtmlCell, SetPos)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetPos)
{
	Object_wx_HtmlCell *pSelf = Object_wx_HtmlCell::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pSelf->GetEntity()->SetPos(x, y);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlCell
//----------------------------------------------------------------------------
Object_wx_HtmlCell::~Object_wx_HtmlCell()
{
}

Object *Object_wx_HtmlCell::Clone() const
{
	return NULL;
}

String Object_wx_HtmlCell::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlCell:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_HtmlCell::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(AdjustPagebreak);
	Gura_RealizeUserSymbol(Draw);
	Gura_RealizeUserSymbol(DrawInvisible);
	Gura_RealizeUserSymbol(Find);
	Gura_RealizeUserSymbol(GetId);
	Gura_RealizeUserSymbol(GetLink);
	Gura_RealizeUserSymbol(GetMouseCursor);
	Gura_RealizeUserSymbol(Layout);
	Gura_RealizeUserSymbol(ProcessMouseClick);
	Gura_AssignFunction(HtmlCellEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlCell)
{
	Gura_AssignMethod(wx_HtmlCell, AdjustPagebreak);
	Gura_AssignMethod(wx_HtmlCell, Draw);
	Gura_AssignMethod(wx_HtmlCell, DrawInvisible);
	Gura_AssignMethod(wx_HtmlCell, Find);
	Gura_AssignMethod(wx_HtmlCell, GetDescent);
	Gura_AssignMethod(wx_HtmlCell, GetFirstChild);
	Gura_AssignMethod(wx_HtmlCell, GetHeight);
	Gura_AssignMethod(wx_HtmlCell, GetId);
	Gura_AssignMethod(wx_HtmlCell, GetLink);
	Gura_AssignMethod(wx_HtmlCell, GetMouseCursor);
	Gura_AssignMethod(wx_HtmlCell, GetNext);
	Gura_AssignMethod(wx_HtmlCell, GetParent);
	Gura_AssignMethod(wx_HtmlCell, GetPosX);
	Gura_AssignMethod(wx_HtmlCell, GetPosY);
	Gura_AssignMethod(wx_HtmlCell, GetWidth);
	Gura_AssignMethod(wx_HtmlCell, Layout);
	Gura_AssignMethod(wx_HtmlCell, ProcessMouseClick);
	Gura_AssignMethod(wx_HtmlCell, SetId);
	Gura_AssignMethod(wx_HtmlCell, SetLink);
	Gura_AssignMethod(wx_HtmlCell, SetNext);
	Gura_AssignMethod(wx_HtmlCell, SetParent);
	Gura_AssignMethod(wx_HtmlCell, SetPos);
}

Gura_ImplementDescendantCreator(wx_HtmlCell)
{
	return new Object_wx_HtmlCell((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
