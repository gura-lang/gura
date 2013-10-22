//----------------------------------------------------------------------------
// wxListCtrl
// extracted from listctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnGetItemAttr);
Gura_DeclarePrivUserSymbol(OnGetItemImage);
Gura_DeclarePrivUserSymbol(OnGetItemColumnImage);
Gura_DeclarePrivUserSymbol(OnGetItemText);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListCtrl: public wxListCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	AutoPtr<Object_wx_ListCtrl> _pObj;
public:
	inline wx_ListCtrl() : wxListCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_ListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxListCtrl(parent, id, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	virtual wxListItemAttr *OnGetItemAttr(long item) const;
	virtual int OnGetItemImage(long item) const;
	virtual int OnGetItemColumnImage(long item, long column) const;
	virtual wxString OnGetItemText(long item, long column) const;
	~wx_ListCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ListCtrl *pObj) {
		_sig = sig, _pObj.reset(Object_wx_ListCtrl::Reference(pObj));
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
public:
	// reveal private or protected member functions to public
	inline wxListItemAttr *_OnGetItemAttr(long item) const {
		return wxListCtrl::OnGetItemAttr(item);
	}
	inline int _OnGetItemImage(long item) const {
		return wxListCtrl::OnGetItemImage(item);
	}
	inline int _OnGetItemColumnImage(long item, long column) const {
		return wxListCtrl::OnGetItemColumnImage(item, column);
	}
	inline wxString _OnGetItemText(long item, long column) const {
		return wxListCtrl::OnGetItemText(item, column);
	}
};

wx_ListCtrl::~wx_ListCtrl()
{
}

wxListItemAttr *wx_ListCtrl::OnGetItemAttr(long item) const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnGetItemAttr);
	if (pFunc == NULL) return wxListCtrl::OnGetItemAttr(item);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_wx_ListItemAttr, true)) return false;
	return rtn.IsValid()? Object_wx_ListItemAttr::GetObject(rtn)->GetEntity() : NULL;
}

int wx_ListCtrl::OnGetItemImage(long item) const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnGetItemImage);
	if (pFunc == NULL) return wxListCtrl::OnGetItemImage(item);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

int wx_ListCtrl::OnGetItemColumnImage(long item, long column) const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnGetItemColumnImage);
	if (pFunc == NULL) return wxListCtrl::OnGetItemColumnImage(item, column);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	valList.push_back(Value(column));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

wxString wx_ListCtrl::OnGetItemText(long item, long column) const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnGetItemText);
	if (pFunc == NULL) return wxListCtrl::OnGetItemText(item, column);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	valList.push_back(Value(column));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_string)) return wxEmptyString;
	return wxString::FromUTF8(rtn.GetString());
}

