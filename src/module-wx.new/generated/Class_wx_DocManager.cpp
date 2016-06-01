//----------------------------------------------------------------------------
// wxDocManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocManager
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DocManager, wxDocManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, wxDocManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int initialize = arg.GetNumber(1)
	//pThis->GetEntity()->wxDocManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, ~wxDocManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, ~wxDocManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDocManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, ActivateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "activate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, ActivateView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int activate = arg.GetNumber(1)
	//pThis->GetEntity()->ActivateView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, AddDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, AddDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//pThis->GetEntity()->AddDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, AddFileToHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, AddFileToHistory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->AddFileToHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, AssociateTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "temp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, AssociateTemplate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int temp = arg.GetNumber(0)
	//pThis->GetEntity()->AssociateTemplate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FindTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "classinfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FindTemplate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int classinfo = arg.GetNumber(0)
	//pThis->GetEntity()->FindTemplate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FindDocumentByPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FindDocumentByPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->FindDocumentByPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, CloseDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "force", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, CloseDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int force = arg.GetNumber(1)
	//pThis->GetEntity()->CloseDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, CloseDocuments)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "force", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, CloseDocuments)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int force = arg.GetNumber(0)
	//pThis->GetEntity()->CloseDocuments();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, CreateDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, CreateDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, CreateNewDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, CreateNewDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateNewDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, CreateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, CreateView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, DisassociateTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "temp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, DisassociateTemplate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int temp = arg.GetNumber(0)
	//pThis->GetEntity()->DisassociateTemplate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryAddFilesToMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryAddFilesToMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FileHistoryAddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryAddFilesToMenu_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryAddFilesToMenu_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryAddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryLoad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryLoad)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryLoad();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryRemoveMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryRemoveMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryRemoveMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FileHistorySave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resourceFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistorySave)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int resourceFile = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistorySave();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FileHistoryUseMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FileHistoryUseMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryUseMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, FindTemplateForPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, FindTemplateForPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->FindTemplateForPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetAnyUsableView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetAnyUsableView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAnyUsableView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetCurrentDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetCurrentDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetCurrentView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetCurrentView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetDocumentsVector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetDocumentsVector)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentsVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetTemplatesVector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetTemplatesVector)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTemplatesVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetDocuments)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetDocuments)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocuments();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetFileHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetFileHistory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFileHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetHistoryFilesCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetHistoryFilesCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHistoryFilesCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetLastDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetLastDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLastDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetMaxDocsOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetMaxDocsOpen)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMaxDocsOpen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, GetTemplates)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, GetTemplates)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTemplates();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, Initialize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, MakeNewDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, MakeNewDocumentName)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeNewDocumentName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnCreateFileHistory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, OnCreateFileHistory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnCreateFileHistory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnFileClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileClose)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileClose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnFileCloseAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileCloseAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileCloseAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnFileNew)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileNew)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileNew();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnFileOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileOpen)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileOpen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnFileRevert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileRevert)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileRevert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnFileSave)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileSave)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileSave();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnFileSaveAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnFileSaveAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileSaveAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, RemoveDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, RemoveDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, SelectDocumentPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "save", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, SelectDocumentPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int templates = arg.GetNumber(0)
	//int noTemplates = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int save = arg.GetNumber(4)
	//pThis->GetEntity()->SelectDocumentPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, SelectDocumentType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sort", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, SelectDocumentType)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int templates = arg.GetNumber(0)
	//int noTemplates = arg.GetNumber(1)
	//int sort = arg.GetNumber(2)
	//pThis->GetEntity()->SelectDocumentType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, SelectViewType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sort", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, SelectViewType)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int templates = arg.GetNumber(0)
	//int noTemplates = arg.GetNumber(1)
	//int sort = arg.GetNumber(2)
	//pThis->GetEntity()->SelectViewType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, SetLastDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, SetLastDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetLastDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, SetMaxDocsOpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, SetMaxDocsOpen)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxDocsOpen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, OnMRUFileNotExist)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, OnMRUFileNotExist)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int filename = arg.GetNumber(1)
	//pThis->GetEntity()->OnMRUFileNotExist();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocManager, CreatePreviewFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, CreatePreviewFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int preview = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//pThis->GetEntity()->CreatePreviewFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocManager)
{
	Gura_AssignMethod(wx_DocManager, wxDocManager);
	Gura_AssignMethod(wx_DocManager, ~wxDocManager);
	Gura_AssignMethod(wx_DocManager, ActivateView);
	Gura_AssignMethod(wx_DocManager, AddDocument);
	Gura_AssignMethod(wx_DocManager, AddFileToHistory);
	Gura_AssignMethod(wx_DocManager, AssociateTemplate);
	Gura_AssignMethod(wx_DocManager, FindTemplate);
	Gura_AssignMethod(wx_DocManager, FindDocumentByPath);
	Gura_AssignMethod(wx_DocManager, CloseDocument);
	Gura_AssignMethod(wx_DocManager, CloseDocuments);
	Gura_AssignMethod(wx_DocManager, CreateDocument);
	Gura_AssignMethod(wx_DocManager, CreateNewDocument);
	Gura_AssignMethod(wx_DocManager, CreateView);
	Gura_AssignMethod(wx_DocManager, DisassociateTemplate);
	Gura_AssignMethod(wx_DocManager, FileHistoryAddFilesToMenu);
	Gura_AssignMethod(wx_DocManager, FileHistoryAddFilesToMenu_1);
	Gura_AssignMethod(wx_DocManager, FileHistoryLoad);
	Gura_AssignMethod(wx_DocManager, FileHistoryRemoveMenu);
	Gura_AssignMethod(wx_DocManager, FileHistorySave);
	Gura_AssignMethod(wx_DocManager, FileHistoryUseMenu);
	Gura_AssignMethod(wx_DocManager, FindTemplateForPath);
	Gura_AssignMethod(wx_DocManager, GetAnyUsableView);
	Gura_AssignMethod(wx_DocManager, GetCurrentDocument);
	Gura_AssignMethod(wx_DocManager, GetCurrentView);
	Gura_AssignMethod(wx_DocManager, GetDocumentsVector);
	Gura_AssignMethod(wx_DocManager, GetTemplatesVector);
	Gura_AssignMethod(wx_DocManager, GetDocuments);
	Gura_AssignMethod(wx_DocManager, GetFileHistory);
	Gura_AssignMethod(wx_DocManager, GetHistoryFilesCount);
	Gura_AssignMethod(wx_DocManager, GetLastDirectory);
	Gura_AssignMethod(wx_DocManager, GetMaxDocsOpen);
	Gura_AssignMethod(wx_DocManager, GetTemplates);
	Gura_AssignMethod(wx_DocManager, Initialize);
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
	Gura_AssignMethod(wx_DocManager, OnMRUFileNotExist);
	Gura_AssignMethod(wx_DocManager, CreatePreviewFrame);
}

Gura_ImplementDescendantCreator(wx_DocManager)
{
	return new Object_wx_DocManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
