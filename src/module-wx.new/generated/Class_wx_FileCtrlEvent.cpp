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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FileCtrlEvent, wxFileCtrlEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "evtObject", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrlEvent, wxFileCtrlEvent)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int evtObject = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//pThis->GetEntity()->wxFileCtrlEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrlEvent, GetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, GetDirectory)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrlEvent, GetFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, GetFile)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrlEvent, GetFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, GetFiles)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrlEvent, GetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrlEvent, GetFilterIndex)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrlEvent, SetFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "files", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrlEvent, SetFiles)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int files = arg.GetNumber(0)
	//pThis->GetEntity()->SetFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrlEvent, SetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "directory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrlEvent, SetDirectory)
{
	Object_wx_FileCtrlEvent *pThis = Object_wx_FileCtrlEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int directory = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileCtrlEvent, SetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrlEvent, SetFilterIndex)
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
	Gura_AssignMethod(wx_FileCtrlEvent, wxFileCtrlEvent);
	Gura_AssignMethod(wx_FileCtrlEvent, GetDirectory);
	Gura_AssignMethod(wx_FileCtrlEvent, GetFile);
	Gura_AssignMethod(wx_FileCtrlEvent, GetFiles);
	Gura_AssignMethod(wx_FileCtrlEvent, GetFilterIndex);
	Gura_AssignMethod(wx_FileCtrlEvent, SetFiles);
	Gura_AssignMethod(wx_FileCtrlEvent, SetDirectory);
	Gura_AssignMethod(wx_FileCtrlEvent, SetFilterIndex);
}

Gura_ImplementDescendantCreator(wx_FileCtrlEvent)
{
	return new Object_wx_FileCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