void wx_ListCtrl::GuraObjectDeleted()
{
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(ListCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_ListCtrl *pEntity = new wx_ListCtrl();
	Object_wx_ListCtrl *pObj = Object_wx_ListCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ListCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ListCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxLC_ICON;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(5)) validator = Object_wx_Validator::GetObject(args, 5)->GetEntity();
	wxString name = wxListCtrlNameStr;
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_ListCtrl *pEntity = new wx_ListCtrl(parent, id, *pos, *size, style, *validator, name);
	Object_wx_ListCtrl *pObj = Object_wx_ListCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ListCtrl, Arrange)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, Arrange)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int flag = wxLIST_ALIGN_DEFAULT;
	if (args.IsValid(0)) flag = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Arrange(flag);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, AssignImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, AssignImageList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	int which = args.GetInt(1);
	pThis->GetEntity()->AssignImageList(imageList, which);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, ClearAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, ClearAll)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, Create)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxLC_ICON;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(5)) validator = Object_wx_Validator::GetObject(args, 5)->GetEntity();
	wxString name = wxListCtrlNameStr;
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, DeleteAllItems)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteAllItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DeleteAllItems();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, DeleteColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	bool rtn = pThis->GetEntity()->DeleteColumn(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, DeleteItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	bool rtn = pThis->GetEntity()->DeleteItem(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, EditLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EditLabel)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	pThis->GetEntity()->EditLabel(item);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, EnsureVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, EnsureVisible)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	bool rtn = pThis->GetEntity()->EnsureVisible(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, FindItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "partial", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, FindItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long start = args.GetLong(0);
	wxString str = wxString::FromUTF8(args.GetString(1));
	bool partial = false;
	if (args.IsValid(2)) partial = args.GetBoolean(2);
	long rtn = pThis->GetEntity()->FindItem(start, str, partial);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, FindItemData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, FindItemData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long start = args.GetLong(0);
	long data = args.GetLong(1);
	long rtn = pThis->GetEntity()->FindItem(start, data);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, FindItemAtPos)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, FindItemAtPos)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long start = args.GetLong(0);
	wxPoint *pt = Object_wx_Point::GetObject(args, 1)->GetEntity();
	int direction = args.GetInt(2);
	long rtn = pThis->GetEntity()->FindItem(start, *pt, direction);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxListItem *item = Object_wx_ListItem::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetColumn(col, *item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColumnCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnWidth)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetColumnWidth(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetCountPerPage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetCountPerPage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCountPerPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetEditControl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetEditControl)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextCtrl *rtn = (wxTextCtrl *)pThis->GetEntity()->GetEditControl();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextCtrl(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ListCtrl, GetImageList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetImageList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int which = args.GetInt(0);
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetImageList(which);
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageList(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "itemId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxListItem info;
	long itemId = args.GetLong(0);
	info.SetId(itemId);
	if (args.IsValid(1)) {
		int column = args.GetInt(1);
		info.SetColumn(column);
	}
	info.SetMask(wxLIST_MASK_STATE | wxLIST_MASK_TEXT | wxLIST_MASK_IMAGE |
					wxLIST_MASK_DATA | wxLIST_MASK_WIDTH | wxLIST_MASK_FORMAT);
	bool rtn = pThis->GetEntity()->GetItem(info);
	Value value;
	if (rtn) {
		value = Value(new Object_wx_ListItem(new wxListItem(info), NULL, OwnerTrue));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_ListCtrl, GetItemBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxColour rtn = pThis->GetEntity()->GetItemBackgroundColour(item);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetItemCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long rtn = pThis->GetEntity()->GetItemData(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemFont)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxFont rtn = pThis->GetEntity()->GetItemFont(item);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemPosition)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxPoint *pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetItemPosition(item, *pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "code", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxRect rect;
	int code = wxLIST_RECT_BOUNDS;
	if (args.IsValid(1)) code = args.GetInt(1);
	bool rtn = pThis->GetEntity()->GetItemRect(item, rect, code);
	Value value;
	if (rtn) value = Value(new Object_wx_Rect(new wxRect(rect), NULL, OwnerTrue));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_ListCtrl, GetSubItemRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "subItem", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "code", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetSubItemRect)
{
#if defined(__WXMSW__)
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long subItem = args.GetLong(1);
	wxRect rect;
	int code = wxLIST_RECT_BOUNDS;
	if (args.IsValid(2)) code = args.GetInt(2);
	bool rtn = pThis->GetEntity()->GetSubItemRect(item, subItem, rect, code);
	Value value;
	if (rtn) value = Value(new Object_wx_Rect(new wxRect(rect), NULL, OwnerTrue));
	return ReturnValue(env, sig, args, value);
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_ListCtrl, GetItemSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemSpacing)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetItemSpacing();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemState)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long stateMask = args.GetLong(1);
	int rtn = pThis->GetEntity()->GetItemState(item, stateMask);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxString rtn = pThis->GetEntity()->GetItemText(item);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxColour rtn = pThis->GetEntity()->GetItemTextColour(item);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetNextItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "geometry", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetNextItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	int geometry = wxLIST_NEXT_ALL;
	if (args.IsValid(1)) geometry = args.GetInt(1);
	int state = wxLIST_STATE_DONTCARE;
	if (args.IsValid(2)) state = args.GetInt(2);
	long rtn = pThis->GetEntity()->GetNextItem(item, geometry, state);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetSelectedItemCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetSelectedItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSelectedItemCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetTopItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetTopItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetTopItem();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetViewRect)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetViewRect)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetViewRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, HitTest)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *point = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int flags = 0;
	long subItem;
	long rtn = pThis->GetEntity()->HitTest(*point, flags, &subItem);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, rtn, flags, subItem));
}

