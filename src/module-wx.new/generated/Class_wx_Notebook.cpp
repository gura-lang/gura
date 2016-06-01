//----------------------------------------------------------------------------
// wxNotebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNotebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNotebook
//----------------------------------------------------------------------------
Object_wx_Notebook::~Object_wx_Notebook()
{
}

Object *Object_wx_Notebook::Clone() const
{
	return nullptr;
}

String Object_wx_Notebook::ToString(bool exprFlag)
{
	String rtn("<wx.Notebook:");
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
Gura_DeclareMethod(wx_Notebook, wxNotebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, wxNotebook)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxNotebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, wxNotebook_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, wxNotebook_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxNotebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, ~wxNotebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, ~wxNotebook)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxNotebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_Notebook, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, GetRowCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, GetThemeBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, GetThemeBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetThemeBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, OnSelChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, OnSelChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnSelChange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, SetPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "padding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPadding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int padding = arg.GetNumber(0)
	//pThis->GetEntity()->SetPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, GetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, GetPageImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nPage = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, SetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPageImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int image = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, GetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, GetPageText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nPage = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, SetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPageText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Notebook, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, ChangeSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, ChangeSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, InsertPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int select = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Notebook)
{
	Gura_AssignMethod(wx_Notebook, wxNotebook);
	Gura_AssignMethod(wx_Notebook, wxNotebook_1);
	Gura_AssignMethod(wx_Notebook, ~wxNotebook);
	Gura_AssignMethod(wx_Notebook, Create);
	Gura_AssignMethod(wx_Notebook, GetRowCount);
	Gura_AssignMethod(wx_Notebook, GetThemeBackgroundColour);
	Gura_AssignMethod(wx_Notebook, OnSelChange);
	Gura_AssignMethod(wx_Notebook, SetPadding);
	Gura_AssignMethod(wx_Notebook, GetPageImage);
	Gura_AssignMethod(wx_Notebook, SetPageImage);
	Gura_AssignMethod(wx_Notebook, GetPageText);
	Gura_AssignMethod(wx_Notebook, SetPageText);
	Gura_AssignMethod(wx_Notebook, GetSelection);
	Gura_AssignMethod(wx_Notebook, SetSelection);
	Gura_AssignMethod(wx_Notebook, ChangeSelection);
	Gura_AssignMethod(wx_Notebook, InsertPage);
}

Gura_ImplementDescendantCreator(wx_Notebook)
{
	return new Object_wx_Notebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
