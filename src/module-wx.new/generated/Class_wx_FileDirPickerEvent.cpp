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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxFileDirPickerEvent, "wxFileDirPickerEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileDirPickerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileDirPickerEvent)
{
	//wxFileDirPickerEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFileDirPickerEvent_1, "wxFileDirPickerEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileDirPickerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFileDirPickerEvent_1)
{
	//int type = arg.GetNumber(0)
	//int generator = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//int path = arg.GetNumber(3)
	//wxFileDirPickerEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileDirPickerEvent, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDirPickerEvent, __GetPath)
{
	Object_wx_FileDirPickerEvent *pThis = Object_wx_FileDirPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDirPickerEvent, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDirPickerEvent, __SetPath)
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
	// Constructor assignment
	Gura_AssignFunction(__wxFileDirPickerEvent);
	Gura_AssignFunction(__wxFileDirPickerEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_FileDirPickerEvent, __GetPath);
	Gura_AssignMethod(wx_FileDirPickerEvent, __SetPath);
}

Gura_ImplementDescendantCreator(wx_FileDirPickerEvent)
{
	return new Object_wx_FileDirPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