Gura_DeclareMethod(wx_ListCtrl, InsertColumnItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "info", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertColumnItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long col = args.GetLong(0);
	wxListItem *info = Object_wx_ListItem::GetObject(args, 1)->GetEntity();
	long rtn = pThis->GetEntity()->InsertColumn(col, *info);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "heading", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long col = args.GetLong(0);
	wxString heading = wxString::FromUTF8(args.GetString(1));
	int format = wxLIST_FORMAT_LEFT;
	if (args.IsValid(2)) format = args.GetInt(2);
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	long rtn = pThis->GetEntity()->InsertColumn(col, heading, format, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxListItem *info = Object_wx_ListItem::GetObject(args, 0)->GetEntity();
	long rtn = pThis->GetEntity()->InsertItem(*info);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertStringItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertStringItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	long rtn = pThis->GetEntity()->InsertItem(index, label);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertImageItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertImageItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	int imageIndex = args.GetInt(1);
	long rtn = pThis->GetEntity()->InsertItem(index, imageIndex);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertImageStringItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertImageStringItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	wxString label = wxString::FromUTF8(args.GetString(1));
	int imageIndex = args.GetInt(2);
	long rtn = pThis->GetEntity()->InsertItem(index, label, imageIndex);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemAttr)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxListItemAttr *rtn = (wxListItemAttr *)dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemAttr(item);
	return ReturnValue(env, sig, args, Value(new Object_wx_ListItemAttr(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	int rtn = dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemImage(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemColumnImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemColumnImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long column = args.GetLong(1);
	int rtn = dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemColumnImage(item, column);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long column = args.GetLong(1);
	wxString rtn = dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemText(item, column);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListCtrl, RefreshItem)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, RefreshItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	pThis->GetEntity()->RefreshItem(item);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, RefreshItems)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "itemFrom", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "itemTo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, RefreshItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long itemFrom = args.GetLong(0);
	long itemTo = args.GetLong(1);
	pThis->GetEntity()->RefreshItems(itemFrom, itemTo);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, ScrollList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, ScrollList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int dx = args.GetInt(0);
	int dy = args.GetInt(1);
	bool rtn = pThis->GetEntity()->ScrollList(dx, dy);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *col = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetColumn)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxListItem *item = Object_wx_ListItem::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetColumn(col, *item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetColumnWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetColumnWidth)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int width = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetColumnWidth(col, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetImageList)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = NULL;
	if (args.IsValid(0)) imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	int which = args.GetInt(1);
	pThis->GetEntity()->SetImageList(imageList, which);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxListItem *info = Object_wx_ListItem::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetItem(*info);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetStringItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetStringItem)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	int col = args.GetInt(1);
	wxString label = wxString::FromUTF8(args.GetString(2));
	int imageId = -1;
	if (args.IsValid(3)) imageId = args.GetInt(3);
	long rtn = pThis->GetEntity()->SetItem(index, col, label, imageId);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemBackgroundColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxColour *col = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetItemBackgroundColour(item, *col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemCount)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemCount)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long count = args.GetLong(0);
	pThis->GetEntity()->SetItemCount(count);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemData)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long data = args.GetLong(1);
	bool rtn = pThis->GetEntity()->SetItemData(item, data);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemFont)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxFont *font = Object_wx_Font::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetItemFont(item, *font);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	int image = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetItemImage(item, image);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemColumnImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemColumnImage)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long column = args.GetLong(1);
	int image = args.GetInt(2);
	bool rtn = pThis->GetEntity()->SetItemColumnImage(item, column, image);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemPosition)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxPoint *pos = Object_wx_Point::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetItemPosition(item, *pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemPtrData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_UIntPtr, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemPtrData)
{
#if 0
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxUIntPtr *data = Object_wx_UIntPtr::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetItemPtrData(item, *data);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemState)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemState)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long state = args.GetLong(1);
	long stateMask = args.GetLong(2);
	bool rtn = pThis->GetEntity()->SetItemState(item, state, stateMask);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemText)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxString text = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetItemText(item, text);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	wxColour *col = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetItemTextColour(item, *col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetSingleStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "add", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetSingleStyle)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long style = args.GetLong(0);
	bool add = true;
	if (args.IsValid(1)) add = args.GetBoolean(1);
	pThis->GetEntity()->SetSingleStyle(style, add);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetTextColour)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *col = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SetWindowStyleFlag)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetWindowStyleFlag)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long style = args.GetLong(0);
	pThis->GetEntity()->SetWindowStyleFlag(style);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListCtrl, SortItems)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fnSortCallBack", VTYPE_function, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

