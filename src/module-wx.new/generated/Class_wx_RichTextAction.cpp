//----------------------------------------------------------------------------
// wxRichTextAction
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextAction
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextAction
//----------------------------------------------------------------------------
Object_wx_RichTextAction::~Object_wx_RichTextAction()
{
}

Object *Object_wx_RichTextAction::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextAction::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextAction:");
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
Gura_DeclareFunctionAlias(__wxRichTextAction, "wxRichTextAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ignoreFirstTime", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRichTextAction)
{
	//int cmd = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int buffer = arg.GetNumber(3)
	//int container = arg.GetNumber(4)
	//int ctrl = arg.GetNumber(5)
	//int ignoreFirstTime = arg.GetNumber(6)
	//wxRichTextAction();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextAction, __Do, "Do")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __Do)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Do();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __Undo, "Undo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __Undo)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __UpdateAppearance, "UpdateAppearance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sendUpdateEvent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldFloatRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "optimizationLineCharPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "optimizationLineYPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isDoCmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __UpdateAppearance)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int caretPosition = arg.GetNumber(0)
	//int sendUpdateEvent = arg.GetNumber(1)
	//int oldFloatRect = arg.GetNumber(2)
	//int optimizationLineCharPositions = arg.GetNumber(3)
	//int optimizationLineYPositions = arg.GetNumber(4)
	//int isDoCmd = arg.GetNumber(5)
	//pThis->GetEntity()->UpdateAppearance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __ApplyParagraphs, "ApplyParagraphs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fragment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __ApplyParagraphs)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fragment = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyParagraphs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetNewParagraphs, "GetNewParagraphs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetNewParagraphs)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNewParagraphs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetOldParagraphs, "GetOldParagraphs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetOldParagraphs)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOldParagraphs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetAttributes, "GetAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetAttributes)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __StoreObject, "StoreObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __StoreObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->StoreObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __SetObject, "SetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __SetObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->SetObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __MakeObject, "MakeObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __MakeObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->MakeObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __SetOldAndNewObjects, "SetOldAndNewObjects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __SetOldAndNewObjects)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldObj = arg.GetNumber(0)
	//int newObj = arg.GetNumber(1)
	//pThis->GetEntity()->SetOldAndNewObjects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __CalculateRefreshOptimizations, "CalculateRefreshOptimizations")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "optimizationLineCharPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "optimizationLineYPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldFloatRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __CalculateRefreshOptimizations)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int optimizationLineCharPositions = arg.GetNumber(0)
	//int optimizationLineYPositions = arg.GetNumber(1)
	//int oldFloatRect = arg.GetNumber(2)
	//pThis->GetEntity()->CalculateRefreshOptimizations();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __SetPosition)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetPosition)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __SetRange)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetRange)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetContainerAddress, "GetContainerAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetContainerAddress)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetContainerAddress_1, "GetContainerAddress_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetContainerAddress_1)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __SetContainerAddress, "SetContainerAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __SetContainerAddress)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __SetContainerAddress_1, "SetContainerAddress_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __SetContainerAddress_1)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->SetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetContainer, "GetContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetContainer)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetName)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __SetIgnoreFirstTime, "SetIgnoreFirstTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, __SetIgnoreFirstTime)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetIgnoreFirstTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextAction, __GetIgnoreFirstTime, "GetIgnoreFirstTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, __GetIgnoreFirstTime)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIgnoreFirstTime();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextAction
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextAction)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextAction);
	// Method assignment
	Gura_AssignMethod(wx_RichTextAction, __Do);
	Gura_AssignMethod(wx_RichTextAction, __Undo);
	Gura_AssignMethod(wx_RichTextAction, __UpdateAppearance);
	Gura_AssignMethod(wx_RichTextAction, __ApplyParagraphs);
	Gura_AssignMethod(wx_RichTextAction, __GetNewParagraphs);
	Gura_AssignMethod(wx_RichTextAction, __GetOldParagraphs);
	Gura_AssignMethod(wx_RichTextAction, __GetAttributes);
	Gura_AssignMethod(wx_RichTextAction, __GetObject);
	Gura_AssignMethod(wx_RichTextAction, __StoreObject);
	Gura_AssignMethod(wx_RichTextAction, __SetObject);
	Gura_AssignMethod(wx_RichTextAction, __MakeObject);
	Gura_AssignMethod(wx_RichTextAction, __SetOldAndNewObjects);
	Gura_AssignMethod(wx_RichTextAction, __CalculateRefreshOptimizations);
	Gura_AssignMethod(wx_RichTextAction, __SetPosition);
	Gura_AssignMethod(wx_RichTextAction, __GetPosition);
	Gura_AssignMethod(wx_RichTextAction, __SetRange);
	Gura_AssignMethod(wx_RichTextAction, __GetRange);
	Gura_AssignMethod(wx_RichTextAction, __GetContainerAddress);
	Gura_AssignMethod(wx_RichTextAction, __GetContainerAddress_1);
	Gura_AssignMethod(wx_RichTextAction, __SetContainerAddress);
	Gura_AssignMethod(wx_RichTextAction, __SetContainerAddress_1);
	Gura_AssignMethod(wx_RichTextAction, __GetContainer);
	Gura_AssignMethod(wx_RichTextAction, __GetName);
	Gura_AssignMethod(wx_RichTextAction, __SetIgnoreFirstTime);
	Gura_AssignMethod(wx_RichTextAction, __GetIgnoreFirstTime);
}

Gura_ImplementDescendantCreator(wx_RichTextAction)
{
	return new Object_wx_RichTextAction((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
