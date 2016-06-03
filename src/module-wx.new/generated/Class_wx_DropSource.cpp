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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxDropSource, "wxDropSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDropSource)
{
	//int win = arg.GetNumber(0)
	//int iconCopy = arg.GetNumber(1)
	//int iconMove = arg.GetNumber(2)
	//int iconNone = arg.GetNumber(3)
	//wxDropSource();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDropSource_1, "wxDropSource_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDropSource_1)
{
	//int data = arg.GetNumber(0)
	//int win = arg.GetNumber(1)
	//int iconCopy = arg.GetNumber(2)
	//int iconMove = arg.GetNumber(3)
	//int iconNone = arg.GetNumber(4)
	//wxDropSource();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDropSource_2, "wxDropSource_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDropSource_2)
{
	//int win = arg.GetNumber(0)
	//int iconCopy = arg.GetNumber(1)
	//int iconMove = arg.GetNumber(2)
	//int iconNone = arg.GetNumber(3)
	//wxDropSource();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDropSource_3, "wxDropSource_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDropSource_3)
{
	//int data = arg.GetNumber(0)
	//int win = arg.GetNumber(1)
	//int iconCopy = arg.GetNumber(2)
	//int iconMove = arg.GetNumber(3)
	//int iconNone = arg.GetNumber(4)
	//wxDropSource();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DropSource, __DoDragDrop, "DoDragDrop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, __DoDragDrop)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->DoDragDrop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropSource, __GetDataObject, "GetDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropSource, __GetDataObject)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropSource, __GiveFeedback, "GiveFeedback")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, __GiveFeedback)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int effect = arg.GetNumber(0)
	//pThis->GetEntity()->GiveFeedback();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropSource, __SetCursor, "SetCursor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, __SetCursor)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//int cursor = arg.GetNumber(1)
	//pThis->GetEntity()->SetCursor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropSource, __SetIcon, "SetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, __SetIcon)
{
	Object_wx_DropSource *pThis = Object_wx_DropSource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//int icon = arg.GetNumber(1)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropSource, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropSource, __SetData)
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
	// Constructor assignment
	Gura_AssignFunction(__wxDropSource);
	Gura_AssignFunction(__wxDropSource_1);
	Gura_AssignFunction(__wxDropSource_2);
	Gura_AssignFunction(__wxDropSource_3);
	// Method assignment
	Gura_AssignMethod(wx_DropSource, __DoDragDrop);
	Gura_AssignMethod(wx_DropSource, __GetDataObject);
	Gura_AssignMethod(wx_DropSource, __GiveFeedback);
	Gura_AssignMethod(wx_DropSource, __SetCursor);
	Gura_AssignMethod(wx_DropSource, __SetIcon);
	Gura_AssignMethod(wx_DropSource, __SetData);
}

Gura_ImplementDescendantCreator(wx_DropSource)
{
	return new Object_wx_DropSource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
