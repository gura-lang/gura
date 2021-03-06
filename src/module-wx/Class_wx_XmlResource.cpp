//----------------------------------------------------------------------------
// wxXmlResource
// extracted from xmlres.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_XmlResource: public wxXmlResource, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_XmlResource *_pObj;
public:
	inline wx_XmlResource(const wxString& filemask, int flags, const wxString& domain) : wxXmlResource(filemask, flags, domain), _pObj(nullptr) {}
	inline wx_XmlResource(int flags, const wxString& domain) : wxXmlResource(flags, domain), _pObj(nullptr) {}
	~wx_XmlResource();
	inline void AssocWithGura(Object_wx_XmlResource *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_XmlResource::~wx_XmlResource()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_XmlResource::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxXmlResource
//----------------------------------------------------------------------------
Gura_DeclareFunction(XmlResource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlResource));
	DeclareArg(env, "filemask", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "domain", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlResource)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString filemask = wxString::FromUTF8(arg.GetString(0));
	int flags = wxXRC_USE_LOCALE;
	if (arg.IsValid(1)) flags = arg.GetInt(1);
	wxString domain = wxEmptyString;
	if (arg.IsValid(2)) domain = wxString::FromUTF8(arg.GetString(2));
	wx_XmlResource *pEntity = new wx_XmlResource(filemask, flags, domain);
	Object_wx_XmlResource *pObj = Object_wx_XmlResource::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlResource(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(XmlResource_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_XmlResource));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "domain", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(XmlResource_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int flags = wxXRC_USE_LOCALE;
	if (arg.IsValid(0)) flags = arg.GetInt(0);
	wxString domain = wxEmptyString;
	if (arg.IsValid(1)) domain = wxString::FromUTF8(arg.GetString(1));
	wx_XmlResource *pEntity = new wx_XmlResource(flags, domain);
	Object_wx_XmlResource *pObj = Object_wx_XmlResource::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_XmlResource(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_XmlResource, AddHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "handler", VTYPE_wx_XmlResourceHandler, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, AddHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlResourceHandler *handler = Object_wx_XmlResourceHandler::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->AddHandler(handler);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, AttachUnknownControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "control", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, AttachUnknownControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxWindow *control = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxWindow *parent = (wxWindow *)(nullptr);
	if (arg.IsValid(2)) parent = Object_wx_Window::GetObject(arg, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->AttachUnknownControl(name, control, parent);
	return ReturnValue(env, arg, Value(rtn));
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
	pThis->GetEntity()->ClearHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, CompareVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "release", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "revision", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, CompareVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int major = arg.GetInt(0);
	int minor = arg.GetInt(1);
	int release = arg.GetInt(2);
	int revision = arg.GetInt(3);
	int rtn = pThis->GetEntity()->CompareVersion(major, minor, release, revision);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlResource *rtn = (wxXmlResource *)pThis->GetEntity()->Get();
	return ReturnValue(env, arg, Value(new Object_wx_XmlResource(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, GetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, GetVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetVersion();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, GetXRCID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str_id", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value_if_not_found", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, GetXRCID)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString str_id = wxString::FromUTF8(arg.GetString(0));
	int value_if_not_found = -2;
	if (arg.IsValid(1)) value_if_not_found = arg.GetInt(1);
	int rtn = pThis->GetEntity()->GetXRCID(str_id, value_if_not_found);
	return ReturnValue(env, arg, Value(rtn));
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
	pThis->GetEntity()->InitAllHandlers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filemask", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, Load)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filemask = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Load(filemask);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, LoadBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxBitmap rtn = pThis->GetEntity()->LoadBitmap(name);
	return ReturnValue(env, arg, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_XmlResource, LoadDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxDialog *rtn = (wxDialog *)pThis->GetEntity()->LoadDialog(parent, name);
	return ReturnValue(env, arg, Value(new Object_wx_Dialog(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, LoadDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dlg", VTYPE_wx_Dialog, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDialog *dlg = Object_wx_Dialog::GetObject(arg, 0)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString name = wxString::FromUTF8(arg.GetString(2));
	bool rtn = pThis->GetEntity()->LoadDialog(dlg, parent, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, LoadFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame *frame = Object_wx_Frame::GetObject(arg, 0)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString name = wxString::FromUTF8(arg.GetString(2));
	bool rtn = pThis->GetEntity()->LoadFrame(frame, parent, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, LoadIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxIcon rtn = pThis->GetEntity()->LoadIcon(name);
	return ReturnValue(env, arg, Value(new Object_wx_Icon(new wxIcon(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_XmlResource, LoadMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->LoadMenu(name);
	return ReturnValue(env, arg, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, LoadMenuBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadMenuBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxMenuBar *rtn = (wxMenuBar *)pThis->GetEntity()->LoadMenuBar(parent, name);
	return ReturnValue(env, arg, Value(new Object_wx_MenuBar(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, LoadMenuBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadMenuBar_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(arg.GetString(0));
	wxMenuBar *rtn = (wxMenuBar *)pThis->GetEntity()->LoadMenuBar(name);
	return ReturnValue(env, arg, Value(new Object_wx_MenuBar(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, LoadPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxPanel *rtn = (wxPanel *)pThis->GetEntity()->LoadPanel(parent, name);
	return ReturnValue(env, arg, Value(new Object_wx_Panel(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, LoadPanel_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "panel", VTYPE_wx_Panel, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadPanel_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPanel *panel = Object_wx_Panel::GetObject(arg, 0)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString name = wxString::FromUTF8(arg.GetString(2));
	bool rtn = pThis->GetEntity()->LoadPanel(panel, parent, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, LoadToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, LoadToolBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString name = wxString::FromUTF8(arg.GetString(1));
	wxToolBar *rtn = (wxToolBar *)pThis->GetEntity()->LoadToolBar(parent, name);
	return ReturnValue(env, arg, Value(new Object_wx_ToolBar(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "res", VTYPE_wx_XmlResource, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxXmlResource *res = Object_wx_XmlResource::GetObject(arg, 0)->GetEntity();
	wxXmlResource *rtn = (wxXmlResource *)pThis->GetEntity()->Set(res);
	return ReturnValue(env, arg, Value(new Object_wx_XmlResource(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_XmlResource, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_XmlResource, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flags = arg.GetInt(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, Unload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, Unload)
{
	Signal &sig = env.GetSignal();
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Unload(filename);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_XmlResource, GetDomain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, GetDomain)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxChar rtn = pThis->GetEntity()->GetDomain();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_XmlResource, SetDomain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "domain", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_XmlResource, SetDomain)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_XmlResource *pThis = Object_wx_XmlResource::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString domain = wxString::FromUTF8(arg.GetString(0));
	wxChar rtn = pThis->GetEntity()->SetDomain(domain);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

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
// Class implementation for wxXmlResource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XmlResource)
{
	Gura_AssignFunction(XmlResource);
	Gura_AssignFunction(XmlResource_1);
	Gura_AssignMethod(wx_XmlResource, AddHandler);
	Gura_AssignMethod(wx_XmlResource, AttachUnknownControl);
	Gura_AssignMethod(wx_XmlResource, ClearHandlers);
	Gura_AssignMethod(wx_XmlResource, CompareVersion);
	Gura_AssignMethod(wx_XmlResource, Get);
	Gura_AssignMethod(wx_XmlResource, GetFlags);
	Gura_AssignMethod(wx_XmlResource, GetVersion);
	Gura_AssignMethod(wx_XmlResource, GetXRCID);
	Gura_AssignMethod(wx_XmlResource, InitAllHandlers);
	Gura_AssignMethod(wx_XmlResource, Load);
	Gura_AssignMethod(wx_XmlResource, LoadBitmap);
	Gura_AssignMethod(wx_XmlResource, LoadDialog);
	Gura_AssignMethod(wx_XmlResource, LoadDialog_1);
	Gura_AssignMethod(wx_XmlResource, LoadFrame);
	Gura_AssignMethod(wx_XmlResource, LoadIcon);
	Gura_AssignMethod(wx_XmlResource, LoadMenu);
	Gura_AssignMethod(wx_XmlResource, LoadMenuBar);
	Gura_AssignMethod(wx_XmlResource, LoadMenuBar_1);
	Gura_AssignMethod(wx_XmlResource, LoadPanel);
	Gura_AssignMethod(wx_XmlResource, LoadPanel_1);
	Gura_AssignMethod(wx_XmlResource, LoadToolBar);
	Gura_AssignMethod(wx_XmlResource, Set);
	Gura_AssignMethod(wx_XmlResource, SetFlags);
	Gura_AssignMethod(wx_XmlResource, Unload);
	Gura_AssignMethod(wx_XmlResource, GetDomain);
	Gura_AssignMethod(wx_XmlResource, SetDomain);
}

Gura_ImplementDescendantCreator(wx_XmlResource)
{
	return new Object_wx_XmlResource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
