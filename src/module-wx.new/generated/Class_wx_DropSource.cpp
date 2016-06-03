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
Gura_DeclareFunctionAlias(__DropSource, "DropSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DropSource));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DropSource)
{
	//wxWindow* win = arg.GetNumber(0)
	//const wxCursor& iconCopy = arg.GetNumber(1)
	//const wxCursor& iconMove = arg.GetNumber(2)
	//const wxCursor& iconNone = arg.GetNumber(3)
	//wxDropSource();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DropSource_1, "DropSource_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DropSource));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DropSource_1)
{
	//wxDataObject& data = arg.GetNumber(0)
	//wxWindow* win = arg.GetNumber(1)
	//const wxCursor& iconCopy = arg.GetNumber(2)
	//const wxCursor& iconMove = arg.GetNumber(3)
	//const wxCursor& iconNone = arg.GetNumber(4)
	//wxDropSource();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DropSource_2, "DropSource_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DropSource));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DropSource_2)
{
	//wxWindow* win = arg.GetNumber(0)
	//const wxIcon& iconCopy = arg.GetNumber(1)
	//const wxIcon& iconMove = arg.GetNumber(2)
	//const wxIcon& iconNone = arg.GetNumber(3)
	//wxDropSource();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DropSource_3, "DropSource_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconCopy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconMove", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconNone", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DropSource));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DropSource_3)
{
	//wxDataObject& data = arg.GetNumber(0)
	//wxWindow* win = arg.GetNumber(1)
	//const wxIcon& iconCopy = arg.GetNumber(2)
	//const wxIcon& iconMove = arg.GetNumber(3)
	//const wxIcon& iconNone = arg.GetNumber(4)
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
	//wxDragResult effect = arg.GetNumber(0)
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
	//wxDragResult res = arg.GetNumber(0)
	//const wxCursor& cursor = arg.GetNumber(1)
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
	//wxDragResult res = arg.GetNumber(0)
	//const wxIcon& icon = arg.GetNumber(1)
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
	//wxDataObject& data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDropSource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropSource)
{
	// Constructor assignment
	Gura_AssignFunction(__DropSource);
	Gura_AssignFunction(__DropSource_1);
	Gura_AssignFunction(__DropSource_2);
	Gura_AssignFunction(__DropSource_3);
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
