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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Document, wxDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, wxDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, ~wxDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, ~wxDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, AddView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "view", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, AddView)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int view = arg.GetNumber(0)
	//pThis->GetEntity()->AddView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, AlreadySaved)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, AlreadySaved)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AlreadySaved();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, Activate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, DeleteAllViews)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, DeleteAllViews)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllViews();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, DeleteContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, DeleteContents)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DeleteContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetCommandProcessor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetDocumentManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetDocumentName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetDocumentSaved)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetDocumentSaved)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentSaved();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetDocumentTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetDocumentTemplate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentTemplate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetDocumentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetDocumentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetFirstView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetFirstView)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFirstView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetUserReadableName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetUserReadableName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUserReadableName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetViewsVector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetViewsVector)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetViewsVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetViews)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetViews)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetViews();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, GetViews_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, GetViews_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetViews();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, IsChildDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, IsChildDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsChildDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, IsModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, LoadObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, LoadObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, LoadObject_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, LoadObject_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->LoadObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, Modify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modify", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, Modify)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int modify = arg.GetNumber(0)
	//pThis->GetEntity()->Modify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnChangedViewList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, OnChangedViewList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnChangedViewList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnCloseDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, OnCloseDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnCloseDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnCreate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, OnCreate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->OnCreate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnCreateCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, OnCreateCommandProcessor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnCreateCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnNewDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, OnNewDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnNewDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnOpenDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, OnOpenDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->OnOpenDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnSaveDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, OnSaveDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->OnSaveDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnSaveModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, OnSaveModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnSaveModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, RemoveView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "view", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, RemoveView)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int view = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, Save)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Save();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SaveAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, SaveAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SaveAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, Revert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, Revert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Revert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SaveObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SaveObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->SaveObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SaveObject_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SaveObject_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->SaveObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SetCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "processor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetCommandProcessor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int processor = arg.GetNumber(0)
	//pThis->GetEntity()->SetCommandProcessor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SetDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetDocumentName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SetDocumentTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "templ", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetDocumentTemplate)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int templ = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentTemplate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SetDocumentSaved)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "saved", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetDocumentSaved)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int saved = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentSaved();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "notifyViews", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int notifyViews = arg.GetNumber(1)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, OnChangeFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifyViews", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, OnChangeFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int notifyViews = arg.GetNumber(0)
	//pThis->GetEntity()->OnChangeFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, UpdateAllViews)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sender", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hint", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, UpdateAllViews)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sender = arg.GetNumber(0)
	//int hint = arg.GetNumber(1)
	//pThis->GetEntity()->UpdateAllViews();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, DoSaveDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, DoSaveDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->DoSaveDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Document, DoOpenDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, DoOpenDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_Document *pThis = Object_wx_Document::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->DoOpenDocument();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocument
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Document)
{
	Gura_AssignMethod(wx_Document, wxDocument);
	Gura_AssignMethod(wx_Document, ~wxDocument);
	Gura_AssignMethod(wx_Document, AddView);
	Gura_AssignMethod(wx_Document, AlreadySaved);
	Gura_AssignMethod(wx_Document, Activate);
	Gura_AssignMethod(wx_Document, Close);
	Gura_AssignMethod(wx_Document, DeleteAllViews);
	Gura_AssignMethod(wx_Document, DeleteContents);
	Gura_AssignMethod(wx_Document, GetCommandProcessor);
	Gura_AssignMethod(wx_Document, GetDocumentManager);
	Gura_AssignMethod(wx_Document, GetDocumentName);
	Gura_AssignMethod(wx_Document, GetDocumentSaved);
	Gura_AssignMethod(wx_Document, GetDocumentTemplate);
	Gura_AssignMethod(wx_Document, GetDocumentWindow);
	Gura_AssignMethod(wx_Document, GetFilename);
	Gura_AssignMethod(wx_Document, GetFirstView);
	Gura_AssignMethod(wx_Document, GetTitle);
	Gura_AssignMethod(wx_Document, GetUserReadableName);
	Gura_AssignMethod(wx_Document, GetViewsVector);
	Gura_AssignMethod(wx_Document, GetViews);
	Gura_AssignMethod(wx_Document, GetViews_1);
	Gura_AssignMethod(wx_Document, IsChildDocument);
	Gura_AssignMethod(wx_Document, IsModified);
	Gura_AssignMethod(wx_Document, LoadObject);
	Gura_AssignMethod(wx_Document, LoadObject_1);
	Gura_AssignMethod(wx_Document, Modify);
	Gura_AssignMethod(wx_Document, OnChangedViewList);
	Gura_AssignMethod(wx_Document, OnCloseDocument);
	Gura_AssignMethod(wx_Document, OnCreate);
	Gura_AssignMethod(wx_Document, OnCreateCommandProcessor);
	Gura_AssignMethod(wx_Document, OnNewDocument);
	Gura_AssignMethod(wx_Document, OnOpenDocument);
	Gura_AssignMethod(wx_Document, OnSaveDocument);
	Gura_AssignMethod(wx_Document, OnSaveModified);
	Gura_AssignMethod(wx_Document, RemoveView);
	Gura_AssignMethod(wx_Document, Save);
	Gura_AssignMethod(wx_Document, SaveAs);
	Gura_AssignMethod(wx_Document, Revert);
	Gura_AssignMethod(wx_Document, SaveObject);
	Gura_AssignMethod(wx_Document, SaveObject_1);
	Gura_AssignMethod(wx_Document, SetCommandProcessor);
	Gura_AssignMethod(wx_Document, SetDocumentName);
	Gura_AssignMethod(wx_Document, SetDocumentTemplate);
	Gura_AssignMethod(wx_Document, SetDocumentSaved);
	Gura_AssignMethod(wx_Document, SetFilename);
	Gura_AssignMethod(wx_Document, OnChangeFilename);
	Gura_AssignMethod(wx_Document, SetTitle);
	Gura_AssignMethod(wx_Document, UpdateAllViews);
	Gura_AssignMethod(wx_Document, DoSaveDocument);
	Gura_AssignMethod(wx_Document, DoOpenDocument);
}

Gura_ImplementDescendantCreator(wx_Document)
{
	return new Object_wx_Document((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
