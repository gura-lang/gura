//----------------------------------------------------------------------------
// wxPenList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPenList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPenList
//----------------------------------------------------------------------------
Object_wx_PenList::~Object_wx_PenList()
{
}

Object *Object_wx_PenList::Clone() const
{
	return nullptr;
}

String Object_wx_PenList::ToString(bool exprFlag)
{
	String rtn("<wx.PenList:");
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
Gura_DeclareMethod(wx_PenList, wxPenList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PenList, wxPenList)
{
	Signal &sig = env.GetSignal();
	Object_wx_PenList *pThis = Object_wx_PenList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPenList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PenList, FindOrCreatePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PenList, FindOrCreatePen)
{
	Signal &sig = env.GetSignal();
	Object_wx_PenList *pThis = Object_wx_PenList::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//pThis->GetEntity()->FindOrCreatePen();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPenList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PenList)
{
	Gura_AssignMethod(wx_PenList, wxPenList);
	Gura_AssignMethod(wx_PenList, FindOrCreatePen);
}

Gura_ImplementDescendantCreator(wx_PenList)
{
	return new Object_wx_PenList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
