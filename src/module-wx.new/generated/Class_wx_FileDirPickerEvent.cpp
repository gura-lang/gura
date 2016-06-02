//----------------------------------------------------------------------------
// wxFileDirPickerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDirPickerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileDirPickerEvent
//----------------------------------------------------------------------------
Object_wx_FileDirPickerEvent::~Object_wx_FileDirPickerEvent()
{
}

Object *Object_wx_FileDirPickerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FileDirPickerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FileDirPickerEvent:");
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
Gura_DeclareMethod(wx_FileDirPickerEvent, wxFileDirPickerEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDirPickerEvent, wxFileDirPickerEvent)
{
	Object_wx_FileDirPickerEvent *pThis = Object_wx_FileDirPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFileDirPickerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDirPickerEvent, wxFileDirPickerEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDirPickerEvent, wxFileDirPickerEvent_1)
{
	Object_wx_FileDirPickerEvent *pThis = Object_wx_FileDirPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int generator = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int path = arg.GetNumber(3)
	//pThis->GetEntity()->wxFileDirPickerEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDirPickerEvent, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDirPickerEvent, GetPath)
{
	Object_wx_FileDirPickerEvent *pThis = Object_wx_FileDirPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDirPickerEvent, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDirPickerEvent, SetPath)
{
	Object_wx_FileDirPickerEvent *pThis = Object_wx_FileDirPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDirPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDirPickerEvent)
{
	Gura_AssignMethod(wx_FileDirPickerEvent, wxFileDirPickerEvent);
	Gura_AssignMethod(wx_FileDirPickerEvent, wxFileDirPickerEvent_1);
	Gura_AssignMethod(wx_FileDirPickerEvent, GetPath);
	Gura_AssignMethod(wx_FileDirPickerEvent, SetPath);
}

Gura_ImplementDescendantCreator(wx_FileDirPickerEvent)
{
	return new Object_wx_FileDirPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
