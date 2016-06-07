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
Gura_DeclareFunctionAlias(__FileDirPickerEvent, "FileDirPickerEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileDirPickerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileDirPickerEvent)
{
	//wxFileDirPickerEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileDirPickerEvent_1, "FileDirPickerEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "generator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileDirPickerEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileDirPickerEvent_1)
{
	//wxEventType type = arg.GetNumber(0)
	//wxObject* generator = arg.GetNumber(1)
	//int id = arg.GetNumber(2)
	//const wxString& path = arg.GetNumber(3)
	//wxFileDirPickerEvent(type, generator, id, path);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileDirPickerEvent, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDirPickerEvent, __GetPath)
{
	Object_wx_FileDirPickerEvent *pThis = Object_wx_FileDirPickerEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetPath();
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
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath(path);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDirPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDirPickerEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__FileDirPickerEvent);
	Gura_AssignFunction(__FileDirPickerEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_FileDirPickerEvent, __GetPath);
	Gura_AssignMethod(wx_FileDirPickerEvent, __SetPath);
}

Gura_ImplementDescendantCreator(wx_FileDirPickerEvent)
{
	return new Object_wx_FileDirPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
