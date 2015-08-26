//----------------------------------------------------------------------------
// wxDocTemplate
// extracted from doctempl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DocTemplate: public wxDocTemplate, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DocTemplate *_pObj;
public:
	inline wx_DocTemplate(wxDocManager* manager, const wxString& descr, const wxString& filter, const wxString& dir, const wxString& ext, const wxString& docTypeName, const wxString& viewTypeName, wxClassInfo* docClassInfo, wxClassInfo* viewClassInfo, long flags) : wxDocTemplate(manager, descr, filter, dir, ext, docTypeName, viewTypeName, docClassInfo, viewClassInfo, flags), _pObj(nullptr) {}
	~wx_DocTemplate();
	inline void AssocWithGura(Object_wx_DocTemplate *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DocTemplate::~wx_DocTemplate()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DocTemplate::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocTemplate
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DocTemplate));
	DeclareArg(env, "manager", VTYPE_wx_DocManager, OCCUR_Once);
	DeclareArg(env, "descr", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "filter", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "docTypeName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "viewTypeName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "docClassInfo", VTYPE_wx_ClassInfo, OCCUR_ZeroOrOnce);
	DeclareArg(env, "viewClassInfo", VTYPE_wx_ClassInfo, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DocTemplate)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDocManager *manager = Object_wx_DocManager::GetObject(args, 0)->GetEntity();
	wxString descr = wxString::FromUTF8(args.GetString(1));
	wxString filter = wxString::FromUTF8(args.GetString(2));
	wxString dir = wxString::FromUTF8(args.GetString(3));
	wxString ext = wxString::FromUTF8(args.GetString(4));
	wxString docTypeName = wxString::FromUTF8(args.GetString(5));
	wxString viewTypeName = wxString::FromUTF8(args.GetString(6));
	wxClassInfo *docClassInfo = (wxClassInfo *)(nullptr);
	if (args.IsValid(7)) docClassInfo = Object_wx_ClassInfo::GetObject(args, 7)->GetEntity();
	wxClassInfo *viewClassInfo = (wxClassInfo *)(nullptr);
	if (args.IsValid(8)) viewClassInfo = Object_wx_ClassInfo::GetObject(args, 8)->GetEntity();
	long flags = wxDEFAULT_TEMPLATE_FLAGS;
	if (args.IsValid(9)) flags = args.GetLong(9);
	wx_DocTemplate *pEntity = new wx_DocTemplate(manager, descr, filter, dir, ext, docTypeName, viewTypeName, docClassInfo, viewClassInfo, flags);
	Object_wx_DocTemplate *pObj = Object_wx_DocTemplate::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DocTemplate(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_DocTemplate, CreateDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, CreateDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(args.GetString(0));
	long flags = 0;
	if (args.IsValid(1)) flags = args.GetLong(1);
	wxDocument *rtn = (wxDocument *)pThis->GetEntity()->CreateDocument(path, flags);
	return ReturnValue(env, args, Value(new Object_wx_Document(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocTemplate, CreateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, CreateView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	long flags = 0;
	if (args.IsValid(1)) flags = args.GetLong(1);
	wxView *rtn = (wxView *)pThis->GetEntity()->CreateView(doc, flags);
	return ReturnValue(env, args, Value(new Object_wx_View(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocTemplate, GetDefaultExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDefaultExtension)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDefaultExtension();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDescription();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDirectory();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDocumentManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocManager *rtn = (wxDocManager *)pThis->GetEntity()->GetDocumentManager();
	return ReturnValue(env, args, Value(new Object_wx_DocManager(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocTemplate, GetDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDocumentName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDocumentName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetFileFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetFileFilter)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFileFilter();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocTemplate, GetViewName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetViewName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetViewName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, InitDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, InitDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	wxString path = wxString::FromUTF8(args.GetString(1));
	long flags = 0;
	if (args.IsValid(2)) flags = args.GetLong(2);
	bool rtn = pThis->GetEntity()->InitDocument(doc, path, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocTemplate, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, IsVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsVisible();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocTemplate, SetDefaultExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDefaultExtension)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString ext = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDefaultExtension(ext);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "descr", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString descr = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDescription(descr);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDirectory(dir);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "manager", VTYPE_wx_DocManager, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDocumentManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocManager *manager = Object_wx_DocManager::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDocumentManager(manager);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetFileFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filter", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetFileFilter)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filter = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFileFilter(filter);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long flags = args.GetLong(0);
	pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDocTemplate
//----------------------------------------------------------------------------
Object_wx_DocTemplate::~Object_wx_DocTemplate()
{
}

Object *Object_wx_DocTemplate::Clone() const
{
	return nullptr;
}

String Object_wx_DocTemplate::ToString(bool exprFlag)
{
	String rtn("<wx.DocTemplate:");
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
// Class implementation for wxDocTemplate
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocTemplate)
{
	Gura_AssignFunction(DocTemplate);
	Gura_AssignMethod(wx_DocTemplate, CreateDocument);
	Gura_AssignMethod(wx_DocTemplate, CreateView);
	Gura_AssignMethod(wx_DocTemplate, GetDefaultExtension);
	Gura_AssignMethod(wx_DocTemplate, GetDescription);
	Gura_AssignMethod(wx_DocTemplate, GetDirectory);
	Gura_AssignMethod(wx_DocTemplate, GetDocumentManager);
	Gura_AssignMethod(wx_DocTemplate, GetDocumentName);
	Gura_AssignMethod(wx_DocTemplate, GetFileFilter);
	Gura_AssignMethod(wx_DocTemplate, GetFlags);
	Gura_AssignMethod(wx_DocTemplate, GetViewName);
	Gura_AssignMethod(wx_DocTemplate, InitDocument);
	Gura_AssignMethod(wx_DocTemplate, IsVisible);
	Gura_AssignMethod(wx_DocTemplate, SetDefaultExtension);
	Gura_AssignMethod(wx_DocTemplate, SetDescription);
	Gura_AssignMethod(wx_DocTemplate, SetDirectory);
	Gura_AssignMethod(wx_DocTemplate, SetDocumentManager);
	Gura_AssignMethod(wx_DocTemplate, SetFileFilter);
	Gura_AssignMethod(wx_DocTemplate, SetFlags);
}

Gura_ImplementDescendantCreator(wx_DocTemplate)
{
	return new Object_wx_DocTemplate((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
