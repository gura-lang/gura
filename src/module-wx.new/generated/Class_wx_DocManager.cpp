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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DocManager, "DocManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "initialize", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DocManager));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DocManager)
{
	//long flags = arg.GetNumber(0)
	//bool initialize = arg.GetNumber(1)
	//wxDocManager();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DocManager, __ActivateView, "ActivateView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "activate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __ActivateView)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxView* doc = arg.GetNumber(0)
	//bool activate = arg.GetNumber(1)
	//pThis->GetEntity()->ActivateView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __AddDocument, "AddDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __AddDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocument* doc = arg.GetNumber(0)
	//pThis->GetEntity()->AddDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __AddFileToHistory, "AddFileToHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __AddFileToHistory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//pThis->GetEntity()->AddFileToHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __AssociateTemplate, "AssociateTemplate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "temp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __AssociateTemplate)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocTemplate* temp = arg.GetNumber(0)
	//pThis->GetEntity()->AssociateTemplate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FindTemplate, "FindTemplate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "classinfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FindTemplate)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxClassInfo* classinfo = arg.GetNumber(0)
	//pThis->GetEntity()->FindTemplate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FindDocumentByPath, "FindDocumentByPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FindDocumentByPath)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->FindDocumentByPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __CloseDocument, "CloseDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "force", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __CloseDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocument* doc = arg.GetNumber(0)
	//bool force = arg.GetNumber(1)
	//pThis->GetEntity()->CloseDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __CloseDocuments, "CloseDocuments")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "force", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __CloseDocuments)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool force = arg.GetNumber(0)
	//pThis->GetEntity()->CloseDocuments();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __CreateDocument, "CreateDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __CreateDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//long flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __CreateNewDocument, "CreateNewDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __CreateNewDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateNewDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __CreateView, "CreateView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __CreateView)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocument* doc = arg.GetNumber(0)
	//long flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __DisassociateTemplate, "DisassociateTemplate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "temp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __DisassociateTemplate)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocTemplate* temp = arg.GetNumber(0)
	//pThis->GetEntity()->DisassociateTemplate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FileHistoryAddFilesToMenu, "FileHistoryAddFilesToMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __FileHistoryAddFilesToMenu)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->FileHistoryAddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FileHistoryAddFilesToMenu_1, "FileHistoryAddFilesToMenu_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FileHistoryAddFilesToMenu_1)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* menu = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryAddFilesToMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FileHistoryLoad, "FileHistoryLoad")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FileHistoryLoad)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxConfigBase& config = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryLoad();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FileHistoryRemoveMenu, "FileHistoryRemoveMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FileHistoryRemoveMenu)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* menu = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryRemoveMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FileHistorySave, "FileHistorySave")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resourceFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FileHistorySave)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConfigBase& resourceFile = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistorySave();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FileHistoryUseMenu, "FileHistoryUseMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FileHistoryUseMenu)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* menu = arg.GetNumber(0)
	//pThis->GetEntity()->FileHistoryUseMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __FindTemplateForPath, "FindTemplateForPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __FindTemplateForPath)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->FindTemplateForPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetAnyUsableView, "GetAnyUsableView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetAnyUsableView)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAnyUsableView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetCurrentDocument, "GetCurrentDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetCurrentDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetCurrentView, "GetCurrentView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetCurrentView)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetDocumentsVector, "GetDocumentsVector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetDocumentsVector)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentsVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetTemplatesVector, "GetTemplatesVector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetTemplatesVector)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTemplatesVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetDocuments, "GetDocuments")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetDocuments)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocuments();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetFileHistory, "GetFileHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetFileHistory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetHistoryFilesCount, "GetHistoryFilesCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetHistoryFilesCount)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHistoryFilesCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetLastDirectory, "GetLastDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetLastDirectory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetMaxDocsOpen, "GetMaxDocsOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetMaxDocsOpen)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxDocsOpen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __GetTemplates, "GetTemplates")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __GetTemplates)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTemplates();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __Initialize, "Initialize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __Initialize)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __MakeNewDocumentName, "MakeNewDocumentName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __MakeNewDocumentName)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeNewDocumentName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnCreateFileHistory, "OnCreateFileHistory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocManager, __OnCreateFileHistory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnCreateFileHistory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnFileClose, "OnFileClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnFileClose)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCommandEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileClose();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnFileCloseAll, "OnFileCloseAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnFileCloseAll)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCommandEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileCloseAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnFileNew, "OnFileNew")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnFileNew)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCommandEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileNew();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnFileOpen, "OnFileOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnFileOpen)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCommandEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileOpen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnFileRevert, "OnFileRevert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnFileRevert)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCommandEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileRevert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnFileSave, "OnFileSave")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnFileSave)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCommandEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileSave();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnFileSaveAs, "OnFileSaveAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnFileSaveAs)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCommandEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnFileSaveAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __RemoveDocument, "RemoveDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __RemoveDocument)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocument* doc = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __SelectDocumentPath, "SelectDocumentPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "save", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __SelectDocumentPath)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocTemplate** templates = arg.GetNumber(0)
	//int noTemplates = arg.GetNumber(1)
	//wxString& path = arg.GetNumber(2)
	//long flags = arg.GetNumber(3)
	//bool save = arg.GetNumber(4)
	//pThis->GetEntity()->SelectDocumentPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __SelectDocumentType, "SelectDocumentType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sort", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __SelectDocumentType)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocTemplate** templates = arg.GetNumber(0)
	//int noTemplates = arg.GetNumber(1)
	//bool sort = arg.GetNumber(2)
	//pThis->GetEntity()->SelectDocumentType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __SelectViewType, "SelectViewType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noTemplates", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sort", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __SelectViewType)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDocTemplate** templates = arg.GetNumber(0)
	//int noTemplates = arg.GetNumber(1)
	//bool sort = arg.GetNumber(2)
	//pThis->GetEntity()->SelectViewType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __SetLastDirectory, "SetLastDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __SetLastDirectory)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetLastDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __SetMaxDocsOpen, "SetMaxDocsOpen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __SetMaxDocsOpen)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxDocsOpen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __OnMRUFileNotExist, "OnMRUFileNotExist")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __OnMRUFileNotExist)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned n = arg.GetNumber(0)
	//const wxString& filename = arg.GetNumber(1)
	//pThis->GetEntity()->OnMRUFileNotExist();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocManager, __CreatePreviewFrame, "CreatePreviewFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "preview", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocManager, __CreatePreviewFrame)
{
	Object_wx_DocManager *pThis = Object_wx_DocManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintPreviewBase* preview = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//pThis->GetEntity()->CreatePreviewFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocManager)
{
	// Constructor assignment
	Gura_AssignFunction(__DocManager);
	// Method assignment
	Gura_AssignMethod(wx_DocManager, __ActivateView);
	Gura_AssignMethod(wx_DocManager, __AddDocument);
	Gura_AssignMethod(wx_DocManager, __AddFileToHistory);
	Gura_AssignMethod(wx_DocManager, __AssociateTemplate);
	Gura_AssignMethod(wx_DocManager, __FindTemplate);
	Gura_AssignMethod(wx_DocManager, __FindDocumentByPath);
	Gura_AssignMethod(wx_DocManager, __CloseDocument);
	Gura_AssignMethod(wx_DocManager, __CloseDocuments);
	Gura_AssignMethod(wx_DocManager, __CreateDocument);
	Gura_AssignMethod(wx_DocManager, __CreateNewDocument);
	Gura_AssignMethod(wx_DocManager, __CreateView);
	Gura_AssignMethod(wx_DocManager, __DisassociateTemplate);
	Gura_AssignMethod(wx_DocManager, __FileHistoryAddFilesToMenu);
	Gura_AssignMethod(wx_DocManager, __FileHistoryAddFilesToMenu_1);
	Gura_AssignMethod(wx_DocManager, __FileHistoryLoad);
	Gura_AssignMethod(wx_DocManager, __FileHistoryRemoveMenu);
	Gura_AssignMethod(wx_DocManager, __FileHistorySave);
	Gura_AssignMethod(wx_DocManager, __FileHistoryUseMenu);
	Gura_AssignMethod(wx_DocManager, __FindTemplateForPath);
	Gura_AssignMethod(wx_DocManager, __GetAnyUsableView);
	Gura_AssignMethod(wx_DocManager, __GetCurrentDocument);
	Gura_AssignMethod(wx_DocManager, __GetCurrentView);
	Gura_AssignMethod(wx_DocManager, __GetDocumentsVector);
	Gura_AssignMethod(wx_DocManager, __GetTemplatesVector);
	Gura_AssignMethod(wx_DocManager, __GetDocuments);
	Gura_AssignMethod(wx_DocManager, __GetFileHistory);
	Gura_AssignMethod(wx_DocManager, __GetHistoryFilesCount);
	Gura_AssignMethod(wx_DocManager, __GetLastDirectory);
	Gura_AssignMethod(wx_DocManager, __GetMaxDocsOpen);
	Gura_AssignMethod(wx_DocManager, __GetTemplates);
	Gura_AssignMethod(wx_DocManager, __Initialize);
	Gura_AssignMethod(wx_DocManager, __MakeNewDocumentName);
	Gura_AssignMethod(wx_DocManager, __OnCreateFileHistory);
	Gura_AssignMethod(wx_DocManager, __OnFileClose);
	Gura_AssignMethod(wx_DocManager, __OnFileCloseAll);
	Gura_AssignMethod(wx_DocManager, __OnFileNew);
	Gura_AssignMethod(wx_DocManager, __OnFileOpen);
	Gura_AssignMethod(wx_DocManager, __OnFileRevert);
	Gura_AssignMethod(wx_DocManager, __OnFileSave);
	Gura_AssignMethod(wx_DocManager, __OnFileSaveAs);
	Gura_AssignMethod(wx_DocManager, __RemoveDocument);
	Gura_AssignMethod(wx_DocManager, __SelectDocumentPath);
	Gura_AssignMethod(wx_DocManager, __SelectDocumentType);
	Gura_AssignMethod(wx_DocManager, __SelectViewType);
	Gura_AssignMethod(wx_DocManager, __SetLastDirectory);
	Gura_AssignMethod(wx_DocManager, __SetMaxDocsOpen);
	Gura_AssignMethod(wx_DocManager, __OnMRUFileNotExist);
	Gura_AssignMethod(wx_DocManager, __CreatePreviewFrame);
}

Gura_ImplementDescendantCreator(wx_DocManager)
{
	return new Object_wx_DocManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