class wxListCompareFunction {
private:
	Environment &_env;
	Signal &_sig;
	const Function *_pFunc;
public:
	inline wxListCompareFunction(Environment &env, Signal &sig, const Function *pFunc) :
											_env(env), _sig(sig), _pFunc(pFunc) {}
	int Body(long item1, long item2);
	static int wxCALLBACK Stub(long item1, long item2, long sortData);
};

int wxListCompareFunction::Body(long item1, long item2)
{
	//ValueList valList;
	//valList.reserve(2);
	//valList.push_back(Value(item1));
	//valList.push_back(Value(item2));
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetValues(Value(item1), Value(item2));
	Value rtn = _pFunc->Eval(_env, _sig, *pArgs);
	return rtn.GetInt();
}

int wxCALLBACK wxListCompareFunction::Stub(long item1, long item2, long sortData)
{
	wxListCompareFunction *pThis = reinterpret_cast<wxListCompareFunction *>(sortData);
	return pThis->Body(item1, item2);
}

Gura_ImplementMethod(wx_ListCtrl, SortItems)
{
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxListCompareFunction listCompareFunction(env, sig, args.GetFunction(0));
	long sortData = reinterpret_cast<long>(&listCompareFunction);
	bool rtn = pThis->GetEntity()->SortItems(wxListCompareFunction::Stub, sortData);
	return Value(rtn);
}

//----------------------------------------------------------------------------
// Object implementation for wxListCtrl
//----------------------------------------------------------------------------
Object_wx_ListCtrl::~Object_wx_ListCtrl()
{
}

Object *Object_wx_ListCtrl::Clone() const
{
	return NULL;
}

