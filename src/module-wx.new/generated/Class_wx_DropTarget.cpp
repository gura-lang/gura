//----------------------------------------------------------------------------
// wxDropTarget
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDropTarget
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDropTarget
//----------------------------------------------------------------------------
Object_wx_DropTarget::~Object_wx_DropTarget()
{
}

Object *Object_wx_DropTarget::Clone() const
{
	return nullptr;
}

String Object_wx_DropTarget::ToString(bool exprFlag)
{
	String rtn("<wx.DropTarget:");
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
Gura_DeclareFunctionAlias(__DropTarget, "DropTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DropTarget));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DropTarget)
{
	//wxDataObject* data = arg.GetNumber(0)
	//wxDropTarget(data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DropTarget, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, __GetData)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __OnData, "OnData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defResult", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, __OnData)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxDragResult defResult = arg.GetNumber(2)
	//wxDragResult _rtn = pThis->GetEntity()->OnData(x, y, defResult);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __OnDragOver, "OnDragOver")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defResult", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, __OnDragOver)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxDragResult defResult = arg.GetNumber(2)
	//wxDragResult _rtn = pThis->GetEntity()->OnDragOver(x, y, defResult);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __OnDrop, "OnDrop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, __OnDrop)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->OnDrop(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __OnEnter, "OnEnter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defResult", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, __OnEnter)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxDragResult defResult = arg.GetNumber(2)
	//wxDragResult _rtn = pThis->GetEntity()->OnEnter(x, y, defResult);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __OnLeave, "OnLeave")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, __OnLeave)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnLeave();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __GetDataObject, "GetDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, __GetDataObject)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataObject* _rtn = pThis->GetEntity()->GetDataObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __SetDataObject, "SetDataObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, __SetDataObject)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDataObject* data = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataObject(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __SetDefaultAction, "SetDefaultAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropTarget, __SetDefaultAction)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDragResult action = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultAction(action);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DropTarget, __GetDefaultAction, "GetDefaultAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DropTarget, __GetDefaultAction)
{
	Object_wx_DropTarget *pThis = Object_wx_DropTarget::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDragResult _rtn = pThis->GetEntity()->GetDefaultAction();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDropTarget
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropTarget)
{
	// Constructor assignment
	Gura_AssignFunction(__DropTarget);
	// Method assignment
	Gura_AssignMethod(wx_DropTarget, __GetData);
	Gura_AssignMethod(wx_DropTarget, __OnData);
	Gura_AssignMethod(wx_DropTarget, __OnDragOver);
	Gura_AssignMethod(wx_DropTarget, __OnDrop);
	Gura_AssignMethod(wx_DropTarget, __OnEnter);
	Gura_AssignMethod(wx_DropTarget, __OnLeave);
	Gura_AssignMethod(wx_DropTarget, __GetDataObject);
	Gura_AssignMethod(wx_DropTarget, __SetDataObject);
	Gura_AssignMethod(wx_DropTarget, __SetDefaultAction);
	Gura_AssignMethod(wx_DropTarget, __GetDefaultAction);
}

Gura_ImplementDescendantCreator(wx_DropTarget)
{
	return new Object_wx_DropTarget((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
