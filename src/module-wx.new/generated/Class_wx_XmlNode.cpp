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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_XmlNode, wxXmlNode)
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

Gura_ImplementMethod(wx_XmlNode, wxXmlNode)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int content = arg.GetNumber(3)
	//int attrs = arg.GetNumber(4)
	//int next = arg.GetNumber(5)
	//int lineNo = arg.GetNumber(6)
	//pThis->GetEntity()->wxXmlNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, wxXmlNode_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "content", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lineNo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, wxXmlNode_1)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int content = arg.GetNumber(2)
	//int lineNo = arg.GetNumber(3)
	//pThis->GetEntity()->wxXmlNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, wxXmlNode_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, wxXmlNode_2)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->wxXmlNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, AddAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, AddAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AddAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, AddAttribute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, AddAttribute_1)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->AddAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, AddChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, AddChild)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->AddChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, DeleteAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, DeleteAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, GetAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attrName = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetAttribute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultVal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, GetAttribute_1)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attrName = arg.GetNumber(0)
	//int defaultVal = arg.GetNumber(1)
	//pThis->GetEntity()->GetAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetAttributes)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetChildren)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetContent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetDepth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "grandparent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, GetDepth)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int grandparent = arg.GetNumber(0)
	//pThis->GetEntity()->GetDepth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetNoConversion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetNoConversion)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNoConversion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetLineNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetLineNumber)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetName)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetNext)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetNodeContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetNodeContent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNodeContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetParent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, GetType)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, HasAttribute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attrName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, HasAttribute)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attrName = arg.GetNumber(0)
	//pThis->GetEntity()->HasAttribute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, InsertChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "followingNode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, InsertChild)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int followingNode = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, InsertChildAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precedingNode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, InsertChildAfter)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//int precedingNode = arg.GetNumber(1)
	//pThis->GetEntity()->InsertChildAfter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, IsWhitespaceOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlNode, IsWhitespaceOnly)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsWhitespaceOnly();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, RemoveChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, RemoveChild)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetAttributes)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetChildren)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->SetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "con", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetContent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int con = arg.GetNumber(0)
	//pThis->GetEntity()->SetContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetName)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetNext)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int next = arg.GetNumber(0)
	//pThis->GetEntity()->SetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetNoConversion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "noconversion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetNoConversion)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int noconversion = arg.GetNumber(0)
	//pThis->GetEntity()->SetNoConversion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetParent)
{
	Object_wx_XmlNode *pThis = Object_wx_XmlNode::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlNode, SetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlNode, SetType)
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
	Gura_AssignMethod(wx_XmlNode, wxXmlNode);
	Gura_AssignMethod(wx_XmlNode, wxXmlNode_1);
	Gura_AssignMethod(wx_XmlNode, wxXmlNode_2);
	Gura_AssignMethod(wx_XmlNode, AddAttribute);
	Gura_AssignMethod(wx_XmlNode, AddAttribute_1);
	Gura_AssignMethod(wx_XmlNode, AddChild);
	Gura_AssignMethod(wx_XmlNode, DeleteAttribute);
	Gura_AssignMethod(wx_XmlNode, GetAttribute);
	Gura_AssignMethod(wx_XmlNode, GetAttribute_1);
	Gura_AssignMethod(wx_XmlNode, GetAttributes);
	Gura_AssignMethod(wx_XmlNode, GetChildren);
	Gura_AssignMethod(wx_XmlNode, GetContent);
	Gura_AssignMethod(wx_XmlNode, GetDepth);
	Gura_AssignMethod(wx_XmlNode, GetNoConversion);
	Gura_AssignMethod(wx_XmlNode, GetLineNumber);
	Gura_AssignMethod(wx_XmlNode, GetName);
	Gura_AssignMethod(wx_XmlNode, GetNext);
	Gura_AssignMethod(wx_XmlNode, GetNodeContent);
	Gura_AssignMethod(wx_XmlNode, GetParent);
	Gura_AssignMethod(wx_XmlNode, GetType);
	Gura_AssignMethod(wx_XmlNode, HasAttribute);
	Gura_AssignMethod(wx_XmlNode, InsertChild);
	Gura_AssignMethod(wx_XmlNode, InsertChildAfter);
	Gura_AssignMethod(wx_XmlNode, IsWhitespaceOnly);
	Gura_AssignMethod(wx_XmlNode, RemoveChild);
	Gura_AssignMethod(wx_XmlNode, SetAttributes);
	Gura_AssignMethod(wx_XmlNode, SetChildren);
	Gura_AssignMethod(wx_XmlNode, SetContent);
	Gura_AssignMethod(wx_XmlNode, SetName);
	Gura_AssignMethod(wx_XmlNode, SetNext);
	Gura_AssignMethod(wx_XmlNode, SetNoConversion);
	Gura_AssignMethod(wx_XmlNode, SetParent);
	Gura_AssignMethod(wx_XmlNode, SetType);
}

Gura_ImplementDescendantCreator(wx_XmlNode)
{
	return new Object_wx_XmlNode((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
