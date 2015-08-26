//----------------------------------------------------------------------------
// wxHtmlCell
// extracted from htcell.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	//Gura::Signal *_pSig;
	Object_wx_HtmlCell *_pObj;
public:
	inline wx_HtmlCell() : wxHtmlCell(), _pObj(nullptr) {}
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
	inline void AssocWithGura(Object_wx_HtmlCell *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlCell::~wx_HtmlCell()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlCell::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlCell
//----------------------------------------------------------------------------
Gura_DeclareFunction(HtmlCellEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlCell));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(HtmlCellEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_HtmlCell *pEntity = new wx_HtmlCell();
	Object_wx_HtmlCell *pObj = Object_wx_HtmlCell::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_HtmlCell(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_HtmlCell, AdjustPagebreak)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "pagebreak", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, AdjustPagebreak)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pagebreak = args.GetInt(0);
	bool rtn = pThis->GetEntity()->AdjustPagebreak(pagebreak);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
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
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int view_y1 = args.GetInt(3);
	int view_y2 = args.GetInt(4);
	pThis->GetEntity()->Draw(*dc, x, y, view_y1, view_y2);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, DrawInvisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_HtmlCell, DrawInvisible)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	pThis->GetEntity()->DrawInvisible(*dc, x, y);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "condition", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, Find)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int condition = args.GetInt(0);
	int param = args.GetInt(1);
	wxHtmlCell *rtn = (wxHtmlCell *)pThis->GetEntity()->Find(condition, param);
	return ReturnValue(env, args, Value(new Object_wx_HtmlCell(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetDescent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetDescent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetFirstChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetFirstChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlCell *rtn = (wxHtmlCell *)pThis->GetEntity()->GetFirstChild();
	return ReturnValue(env, args, Value(new Object_wx_HtmlCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetId();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_HtmlCell, GetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = 0;
	if (args.IsValid(0)) x = args.GetInt(0);
	int y = 0;
	if (args.IsValid(1)) y = args.GetInt(1);
	wxHtmlLinkInfo *rtn = (wxHtmlLinkInfo *)pThis->GetEntity()->GetLink(x, y);
	return ReturnValue(env, args, Value(new Object_wx_HtmlLinkInfo(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetMouseCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_HtmlWindowInterface, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetMouseCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlWindowInterface *window = Object_wx_HtmlWindowInterface::GetObject(args, 0)->GetEntity();
	wxCursor rtn = pThis->GetEntity()->GetMouseCursor(window);
	return ReturnValue(env, args, Value(new Object_wx_Cursor(new wxCursor(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_HtmlCell, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlCell *rtn = (wxHtmlCell *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, args, Value(new Object_wx_HtmlCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlContainerCell *rtn = (wxHtmlContainerCell *)pThis->GetEntity()->GetParent();
	return ReturnValue(env, args, Value(new Object_wx_HtmlContainerCell(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_HtmlCell, GetPosX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetPosX)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPosX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetPosY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetPosY)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPosY();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int w = args.GetInt(0);
	pThis->GetEntity()->Layout(w);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, ProcessMouseClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_HtmlWindowInterface, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "event", VTYPE_wx_MouseEvent, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_HtmlCell, ProcessMouseClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlWindowInterface *window = Object_wx_HtmlWindowInterface::GetObject(args, 0)->GetEntity();
	wxPoint *pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	wxMouseEvent *event = Object_wx_MouseEvent::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->ProcessMouseClick(window, *pos, *event);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_HtmlCell, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString id = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "link", VTYPE_wx_HtmlLinkInfo, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlLinkInfo *link = Object_wx_HtmlLinkInfo::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetLink(*link);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "cell", VTYPE_wx_HtmlCell, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlCell *cell = Object_wx_HtmlCell::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNext(cell);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "p", VTYPE_wx_HtmlContainerCell, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxHtmlContainerCell *p = Object_wx_HtmlContainerCell::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetParent(p);
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->SetPos(x, y);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxHtmlCell
//----------------------------------------------------------------------------
Object_wx_HtmlCell::~Object_wx_HtmlCell()
{
}

Object *Object_wx_HtmlCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlCell:");
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
// Class implementation for wxHtmlCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlCell)
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
	return new Object_wx_HtmlCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
