//----------------------------------------------------------------------------
// wxMiniFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMiniFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMiniFrame
//----------------------------------------------------------------------------
Object_wx_MiniFrame::~Object_wx_MiniFrame()
{
}

Object *Object_wx_MiniFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MiniFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MiniFrame:");
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
Gura_DeclareMethodAlias(wx_MiniFrame, __wxMiniFrame, "wxMiniFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MiniFrame, __wxMiniFrame)
{
	Object_wx_MiniFrame *pThis = Object_wx_MiniFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMiniFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MiniFrame, __wxMiniFrame_1, "wxMiniFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MiniFrame, __wxMiniFrame_1)
{
	Object_wx_MiniFrame *pThis = Object_wx_MiniFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxMiniFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MiniFrame, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MiniFrame, __Create)
{
	Object_wx_MiniFrame *pThis = Object_wx_MiniFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMiniFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MiniFrame)
{
	Gura_AssignMethod(wx_MiniFrame, __wxMiniFrame);
	Gura_AssignMethod(wx_MiniFrame, __wxMiniFrame_1);
	Gura_AssignMethod(wx_MiniFrame, __Create);
}

Gura_ImplementDescendantCreator(wx_MiniFrame)
{
	return new Object_wx_MiniFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
