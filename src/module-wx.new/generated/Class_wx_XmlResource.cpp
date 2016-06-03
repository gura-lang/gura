//----------------------------------------------------------------------------
// wxXmlResource
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlResource
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXmlResource
//----------------------------------------------------------------------------
Object_wx_XmlResource::~Object_wx_XmlResource()
{
}

Object *Object_wx_XmlResource::Clone() const
{
	return nullptr;
}

String Object_wx_XmlResource::ToString(bool exprFlag)
{
	String rtn("<wx.XmlResource:");
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
Gura_DeclareMethodAlias(wx_XmlResource, __wxXmlResource, "wxXmlResource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filemask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __wxXmlResource)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filemask = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//int domain = arg.GetNumber(2)
	//pThis->GetEntity()->wxXmlResource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __wxXmlResource_1, "wxXmlResource_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __wxXmlResource_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->wxXmlResource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __AddHandler, "AddHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __AddHandler)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __InsertHandler, "InsertHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __InsertHandler)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertHandler();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __AttachUnknownControl, "AttachUnknownControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __AttachUnknownControl)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int control = arg.GetNumber(1)
	//int parent = arg.GetNumber(2)
	//pThis->GetEntity()->AttachUnknownControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __ClearHandlers, "ClearHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __ClearHandlers)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __AddSubclassFactory, "AddSubclassFactory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "factory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __AddSubclassFactory)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factory = arg.GetNumber(0)
	//pThis->GetEntity()->AddSubclassFactory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __CompareVersion, "CompareVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "release", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "revision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __CompareVersion)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//int release = arg.GetNumber(2)
	//int revision = arg.GetNumber(3)
	//pThis->GetEntity()->CompareVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __FindXRCIDById, "FindXRCIDById")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __FindXRCIDById)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numId = arg.GetNumber(0)
	//pThis->GetEntity()->FindXRCIDById();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __Get)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetDomain, "GetDomain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __GetDomain)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDomain();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __GetFlags)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetResourceNode, "GetResourceNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __GetResourceNode)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetResourceNode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __GetVersion)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetXRCID, "GetXRCID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value_if_not_found", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __GetXRCID)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str_id = arg.GetNumber(0)
	//int value_if_not_found = arg.GetNumber(1)
	//pThis->GetEntity()->GetXRCID();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __InitAllHandlers, "InitAllHandlers")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __InitAllHandlers)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->InitAllHandlers();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filemask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __Load)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filemask = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadFile)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadAllFiles, "LoadAllFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadAllFiles)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//pThis->GetEntity()->LoadAllFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadBitmap, "LoadBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadBitmap)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadDialog, "LoadDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadDialog)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadDialog_1, "LoadDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dlg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadDialog_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dlg = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->LoadDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadFrame, "LoadFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadFrame)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadFrame_1, "LoadFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadFrame_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->LoadFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadIcon, "LoadIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadIcon)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadMenu, "LoadMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadMenu)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadMenuBar, "LoadMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadMenuBar)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadMenuBar_1, "LoadMenuBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadMenuBar_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadMenuBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObject, "LoadObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObject)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int classname = arg.GetNumber(2)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObject_1, "LoadObject_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObject_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int instance = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int classname = arg.GetNumber(3)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObjectRecursively, "LoadObjectRecursively")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObjectRecursively)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int classname = arg.GetNumber(2)
	//pThis->GetEntity()->LoadObjectRecursively();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObjectRecursively_1, "LoadObjectRecursively_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObjectRecursively_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int instance = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int classname = arg.GetNumber(3)
	//pThis->GetEntity()->LoadObjectRecursively();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadPanel, "LoadPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadPanel)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadPanel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadPanel_1, "LoadPanel_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "panel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadPanel_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int panel = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->LoadPanel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadToolBar, "LoadToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadToolBar)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __Set)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __SetDomain, "SetDomain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __SetDomain)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->SetDomain();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __SetFlags)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __Unload, "Unload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __Unload)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->Unload();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __ReportError, "ReportError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __ReportError)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __DoReportError, "DoReportError")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xrcFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __DoReportError)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int xrcFile = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//int message = arg.GetNumber(2)
	//pThis->GetEntity()->DoReportError();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlResource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResource)
{
	Gura_AssignMethod(wx_XmlResource, __wxXmlResource);
	Gura_AssignMethod(wx_XmlResource, __wxXmlResource_1);
	Gura_AssignMethod(wx_XmlResource, __AddHandler);
	Gura_AssignMethod(wx_XmlResource, __InsertHandler);
	Gura_AssignMethod(wx_XmlResource, __AttachUnknownControl);
	Gura_AssignMethod(wx_XmlResource, __ClearHandlers);
	Gura_AssignMethod(wx_XmlResource, __AddSubclassFactory);
	Gura_AssignMethod(wx_XmlResource, __CompareVersion);
	Gura_AssignMethod(wx_XmlResource, __FindXRCIDById);
	Gura_AssignMethod(wx_XmlResource, __Get);
	Gura_AssignMethod(wx_XmlResource, __GetDomain);
	Gura_AssignMethod(wx_XmlResource, __GetFlags);
	Gura_AssignMethod(wx_XmlResource, __GetResourceNode);
	Gura_AssignMethod(wx_XmlResource, __GetVersion);
	Gura_AssignMethod(wx_XmlResource, __GetXRCID);
	Gura_AssignMethod(wx_XmlResource, __InitAllHandlers);
	Gura_AssignMethod(wx_XmlResource, __Load);
	Gura_AssignMethod(wx_XmlResource, __LoadFile);
	Gura_AssignMethod(wx_XmlResource, __LoadAllFiles);
	Gura_AssignMethod(wx_XmlResource, __LoadBitmap);
	Gura_AssignMethod(wx_XmlResource, __LoadDialog);
	Gura_AssignMethod(wx_XmlResource, __LoadDialog_1);
	Gura_AssignMethod(wx_XmlResource, __LoadFrame);
	Gura_AssignMethod(wx_XmlResource, __LoadFrame_1);
	Gura_AssignMethod(wx_XmlResource, __LoadIcon);
	Gura_AssignMethod(wx_XmlResource, __LoadMenu);
	Gura_AssignMethod(wx_XmlResource, __LoadMenuBar);
	Gura_AssignMethod(wx_XmlResource, __LoadMenuBar_1);
	Gura_AssignMethod(wx_XmlResource, __LoadObject);
	Gura_AssignMethod(wx_XmlResource, __LoadObject_1);
	Gura_AssignMethod(wx_XmlResource, __LoadObjectRecursively);
	Gura_AssignMethod(wx_XmlResource, __LoadObjectRecursively_1);
	Gura_AssignMethod(wx_XmlResource, __LoadPanel);
	Gura_AssignMethod(wx_XmlResource, __LoadPanel_1);
	Gura_AssignMethod(wx_XmlResource, __LoadToolBar);
	Gura_AssignMethod(wx_XmlResource, __Set);
	Gura_AssignMethod(wx_XmlResource, __SetDomain);
	Gura_AssignMethod(wx_XmlResource, __SetFlags);
	Gura_AssignMethod(wx_XmlResource, __Unload);
	Gura_AssignMethod(wx_XmlResource, __ReportError);
	Gura_AssignMethod(wx_XmlResource, __DoReportError);
}

Gura_ImplementDescendantCreator(wx_XmlResource)
{
	return new Object_wx_XmlResource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
