//----------------------------------------------------------------------------
// wxRichTextFileHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFileHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFileHandler
//----------------------------------------------------------------------------
Object_wx_RichTextFileHandler::~Object_wx_RichTextFileHandler()
{
}

Object *Object_wx_RichTextFileHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFileHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFileHandler:");
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
Gura_DeclareMethod(wx_RichTextFileHandler, wxRichTextFileHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, wxRichTextFileHandler)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->wxRichTextFileHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, LoadFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SaveFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, LoadFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, LoadFile_1)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int filename = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SaveFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SaveFile_1)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int filename = arg.GetNumber(1)
	//pThis->GetEntity()->SaveFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, CanHandle)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->CanHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, CanSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, CanSave)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanSave();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, CanLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, CanLoad)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanLoad();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, IsVisible)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetVisible)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetName)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetName)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetExtension)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ext = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetExtension)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetType)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetType)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetFlags)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetFlags)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, SetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, SetEncoding)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, GetEncoding)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, DoLoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, DoLoadFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoLoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextFileHandler, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, DoSaveFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoSaveFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFileHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFileHandler)
{
	Gura_AssignMethod(wx_RichTextFileHandler, wxRichTextFileHandler);
	Gura_AssignMethod(wx_RichTextFileHandler, LoadFile);
	Gura_AssignMethod(wx_RichTextFileHandler, SaveFile);
	Gura_AssignMethod(wx_RichTextFileHandler, LoadFile_1);
	Gura_AssignMethod(wx_RichTextFileHandler, SaveFile_1);
	Gura_AssignMethod(wx_RichTextFileHandler, CanHandle);
	Gura_AssignMethod(wx_RichTextFileHandler, CanSave);
	Gura_AssignMethod(wx_RichTextFileHandler, CanLoad);
	Gura_AssignMethod(wx_RichTextFileHandler, IsVisible);
	Gura_AssignMethod(wx_RichTextFileHandler, SetVisible);
	Gura_AssignMethod(wx_RichTextFileHandler, SetName);
	Gura_AssignMethod(wx_RichTextFileHandler, GetName);
	Gura_AssignMethod(wx_RichTextFileHandler, SetExtension);
	Gura_AssignMethod(wx_RichTextFileHandler, GetExtension);
	Gura_AssignMethod(wx_RichTextFileHandler, SetType);
	Gura_AssignMethod(wx_RichTextFileHandler, GetType);
	Gura_AssignMethod(wx_RichTextFileHandler, SetFlags);
	Gura_AssignMethod(wx_RichTextFileHandler, GetFlags);
	Gura_AssignMethod(wx_RichTextFileHandler, SetEncoding);
	Gura_AssignMethod(wx_RichTextFileHandler, GetEncoding);
	Gura_AssignMethod(wx_RichTextFileHandler, DoLoadFile);
	Gura_AssignMethod(wx_RichTextFileHandler, DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextFileHandler)
{
	return new Object_wx_RichTextFileHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
