//----------------------------------------------------------------------------
// wxRichTextXMLHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextXMLHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextXMLHandler
//----------------------------------------------------------------------------
Object_wx_RichTextXMLHandler::~Object_wx_RichTextXMLHandler()
{
}

Object *Object_wx_RichTextXMLHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextXMLHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextXMLHandler:");
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
Gura_DeclareMethod(wx_RichTextXMLHandler, wxRichTextXMLHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, wxRichTextXMLHandler)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->wxRichTextXMLHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, CanLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, CanLoad)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanLoad();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, CanSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, CanSave)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanSave();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, ExportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, ExportXML)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//int level = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, ImportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, ImportXML)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//int node = arg.GetNumber(2)
	//pThis->GetEntity()->ImportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, RegisterNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nodeName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "className", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, RegisterNodeName)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nodeName = arg.GetNumber(0)
	//int className = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, ClearNodeToClassMap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, ClearNodeToClassMap)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearNodeToClassMap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, DoLoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, DoLoadFile)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoLoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextXMLHandler, DoSaveFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, DoSaveFile)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoSaveFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextXMLHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextXMLHandler)
{
	Gura_AssignMethod(wx_RichTextXMLHandler, wxRichTextXMLHandler);
	Gura_AssignMethod(wx_RichTextXMLHandler, CanLoad);
	Gura_AssignMethod(wx_RichTextXMLHandler, CanSave);
	Gura_AssignMethod(wx_RichTextXMLHandler, ExportXML);
	Gura_AssignMethod(wx_RichTextXMLHandler, ImportXML);
	Gura_AssignMethod(wx_RichTextXMLHandler, RegisterNodeName);
	Gura_AssignMethod(wx_RichTextXMLHandler, ClearNodeToClassMap);
	Gura_AssignMethod(wx_RichTextXMLHandler, DoLoadFile);
	Gura_AssignMethod(wx_RichTextXMLHandler, DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextXMLHandler)
{
	return new Object_wx_RichTextXMLHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
