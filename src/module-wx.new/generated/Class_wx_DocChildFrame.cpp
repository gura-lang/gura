//----------------------------------------------------------------------------
// wxDocChildFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocChildFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocChildFrame
//----------------------------------------------------------------------------
Object_wx_DocChildFrame::~Object_wx_DocChildFrame()
{
}

Object *Object_wx_DocChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocChildFrame:");
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
Gura_DeclareMethod(wx_DocChildFrame, wxDocChildFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "view", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocChildFrame, wxDocChildFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int view = arg.GetNumber(1)
	//int parent = arg.GetNumber(2)
	//int id = arg.GetNumber(3)
	//int title = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//int size = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxDocChildFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocChildFrame, ~wxDocChildFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocChildFrame, ~wxDocChildFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDocChildFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocChildFrame, GetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocChildFrame, GetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocChildFrame, GetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocChildFrame, GetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocChildFrame, SetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocChildFrame, SetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocChildFrame, SetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "view", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocChildFrame, SetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int view = arg.GetNumber(0)
	//pThis->GetEntity()->SetView();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocChildFrame)
{
	Gura_AssignMethod(wx_DocChildFrame, wxDocChildFrame);
	Gura_AssignMethod(wx_DocChildFrame, ~wxDocChildFrame);
	Gura_AssignMethod(wx_DocChildFrame, GetDocument);
	Gura_AssignMethod(wx_DocChildFrame, GetView);
	Gura_AssignMethod(wx_DocChildFrame, SetDocument);
	Gura_AssignMethod(wx_DocChildFrame, SetView);
}

Gura_ImplementDescendantCreator(wx_DocChildFrame)
{
	return new Object_wx_DocChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
