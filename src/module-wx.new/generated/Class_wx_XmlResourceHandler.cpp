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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_XmlResourceHandler, wxXmlResourceHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, wxXmlResourceHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxXmlResourceHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, ~wxXmlResourceHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, ~wxXmlResourceHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxXmlResourceHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateResource)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int instance = arg.GetNumber(2)
	//pThis->GetEntity()->CreateResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, DoCreateResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, DoCreateResource)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DoCreateResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CanHandle)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->CanHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, SetParentResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, SetParentResource)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, AddStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, AddStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->AddStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, AddWindowStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, AddWindowStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AddWindowStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "this_hnd_only", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int this_hnd_only = arg.GetNumber(1)
	//pThis->GetEntity()->CreateChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateChildrenPrivately)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootnode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateChildrenPrivately)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int rootnode = arg.GetNumber(1)
	//pThis->GetEntity()->CreateChildrenPrivately();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, CreateResFromNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, CreateResFromNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int instance = arg.GetNumber(2)
	//pThis->GetEntity()->CreateResFromNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetAnimation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetAnimation)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetAnimation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetBitmap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetBitmap_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetBool)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//pThis->GetEntity()->GetBool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultColour = arg.GetNumber(1)
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetCurFileSystem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetCurFileSystem)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurFileSystem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetDimension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "windowToUse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetDimension)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//int windowToUse = arg.GetNumber(2)
	//pThis->GetEntity()->GetDimension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dirDefault", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int dirDefault = arg.GetNumber(1)
	//pThis->GetEntity()->GetDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetID)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetID();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetIcon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetIcon_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetIconBundle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultArtClient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetIconBundle)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultArtClient = arg.GetNumber(1)
	//pThis->GetEntity()->GetIconBundle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetImageList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//pThis->GetEntity()->GetLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetFloat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetFloat)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaultv = arg.GetNumber(1)
	//pThis->GetEntity()->GetFloat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, IsObjectNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, IsObjectNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->IsObjectNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetNodeContent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetNodeContent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeContent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetNodeParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetNodeParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetNodeNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetNodeNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetNodeChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetNodeChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetNodeChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParamNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParamNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetParamNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParamValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParamValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetParamValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParamValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParamValue_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//pThis->GetEntity()->GetParamValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "windowToUse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int windowToUse = arg.GetNumber(1)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaults", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int defaults = arg.GetNumber(1)
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "translate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int translate = arg.GetNumber(1)
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, HasParam)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, HasParam)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//pThis->GetEntity()->HasParam();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, IsOfClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, IsOfClass)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int node = arg.GetNumber(0)
	//int classname = arg.GetNumber(1)
	//pThis->GetEntity()->IsOfClass();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, SetupWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, SetupWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//pThis->GetEntity()->SetupWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, ReportError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, ReportError)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, ReportError_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, ReportError_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, ReportParamError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "param", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResourceHandler, ReportParamError)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int param = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->ReportParamError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetResource)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetClass)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClass();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetInstance)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInstance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResourceHandler, GetParentAsWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResourceHandler, GetParentAsWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResourceHandler *pThis = Object_wx_XmlResourceHandler::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParentAsWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlResourceHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResourceHandler)
{
	Gura_AssignMethod(wx_XmlResourceHandler, wxXmlResourceHandler);
	Gura_AssignMethod(wx_XmlResourceHandler, ~wxXmlResourceHandler);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateResource);
	Gura_AssignMethod(wx_XmlResourceHandler, DoCreateResource);
	Gura_AssignMethod(wx_XmlResourceHandler, CanHandle);
	Gura_AssignMethod(wx_XmlResourceHandler, SetParentResource);
	Gura_AssignMethod(wx_XmlResourceHandler, AddStyle);
	Gura_AssignMethod(wx_XmlResourceHandler, AddWindowStyles);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateChildren);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateChildrenPrivately);
	Gura_AssignMethod(wx_XmlResourceHandler, CreateResFromNode);
	Gura_AssignMethod(wx_XmlResourceHandler, GetAnimation);
	Gura_AssignMethod(wx_XmlResourceHandler, GetBitmap);
	Gura_AssignMethod(wx_XmlResourceHandler, GetBitmap_1);
	Gura_AssignMethod(wx_XmlResourceHandler, GetBool);
	Gura_AssignMethod(wx_XmlResourceHandler, GetColour);
	Gura_AssignMethod(wx_XmlResourceHandler, GetCurFileSystem);
	Gura_AssignMethod(wx_XmlResourceHandler, GetDimension);
	Gura_AssignMethod(wx_XmlResourceHandler, GetDirection);
	Gura_AssignMethod(wx_XmlResourceHandler, GetFont);
	Gura_AssignMethod(wx_XmlResourceHandler, GetID);
	Gura_AssignMethod(wx_XmlResourceHandler, GetIcon);
	Gura_AssignMethod(wx_XmlResourceHandler, GetIcon_1);
	Gura_AssignMethod(wx_XmlResourceHandler, GetIconBundle);
	Gura_AssignMethod(wx_XmlResourceHandler, GetImageList);
	Gura_AssignMethod(wx_XmlResourceHandler, GetLong);
	Gura_AssignMethod(wx_XmlResourceHandler, GetFloat);
	Gura_AssignMethod(wx_XmlResourceHandler, GetName);
	Gura_AssignMethod(wx_XmlResourceHandler, IsObjectNode);
	Gura_AssignMethod(wx_XmlResourceHandler, GetNodeContent);
	Gura_AssignMethod(wx_XmlResourceHandler, GetNodeParent);
	Gura_AssignMethod(wx_XmlResourceHandler, GetNodeNext);
	Gura_AssignMethod(wx_XmlResourceHandler, GetNodeChildren);
	Gura_AssignMethod(wx_XmlResourceHandler, GetParamNode);
	Gura_AssignMethod(wx_XmlResourceHandler, GetParamValue);
	Gura_AssignMethod(wx_XmlResourceHandler, GetParamValue_1);
	Gura_AssignMethod(wx_XmlResourceHandler, GetPosition);
	Gura_AssignMethod(wx_XmlResourceHandler, GetSize);
	Gura_AssignMethod(wx_XmlResourceHandler, GetStyle);
	Gura_AssignMethod(wx_XmlResourceHandler, GetText);
	Gura_AssignMethod(wx_XmlResourceHandler, HasParam);
	Gura_AssignMethod(wx_XmlResourceHandler, IsOfClass);
	Gura_AssignMethod(wx_XmlResourceHandler, SetupWindow);
	Gura_AssignMethod(wx_XmlResourceHandler, ReportError);
	Gura_AssignMethod(wx_XmlResourceHandler, ReportError_1);
	Gura_AssignMethod(wx_XmlResourceHandler, ReportParamError);
	Gura_AssignMethod(wx_XmlResourceHandler, GetResource);
	Gura_AssignMethod(wx_XmlResourceHandler, GetNode);
	Gura_AssignMethod(wx_XmlResourceHandler, GetClass);
	Gura_AssignMethod(wx_XmlResourceHandler, GetParent);
	Gura_AssignMethod(wx_XmlResourceHandler, GetInstance);
	Gura_AssignMethod(wx_XmlResourceHandler, GetParentAsWindow);
}

Gura_ImplementDescendantCreator(wx_XmlResourceHandler)
{
	return new Object_wx_XmlResourceHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
