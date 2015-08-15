//----------------------------------------------------------------------------
// wxTreebook
// extracted from treebook.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Treebook: public wxTreebook, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Treebook *_pObj;
public:
	inline wx_Treebook() : wxTreebook(), _pObj(nullptr) {}
	inline wx_Treebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxTreebook(parent, id, pos, size, style, name), _pObj(nullptr) {}
	~wx_Treebook();
	inline void AssocWithGura(Object_wx_Treebook *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Treebook::~wx_Treebook()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Treebook::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreebook
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreebookEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Treebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreebookEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Treebook *pEntity = new wx_Treebook();
	Object_wx_Treebook *pObj = Object_wx_Treebook::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Treebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Treebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Treebook));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Treebook)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxBK_DEFAULT;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxEmptyString;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_Treebook *pEntity = new wx_Treebook(parent, id, *pos, *size, style, name);
	Object_wx_Treebook *pObj = Object_wx_Treebook::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Treebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Treebook, AddPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bSelect", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, AddPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *page = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool bSelect = false;
	if (args.IsValid(2)) bSelect = args.GetBoolean(2);
	int imageId = wxNOT_FOUND;
	if (args.IsValid(3)) imageId = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AddPage(page, text, bSelect, imageId);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, AddSubPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bSelect", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, AddSubPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *page = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool bSelect = false;
	if (args.IsValid(2)) bSelect = args.GetBoolean(2);
	int imageId = wxNOT_FOUND;
	if (args.IsValid(3)) imageId = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AddSubPage(page, text, bSelect, imageId);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, AssignImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_Treebook, AssignImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AssignImageList(imageList);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, ChangeSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, ChangeSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->ChangeSelection(page);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, CollapseNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, CollapseNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pageId = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->CollapseNode(pageId);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, Create)
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

Gura_ImplementMethod(wx_Treebook, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxBK_DEFAULT;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxEmptyString;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, DeleteAllPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, DeleteAllPages)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DeleteAllPages();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, DeletePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, DeletePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pagePos = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->DeletePage(pagePos);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, ExpandNode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "expand", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, ExpandNode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pageId = args.GetSizeT(0);
	bool expand = true;
	if (args.IsValid(1)) expand = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->ExpandNode(pageId, expand);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, GetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, GetPageImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->GetPageImage(n);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, GetPageParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, GetPageParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->GetPageParent(page);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, GetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, GetPageText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetPageText(n);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Treebook, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bSelect", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, InsertPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pagePos = args.GetSizeT(0);
	wxWindow *page = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(2));
	bool bSelect = false;
	if (args.IsValid(3)) bSelect = args.GetBoolean(3);
	int imageId = wxNOT_FOUND;
	if (args.IsValid(4)) imageId = args.GetInt(4);
	bool rtn = pThis->GetEntity()->InsertPage(pagePos, page, text, bSelect, imageId);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, InsertSubPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pagePos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bSelect", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, InsertSubPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pagePos = args.GetSizeT(0);
	wxWindow *page = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(2));
	bool bSelect = false;
	if (args.IsValid(3)) bSelect = args.GetBoolean(3);
	int imageId = wxNOT_FOUND;
	if (args.IsValid(4)) imageId = args.GetInt(4);
	bool rtn = pThis->GetEntity()->InsertSubPage(pagePos, page, text, bSelect, imageId);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, IsNodeExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, IsNodeExpanded)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pageId = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->IsNodeExpanded(pageId);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_Treebook, SetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *imageList = nullptr;
	if (args.IsValid(0)) imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetImageList(imageList);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Treebook, SetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, SetPageImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = args.GetSizeT(0);
	int imageId = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetPageImage(page, imageId);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, SetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, SetPageText)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t page = args.GetSizeT(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetPageText(page, text);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Treebook, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Treebook, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Treebook *pThis = Object_wx_Treebook::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t n = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->SetSelection(n);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTreebook
//----------------------------------------------------------------------------
Object_wx_Treebook::~Object_wx_Treebook()
{
}

Object *Object_wx_Treebook::Clone() const
{
	return nullptr;
}

String Object_wx_Treebook::ToString(bool exprFlag)
{
	String rtn("<wx.Treebook:");
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
// Class implementation for wxTreebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Treebook)
{
	Gura_AssignFunction(TreebookEmpty);
	Gura_AssignFunction(Treebook);
	Gura_AssignMethod(wx_Treebook, AddPage);
	Gura_AssignMethod(wx_Treebook, AddSubPage);
	Gura_AssignMethod(wx_Treebook, AssignImageList);
	Gura_AssignMethod(wx_Treebook, ChangeSelection);
	Gura_AssignMethod(wx_Treebook, CollapseNode);
	Gura_AssignMethod(wx_Treebook, Create);
	Gura_AssignMethod(wx_Treebook, DeleteAllPages);
	Gura_AssignMethod(wx_Treebook, DeletePage);
	Gura_AssignMethod(wx_Treebook, ExpandNode);
	Gura_AssignMethod(wx_Treebook, GetPageImage);
	Gura_AssignMethod(wx_Treebook, GetPageParent);
	Gura_AssignMethod(wx_Treebook, GetPageText);
	Gura_AssignMethod(wx_Treebook, GetSelection);
	Gura_AssignMethod(wx_Treebook, InsertPage);
	Gura_AssignMethod(wx_Treebook, InsertSubPage);
	Gura_AssignMethod(wx_Treebook, IsNodeExpanded);
	Gura_AssignMethod(wx_Treebook, SetImageList);
	Gura_AssignMethod(wx_Treebook, SetPageImage);
	Gura_AssignMethod(wx_Treebook, SetPageText);
	Gura_AssignMethod(wx_Treebook, SetSelection);
}

Gura_ImplementDescendantCreator(wx_Treebook)
{
	return new Object_wx_Treebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
