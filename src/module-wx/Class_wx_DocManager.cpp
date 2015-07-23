//----------------------------------------------------------------------------
// wxDocManager
// extracted from docmanag.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DocManager: public wxDocManager, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DocManager *_pObj;
public:
	inline wx_DocManager(long flags, bool initialize) : wxDocManager(flags, initialize), _pObj(nullptr) {}
	~wx_DocManager();
	inline void AssocWithGura(Object_wx_DocManager *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DocManager::~wx_DocManager()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DocManager::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocManager
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DocManager));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "initialize", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DocManager)
{
	if (!CheckWxReady(sig)) return Value::Null;
	long flags = wxDEFAULT_DOCMAN_FLAGS;
	if (args.IsValid(0)) flags = args.GetLong(0);
	bool initialize = true;
	if (args.IsValid(1)) initialize = args.GetBoolean(1);
	wx_DocManager *pEntity = new wx_DocManager(flags, initialize);
	Object_wx_DocManager *pObj = Object_wx_DocManager::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DocManager(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DocManager, ActivateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_View, OCCUR_Once);
	DeclareArg(env, "activate", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, ActivateView)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *doc = Object_wx_View::GetObject(args, 0)->GetEntity();
	bool activate = true;
	if (args.IsValid(1)) activate = args.GetBoolean(1);
	pThis->GetEntity()->ActivateView(doc, activate);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, AddDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, AddDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddDocument(doc);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, AddFileToHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, AddFileToHistory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->AddFileToHistory(filename);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, AssociateTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "temp", VTYPE_wx_DocTemplate, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, AssociateTemplate)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocTemplate *temp = Object_wx_DocTemplate::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AssociateTemplate(temp);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, CloseDocuments)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "force", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, CloseDocuments)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool force = true;
	if (args.IsValid(0)) force = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->CloseDocuments(force);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocManager, CreateDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, CreateDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	long flags = args.GetLong(1);
	wxDocument *rtn = (wxDocument *)pThis->GetEntity()->CreateDocument(path, flags);
	return ReturnValue(env, args, Value(new Object_wx_Document(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocManager, CreateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, CreateView)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	long flags = args.GetLong(1);
	wxView *rtn = (wxView *)pThis->GetEntity()->CreateView(doc, flags);
	return ReturnValue(env, args, Value(new Object_wx_View(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocManager, DisassociateTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "temp", VTYPE_wx_DocTemplate, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, DisassociateTemplate)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocTemplate *temp = Object_wx_DocTemplate::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DisassociateTemplate(temp);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryAddFilesToMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryAddFilesToMenu)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->FileHistoryAddFilesToMenu();
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryAddFilesToMenu_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryAddFilesToMenu_1)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FileHistoryAddFilesToMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "config", VTYPE_wx_ConfigBase, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryLoad)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *config = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FileHistoryLoad(*config);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryRemoveMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryRemoveMenu)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FileHistoryRemoveMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, FileHistorySave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "resourceFile", VTYPE_wx_ConfigBase, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistorySave)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConfigBase *resourceFile = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FileHistorySave(*resourceFile);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryUseMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryUseMenu)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->FileHistoryUseMenu(menu);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, FindTemplateForPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, FindTemplateForPath)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxDocTemplate *rtn = (wxDocTemplate *)pThis->GetEntity()->FindTemplateForPath(path);
	return ReturnValue(env, args, Value(new Object_wx_DocTemplate(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocManager, GetCurrentDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetCurrentDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *rtn = (wxDocument *)pThis->GetEntity()->GetCurrentDocument();
	return ReturnValue(env, args, Value(new Object_wx_Document(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocManager, GetCurrentView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetCurrentView)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *rtn = (wxView *)pThis->GetEntity()->GetCurrentView();
	return ReturnValue(env, args, Value(new Object_wx_View(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocManager, GetDocuments)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetDocuments)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxList &rtn = pThis->GetEntity()->GetDocuments();
	return ReturnValue(env, args, Value(new Object_wx_List(new wxList(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DocManager, GetFileHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetFileHistory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileHistory *rtn = (wxFileHistory *)pThis->GetEntity()->GetFileHistory();
	return ReturnValue(env, args, Value(new Object_wx_FileHistory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocManager, GetLastDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetLastDirectory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetLastDirectory();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocManager, GetMaxDocsOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetMaxDocsOpen)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMaxDocsOpen();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocManager, GetHistoryFilesCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetHistoryFilesCount)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetHistoryFilesCount();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocManager, GetTemplates)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, GetTemplates)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxList &rtn = pThis->GetEntity()->GetTemplates();
	return ReturnValue(env, args, Value(new Object_wx_List(new wxList(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DocManager, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, Initialize)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Initialize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocManager, MakeDefaultName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "buf", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, MakeDefaultName)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString buf = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->MakeDefaultName(buf);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DocManager, MakeNewDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, MakeNewDocumentName)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->MakeNewDocumentName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DocManager, OnCreateFileHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, OnCreateFileHistory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFileHistory *rtn = (wxFileHistory *)pThis->GetEntity()->OnCreateFileHistory();
	return ReturnValue(env, args, Value(new Object_wx_FileHistory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocManager, OnFileClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileClose)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFileClose(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, OnFileCloseAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileCloseAll)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFileCloseAll(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, OnFileNew)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileNew)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFileNew(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, OnFileOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileOpen)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFileOpen(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, OnFileRevert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileRevert)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFileRevert(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, OnFileSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileSave)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFileSave(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, OnFileSaveAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CommandEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileSaveAs)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandEvent *event = Object_wx_CommandEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnFileSaveAs(*event);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, RemoveDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, RemoveDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->RemoveDocument(doc);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, SelectDocumentPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "templates", VTYPE_wx_DocTemplate, OCCUR_Once);
	DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "save", VTYPE_boolean, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, SelectDocumentPath)
{
#if 0
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocTemplate *templates = Object_wx_DocTemplate::GetObject(args, 0)->GetEntity();
	int noTemplates = args.GetInt(1);
	wxString path = wxString::FromUTF8(args.GetString(2));
	long flags = args.GetLong(3);
	bool save = args.GetBoolean(4);
	wxDocTemplate *rtn = (wxDocTemplate *)pThis->GetEntity()->SelectDocumentPath(*templates, noTemplates, path, flags, save);
	return ReturnValue(env, args, Value(new Object_wx_DocTemplate(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, SelectDocumentType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "templates", VTYPE_wx_DocTemplate, OCCUR_Once);
	DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sort", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, SelectDocumentType)
{
#if 0
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocTemplate *templates = Object_wx_DocTemplate::GetObject(args, 0)->GetEntity();
	int noTemplates = args.GetInt(1);
	bool sort = false;
	if (args.IsValid(2)) sort = args.GetBoolean(2);
	wxDocTemplate *rtn = (wxDocTemplate *)pThis->GetEntity()->SelectDocumentType(*templates, noTemplates, sort);
	return ReturnValue(env, args, Value(new Object_wx_DocTemplate(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, SelectViewType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "templates", VTYPE_wx_DocTemplate, OCCUR_Once);
	DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sort", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocManager, SelectViewType)
{
#if 0
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocTemplate *templates = Object_wx_DocTemplate::GetObject(args, 0)->GetEntity();
	int noTemplates = args.GetInt(1);
	bool sort = false;
	if (args.IsValid(2)) sort = args.GetBoolean(2);
	wxDocTemplate *rtn = (wxDocTemplate *)pThis->GetEntity()->SelectViewType(*templates, noTemplates, sort);
	return ReturnValue(env, args, Value(new Object_wx_DocTemplate(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, SetLastDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, SetLastDirectory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dir = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLastDirectory(dir);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocManager, SetMaxDocsOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, SetMaxDocsOpen)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetMaxDocsOpen(n);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDocManager
//----------------------------------------------------------------------------
Object_wx_DocManager::~Object_wx_DocManager()
{
}

Object *Object_wx_DocManager::Clone() const
{
	return nullptr;
}

String Object_wx_DocManager::ToString(bool exprFlag)
{
	String rtn("<wx.DocManager:");
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
// Class implementation for wxDocManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocManager)
{
	Gura_AssignFunction(DocManager);
	Gura_AssignMethod(wx_DocManager, ActivateView);
	Gura_AssignMethod(wx_DocManager, AddDocument);
	Gura_AssignMethod(wx_DocManager, AddFileToHistory);
	Gura_AssignMethod(wx_DocManager, AssociateTemplate);
	Gura_AssignMethod(wx_DocManager, CloseDocuments);
	Gura_AssignMethod(wx_DocManager, CreateDocument);
	Gura_AssignMethod(wx_DocManager, CreateView);
	Gura_AssignMethod(wx_DocManager, DisassociateTemplate);
	Gura_AssignMethod(wx_DocManager, FileHistoryAddFilesToMenu);
	Gura_AssignMethod(wx_DocManager, FileHistoryAddFilesToMenu_1);
	Gura_AssignMethod(wx_DocManager, FileHistoryLoad);
	Gura_AssignMethod(wx_DocManager, FileHistoryRemoveMenu);
	Gura_AssignMethod(wx_DocManager, FileHistorySave);
	Gura_AssignMethod(wx_DocManager, FileHistoryUseMenu);
	Gura_AssignMethod(wx_DocManager, FindTemplateForPath);
	Gura_AssignMethod(wx_DocManager, GetCurrentDocument);
	Gura_AssignMethod(wx_DocManager, GetCurrentView);
	Gura_AssignMethod(wx_DocManager, GetDocuments);
	Gura_AssignMethod(wx_DocManager, GetFileHistory);
	Gura_AssignMethod(wx_DocManager, GetLastDirectory);
	Gura_AssignMethod(wx_DocManager, GetMaxDocsOpen);
	Gura_AssignMethod(wx_DocManager, GetHistoryFilesCount);
	Gura_AssignMethod(wx_DocManager, GetTemplates);
	Gura_AssignMethod(wx_DocManager, Initialize);
	Gura_AssignMethod(wx_DocManager, MakeDefaultName);
	Gura_AssignMethod(wx_DocManager, MakeNewDocumentName);
	Gura_AssignMethod(wx_DocManager, OnCreateFileHistory);
	Gura_AssignMethod(wx_DocManager, OnFileClose);
	Gura_AssignMethod(wx_DocManager, OnFileCloseAll);
	Gura_AssignMethod(wx_DocManager, OnFileNew);
	Gura_AssignMethod(wx_DocManager, OnFileOpen);
	Gura_AssignMethod(wx_DocManager, OnFileRevert);
	Gura_AssignMethod(wx_DocManager, OnFileSave);
	Gura_AssignMethod(wx_DocManager, OnFileSaveAs);
	Gura_AssignMethod(wx_DocManager, RemoveDocument);
	Gura_AssignMethod(wx_DocManager, SelectDocumentPath);
	Gura_AssignMethod(wx_DocManager, SelectDocumentType);
	Gura_AssignMethod(wx_DocManager, SelectViewType);
	Gura_AssignMethod(wx_DocManager, SetLastDirectory);
	Gura_AssignMethod(wx_DocManager, SetMaxDocsOpen);
}

Gura_ImplementDescendantCreator(wx_DocManager)
{
	return new Object_wx_DocManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
