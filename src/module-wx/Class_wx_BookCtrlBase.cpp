//----------------------------------------------------------------------------
// wxBookCtrlBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_BookCtrlBase: public wxBookCtrlBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_BookCtrlBase *_pObj;
public:
	~wx_BookCtrlBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_BookCtrlBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_BookCtrlBase::~wx_BookCtrlBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_BookCtrlBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxBookCtrlBase
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BookCtrlBase, AddPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, AddPage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
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

Gura_DeclareMethod(wx_BookCtrlBase, AdvanceSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "forward", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, AdvanceSelection)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool forward = true;
	if (args.IsValid(0)) forward = args.GetBoolean(0);
	pThis->GetEntity()->AdvanceSelection(forward);
	return Value::Null;
}

Gura_DeclareMethod(wx_BookCtrlBase, AssignImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlBase, AssignImageList)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AssignImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_BookCtrlBase, ChangeSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, ChangeSelection)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->ChangeSelection(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, Create)
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

Gura_ImplementMethod(wx_BookCtrlBase, Create)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
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

Gura_DeclareMethod(wx_BookCtrlBase, DeleteAllPages)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, DeleteAllPages)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DeleteAllPages();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, DeletePage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, DeletePage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->DeletePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, GetCurrentPage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, GetCurrentPage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetCurrentPage();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_BookCtrlBase, GetImageList)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, GetImageList)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetImageList();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_ImageList(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_BookCtrlBase, GetPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, GetPage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetPage(page);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_Window(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_BookCtrlBase, GetPageCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, GetPageCount)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetPageCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, GetPageImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, GetPageImage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nPage = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->GetPageImage(nPage);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, GetPageText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "nPage", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, GetPageText)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t nPage = args.GetSizeT(0);
	wxString rtn = pThis->GetEntity()->GetPageText(nPage);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_BookCtrlBase, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, GetSelection)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, HitTest)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	long flags = 0;
	int rtn = pThis->GetEntity()->HitTest(*pt, &flags);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, flags));
}

Gura_DeclareMethod(wx_BookCtrlBase, InsertPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "page", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, InsertPage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
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

Gura_DeclareMethod(wx_BookCtrlBase, RemovePage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, RemovePage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->RemovePage(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, SetImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_BookCtrlBase, SetImageList)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = NULL;
	if (args.IsValid(0)) imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_BookCtrlBase, SetPageSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_BookCtrlBase, SetPageSize)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPageSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_BookCtrlBase, SetPageImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, SetPageImage)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int image = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetPageImage(page, image);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, SetPageText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, SetPageText)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetPageText(page, text);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_BookCtrlBase, SetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_BookCtrlBase, SetSelection)
{
	Object_wx_BookCtrlBase *pThis = Object_wx_BookCtrlBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t page = args.GetSizeT(0);
	int rtn = pThis->GetEntity()->SetSelection(page);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxBookCtrlBase
//----------------------------------------------------------------------------
Object_wx_BookCtrlBase::~Object_wx_BookCtrlBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_BookCtrlBase::Clone() const
{
	return NULL;
}

String Object_wx_BookCtrlBase::ToString(bool exprFlag)
{
	String rtn("<wx.BookCtrlBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxBookCtrlBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BookCtrlBase)
{
	Gura_AssignMethod(wx_BookCtrlBase, AddPage);
	Gura_AssignMethod(wx_BookCtrlBase, AdvanceSelection);
	Gura_AssignMethod(wx_BookCtrlBase, AssignImageList);
	Gura_AssignMethod(wx_BookCtrlBase, ChangeSelection);
	Gura_AssignMethod(wx_BookCtrlBase, Create);
	Gura_AssignMethod(wx_BookCtrlBase, DeleteAllPages);
	Gura_AssignMethod(wx_BookCtrlBase, DeletePage);
	Gura_AssignMethod(wx_BookCtrlBase, GetCurrentPage);
	Gura_AssignMethod(wx_BookCtrlBase, GetImageList);
	Gura_AssignMethod(wx_BookCtrlBase, GetPage);
	Gura_AssignMethod(wx_BookCtrlBase, GetPageCount);
	Gura_AssignMethod(wx_BookCtrlBase, GetPageImage);
	Gura_AssignMethod(wx_BookCtrlBase, GetPageText);
	Gura_AssignMethod(wx_BookCtrlBase, GetSelection);
	Gura_AssignMethod(wx_BookCtrlBase, HitTest);
	Gura_AssignMethod(wx_BookCtrlBase, InsertPage);
	Gura_AssignMethod(wx_BookCtrlBase, RemovePage);
	Gura_AssignMethod(wx_BookCtrlBase, SetImageList);
	Gura_AssignMethod(wx_BookCtrlBase, SetPageSize);
	Gura_AssignMethod(wx_BookCtrlBase, SetPageImage);
	Gura_AssignMethod(wx_BookCtrlBase, SetPageText);
	Gura_AssignMethod(wx_BookCtrlBase, SetSelection);
}

Gura_ImplementDescendantCreator(wx_BookCtrlBase)
{
	return new Object_wx_BookCtrlBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
