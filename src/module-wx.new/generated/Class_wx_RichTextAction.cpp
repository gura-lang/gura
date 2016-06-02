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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextAction, wxRichTextAction)
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

Gura_ImplementMethod(wx_RichTextAction, wxRichTextAction)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cmd = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int buffer = arg.GetNumber(3)
	//int container = arg.GetNumber(4)
	//int ctrl = arg.GetNumber(5)
	//int ignoreFirstTime = arg.GetNumber(6)
	//pThis->GetEntity()->wxRichTextAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, Do)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, Do)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Do();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, Undo)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, UpdateAppearance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "caretPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sendUpdateEvent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldFloatRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "optimizationLineCharPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "optimizationLineYPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isDoCmd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, UpdateAppearance)
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

Gura_DeclareMethod(wx_RichTextAction, ApplyParagraphs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fragment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, ApplyParagraphs)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fragment = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyParagraphs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetNewParagraphs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetNewParagraphs)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNewParagraphs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetOldParagraphs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetOldParagraphs)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOldParagraphs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetAttributes)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, StoreObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, StoreObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->StoreObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, SetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, SetObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->SetObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, MakeObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, MakeObject)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->MakeObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, SetOldAndNewObjects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "oldObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, SetOldAndNewObjects)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int oldObj = arg.GetNumber(0)
	//int newObj = arg.GetNumber(1)
	//pThis->GetEntity()->SetOldAndNewObjects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, CalculateRefreshOptimizations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "optimizationLineCharPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "optimizationLineYPositions", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oldFloatRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, CalculateRefreshOptimizations)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int optimizationLineCharPositions = arg.GetNumber(0)
	//int optimizationLineYPositions = arg.GetNumber(1)
	//int oldFloatRect = arg.GetNumber(2)
	//pThis->GetEntity()->CalculateRefreshOptimizations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, SetPosition)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetPosition)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, SetRange)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetRange)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetContainerAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetContainerAddress)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetContainerAddress_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetContainerAddress_1)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, SetContainerAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, SetContainerAddress)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, SetContainerAddress_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, SetContainerAddress_1)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int container = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//pThis->GetEntity()->SetContainerAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetContainer)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetName)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, SetIgnoreFirstTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextAction, SetIgnoreFirstTime)
{
	Object_wx_RichTextAction *pThis = Object_wx_RichTextAction::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetIgnoreFirstTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextAction, GetIgnoreFirstTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextAction, GetIgnoreFirstTime)
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
	Gura_AssignMethod(wx_RichTextAction, wxRichTextAction);
	Gura_AssignMethod(wx_RichTextAction, Do);
	Gura_AssignMethod(wx_RichTextAction, Undo);
	Gura_AssignMethod(wx_RichTextAction, UpdateAppearance);
	Gura_AssignMethod(wx_RichTextAction, ApplyParagraphs);
	Gura_AssignMethod(wx_RichTextAction, GetNewParagraphs);
	Gura_AssignMethod(wx_RichTextAction, GetOldParagraphs);
	Gura_AssignMethod(wx_RichTextAction, GetAttributes);
	Gura_AssignMethod(wx_RichTextAction, GetObject);
	Gura_AssignMethod(wx_RichTextAction, StoreObject);
	Gura_AssignMethod(wx_RichTextAction, SetObject);
	Gura_AssignMethod(wx_RichTextAction, MakeObject);
	Gura_AssignMethod(wx_RichTextAction, SetOldAndNewObjects);
	Gura_AssignMethod(wx_RichTextAction, CalculateRefreshOptimizations);
	Gura_AssignMethod(wx_RichTextAction, SetPosition);
	Gura_AssignMethod(wx_RichTextAction, GetPosition);
	Gura_AssignMethod(wx_RichTextAction, SetRange);
	Gura_AssignMethod(wx_RichTextAction, GetRange);
	Gura_AssignMethod(wx_RichTextAction, GetContainerAddress);
	Gura_AssignMethod(wx_RichTextAction, GetContainerAddress_1);
	Gura_AssignMethod(wx_RichTextAction, SetContainerAddress);
	Gura_AssignMethod(wx_RichTextAction, SetContainerAddress_1);
	Gura_AssignMethod(wx_RichTextAction, GetContainer);
	Gura_AssignMethod(wx_RichTextAction, GetName);
	Gura_AssignMethod(wx_RichTextAction, SetIgnoreFirstTime);
	Gura_AssignMethod(wx_RichTextAction, GetIgnoreFirstTime);
}

Gura_ImplementDescendantCreator(wx_RichTextAction)
{
	return new Object_wx_RichTextAction((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
