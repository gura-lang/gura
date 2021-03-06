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
	//Gura::Signal *_pSig;
	Object_wx_Notebook *_pObj;
public:
	inline wx_Notebook() : wxNotebook(), _pObj(nullptr) {}
	inline wx_Notebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxNotebook(parent, id, pos, size, style, name), _pObj(nullptr) {}
	~wx_Notebook();
	inline void AssocWithGura(Object_wx_Notebook *pObj) {
		_pObj = pObj;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Notebook *pEntity = new wx_Notebook();
	Object_wx_Notebook *pObj = Object_wx_Notebook::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Notebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = 0;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxNotebookNameStr;
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	wx_Notebook *pEntity = new wx_Notebook(parent, id, *pos, *size, style, name);
	Object_wx_Notebook *pObj = Object_wx_Notebook::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Notebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
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
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *page = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxString text = wxString::FromUTF8(arg.GetString(1));
	bool select = false;
	if (arg.IsValid(2)) select = arg.GetBoolean(2);
	int imageId = -1;
	if (arg.IsValid(3)) imageId = arg.GetInt(3);
	bool rtn = pThis->GetEntity()->AddPage(page, text, select, imageId);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, AdvanceSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "forward", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, AdvanceSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool forward = true;
	if (arg.IsValid(0)) forward = arg.GetBoolean(0);
	pThis->GetEntity()->AdvanceSelection(forward);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, AssignImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, AssignImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *imageList = Object_wx_ImageList::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->AssignImageList(imageList);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, ChangeSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, ChangeSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	int rtn = pThis->GetEntity()->ChangeSelection(page);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = 0;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxNotebookNameStr;
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, DeleteAllPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, DeleteAllPages)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DeleteAllPages();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, DeletePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, DeletePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	bool rtn = pThis->GetEntity()->DeletePage(page);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetCurrentPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetCurrentPage();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Notebook, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetImageList();
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_ImageList(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Notebook, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPage(page);
	Value value;
	if (rtn != nullptr) value = Value(new Object_wx_Window(rtn, nullptr, OwnerFalse));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_Notebook, GetPageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t rtn = pThis->GetEntity()->GetPageCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t nPage = arg.GetSizeT(0);
	int rtn = pThis->GetEntity()->GetPageImage(nPage);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetPageText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t nPage = arg.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetPageText(nPage);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Notebook, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetRowCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRowCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, GetThemeBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, GetThemeBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetThemeBackgroundColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Notebook, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	long flags = 0;
	int rtn = pThis->GetEntity()->HitTest(*pt, &flags);
	return ReturnValue(env, arg, Value::CreateList(env, rtn, flags));
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
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t index = arg.GetSizeT(0);
	wxWindow *page = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString text = wxString::FromUTF8(arg.GetString(2));
	bool select = false;
	if (arg.IsValid(3)) select = arg.GetBoolean(3);
	int imageId = -1;
	if (arg.IsValid(4)) imageId = arg.GetInt(4);
	bool rtn = pThis->GetEntity()->InsertPage(index, page, text, select, imageId);
	return ReturnValue(env, arg, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_Notebook, OnSelChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_NotebookEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, OnSelChange)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxNotebookEvent *event = Object_wx_NotebookEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnSelChange(*event);
	return Value::Nil;
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	bool rtn = pThis->GetEntity()->RemovePage(page);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_Notebook, SetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *imageList = nullptr;
	if (arg.IsValid(0)) imageList = Object_wx_ImageList::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetImageList(imageList);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, SetPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "padding", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPadding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *padding = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPadding(*padding);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Notebook, SetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Notebook, SetPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPageSize(*size);
	return Value::Nil;
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
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	int image = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->SetPageImage(page, image);
	return ReturnValue(env, arg, Value(rtn));
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
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	wxString text = wxString::FromUTF8(arg.GetString(1));
	bool rtn = pThis->GetEntity()->SetPageText(page, text);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Notebook, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Notebook, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Notebook *pThis = Object_wx_Notebook::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = arg.GetSizeT(0);
	int rtn = pThis->GetEntity()->SetSelection(page);
	return ReturnValue(env, arg, Value(rtn));
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
