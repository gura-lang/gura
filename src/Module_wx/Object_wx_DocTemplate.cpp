//----------------------------------------------------------------------------
// wxDocTemplate
// extracted from doctempl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DocTemplate: public wxDocTemplate, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DocTemplate *_pObj;
public:
	inline wx_DocTemplate(wxDocManager* manager, const wxString& descr, const wxString& filter, const wxString& dir, const wxString& ext, const wxString& docTypeName, const wxString& viewTypeName, wxClassInfo* docClassInfo, wxClassInfo* viewClassInfo, long flags) : wxDocTemplate(manager, descr, filter, dir, ext, docTypeName, viewTypeName, docClassInfo, viewClassInfo, flags), _sig(NULL), _pObj(NULL) {}
	~wx_DocTemplate();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DocTemplate *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DocTemplate::~wx_DocTemplate()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DocTemplate::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocTemplate
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocTemplate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxDocManager *manager = Object_wx_DocManager::GetObject(args, 0)->GetEntity();
	wxString descr = wxString::FromUTF8(args.GetString(1));
	wxString filter = wxString::FromUTF8(args.GetString(2));
	wxString dir = wxString::FromUTF8(args.GetString(3));
	wxString ext = wxString::FromUTF8(args.GetString(4));
	wxString docTypeName = wxString::FromUTF8(args.GetString(5));
	wxString viewTypeName = wxString::FromUTF8(args.GetString(6));
	wxClassInfo *docClassInfo = (wxClassInfo *)(NULL);
	if (args.IsValid(7)) docClassInfo = Object_wx_ClassInfo::GetObject(args, 7)->GetEntity();
	wxClassInfo *viewClassInfo = (wxClassInfo *)(NULL);
	if (args.IsValid(8)) viewClassInfo = Object_wx_ClassInfo::GetObject(args, 8)->GetEntity();
	long flags = wxDEFAULT_TEMPLATE_FLAGS;
	if (args.IsValid(9)) flags = args.GetLong(9);
	wx_DocTemplate *pEntity = new wx_DocTemplate(manager, descr, filter, dir, ext, docTypeName, viewTypeName, docClassInfo, viewClassInfo, flags);
	Object_wx_DocTemplate *pObj = Object_wx_DocTemplate::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DocTemplate(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_DocTemplate, CreateDocument)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, CreateDocument)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	long flags = 0;
	if (args.IsValid(1)) flags = args.GetLong(1);
	wxDocument *rtn = (wxDocument *)pSelf->GetEntity()->CreateDocument(path, flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_Document(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocTemplate, CreateView)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, CreateView)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	long flags = 0;
	if (args.IsValid(1)) flags = args.GetLong(1);
	wxView *rtn = (wxView *)pSelf->GetEntity()->CreateView(doc, flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_View(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocTemplate, GetDefaultExtension)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDefaultExtension)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetDefaultExtension();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetDescription)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDescription)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetDescription();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetDirectory)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDirectory)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetDirectory();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetDocumentManager)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDocumentManager)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDocManager *rtn = (wxDocManager *)pSelf->GetEntity()->GetDocumentManager();
	return ReturnValue(env, sig, args, Value(new Object_wx_DocManager(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocTemplate, GetDocumentName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetDocumentName)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetDocumentName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetFileFilter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetFileFilter)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetFileFilter();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, GetFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetFlags)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocTemplate, GetViewName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, GetViewName)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetViewName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocTemplate, InitDocument)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, InitDocument)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	wxString path = wxString::FromUTF8(args.GetString(1));
	long flags = 0;
	if (args.IsValid(2)) flags = args.GetLong(2);
	bool rtn = pSelf->GetEntity()->InitDocument(doc, path, flags);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocTemplate, IsVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocTemplate, IsVisible)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsVisible();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocTemplate, SetDefaultExtension)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "ext", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDefaultExtension)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString ext = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetDefaultExtension(ext);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocTemplate, SetDescription)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "descr", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDescription)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString descr = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetDescription(descr);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocTemplate, SetDirectory)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDirectory)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetDirectory(dir);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocTemplate, SetDocumentManager)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "manager", VTYPE_wx_DocManager, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDocumentManager)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDocManager *manager = Object_wx_DocManager::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetDocumentManager(manager);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocTemplate, SetFileFilter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filter", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetFileFilter)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filter = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetFileFilter(filter);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocTemplate, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetFlags)
{
	Object_wx_DocTemplate *pSelf = Object_wx_DocTemplate::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	pSelf->GetEntity()->SetFlags(flags);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDocTemplate
//----------------------------------------------------------------------------
Object_wx_DocTemplate::~Object_wx_DocTemplate()
{
}

Object *Object_wx_DocTemplate::Clone() const
{
	return NULL;
}

String Object_wx_DocTemplate::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DocTemplate:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DocTemplate::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DocTemplate);
}

//----------------------------------------------------------------------------
// Class implementation for wxDocTemplate
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocTemplate)
{
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
	return new Object_wx_DocTemplate((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
