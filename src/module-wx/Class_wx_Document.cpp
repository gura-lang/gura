//----------------------------------------------------------------------------
// wxDocument
// extracted from document.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AddView);
Gura_DeclarePrivUserSymbol(Close);
Gura_DeclarePrivUserSymbol(DeleteAllViews);
Gura_DeclarePrivUserSymbol(GetPrintableName);
Gura_DeclarePrivUserSymbol(IsModified);
Gura_DeclarePrivUserSymbol(LoadObject);
Gura_DeclarePrivUserSymbol(LoadObject_1);
Gura_DeclarePrivUserSymbol(Modify);
Gura_DeclarePrivUserSymbol(OnChangedViewList);
Gura_DeclarePrivUserSymbol(OnCloseDocument);
Gura_DeclarePrivUserSymbol(OnCreate);
Gura_DeclarePrivUserSymbol(OnCreateCommandProcessor);
Gura_DeclarePrivUserSymbol(OnNewDocument);
Gura_DeclarePrivUserSymbol(OnOpenDocument);
Gura_DeclarePrivUserSymbol(OnSaveDocument);
Gura_DeclarePrivUserSymbol(OnSaveModified);
Gura_DeclarePrivUserSymbol(RemoveView);
Gura_DeclarePrivUserSymbol(Save);
Gura_DeclarePrivUserSymbol(SaveAs);
Gura_DeclarePrivUserSymbol(SaveObject);
Gura_DeclarePrivUserSymbol(SaveObject_1);
Gura_DeclarePrivUserSymbol(SetCommandProcessor);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Document: public wxDocument, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_Document *_pObj;
public:
	inline wx_Document() : wxDocument(), _pSig(nullptr), _pObj(nullptr) {}
	//virtual bool AddView(wxView * view);
	//virtual bool Close();
	//virtual bool DeleteAllViews();
	//virtual void GetPrintableName(wxString& name);
	//virtual bool IsModified();
	//virtual istream& LoadObject(istream& stream);
	//virtual wxInputStream& LoadObject(wxInputStream& stream);
	//virtual void Modify(bool modify);
	//virtual void OnChangedViewList();
	//virtual bool OnCloseDocument();
	//virtual bool OnCreate(const wxString& path, long flags);
	//virtual wxCommandProcessor* OnCreateCommandProcessor();
	//virtual bool OnNewDocument();
	//virtual bool OnOpenDocument(const wxString& filename);
	//virtual bool OnSaveDocument(const wxString& filename);
	//virtual bool OnSaveModified();
	//virtual bool RemoveView(wxView* view);
	//virtual bool Save();
	//virtual bool SaveAs();
	//virtual ostream& SaveObject(ostream& stream);
	//virtual wxOutputStream& SaveObject(wxOutputStream& stream);
	//virtual void SetCommandProcessor(wxCommandProcessor * processor);
	~wx_Document();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Document *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Document::~wx_Document()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Document::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocument
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocumentEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Document));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DocumentEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Document *pEntity = new wx_Document();
	Object_wx_Document *pObj = Object_wx_Document::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Document(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Document, AddView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "view", VTYPE_wx_View, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, AddView)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *view = Object_wx_View::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AddView(view);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, Close)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, DeleteAllViews)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, DeleteAllViews)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DeleteAllViews();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, GetCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetCommandProcessor)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandProcessor *rtn = (wxCommandProcessor *)pThis->GetEntity()->GetCommandProcessor();
	return ReturnValue(env, args, Value(new Object_wx_CommandProcessor(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Document, GetDocumentTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetDocumentTemplate)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocTemplate *rtn = (wxDocTemplate *)pThis->GetEntity()->GetDocumentTemplate();
	return ReturnValue(env, args, Value(new Object_wx_DocTemplate(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Document, GetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetDocumentManager)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocManager *rtn = (wxDocManager *)pThis->GetEntity()->GetDocumentManager();
	return ReturnValue(env, args, Value(new Object_wx_DocManager(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Document, GetDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetDocumentName)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetDocumentName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Document, GetDocumentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetDocumentWindow)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetDocumentWindow();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Document, GetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetFilename)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetFilename();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Document, GetFirstView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetFirstView)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *rtn = (wxView *)pThis->GetEntity()->GetFirstView();
	return ReturnValue(env, args, Value(new Object_wx_View(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Document, GetPrintableName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, GetPrintableName)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->GetPrintableName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetTitle)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetTitle();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Document, GetViews)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, GetViews)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxList &rtn = pThis->GetEntity()->GetViews();
	return ReturnValue(env, args, Value(new Object_wx_List(new wxList(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Document, IsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, IsModified)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsModified();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, LoadObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, LoadObject)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Document, LoadObject_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, LoadObject_1)
{
#if 0
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxInputStream &rtn = pThis->GetEntity()->LoadObject(*stream);
	return ReturnValue(env, args, Value(new Object_wx_InputStream(new wxInputStream(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, Modify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "modify", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, Modify)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool modify = args.GetBoolean(0);
	pThis->GetEntity()->Modify(modify);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, OnChangedViewList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Document, OnChangedViewList)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->OnChangedViewList();
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, OnCloseDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, OnCloseDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->OnCloseDocument();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, OnCreate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, OnCreate)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	long flags = args.GetLong(1);
	bool rtn = pThis->GetEntity()->OnCreate(path, flags);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, OnCreateCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, OnCreateCommandProcessor)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandProcessor *rtn = (wxCommandProcessor *)pThis->GetEntity()->OnCreateCommandProcessor();
	return ReturnValue(env, args, Value(new Object_wx_CommandProcessor(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Document, OnNewDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, OnNewDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->OnNewDocument();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, OnOpenDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, OnOpenDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->OnOpenDocument(filename);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, OnSaveDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, OnSaveDocument)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->OnSaveDocument(filename);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, OnSaveModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, OnSaveModified)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->OnSaveModified();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, RemoveView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "view", VTYPE_wx_View, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, RemoveView)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *view = Object_wx_View::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->RemoveView(view);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, Save)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, Save)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Save();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, SaveAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, SaveAs)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->SaveAs();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Document, SaveObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, SaveObject)
{
#if 0
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	Stream & stream = args.GetStream(0);
	Stream & rtn = pThis->GetEntity()->SaveObject(stream);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, SaveObject_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, SaveObject_1)
{
#if 0
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxOutputStream &rtn = pThis->GetEntity()->SaveObject(*stream);
	return ReturnValue(env, args, Value(new Object_wx_OutputStream(new wxOutputStream(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, SetCommandProcessor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "processor", VTYPE_wx_CommandProcessor, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetCommandProcessor)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCommandProcessor *processor = Object_wx_CommandProcessor::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCommandProcessor(processor);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, SetDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetDocumentName)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDocumentName(name);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, SetDocumentTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "templ", VTYPE_wx_DocTemplate, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetDocumentTemplate)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocTemplate *templ = Object_wx_DocTemplate::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDocumentTemplate(templ);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, SetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "notifyViews", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, SetFilename)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	bool notifyViews = false;
	if (args.IsValid(1)) notifyViews = args.GetBoolean(1);
	pThis->GetEntity()->SetFilename(filename, notifyViews);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Document, SetTitle)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString title = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetTitle(title);
	return Value::Null;
}

