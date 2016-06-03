//----------------------------------------------------------------------------
// wxFileCtrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileCtrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileCtrlEvent
//----------------------------------------------------------------------------
Object_wx_FileCtrlEvent::~Object_wx_FileCtrlEvent()
{
}

Object *Object_wx_FileCtrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FileCtrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FileCtrlEvent:");
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
Gura_DeclareFunctionAlias(__wxFileCtrlEvent, "wxFileCtrlEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "evtObject", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxFileCtrlEvent)
{
	//int type = arg.GetNumber(0)
	//int evtObject = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//wxFileCtrlEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileCtrlEvent, __GetDirectory, "GetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, __GetDirectory)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrlEvent, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, __GetFile)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrlEvent, __GetFiles, "GetFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, __GetFiles)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrlEvent, __GetFilterIndex, "GetFilterIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, __GetFilterIndex)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrlEvent, __SetFiles, "SetFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "files", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrlEvent, __SetFiles)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int files = arg.GetNumber(0)
	//pThis->GetEntity()->SetFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrlEvent, __SetDirectory, "SetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "directory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrlEvent, __SetDirectory)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int directory = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrlEvent, __SetFilterIndex, "SetFilterIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrlEvent, __SetFilterIndex)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilterIndex();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileCtrlEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFileCtrlEvent);
	// Method assignment
	Gura_AssignMethod(wx_FileCtrlEvent, __GetDirectory);
	Gura_AssignMethod(wx_FileCtrlEvent, __GetFile);
	Gura_AssignMethod(wx_FileCtrlEvent, __GetFiles);
	Gura_AssignMethod(wx_FileCtrlEvent, __GetFilterIndex);
	Gura_AssignMethod(wx_FileCtrlEvent, __SetFiles);
	Gura_AssignMethod(wx_FileCtrlEvent, __SetDirectory);
	Gura_AssignMethod(wx_FileCtrlEvent, __SetFilterIndex);
}

Gura_ImplementDescendantCreator(wx_FileCtrlEvent)
{
	return new Object_wx_FileCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
