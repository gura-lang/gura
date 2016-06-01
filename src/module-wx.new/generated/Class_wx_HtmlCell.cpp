//----------------------------------------------------------------------------
// wxHtmlCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlCell
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlCell, wxHtmlCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, wxHtmlCell)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, AdjustPagebreak)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pagebreak", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "known_pagebreaks", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, AdjustPagebreak)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pagebreak = arg.GetNumber(0)
	//int known_pagebreaks = arg.GetNumber(1)
	//int pageHeight = arg.GetNumber(2)
	//pThis->GetEntity()->AdjustPagebreak();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "view_y1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "view_y2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, Draw)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int view_y1 = arg.GetNumber(3)
	//int view_y2 = arg.GetNumber(4)
	//int info = arg.GetNumber(5)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, DrawInvisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, DrawInvisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int info = arg.GetNumber(3)
	//pThis->GetEntity()->DrawInvisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "condition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, Find)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int condition = arg.GetNumber(0)
	//int param = arg.GetNumber(1)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetDescent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetDescent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDescent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetFirstChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetFirstChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFirstChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, GetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetLink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetMouseCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, GetMouseCursor)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->GetMouseCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetMouseCursorAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rePos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, GetMouseCursorAt)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int rePos = arg.GetNumber(1)
	//pThis->GetEntity()->GetMouseCursorAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetPosX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetPosX)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetPosY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetPosY)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlCell, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, ProcessMouseClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, ProcessMouseClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int event = arg.GetNumber(2)
	//pThis->GetEntity()->ProcessMouseClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int link = arg.GetNumber(0)
	//pThis->GetEntity()->SetLink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//pThis->GetEntity()->SetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlCell, SetPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlCell, SetPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlCell *pThis = Object_wx_HtmlCell::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetPos();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlCell)
{
	Gura_AssignMethod(wx_HtmlCell, wxHtmlCell);
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
	Gura_AssignMethod(wx_HtmlCell, GetMouseCursorAt);
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
