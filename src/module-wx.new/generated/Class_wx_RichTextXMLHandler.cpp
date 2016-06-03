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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRichTextXMLHandler, "wxRichTextXMLHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextXMLHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxRichTextXMLHandler)
{
	//int name = arg.GetNumber(0)
	//int ext = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//wxRichTextXMLHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __CanLoad, "CanLoad")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __CanLoad)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanLoad();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __CanSave, "CanSave")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __CanSave)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanSave();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __ExportXML)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//int level = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __ImportXML, "ImportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __ImportXML)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int obj = arg.GetNumber(1)
	//int node = arg.GetNumber(2)
	//pThis->GetEntity()->ImportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __RegisterNodeName, "RegisterNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nodeName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "className", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __RegisterNodeName)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nodeName = arg.GetNumber(0)
	//int className = arg.GetNumber(1)
	//pThis->GetEntity()->RegisterNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __ClearNodeToClassMap, "ClearNodeToClassMap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __ClearNodeToClassMap)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearNodeToClassMap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __DoLoadFile, "DoLoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __DoLoadFile)
{
	Object_wx_RichTextXMLHandler *pThis = Object_wx_RichTextXMLHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int stream = arg.GetNumber(1)
	//pThis->GetEntity()->DoLoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextXMLHandler, __DoSaveFile, "DoSaveFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextXMLHandler, __DoSaveFile)
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
	// Constructor assignment
	Gura_AssignFunction(__wxRichTextXMLHandler);
	// Method assignment
	Gura_AssignMethod(wx_RichTextXMLHandler, __CanLoad);
	Gura_AssignMethod(wx_RichTextXMLHandler, __CanSave);
	Gura_AssignMethod(wx_RichTextXMLHandler, __ExportXML);
	Gura_AssignMethod(wx_RichTextXMLHandler, __ImportXML);
	Gura_AssignMethod(wx_RichTextXMLHandler, __RegisterNodeName);
	Gura_AssignMethod(wx_RichTextXMLHandler, __ClearNodeToClassMap);
	Gura_AssignMethod(wx_RichTextXMLHandler, __DoLoadFile);
	Gura_AssignMethod(wx_RichTextXMLHandler, __DoSaveFile);
}

Gura_ImplementDescendantCreator(wx_RichTextXMLHandler)
{
	return new Object_wx_RichTextXMLHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
