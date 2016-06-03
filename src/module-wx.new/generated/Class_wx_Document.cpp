//----------------------------------------------------------------------------
// wxDocument
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocument
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocument
//----------------------------------------------------------------------------
Object_wx_Document::~Object_wx_Document()
{
}

Object *Object_wx_Document::Clone() const
{
	return nullptr;
}

String Object_wx_Document::ToString(bool exprFlag)
{
	String rtn("<wx.Document:");
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
Gura_DeclareFunctionAlias(__wxDocument, "wxDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxDocument)
{
	//int parent = arg.GetNumber(0)
	//wxDocument();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Document, __AddView, "AddView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "view", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __AddView)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int view = arg.GetNumber(0)
	//pThis->GetEntity()->AddView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __AlreadySaved, "AlreadySaved")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __AlreadySaved)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AlreadySaved();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __Activate, "Activate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __Activate)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __Close)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __DeleteAllViews, "DeleteAllViews")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __DeleteAllViews)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllViews();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __DeleteContents, "DeleteContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __DeleteContents)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteContents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetCommandProcessor, "GetCommandProcessor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetCommandProcessor)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetDocumentManager, "GetDocumentManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetDocumentManager)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetDocumentName, "GetDocumentName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetDocumentName)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetDocumentSaved, "GetDocumentSaved")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetDocumentSaved)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentSaved();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetDocumentTemplate, "GetDocumentTemplate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetDocumentTemplate)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentTemplate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetDocumentWindow, "GetDocumentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetDocumentWindow)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetFilename, "GetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetFilename)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetFirstView, "GetFirstView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetFirstView)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetTitle)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetUserReadableName, "GetUserReadableName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetUserReadableName)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserReadableName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetViewsVector, "GetViewsVector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetViewsVector)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewsVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetViews, "GetViews")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetViews)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViews();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __GetViews_1, "GetViews_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __GetViews_1)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViews();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __IsChildDocument, "IsChildDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __IsChildDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsChildDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __IsModified, "IsModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __IsModified)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __LoadObject, "LoadObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __LoadObject)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __LoadObject_1, "LoadObject_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __LoadObject_1)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __Modify, "Modify")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modify", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __Modify)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modify = arg.GetNumber(0)
	//pThis->GetEntity()->Modify();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnChangedViewList, "OnChangedViewList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __OnChangedViewList)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnChangedViewList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnCloseDocument, "OnCloseDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __OnCloseDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnCloseDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnCreate, "OnCreate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __OnCreate)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->OnCreate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnCreateCommandProcessor, "OnCreateCommandProcessor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __OnCreateCommandProcessor)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnCreateCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnNewDocument, "OnNewDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __OnNewDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnNewDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnOpenDocument, "OnOpenDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __OnOpenDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->OnOpenDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnSaveDocument, "OnSaveDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __OnSaveDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->OnSaveDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnSaveModified, "OnSaveModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __OnSaveModified)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnSaveModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __RemoveView, "RemoveView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "view", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __RemoveView)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int view = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __Save, "Save")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __Save)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SaveAs, "SaveAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __SaveAs)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SaveAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __Revert, "Revert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, __Revert)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Revert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SaveObject, "SaveObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SaveObject)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->SaveObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SaveObject_1, "SaveObject_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SaveObject_1)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->SaveObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SetCommandProcessor, "SetCommandProcessor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "processor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SetCommandProcessor)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int processor = arg.GetNumber(0)
	//pThis->GetEntity()->SetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SetDocumentName, "SetDocumentName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SetDocumentName)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SetDocumentTemplate, "SetDocumentTemplate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templ", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SetDocumentTemplate)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int templ = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentTemplate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SetDocumentSaved, "SetDocumentSaved")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "saved", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SetDocumentSaved)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int saved = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentSaved();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SetFilename, "SetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "notifyViews", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SetFilename)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int notifyViews = arg.GetNumber(1)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __OnChangeFilename, "OnChangeFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifyViews", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __OnChangeFilename)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int notifyViews = arg.GetNumber(0)
	//pThis->GetEntity()->OnChangeFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __SetTitle)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __UpdateAllViews, "UpdateAllViews")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sender", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __UpdateAllViews)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sender = arg.GetNumber(0)
	//int hint = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateAllViews();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __DoSaveDocument, "DoSaveDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __DoSaveDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->DoSaveDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Document, __DoOpenDocument, "DoOpenDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, __DoOpenDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->DoOpenDocument();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocument
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Document)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDocument);
	// Method assignment
	Gura_AssignMethod(wx_Document, __AddView);
	Gura_AssignMethod(wx_Document, __AlreadySaved);
	Gura_AssignMethod(wx_Document, __Activate);
	Gura_AssignMethod(wx_Document, __Close);
	Gura_AssignMethod(wx_Document, __DeleteAllViews);
	Gura_AssignMethod(wx_Document, __DeleteContents);
	Gura_AssignMethod(wx_Document, __GetCommandProcessor);
	Gura_AssignMethod(wx_Document, __GetDocumentManager);
	Gura_AssignMethod(wx_Document, __GetDocumentName);
	Gura_AssignMethod(wx_Document, __GetDocumentSaved);
	Gura_AssignMethod(wx_Document, __GetDocumentTemplate);
	Gura_AssignMethod(wx_Document, __GetDocumentWindow);
	Gura_AssignMethod(wx_Document, __GetFilename);
	Gura_AssignMethod(wx_Document, __GetFirstView);
	Gura_AssignMethod(wx_Document, __GetTitle);
	Gura_AssignMethod(wx_Document, __GetUserReadableName);
	Gura_AssignMethod(wx_Document, __GetViewsVector);
	Gura_AssignMethod(wx_Document, __GetViews);
	Gura_AssignMethod(wx_Document, __GetViews_1);
	Gura_AssignMethod(wx_Document, __IsChildDocument);
	Gura_AssignMethod(wx_Document, __IsModified);
	Gura_AssignMethod(wx_Document, __LoadObject);
	Gura_AssignMethod(wx_Document, __LoadObject_1);
	Gura_AssignMethod(wx_Document, __Modify);
	Gura_AssignMethod(wx_Document, __OnChangedViewList);
	Gura_AssignMethod(wx_Document, __OnCloseDocument);
	Gura_AssignMethod(wx_Document, __OnCreate);
	Gura_AssignMethod(wx_Document, __OnCreateCommandProcessor);
	Gura_AssignMethod(wx_Document, __OnNewDocument);
	Gura_AssignMethod(wx_Document, __OnOpenDocument);
	Gura_AssignMethod(wx_Document, __OnSaveDocument);
	Gura_AssignMethod(wx_Document, __OnSaveModified);
	Gura_AssignMethod(wx_Document, __RemoveView);
	Gura_AssignMethod(wx_Document, __Save);
	Gura_AssignMethod(wx_Document, __SaveAs);
	Gura_AssignMethod(wx_Document, __Revert);
	Gura_AssignMethod(wx_Document, __SaveObject);
	Gura_AssignMethod(wx_Document, __SaveObject_1);
	Gura_AssignMethod(wx_Document, __SetCommandProcessor);
	Gura_AssignMethod(wx_Document, __SetDocumentName);
	Gura_AssignMethod(wx_Document, __SetDocumentTemplate);
	Gura_AssignMethod(wx_Document, __SetDocumentSaved);
	Gura_AssignMethod(wx_Document, __SetFilename);
	Gura_AssignMethod(wx_Document, __OnChangeFilename);
	Gura_AssignMethod(wx_Document, __SetTitle);
	Gura_AssignMethod(wx_Document, __UpdateAllViews);
	Gura_AssignMethod(wx_Document, __DoSaveDocument);
	Gura_AssignMethod(wx_Document, __DoOpenDocument);
}

Gura_ImplementDescendantCreator(wx_Document)
{
	return new Object_wx_Document((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
