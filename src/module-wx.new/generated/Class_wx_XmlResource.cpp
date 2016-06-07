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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__XmlResource, "XmlResource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filemask", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XmlResource));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlResource)
{
	//const wxString& filemask = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//const wxString& domain = arg.GetNumber(2)
	//wxXmlResource(filemask, flags, domain);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__XmlResource_1, "XmlResource_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "domain", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_XmlResource));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__XmlResource_1)
{
	//int flags = arg.GetNumber(0)
	//const wxString& domain = arg.GetNumber(1)
	//wxXmlResource(flags, domain);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_XmlResource, __AddHandler, "AddHandler")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __AddHandler)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlResourceHandler* handler = arg.GetNumber(0)
	//pThis->GetEntity()->AddHandler(handler);
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
	//wxXmlResourceHandler* handler = arg.GetNumber(0)
	//pThis->GetEntity()->InsertHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __AttachUnknownControl, "AttachUnknownControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __AttachUnknownControl)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxWindow* control = arg.GetNumber(1)
	//wxWindow* parent = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->AttachUnknownControl(name, control, parent);
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
	//wxXmlSubclassFactory* factory = arg.GetNumber(0)
	//pThis->GetEntity()->AddSubclassFactory(factory);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __CompareVersion, "CompareVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//int _rtn = pThis->GetEntity()->CompareVersion(major, minor, release, revision);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __FindXRCIDById, "FindXRCIDById")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "numId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __FindXRCIDById)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int numId = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->FindXRCIDById(numId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __Get)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlResource* _rtn = pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetDomain, "GetDomain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __GetDomain)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetDomain();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __GetFlags)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetResourceNode, "GetResourceNode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __GetResourceNode)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxXmlNode* _rtn = pThis->GetEntity()->GetResourceNode(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_XmlResource, __GetVersion)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __GetXRCID, "GetXRCID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value_if_not_found", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __GetXRCID)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str_id = arg.GetNumber(0)
	//int value_if_not_found = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->GetXRCID(str_id, value_if_not_found);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filemask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __Load)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filemask = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Load(filemask);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadFile, "LoadFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadFile)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFileName& file = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->LoadFile(file);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadAllFiles, "LoadAllFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadAllFiles)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dirname = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->LoadAllFiles(dirname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadBitmap, "LoadBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadBitmap)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxBitmap _rtn = pThis->GetEntity()->LoadBitmap(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadDialog, "LoadDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadDialog)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//wxDialog* _rtn = pThis->GetEntity()->LoadDialog(parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadDialog_1, "LoadDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dlg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadDialog_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDialog* dlg = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& name = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->LoadDialog(dlg, parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadFrame, "LoadFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadFrame)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//wxFrame* _rtn = pThis->GetEntity()->LoadFrame(parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadFrame_1, "LoadFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "frame", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadFrame_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFrame* frame = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& name = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->LoadFrame(frame, parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadIcon, "LoadIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadIcon)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxIcon _rtn = pThis->GetEntity()->LoadIcon(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadMenu, "LoadMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadMenu)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxMenu* _rtn = pThis->GetEntity()->LoadMenu(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadMenuBar, "LoadMenuBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadMenuBar)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//wxMenuBar* _rtn = pThis->GetEntity()->LoadMenuBar(parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadMenuBar_1, "LoadMenuBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadMenuBar_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxMenuBar* _rtn = pThis->GetEntity()->LoadMenuBar(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObject, "LoadObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObject)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//const wxString& classname = arg.GetNumber(2)
	//wxObject* _rtn = pThis->GetEntity()->LoadObject(parent, name, classname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObject_1, "LoadObject_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObject_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObject* instance = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& name = arg.GetNumber(2)
	//const wxString& classname = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->LoadObject(instance, parent, name, classname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObjectRecursively, "LoadObjectRecursively")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObjectRecursively)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//const wxString& classname = arg.GetNumber(2)
	//wxObject* _rtn = pThis->GetEntity()->LoadObjectRecursively(parent, name, classname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadObjectRecursively_1, "LoadObjectRecursively_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "instance", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadObjectRecursively_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxObject* instance = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& name = arg.GetNumber(2)
	//const wxString& classname = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->LoadObjectRecursively(instance, parent, name, classname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadPanel, "LoadPanel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadPanel)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//wxPanel* _rtn = pThis->GetEntity()->LoadPanel(parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadPanel_1, "LoadPanel_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "panel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadPanel_1)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPanel* panel = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& name = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->LoadPanel(panel, parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __LoadToolBar, "LoadToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __LoadToolBar)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& name = arg.GetNumber(1)
	//wxToolBar* _rtn = pThis->GetEntity()->LoadToolBar(parent, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "res", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __Set)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlResource* res = arg.GetNumber(0)
	//wxXmlResource* _rtn = pThis->GetEntity()->Set(res);
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
	//const wxString& domain = arg.GetNumber(0)
	//pThis->GetEntity()->SetDomain(domain);
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
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_XmlResource, __Unload, "Unload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, __Unload)
{
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Unload(filename);
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
	//const wxXmlNode* context = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//pThis->GetEntity()->ReportError(context, message);
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
	//const wxString& xrcFile = arg.GetNumber(0)
	//const wxXmlNode* position = arg.GetNumber(1)
	//const wxString& message = arg.GetNumber(2)
	//pThis->GetEntity()->DoReportError(xrcFile, position, message);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxXmlResource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResource)
{
	// Constructor assignment
	Gura_AssignFunction(__XmlResource);
	Gura_AssignFunction(__XmlResource_1);
	// Method assignment
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
