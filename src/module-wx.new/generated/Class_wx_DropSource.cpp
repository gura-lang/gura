//----------------------------------------------------------------------------
// wxDropSource
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDropSource
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDropSource
//----------------------------------------------------------------------------
Object_wx_DropSource::~Object_wx_DropSource()
{
}

Object *Object_wx_DropSource::Clone() const
{
	return nullptr;
}

String Object_wx_DropSource::ToString(bool exprFlag)
{
	String rtn("<wx.DropSource:");
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
Gura_DeclareMethod(wx_DropSource, wxDropSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, wxDropSource)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int iconCopy = arg.GetNumber(1)
	//int iconMove = arg.GetNumber(2)
	//int iconNone = arg.GetNumber(3)
	//pThis->GetEntity()->wxDropSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, wxDropSource_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, wxDropSource_1)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int win = arg.GetNumber(1)
	//int iconCopy = arg.GetNumber(2)
	//int iconMove = arg.GetNumber(3)
	//int iconNone = arg.GetNumber(4)
	//pThis->GetEntity()->wxDropSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, wxDropSource_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, wxDropSource_2)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int iconCopy = arg.GetNumber(1)
	//int iconMove = arg.GetNumber(2)
	//int iconNone = arg.GetNumber(3)
	//pThis->GetEntity()->wxDropSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, wxDropSource_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, wxDropSource_3)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int win = arg.GetNumber(1)
	//int iconCopy = arg.GetNumber(2)
	//int iconMove = arg.GetNumber(3)
	//int iconNone = arg.GetNumber(4)
	//pThis->GetEntity()->wxDropSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, DoDragDrop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, DoDragDrop)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->DoDragDrop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, GetDataObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropSource, GetDataObject)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, GiveFeedback)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, GiveFeedback)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int effect = arg.GetNumber(0)
	//pThis->GetEntity()->GiveFeedback();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, SetCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, SetCursor)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->SetCursor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, SetIcon)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropSource, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, SetData)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDropSource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropSource)
{
	Gura_AssignMethod(wx_DropSource, wxDropSource);
	Gura_AssignMethod(wx_DropSource, wxDropSource_1);
	Gura_AssignMethod(wx_DropSource, wxDropSource_2);
	Gura_AssignMethod(wx_DropSource, wxDropSource_3);
	Gura_AssignMethod(wx_DropSource, DoDragDrop);
	Gura_AssignMethod(wx_DropSource, GetDataObject);
	Gura_AssignMethod(wx_DropSource, GiveFeedback);
	Gura_AssignMethod(wx_DropSource, SetCursor);
	Gura_AssignMethod(wx_DropSource, SetIcon);
	Gura_AssignMethod(wx_DropSource, SetData);
}

Gura_ImplementDescendantCreator(wx_DropSource)
{
	return new Object_wx_DropSource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