Gura_DeclareMethod(wx_Document, UpdateAllViews)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "sender", VTYPE_wx_View, OCCUR_ZeroOrOnce);
	DeclareArg(env, "hint", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Document, UpdateAllViews)
{
	Object_wx_Document *pThis = Object_wx_Document::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *sender = (wxView *)(nullptr);
	if (args.IsValid(0)) sender = Object_wx_View::GetObject(args, 0)->GetEntity();
	wxObject *hint = (wxObject *)(nullptr);
	if (args.IsValid(1)) hint = Object_wx_Object::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->UpdateAllViews(sender, hint);
	return Value::Null;
}

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
// Class implementation for wxDocument
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Document)
{
	Gura_RealizeUserSymbol(AddView);
	Gura_RealizeUserSymbol(Close);
	Gura_RealizeUserSymbol(DeleteAllViews);
	Gura_RealizeUserSymbol(GetPrintableName);
	Gura_RealizeUserSymbol(IsModified);
	Gura_RealizeUserSymbol(LoadObject);
	Gura_RealizeUserSymbol(LoadObject_1);
	Gura_RealizeUserSymbol(Modify);
	Gura_RealizeUserSymbol(OnChangedViewList);
	Gura_RealizeUserSymbol(OnCloseDocument);
	Gura_RealizeUserSymbol(OnCreate);
	Gura_RealizeUserSymbol(OnCreateCommandProcessor);
	Gura_RealizeUserSymbol(OnNewDocument);
	Gura_RealizeUserSymbol(OnOpenDocument);
	Gura_RealizeUserSymbol(OnSaveDocument);
	Gura_RealizeUserSymbol(OnSaveModified);
	Gura_RealizeUserSymbol(RemoveView);
	Gura_RealizeUserSymbol(Save);
	Gura_RealizeUserSymbol(SaveAs);
	Gura_RealizeUserSymbol(SaveObject);
	Gura_RealizeUserSymbol(SaveObject_1);
	Gura_RealizeUserSymbol(SetCommandProcessor);
	Gura_AssignFunction(DocumentEmpty);
	Gura_AssignMethod(wx_Document, AddView);
	Gura_AssignMethod(wx_Document, Close);
	Gura_AssignMethod(wx_Document, DeleteAllViews);
	Gura_AssignMethod(wx_Document, GetCommandProcessor);
	Gura_AssignMethod(wx_Document, GetDocumentTemplate);
	Gura_AssignMethod(wx_Document, GetDocumentManager);
	Gura_AssignMethod(wx_Document, GetDocumentName);
	Gura_AssignMethod(wx_Document, GetDocumentWindow);
	Gura_AssignMethod(wx_Document, GetFilename);
	Gura_AssignMethod(wx_Document, GetFirstView);
	Gura_AssignMethod(wx_Document, GetPrintableName);
	Gura_AssignMethod(wx_Document, GetTitle);
	Gura_AssignMethod(wx_Document, GetViews);
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
	Gura_AssignMethod(wx_Document, SaveObject);
	Gura_AssignMethod(wx_Document, SaveObject_1);
	Gura_AssignMethod(wx_Document, SetCommandProcessor);
	Gura_AssignMethod(wx_Document, SetDocumentName);
	Gura_AssignMethod(wx_Document, SetDocumentTemplate);
	Gura_AssignMethod(wx_Document, SetFilename);
	Gura_AssignMethod(wx_Document, SetTitle);
	Gura_AssignMethod(wx_Document, UpdateAllViews);
}

Gura_ImplementDescendantCreator(wx_Document)
{
	return new Object_wx_Document((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
