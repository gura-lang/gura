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
Gura_DeclareFunctionAlias(__RichTextAction, "RichTextAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "container", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ignoreFirstTime", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextAction));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextAction)
{
	//wxRichTextCommand* cmd = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//wxRichTextCommandId id = arg.GetNumber(2)
	//wxRichTextBuffer* buffer = arg.GetNumber(3)
	//wxRichTextParagraphLayoutBox* container = arg.GetNumber(4)
	//wxRichTextCtrl* ctrl = arg.GetNumber(5)
	//bool ignoreFirstTime = arg.GetNumber(6)
	//wxRichTextAction(cmd, name, id, buffer, container, ctrl, ignoreFirstTime);
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
	//long caretPosition = arg.GetNumber(0)
	//bool sendUpdateEvent = arg.GetNumber(1)
	//const wxRect& oldFloatRect = arg.GetNumber(2)
	//wxArrayInt* optimizationLineCharPositions = arg.GetNumber(3)
	//wxArrayInt* optimizationLineYPositions = arg.GetNumber(4)
	//bool isDoCmd = arg.GetNumber(5)
	//pThis->GetEntity()->UpdateAppearance(caretPosition, sendUpdateEvent, oldFloatRect, optimizationLineCharPositions, optimizationLineYPositions, isDoCmd);
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
	//const wxRichTextParagraphLayoutBox& fragment = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyParagraphs(fragment);
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
	//wxRichTextObject* obj = arg.GetNumber(0)
	//pThis->GetEntity()->StoreObject(obj);
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
	//wxRichTextObject* obj = arg.GetNumber(0)
	//pThis->GetEntity()->SetObject(obj);
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
	//wxRichTextObject* obj = arg.GetNumber(0)
	//pThis->GetEntity()->MakeObject(obj);
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
	//wxRichTextObject* oldObj = arg.GetNumber(0)
	//wxRichTextObject* newObj = arg.GetNumber(1)
	//pThis->GetEntity()->SetOldAndNewObjects(oldObj, newObj);
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
	//wxArrayInt& optimizationLineCharPositions = arg.GetNumber(0)
	//wxArrayInt& optimizationLineYPositions = arg.GetNumber(1)
	//wxRect& oldFloatRect = arg.GetNumber(2)
	//pThis->GetEntity()->CalculateRefreshOptimizations(optimizationLineCharPositions, optimizationLineYPositions, oldFloatRect);
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
	//long pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(pos);
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
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange(range);
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
	//const wxRichTextObjectAddress& address = arg.GetNumber(0)
	//pThis->GetEntity()->SetContainerAddress(address);
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
	//wxRichTextParagraphLayoutBox* container = arg.GetNumber(0)
	//wxRichTextObject* obj = arg.GetNumber(1)
	//pThis->GetEntity()->SetContainerAddress(container, obj);
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
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->SetIgnoreFirstTime(b);
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
	Gura_AssignFunction(__RichTextAction);
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
