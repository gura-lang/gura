//----------------------------------------------------------------------------
// wxNotebook
// extracted from notebook.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Notebook: public wxNotebook, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Notebook *_pObj;
public:
	inline wx_Notebook() : wxNotebook(), _sig(NULL), _pObj(NULL) {}
	inline wx_Notebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxNotebook(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_Notebook();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Notebook *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Notebook::~wx_Notebook()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Notebook::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNotebook
//----------------------------------------------------------------------------
Gura_DeclareFunction(NotebookEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Notebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NotebookEmpty)
{
	wx_Notebook *pEntity = new wx_Notebook();
	Object_wx_Notebook *pObj = Object_wx_Notebook::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Notebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Notebook)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Notebook));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Notebook)
{
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxNotebookNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_Notebook *pEntity = new wx_Notebook(parent, id, *pos, *size, style, name);
	Object_wx_Notebook *pObj = Object_wx_Notebook::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Notebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Notebook, AddPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, AddPage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *page = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool select = false;
	if (args.IsValid(2)) select = args.GetBoolean(2);
	int imageId = -1;
	if (args.IsValid(3)) imageId = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AddPage(page, text, select, imageId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, AdvanceSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "forward", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, AdvanceSelection)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool forward = true;
	if (args.IsValid(0)) forward = args.GetBoolean(0);
	pSelf->GetEntity()->AdvanceSelection(forward);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, AssignImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, AssignImageList)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->AssignImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, ChangeSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, ChangeSelection)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int rtn = pSelf->GetEntity()->ChangeSelection(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, Create)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxNotebookNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pSelf->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, DeleteAllPages)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, DeleteAllPages)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->DeleteAllPages();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, DeletePage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, DeletePage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pSelf->GetEntity()->DeletePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetCurrentPage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetCurrentPage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pSelf->GetEntity()->GetCurrentPage();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Notebook, GetImageList)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetImageList)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImageList *rtn = (wxImageList *)pSelf->GetEntity()->GetImageList();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_ImageList(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Notebook, GetPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxWindow *rtn = (wxWindow *)pSelf->GetEntity()->GetPage(page);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Notebook, GetPageCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageCount)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t rtn = pSelf->GetEntity()->GetPageCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetPageImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageImage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t nPage = args.GetSizeT(0);
	int rtn = pSelf->GetEntity()->GetPageImage(nPage);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetPageText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageText)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t nPage = args.GetSizeT(0);
	wxString rtn = pSelf->GetEntity()->GetPageText(nPage);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Notebook, GetRowCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetRowCount)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetRowCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetSelection)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetThemeBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetThemeBackgroundColour)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pSelf->GetEntity()->GetThemeBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Notebook, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, HitTest)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	long flags = 0;
	int rtn = pSelf->GetEntity()->HitTest(*pt, &flags);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, flags));
}

Gura_DeclareMethod(wx_Notebook, InsertPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, InsertPage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t index = args.GetSizeT(0);
	wxWindow *page = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(2));
	bool select = false;
	if (args.IsValid(3)) select = args.GetBoolean(3);
	int imageId = -1;
	if (args.IsValid(4)) imageId = args.GetInt(4);
	bool rtn = pSelf->GetEntity()->InsertPage(index, page, text, select, imageId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, OnSelChange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_NotebookEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, OnSelChange)
{
#if defined(__WXMSW__)
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxNotebookEvent *event = Object_wx_NotebookEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnSelChange(*event);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_Notebook, RemovePage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, RemovePage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pSelf->GetEntity()->RemovePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_Notebook, SetImageList)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = NULL;
	if (args.IsValid(0)) imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, SetPadding)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "padding", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPadding)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *padding = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPadding(*padding);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, SetPageSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPageSize)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPageSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, SetPageImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, SetPageImage)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int image = args.GetInt(1);
	bool rtn = pSelf->GetEntity()->SetPageImage(page, image);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetPageText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, SetPageText)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->SetPageText(page, text);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, SetSelection)
{
	Object_wx_Notebook *pSelf = Object_wx_Notebook::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int rtn = pSelf->GetEntity()->SetSelection(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxNotebook
//----------------------------------------------------------------------------
Object_wx_Notebook::~Object_wx_Notebook()
{
}

Object *Object_wx_Notebook::Clone() const
{
	return NULL;
}

String Object_wx_Notebook::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Notebook:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Notebook::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignWxStringValue(NotebookNameStr);
	Gura_AssignFunction(NotebookEmpty);
	Gura_AssignFunction(Notebook);
	Gura_AssignFunctionEx(Notebook, "BookCtrl");
}

//----------------------------------------------------------------------------
// Class implementation for wxNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Notebook)
{
	Gura_AssignMethod(wx_Notebook, AddPage);
	Gura_AssignMethod(wx_Notebook, AdvanceSelection);
	Gura_AssignMethod(wx_Notebook, AssignImageList);
	Gura_AssignMethod(wx_Notebook, ChangeSelection);
	Gura_AssignMethod(wx_Notebook, Create);
	Gura_AssignMethod(wx_Notebook, DeleteAllPages);
	Gura_AssignMethod(wx_Notebook, DeletePage);
	Gura_AssignMethod(wx_Notebook, GetCurrentPage);
	Gura_AssignMethod(wx_Notebook, GetImageList);
	Gura_AssignMethod(wx_Notebook, GetPage);
	Gura_AssignMethod(wx_Notebook, GetPageCount);
	Gura_AssignMethod(wx_Notebook, GetPageImage);
	Gura_AssignMethod(wx_Notebook, GetPageText);
	Gura_AssignMethod(wx_Notebook, GetRowCount);
	Gura_AssignMethod(wx_Notebook, GetSelection);
	Gura_AssignMethod(wx_Notebook, GetThemeBackgroundColour);
	Gura_AssignMethod(wx_Notebook, HitTest);
	Gura_AssignMethod(wx_Notebook, InsertPage);
	Gura_AssignMethod(wx_Notebook, OnSelChange);
	Gura_AssignMethod(wx_Notebook, RemovePage);
	Gura_AssignMethod(wx_Notebook, SetImageList);
	Gura_AssignMethod(wx_Notebook, SetPadding);
	Gura_AssignMethod(wx_Notebook, SetPageSize);
	Gura_AssignMethod(wx_Notebook, SetPageImage);
	Gura_AssignMethod(wx_Notebook, SetPageText);
	Gura_AssignMethod(wx_Notebook, SetSelection);
}

Gura_ImplementDescendantCreator(wx_Notebook)
{
	return new Object_wx_Notebook((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
