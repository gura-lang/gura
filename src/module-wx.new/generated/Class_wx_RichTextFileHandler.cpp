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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextFileHandler, "RichTextFileHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextFileHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextFileHandler)
{
	//const wxString& name = arg.GetNumber(0)
	//const wxString& ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//wxRichTextFileHandler(name, ext, type);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextFileHandler, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __LoadFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxInputStream& stream = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->LoadFile(buffer, stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SaveFile, "SaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SaveFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxOutputStream& stream = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SaveFile(buffer, stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __LoadFile_1, "LoadFile_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __LoadFile_1)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//const wxString& filename = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->LoadFile(buffer, filename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SaveFile_1, "SaveFile_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SaveFile_1)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//const wxString& filename = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SaveFile(buffer, filename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __CanHandle, "CanHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __CanHandle)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CanHandle(filename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __CanSave, "CanSave")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __CanSave)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanSave();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __CanLoad, "CanLoad")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __CanLoad)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanLoad();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __IsVisible, "IsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __IsVisible)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SetVisible, "SetVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SetVisible)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetVisible(visible);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SetName)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __GetName)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SetExtension, "SetExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SetExtension)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& ext = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtension(ext);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __GetExtension, "GetExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __GetExtension)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SetType, "SetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SetType)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetType(type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __GetType)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SetFlags)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __GetFlags)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __SetEncoding, "SetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __SetEncoding)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding(encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __GetEncoding, "GetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __GetEncoding)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __DoLoadFile, "DoLoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __DoLoadFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxInputStream& stream = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->DoLoadFile(buffer, stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextFileHandler, __DoSaveFile, "DoSaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextFileHandler, __DoSaveFile)
{
	Object_wx_RichTextFileHandler *pThis = Object_wx_RichTextFileHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxOutputStream& stream = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->DoSaveFile(buffer, stream);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextFileHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFileHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextFileHandler);
	// Method assignment
	Gura_AssignMethod(wx_RichTextFileHandler, __LoadFile);
	Gura_AssignMethod(wx_RichTextFileHandler, __SaveFile);
	Gura_AssignMethod(wx_RichTextFileHandler, __LoadFile_1);
	Gura_AssignMethod(wx_RichTextFileHandler, __SaveFile_1);
	Gura_AssignMethod(wx_RichTextFileHandler, __CanHandle);
	Gura_AssignMethod(wx_RichTextFileHandler, __CanSave);
	Gura_AssignMethod(wx_RichTextFileHandler, __CanLoad);
	Gura_AssignMethod(wx_RichTextFileHandler, __IsVisible);
	Gura_AssignMethod(wx_RichTextFileHandler, __SetVisible);
	Gura_AssignMethod(wx_RichTextFileHandler, __SetName);
	Gura_AssignMethod(wx_RichTextFileHandler, __GetName);
	Gura_AssignMethod(wx_RichTextFileHandler, __SetExtension);
	Gura_AssignMethod(wx_RichTextFileHandler, __GetExtension);
	Gura_AssignMethod(wx_RichTextFileHandler, __SetType);
	Gura_AssignMethod(wx_RichTextFileHandler, __GetType);
	Gura_AssignMethod(wx_RichTextFileHandler, __SetFlags);
	Gura_AssignMethod(wx_RichTextFileHandler, __GetFlags);
	Gura_AssignMethod(wx_RichTextFileHandler, __SetEncoding);
	Gura_AssignMethod(wx_RichTextFileHandler, __GetEncoding);
	Gura_AssignMethod(wx_RichTextFileHandler, __DoLoadFile);
	Gura_AssignMethod(wx_RichTextFileHandler, __DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextFileHandler)
{
	return new Object_wx_RichTextFileHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
