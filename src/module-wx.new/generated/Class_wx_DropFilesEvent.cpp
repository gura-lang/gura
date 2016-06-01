//----------------------------------------------------------------------------
// wxDropFilesEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDropFilesEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDropFilesEvent
//----------------------------------------------------------------------------
Object_wx_DropFilesEvent::~Object_wx_DropFilesEvent()
{
}

Object *Object_wx_DropFilesEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DropFilesEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DropFilesEvent:");
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
Gura_DeclareMethod(wx_DropFilesEvent, wxDropFilesEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noFiles", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "files", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DropFilesEvent, wxDropFilesEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int noFiles = arg.GetNumber(1)
	//int files = arg.GetNumber(2)
	//pThis->GetEntity()->wxDropFilesEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropFilesEvent, GetFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropFilesEvent, GetNumberOfFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetNumberOfFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNumberOfFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DropFilesEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DropFilesEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_DropFilesEvent *pThis = Object_wx_DropFilesEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDropFilesEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropFilesEvent)
{
	Gura_AssignMethod(wx_DropFilesEvent, wxDropFilesEvent);
	Gura_AssignMethod(wx_DropFilesEvent, GetFiles);
	Gura_AssignMethod(wx_DropFilesEvent, GetNumberOfFiles);
	Gura_AssignMethod(wx_DropFilesEvent, GetPosition);
}

Gura_ImplementDescendantCreator(wx_DropFilesEvent)
{
	return new Object_wx_DropFilesEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
