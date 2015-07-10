//----------------------------------------------------------------------------
// wxNotebook
// extracted from notebook.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Notebook: public wxNotebook, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_Notebook *_pObj;
public:
	inline wx_Notebook() : wxNotebook(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Notebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxNotebook(parent, id, pos, size, style, name), _pSig(nullptr), _pObj(nullptr) {}
	~wx_Notebook();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Notebook *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Notebook::~wx_Notebook()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Notebook::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNotebook
//----------------------------------------------------------------------------
Gura_DeclareFunction(NotebookEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Notebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NotebookEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Notebook *pEntity = new wx_Notebook();
	Object_wx_Notebook *pObj = Object_wx_Notebook::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Notebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Notebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
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
	Object_wx_Notebook *pObj = Object_wx_Notebook::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Notebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Notebook, AddPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, AddPage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *page = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool select = false;
	if (args.IsValid(2)) select = args.GetBoolean(2);
	int imageId = -1;
	if (args.IsValid(3)) imageId = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AddPage(page, text, select, imageId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, AdvanceSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "forward", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, AdvanceSelection)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool forward = true;
	if (args.IsValid(0)) forward = args.GetBoolean(0);
	pThis->GetEntity()->AdvanceSelection(forward);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, AssignImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, AssignImageList)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AssignImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, ChangeSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, ChangeSelection)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->ChangeSelection(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
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
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, DeleteAllPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, DeleteAllPages)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DeleteAllPages();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, DeletePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, DeletePage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->DeletePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetCurrentPage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetCurrentPage();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Notebook, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetImageList)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetImageList();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_ImageList(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Notebook, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPage(page);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Notebook, GetPageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageCount)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetPageCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageImage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nPage = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->GetPageImage(nPage);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageText)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nPage = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetPageText(nPage);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Notebook, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetRowCount)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRowCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetSelection)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetThemeBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetThemeBackgroundColour)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetThemeBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Notebook, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, HitTest)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	long flags = 0;
	int rtn = pThis->GetEntity()->HitTest(*pt, &flags);
	return ReturnValue(env, sig, args, Value::CreateList(env, rtn, flags));
}

Gura_DeclareMethod(wx_Notebook, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, InsertPage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t index = args.GetSizeT(0);
	wxWindow *page = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(2));
	bool select = false;
	if (args.IsValid(3)) select = args.GetBoolean(3);
	int imageId = -1;
	if (args.IsValid(4)) imageId = args.GetInt(4);
	bool rtn = pThis->GetEntity()->InsertPage(index, page, text, select, imageId);
	return ReturnValue(env, sig, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_Notebook, OnSelChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_NotebookEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, OnSelChange)
{
#if defined(__WXMSW__)
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxNotebookEvent *event = Object_wx_NotebookEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnSelChange(*event);
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}
#endif

Gura_DeclareMethod(wx_Notebook, RemovePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, RemovePage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->RemovePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_Notebook, SetImageList)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = nullptr;
	if (args.IsValid(0)) imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, SetPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "padding", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPadding)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *padding = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPadding(*padding);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, SetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPageSize)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPageSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Notebook, SetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, SetPageImage)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int image = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetPageImage(page, image);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, SetPageText)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetPageText(page, text);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, SetSelection)
{
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->SetSelection(page);
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
	return nullptr;
}

String Object_wx_Notebook::ToString(bool exprFlag)
{
	String rtn("<wx.Notebook:");
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
// Class implementation for wxNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Notebook)
{
	Gura_AssignWxStringValue(NotebookNameStr);
	Gura_AssignFunction(NotebookEmpty);
	Gura_AssignFunction(Notebook);
	Gura_AssignFunctionEx(Notebook, "BookCtrl");
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
	//Gura_AssignMethod(wx_Notebook, OnSelChange);
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
	return new Object_wx_Notebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
