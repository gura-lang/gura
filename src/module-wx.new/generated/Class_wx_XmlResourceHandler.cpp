//----------------------------------------------------------------------------
// wxXmlResourceHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlResourceHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Object_wx_XmlResourceHandler::~Object_wx_XmlResourceHandler()
{
}

Object *Object_wx_XmlResourceHandler::Clone() const
{
	return nullptr;
}

String Object_wx_XmlResourceHandler::ToString(bool exprFlag)
{
	String rtn("<wx.XmlResourceHandler:");
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
Gura_DeclareFunctionAlias(__wxXmlResourceHandler, "wxXmlResourceHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_XmlResourceHandler));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxXmlResourceHandler)
{
	//wxXmlResourceHandler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_XmlResourceHandler, __CreateResource, "CreateResource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __CreateResource)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int instance = arg.GetNumber(2)
	//pThis->GetEntity()->CreateResource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __DoCreateResource, "DoCreateResource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __DoCreateResource)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoCreateResource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __CanHandle, "CanHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __CanHandle)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->CanHandle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __SetParentResource, "SetParentResource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __SetParentResource)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentResource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __AddStyle, "AddStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __AddStyle)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AddStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __AddWindowStyles, "AddWindowStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __AddWindowStyles)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddWindowStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __CreateChildren, "CreateChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "this_hnd_only", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __CreateChildren)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int this_hnd_only = arg.GetNumber(1)
	//pThis->GetEntity()->CreateChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __CreateChildrenPrivately, "CreateChildrenPrivately")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootnode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __CreateChildrenPrivately)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int rootnode = arg.GetNumber(1)
	//pThis->GetEntity()->CreateChildrenPrivately();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __CreateResFromNode, "CreateResFromNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __CreateResFromNode)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int instance = arg.GetNumber(2)
	//pThis->GetEntity()->CreateResFromNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetAnimation, "GetAnimation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetAnimation)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetAnimation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetBitmap)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetBitmap_1, "GetBitmap_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetBitmap_1)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetBool, "GetBool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetBool)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//pThis->GetEntity()->GetBool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetColour)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultColour = arg.GetNumber(1)
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetCurFileSystem, "GetCurFileSystem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetCurFileSystem)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurFileSystem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetDimension, "GetDimension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "windowToUse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetDimension)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//int windowToUse = arg.GetNumber(2)
	//pThis->GetEntity()->GetDimension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetDirection, "GetDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dirDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetDirection)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int dirDefault = arg.GetNumber(1)
	//pThis->GetEntity()->GetDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetFont)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetID, "GetID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetID)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetIcon, "GetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetIcon)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetIcon_1, "GetIcon_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetIcon_1)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetIconBundle, "GetIconBundle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetIconBundle)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//pThis->GetEntity()->GetIconBundle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetImageList, "GetImageList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetImageList)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetLong, "GetLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetLong)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//pThis->GetEntity()->GetLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetFloat, "GetFloat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetFloat)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//pThis->GetEntity()->GetFloat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetName)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __IsObjectNode, "IsObjectNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __IsObjectNode)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->IsObjectNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetNodeContent, "GetNodeContent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetNodeContent)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeContent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetNodeParent, "GetNodeParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetNodeParent)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetNodeNext, "GetNodeNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetNodeNext)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetNodeChildren, "GetNodeChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetNodeChildren)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetParamNode, "GetParamNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetParamNode)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetParamNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetParamValue, "GetParamValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetParamValue)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetParamValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetParamValue_1, "GetParamValue_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetParamValue_1)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetParamValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetPosition)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "windowToUse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetSize)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int windowToUse = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaults", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetStyle)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaults = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "translate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetText)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int translate = arg.GetNumber(1)
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __HasParam, "HasParam")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __HasParam)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->HasParam();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __IsOfClass, "IsOfClass")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __IsOfClass)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int classname = arg.GetNumber(1)
	//pThis->GetEntity()->IsOfClass();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __SetupWindow, "SetupWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __SetupWindow)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//pThis->GetEntity()->SetupWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __ReportError, "ReportError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __ReportError)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __ReportError_1, "ReportError_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __ReportError_1)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __ReportParamError, "ReportParamError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __ReportParamError)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->ReportParamError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetResource, "GetResource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetResource)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetResource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetNode, "GetNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetNode)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetClass, "GetClass")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetClass)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClass();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetParent)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetInstance, "GetInstance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetInstance)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInstance();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResourceHandler, __GetParentAsWindow, "GetParentAsWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, __GetParentAsWindow)
{
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParentAsWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResourceHandler)
{
	// Constructor assignment
	Gura_AssignFunction(__wxXmlResourceHandler);
	// Method assignment
	Gura_AssignMethod(wx_XmlResourceHandler, __CreateResource);
	Gura_AssignMethod(wx_XmlResourceHandler, __DoCreateResource);
	Gura_AssignMethod(wx_XmlResourceHandler, __CanHandle);
	Gura_AssignMethod(wx_XmlResourceHandler, __SetParentResource);
	Gura_AssignMethod(wx_XmlResourceHandler, __AddStyle);
	Gura_AssignMethod(wx_XmlResourceHandler, __AddWindowStyles);
	Gura_AssignMethod(wx_XmlResourceHandler, __CreateChildren);
	Gura_AssignMethod(wx_XmlResourceHandler, __CreateChildrenPrivately);
	Gura_AssignMethod(wx_XmlResourceHandler, __CreateResFromNode);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetAnimation);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetBitmap);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetBitmap_1);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetBool);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetColour);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetCurFileSystem);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetDimension);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetDirection);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetFont);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetID);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetIcon);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetIcon_1);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetIconBundle);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetImageList);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetLong);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetFloat);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetName);
	Gura_AssignMethod(wx_XmlResourceHandler, __IsObjectNode);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetNodeContent);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetNodeParent);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetNodeNext);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetNodeChildren);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetParamNode);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetParamValue);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetParamValue_1);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetPosition);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetSize);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetStyle);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetText);
	Gura_AssignMethod(wx_XmlResourceHandler, __HasParam);
	Gura_AssignMethod(wx_XmlResourceHandler, __IsOfClass);
	Gura_AssignMethod(wx_XmlResourceHandler, __SetupWindow);
	Gura_AssignMethod(wx_XmlResourceHandler, __ReportError);
	Gura_AssignMethod(wx_XmlResourceHandler, __ReportError_1);
	Gura_AssignMethod(wx_XmlResourceHandler, __ReportParamError);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetResource);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetNode);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetClass);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetParent);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetInstance);
	Gura_AssignMethod(wx_XmlResourceHandler, __GetParentAsWindow);
}

Gura_ImplementDescendantCreator(wx_XmlResourceHandler)
{
	return new Object_wx_XmlResourceHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
