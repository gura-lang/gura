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
Gura_DeclareMethod(wx_XmlResource, wxXmlResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filemask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, wxXmlResource)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filemask = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//int domain = arg.GetNumber(2)
	//pThis->GetEntity()->wxXmlResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, wxXmlResource_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, wxXmlResource_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int domain = arg.GetNumber(1)
	//pThis->GetEntity()->wxXmlResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, ~wxXmlResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, ~wxXmlResource)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxXmlResource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, AddHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, InsertHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, InsertHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, AttachUnknownControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, AttachUnknownControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int control = arg.GetNumber(1)
	//int parent = arg.GetNumber(2)
	//pThis->GetEntity()->AttachUnknownControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, ClearHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, ClearHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, AddSubclassFactory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "factory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, AddSubclassFactory)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int factory = arg.GetNumber(0)
	//pThis->GetEntity()->AddSubclassFactory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, CompareVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "release", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "revision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, CompareVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//int release = arg.GetNumber(2)
	//int revision = arg.GetNumber(3)
	//pThis->GetEntity()->CompareVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, FindXRCIDById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "numId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, FindXRCIDById)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int numId = arg.GetNumber(0)
	//pThis->GetEntity()->FindXRCIDById();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, GetDomain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, GetDomain)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDomain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, GetResourceNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, GetResourceNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetResourceNode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, GetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, GetVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, GetXRCID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value_if_not_found", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, GetXRCID)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str_id = arg.GetNumber(0)
	//int value_if_not_found = arg.GetNumber(1)
	//pThis->GetEntity()->GetXRCID();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, InitAllHandlers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, InitAllHandlers)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->InitAllHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filemask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, Load)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filemask = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->LoadFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadAllFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadAllFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//pThis->GetEntity()->LoadAllFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dlg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dlg = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->LoadDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadFrame_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadFrame_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int frame = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->LoadFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadMenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadMenuBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadMenuBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadMenuBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadMenuBar_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->LoadMenuBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int classname = arg.GetNumber(2)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadObject_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadObject_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int instance = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int classname = arg.GetNumber(3)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadObjectRecursively)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadObjectRecursively)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int classname = arg.GetNumber(2)
	//pThis->GetEntity()->LoadObjectRecursively();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadObjectRecursively_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadObjectRecursively_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int instance = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int classname = arg.GetNumber(3)
	//pThis->GetEntity()->LoadObjectRecursively();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadPanel_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "panel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadPanel_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int panel = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//pThis->GetEntity()->LoadPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, LoadToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, LoadToolBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->LoadToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int res = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, SetDomain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, SetDomain)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int domain = arg.GetNumber(0)
	//pThis->GetEntity()->SetDomain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, Unload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, Unload)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->Unload();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, ReportError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, ReportError)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int context = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->ReportError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, DoReportError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "xrcFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, DoReportError)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_XmlResource, wxXmlResource);
	Gura_AssignMethod(wx_XmlResource, wxXmlResource_1);
	Gura_AssignMethod(wx_XmlResource, ~wxXmlResource);
	Gura_AssignMethod(wx_XmlResource, AddHandler);
	Gura_AssignMethod(wx_XmlResource, InsertHandler);
	Gura_AssignMethod(wx_XmlResource, AttachUnknownControl);
	Gura_AssignMethod(wx_XmlResource, ClearHandlers);
	Gura_AssignMethod(wx_XmlResource, AddSubclassFactory);
	Gura_AssignMethod(wx_XmlResource, CompareVersion);
	Gura_AssignMethod(wx_XmlResource, FindXRCIDById);
	Gura_AssignMethod(wx_XmlResource, Get);
	Gura_AssignMethod(wx_XmlResource, GetDomain);
	Gura_AssignMethod(wx_XmlResource, GetFlags);
	Gura_AssignMethod(wx_XmlResource, GetResourceNode);
	Gura_AssignMethod(wx_XmlResource, GetVersion);
	Gura_AssignMethod(wx_XmlResource, GetXRCID);
	Gura_AssignMethod(wx_XmlResource, InitAllHandlers);
	Gura_AssignMethod(wx_XmlResource, Load);
	Gura_AssignMethod(wx_XmlResource, LoadFile);
	Gura_AssignMethod(wx_XmlResource, LoadAllFiles);
	Gura_AssignMethod(wx_XmlResource, LoadBitmap);
	Gura_AssignMethod(wx_XmlResource, LoadDialog);
	Gura_AssignMethod(wx_XmlResource, LoadDialog_1);
	Gura_AssignMethod(wx_XmlResource, LoadFrame);
	Gura_AssignMethod(wx_XmlResource, LoadFrame_1);
	Gura_AssignMethod(wx_XmlResource, LoadIcon);
	Gura_AssignMethod(wx_XmlResource, LoadMenu);
	Gura_AssignMethod(wx_XmlResource, LoadMenuBar);
	Gura_AssignMethod(wx_XmlResource, LoadMenuBar_1);
	Gura_AssignMethod(wx_XmlResource, LoadObject);
	Gura_AssignMethod(wx_XmlResource, LoadObject_1);
	Gura_AssignMethod(wx_XmlResource, LoadObjectRecursively);
	Gura_AssignMethod(wx_XmlResource, LoadObjectRecursively_1);
	Gura_AssignMethod(wx_XmlResource, LoadPanel);
	Gura_AssignMethod(wx_XmlResource, LoadPanel_1);
	Gura_AssignMethod(wx_XmlResource, LoadToolBar);
	Gura_AssignMethod(wx_XmlResource, Set);
	Gura_AssignMethod(wx_XmlResource, SetDomain);
	Gura_AssignMethod(wx_XmlResource, SetFlags);
	Gura_AssignMethod(wx_XmlResource, Unload);
	Gura_AssignMethod(wx_XmlResource, ReportError);
	Gura_AssignMethod(wx_XmlResource, DoReportError);
}

Gura_ImplementDescendantCreator(wx_XmlResource)
{
	return new Object_wx_XmlResource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