String Object_wx_ListCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ListCtrl:");
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
// Class implementation for wxListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListCtrl)
{
	Gura_RealizeUserSymbol(OnGetItemAttr);
	Gura_RealizeUserSymbol(OnGetItemImage);
	Gura_RealizeUserSymbol(OnGetItemColumnImage);
	Gura_RealizeUserSymbol(OnGetItemText);
	Gura_AssignWxStringValue(ListCtrlNameStr);
	Gura_AssignFunction(ListCtrlEmpty);
	Gura_AssignFunction(ListCtrl);
	Gura_AssignMethod(wx_ListCtrl, Arrange);
	Gura_AssignMethod(wx_ListCtrl, AssignImageList);
	Gura_AssignMethod(wx_ListCtrl, ClearAll);
	Gura_AssignMethod(wx_ListCtrl, Create);
	Gura_AssignMethod(wx_ListCtrl, DeleteAllItems);
	Gura_AssignMethod(wx_ListCtrl, DeleteColumn);
	Gura_AssignMethod(wx_ListCtrl, DeleteItem);
	Gura_AssignMethod(wx_ListCtrl, EditLabel);
	Gura_AssignMethod(wx_ListCtrl, EnsureVisible);
	Gura_AssignMethod(wx_ListCtrl, FindItem);
	Gura_AssignMethod(wx_ListCtrl, FindItemData);
	Gura_AssignMethod(wx_ListCtrl, FindItemAtPos);
	Gura_AssignMethod(wx_ListCtrl, GetColumn);
	Gura_AssignMethod(wx_ListCtrl, GetColumnCount);
	Gura_AssignMethod(wx_ListCtrl, GetColumnWidth);
	Gura_AssignMethod(wx_ListCtrl, GetCountPerPage);
	Gura_AssignMethod(wx_ListCtrl, GetEditControl);
	Gura_AssignMethod(wx_ListCtrl, GetImageList);
	Gura_AssignMethod(wx_ListCtrl, GetItem);
	Gura_AssignMethod(wx_ListCtrl, GetItemBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, GetItemCount);
	Gura_AssignMethod(wx_ListCtrl, GetItemData);
	Gura_AssignMethod(wx_ListCtrl, GetItemFont);
	Gura_AssignMethod(wx_ListCtrl, GetItemPosition);
	Gura_AssignMethod(wx_ListCtrl, GetItemRect);
	Gura_AssignMethod(wx_ListCtrl, GetSubItemRect);
	Gura_AssignMethod(wx_ListCtrl, GetItemSpacing);
	Gura_AssignMethod(wx_ListCtrl, GetItemState);
	Gura_AssignMethod(wx_ListCtrl, GetItemText);
	Gura_AssignMethod(wx_ListCtrl, GetItemTextColour);
	Gura_AssignMethod(wx_ListCtrl, GetNextItem);
	Gura_AssignMethod(wx_ListCtrl, GetSelectedItemCount);
	Gura_AssignMethod(wx_ListCtrl, GetTextColour);
	Gura_AssignMethod(wx_ListCtrl, GetTopItem);
	Gura_AssignMethod(wx_ListCtrl, GetViewRect);
	Gura_AssignMethod(wx_ListCtrl, HitTest);
	Gura_AssignMethod(wx_ListCtrl, InsertColumnItem);
	Gura_AssignMethod(wx_ListCtrl, InsertColumn);
	Gura_AssignMethod(wx_ListCtrl, InsertItem);
	Gura_AssignMethod(wx_ListCtrl, InsertStringItem);
	Gura_AssignMethod(wx_ListCtrl, InsertImageItem);
	Gura_AssignMethod(wx_ListCtrl, InsertImageStringItem);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemAttr);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemImage);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemColumnImage);
	Gura_AssignMethod(wx_ListCtrl, OnGetItemText);
	Gura_AssignMethod(wx_ListCtrl, RefreshItem);
	Gura_AssignMethod(wx_ListCtrl, RefreshItems);
	Gura_AssignMethod(wx_ListCtrl, ScrollList);
	Gura_AssignMethod(wx_ListCtrl, SetBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, SetColumn);
	Gura_AssignMethod(wx_ListCtrl, SetColumnWidth);
	Gura_AssignMethod(wx_ListCtrl, SetImageList);
	Gura_AssignMethod(wx_ListCtrl, SetItem);
	Gura_AssignMethod(wx_ListCtrl, SetStringItem);
	Gura_AssignMethod(wx_ListCtrl, SetItemBackgroundColour);
	Gura_AssignMethod(wx_ListCtrl, SetItemCount);
	Gura_AssignMethod(wx_ListCtrl, SetItemData);
	Gura_AssignMethod(wx_ListCtrl, SetItemFont);
	Gura_AssignMethod(wx_ListCtrl, SetItemImage);
	Gura_AssignMethod(wx_ListCtrl, SetItemColumnImage);
	Gura_AssignMethod(wx_ListCtrl, SetItemPosition);
	Gura_AssignMethod(wx_ListCtrl, SetItemPtrData);
	Gura_AssignMethod(wx_ListCtrl, SetItemState);
	Gura_AssignMethod(wx_ListCtrl, SetItemText);
	Gura_AssignMethod(wx_ListCtrl, SetItemTextColour);
	Gura_AssignMethod(wx_ListCtrl, SetSingleStyle);
	Gura_AssignMethod(wx_ListCtrl, SetTextColour);
	Gura_AssignMethod(wx_ListCtrl, SetWindowStyleFlag);
	Gura_AssignMethod(wx_ListCtrl, SortItems);
}

Gura_ImplementDescendantCreator(wx_ListCtrl)
{
	return new Object_wx_ListCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
