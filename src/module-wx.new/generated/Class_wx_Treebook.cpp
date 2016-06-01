//----------------------------------------------------------------------------
// wxTreebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreebook
//----------------------------------------------------------------------------
Object_wx_Treebook::~Object_wx_Treebook()
{
}

Object *Object_wx_Treebook::Clone() const
{
	return nullptr;
}

String Object_wx_Treebook::ToString(bool exprFlag)
{
	String rtn("<wx.Treebook:");
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
Gura_DeclareMethod(wx_Treebook, wxTreebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Treebook, wxTreebook)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTreebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, wxTreebook_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, wxTreebook_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxTreebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, ~wxTreebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Treebook, ~wxTreebook)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxTreebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, AddPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, AddPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int bSelect = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//pThis->GetEntity()->AddPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, AddSubPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, AddSubPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int bSelect = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//pThis->GetEntity()->AddSubPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, CollapseNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, CollapseNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageId = arg.GetNumber(0)
	//pThis->GetEntity()->CollapseNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, DeletePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, DeletePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pagePos = arg.GetNumber(0)
	//pThis->GetEntity()->DeletePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, ExpandNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "expand", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, ExpandNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageId = arg.GetNumber(0)
	//int expand = arg.GetNumber(1)
	//pThis->GetEntity()->ExpandNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, GetPageParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, GetPageParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Treebook, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, InsertPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pagePos = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int bSelect = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, InsertSubPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bSelect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, InsertSubPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pagePos = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int bSelect = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//pThis->GetEntity()->InsertSubPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, IsNodeExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, IsNodeExpanded)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageId = arg.GetNumber(0)
	//pThis->GetEntity()->IsNodeExpanded();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTreebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Treebook)
{
	Gura_AssignMethod(wx_Treebook, wxTreebook);
	Gura_AssignMethod(wx_Treebook, wxTreebook_1);
	Gura_AssignMethod(wx_Treebook, ~wxTreebook);
	Gura_AssignMethod(wx_Treebook, AddPage);
	Gura_AssignMethod(wx_Treebook, AddSubPage);
	Gura_AssignMethod(wx_Treebook, CollapseNode);
	Gura_AssignMethod(wx_Treebook, Create);
	Gura_AssignMethod(wx_Treebook, DeletePage);
	Gura_AssignMethod(wx_Treebook, ExpandNode);
	Gura_AssignMethod(wx_Treebook, GetPageParent);
	Gura_AssignMethod(wx_Treebook, GetSelection);
	Gura_AssignMethod(wx_Treebook, InsertPage);
	Gura_AssignMethod(wx_Treebook, InsertSubPage);
	Gura_AssignMethod(wx_Treebook, IsNodeExpanded);
}

Gura_ImplementDescendantCreator(wx_Treebook)
{
	return new Object_wx_Treebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
