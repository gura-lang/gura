//----------------------------------------------------------------------------
// wxXmlNode
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlNode
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlNode
//----------------------------------------------------------------------------
Object_wx_XmlNode::~Object_wx_XmlNode()
{
}

Object *Object_wx_XmlNode::Clone() const
{
	return nullptr;
}

String Object_wx_XmlNode::ToString(bool exprFlag)
{
	String rtn("<wx.XmlNode:");
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
Gura_DeclareFunctionAlias(__wxXmlNode, "wxXmlNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "content", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attrs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxXmlNode)
{
	//int parent = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int content = arg.GetNumber(3)
	//int attrs = arg.GetNumber(4)
	//int next = arg.GetNumber(5)
	//int lineNo = arg.GetNumber(6)
	//wxXmlNode();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxXmlNode_1, "wxXmlNode_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "content", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxXmlNode_1)
{
	//int type = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int content = arg.GetNumber(2)
	//int lineNo = arg.GetNumber(3)
	//wxXmlNode();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxXmlNode_2, "wxXmlNode_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxXmlNode_2)
{
	//int node = arg.GetNumber(0)
	//wxXmlNode();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_XmlNode, __AddAttribute, "AddAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __AddAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AddAttribute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __AddAttribute_1, "AddAttribute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __AddAttribute_1)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->AddAttribute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __AddChild, "AddChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __AddChild)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->AddChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __DeleteAttribute, "DeleteAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __DeleteAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteAttribute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetAttribute, "GetAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __GetAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attrName = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttribute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetAttribute_1, "GetAttribute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __GetAttribute_1)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attrName = arg.GetNumber(0)
	//int defaultVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttribute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetAttributes, "GetAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetAttributes)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetChildren, "GetChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetChildren)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetContent, "GetContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetContent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetDepth, "GetDepth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grandparent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __GetDepth)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grandparent = arg.GetNumber(0)
	//pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetNoConversion, "GetNoConversion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetNoConversion)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNoConversion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetLineNumber, "GetLineNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetLineNumber)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineNumber();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetName)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetNext, "GetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetNext)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetNodeContent, "GetNodeContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetNodeContent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNodeContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetParent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __GetType)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __HasAttribute, "HasAttribute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __HasAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attrName = arg.GetNumber(0)
	//pThis->GetEntity()->HasAttribute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __InsertChild, "InsertChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "followingNode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __InsertChild)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int followingNode = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __InsertChildAfter, "InsertChildAfter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precedingNode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __InsertChildAfter)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int precedingNode = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChildAfter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __IsWhitespaceOnly, "IsWhitespaceOnly")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, __IsWhitespaceOnly)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsWhitespaceOnly();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __RemoveChild, "RemoveChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __RemoveChild)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetAttributes, "SetAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetAttributes)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetChildren, "SetChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetChildren)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->SetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetContent, "SetContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "con", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetContent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int con = arg.GetNumber(0)
	//pThis->GetEntity()->SetContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetName)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetNext, "SetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetNext)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int next = arg.GetNumber(0)
	//pThis->GetEntity()->SetNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetNoConversion, "SetNoConversion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noconversion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetNoConversion)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noconversion = arg.GetNumber(0)
	//pThis->GetEntity()->SetNoConversion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetParent, "SetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetParent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlNode, __SetType, "SetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, __SetType)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlNode
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlNode)
{
	// Constructor assignment
	Gura_AssignFunction(__wxXmlNode);
	Gura_AssignFunction(__wxXmlNode_1);
	Gura_AssignFunction(__wxXmlNode_2);
	// Method assignment
	Gura_AssignMethod(wx_XmlNode, __AddAttribute);
	Gura_AssignMethod(wx_XmlNode, __AddAttribute_1);
	Gura_AssignMethod(wx_XmlNode, __AddChild);
	Gura_AssignMethod(wx_XmlNode, __DeleteAttribute);
	Gura_AssignMethod(wx_XmlNode, __GetAttribute);
	Gura_AssignMethod(wx_XmlNode, __GetAttribute_1);
	Gura_AssignMethod(wx_XmlNode, __GetAttributes);
	Gura_AssignMethod(wx_XmlNode, __GetChildren);
	Gura_AssignMethod(wx_XmlNode, __GetContent);
	Gura_AssignMethod(wx_XmlNode, __GetDepth);
	Gura_AssignMethod(wx_XmlNode, __GetNoConversion);
	Gura_AssignMethod(wx_XmlNode, __GetLineNumber);
	Gura_AssignMethod(wx_XmlNode, __GetName);
	Gura_AssignMethod(wx_XmlNode, __GetNext);
	Gura_AssignMethod(wx_XmlNode, __GetNodeContent);
	Gura_AssignMethod(wx_XmlNode, __GetParent);
	Gura_AssignMethod(wx_XmlNode, __GetType);
	Gura_AssignMethod(wx_XmlNode, __HasAttribute);
	Gura_AssignMethod(wx_XmlNode, __InsertChild);
	Gura_AssignMethod(wx_XmlNode, __InsertChildAfter);
	Gura_AssignMethod(wx_XmlNode, __IsWhitespaceOnly);
	Gura_AssignMethod(wx_XmlNode, __RemoveChild);
	Gura_AssignMethod(wx_XmlNode, __SetAttributes);
	Gura_AssignMethod(wx_XmlNode, __SetChildren);
	Gura_AssignMethod(wx_XmlNode, __SetContent);
	Gura_AssignMethod(wx_XmlNode, __SetName);
	Gura_AssignMethod(wx_XmlNode, __SetNext);
	Gura_AssignMethod(wx_XmlNode, __SetNoConversion);
	Gura_AssignMethod(wx_XmlNode, __SetParent);
	Gura_AssignMethod(wx_XmlNode, __SetType);
}

Gura_ImplementDescendantCreator(wx_XmlNode)
{
	return new Object_wx_XmlNode((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
