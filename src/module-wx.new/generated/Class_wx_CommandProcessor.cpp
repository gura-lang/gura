//----------------------------------------------------------------------------
// wxCommandProcessor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandProcessor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommandProcessor
//----------------------------------------------------------------------------
Object_wx_CommandProcessor::~Object_wx_CommandProcessor()
{
}

Object *Object_wx_CommandProcessor::Clone() const
{
	return nullptr;
}

String Object_wx_CommandProcessor::ToString(bool exprFlag)
{
	String rtn("<wx.CommandProcessor:");
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
Gura_DeclareMethod(wx_CommandProcessor, wxCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maxCommands", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandProcessor, wxCommandProcessor)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int maxCommands = arg.GetNumber(0)
	//pThis->GetEntity()->wxCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, ~wxCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, ~wxCommandProcessor)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, CanUndo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, CanUndo)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanUndo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, CanRedo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, CanRedo)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanRedo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, ClearCommands)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, ClearCommands)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearCommands();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetCommands)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetCommands)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCommands();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetCurrentCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetCurrentCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetEditMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetEditMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEditMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetMaxCommands)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetMaxCommands)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxCommands();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetRedoAccelerator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetRedoAccelerator)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRedoAccelerator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetRedoMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetRedoMenuLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRedoMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetUndoAccelerator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetUndoAccelerator)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUndoAccelerator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, GetUndoMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, GetUndoMenuLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUndoMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, Initialize)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, IsDirty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, IsDirty)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDirty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, MarkAsSaved)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, MarkAsSaved)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MarkAsSaved();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, Redo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, Redo)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Redo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, SetEditMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandProcessor, SetEditMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetEditMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, SetMenuStrings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, SetMenuStrings)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetMenuStrings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, SetRedoAccelerator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "accel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandProcessor, SetRedoAccelerator)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int accel = arg.GetNumber(0)
	//pThis->GetEntity()->SetRedoAccelerator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, SetUndoAccelerator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "accel", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandProcessor, SetUndoAccelerator)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int accel = arg.GetNumber(0)
	//pThis->GetEntity()->SetUndoAccelerator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, Submit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "storeIt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandProcessor, Submit)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int command = arg.GetNumber(0)
	//int storeIt = arg.GetNumber(1)
	//pThis->GetEntity()->Submit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, Store)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CommandProcessor, Store)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int command = arg.GetNumber(0)
	//pThis->GetEntity()->Store();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CommandProcessor, Undo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CommandProcessor, Undo)
{
	Signal &sig = env.GetSignal();
	Object_wx_CommandProcessor *pThis = Object_wx_CommandProcessor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Undo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCommandProcessor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandProcessor)
{
	Gura_AssignMethod(wx_CommandProcessor, wxCommandProcessor);
	Gura_AssignMethod(wx_CommandProcessor, ~wxCommandProcessor);
	Gura_AssignMethod(wx_CommandProcessor, CanUndo);
	Gura_AssignMethod(wx_CommandProcessor, CanRedo);
	Gura_AssignMethod(wx_CommandProcessor, ClearCommands);
	Gura_AssignMethod(wx_CommandProcessor, GetCommands);
	Gura_AssignMethod(wx_CommandProcessor, GetCurrentCommand);
	Gura_AssignMethod(wx_CommandProcessor, GetEditMenu);
	Gura_AssignMethod(wx_CommandProcessor, GetMaxCommands);
	Gura_AssignMethod(wx_CommandProcessor, GetRedoAccelerator);
	Gura_AssignMethod(wx_CommandProcessor, GetRedoMenuLabel);
	Gura_AssignMethod(wx_CommandProcessor, GetUndoAccelerator);
	Gura_AssignMethod(wx_CommandProcessor, GetUndoMenuLabel);
	Gura_AssignMethod(wx_CommandProcessor, Initialize);
	Gura_AssignMethod(wx_CommandProcessor, IsDirty);
	Gura_AssignMethod(wx_CommandProcessor, MarkAsSaved);
	Gura_AssignMethod(wx_CommandProcessor, Redo);
	Gura_AssignMethod(wx_CommandProcessor, SetEditMenu);
	Gura_AssignMethod(wx_CommandProcessor, SetMenuStrings);
	Gura_AssignMethod(wx_CommandProcessor, SetRedoAccelerator);
	Gura_AssignMethod(wx_CommandProcessor, SetUndoAccelerator);
	Gura_AssignMethod(wx_CommandProcessor, Submit);
	Gura_AssignMethod(wx_CommandProcessor, Store);
	Gura_AssignMethod(wx_CommandProcessor, Undo);
}

Gura_ImplementDescendantCreator(wx_CommandProcessor)
{
	return new Object_wx_CommandProcessor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
