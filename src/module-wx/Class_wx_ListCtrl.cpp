//----------------------------------------------------------------------------
// wxListCtrl
// extracted from listctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnGetItemAttr);
Gura_DeclarePrivUserSymbol(OnGetItemImage);
Gura_DeclarePrivUserSymbol(OnGetItemColumnImage);
Gura_DeclarePrivUserSymbol(OnGetItemText);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListCtrl: public wxListCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_ListCtrl> _pObj;
public:
	inline wx_ListCtrl() : wxListCtrl(), _pObj(nullptr) {}
	inline wx_ListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxListCtrl(parent, id, pos, size, style, validator, name), _pObj(nullptr) {}
	virtual wxListItemAttr *OnGetItemAttr(long item) const;
	virtual int OnGetItemImage(long item) const;
	virtual int OnGetItemColumnImage(long item, long column) const;
	virtual wxString OnGetItemText(long item, long column) const;
	~wx_ListCtrl();
	inline void AssocWithGura(Object_wx_ListCtrl *pObj) {
		_pObj.reset(Object_wx_ListCtrl::Reference(pObj));
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
	if (pFunc == nullptr) return wxListCtrl::OnGetItemAttr(item);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_wx_ListItemAttr, true)) return nullptr;
	return rtn.IsValid()? Object_wx_ListItemAttr::GetObject(rtn)->GetEntity() : nullptr;
}

int wx_ListCtrl::OnGetItemImage(long item) const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnGetItemImage);
	if (pFunc == nullptr) return wxListCtrl::OnGetItemImage(item);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

int wx_ListCtrl::OnGetItemColumnImage(long item, long column) const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnGetItemColumnImage);
	if (pFunc == nullptr) return wxListCtrl::OnGetItemColumnImage(item, column);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	valList.push_back(Value(column));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

wxString wx_ListCtrl::OnGetItemText(long item, long column) const
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnGetItemText);
	if (pFunc == nullptr) return wxListCtrl::OnGetItemText(item, column);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(1);
	valList.push_back(Value(item));
	valList.push_back(Value(column));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_string)) return wxEmptyString;
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListCtrlEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ListCtrl *pEntity = new wx_ListCtrl();
	Object_wx_ListCtrl *pObj = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(ListCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxLC_ICON;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(5)) validator = Object_wx_Validator::GetObject(arg, 5)->GetEntity();
	wxString name = wxListCtrlNameStr;
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_ListCtrl *pEntity = new wx_ListCtrl(parent, id, *pos, *size, style, *validator, name);
	Object_wx_ListCtrl *pObj = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_ListCtrl, Arrange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, Arrange)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int flag = wxLIST_ALIGN_DEFAULT;
	if (arg.IsValid(0)) flag = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->Arrange(flag);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, AssignImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, AssignImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *imageList = Object_wx_ImageList::GetObject(arg, 0)->GetEntity();
	int which = arg.GetInt(1);
	pThis->GetEntity()->AssignImageList(imageList, which);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, ClearAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListCtrl, ClearAll)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ClearAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxLC_ICON;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(5)) validator = Object_wx_Validator::GetObject(arg, 5)->GetEntity();
	wxString name = wxListCtrlNameStr;
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, *validator, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, DeleteAllItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteAllItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->DeleteAllItems();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, DeleteColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->DeleteColumn(col);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, DeleteItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, DeleteItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	bool rtn = pThis->GetEntity()->DeleteItem(item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, EditLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, EditLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	pThis->GetEntity()->EditLabel(item);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, EnsureVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	bool rtn = pThis->GetEntity()->EnsureVisible(item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, FindItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "partial", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, FindItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long start = arg.GetLong(0);
	wxString str = wxString::FromUTF8(arg.GetString(1));
	bool partial = false;
	if (arg.IsValid(2)) partial = arg.GetBoolean(2);
	long rtn = pThis->GetEntity()->FindItem(start, str, partial);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, FindItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, FindItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long start = arg.GetLong(0);
	long data = arg.GetLong(1);
	long rtn = pThis->GetEntity()->FindItem(start, data);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, FindItemAtPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, FindItemAtPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long start = arg.GetLong(0);
	wxPoint *pt = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	int direction = arg.GetInt(2);
	long rtn = pThis->GetEntity()->FindItem(start, *pt, direction);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	wxListItem *item = Object_wx_ListItem::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetColumn(col, *item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetColumnCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetColumnWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetColumnWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	int rtn = pThis->GetEntity()->GetColumnWidth(col);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetCountPerPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetCountPerPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCountPerPage();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetEditControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetEditControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTextCtrl *rtn = (wxTextCtrl *)pThis->GetEntity()->GetEditControl();
	return ReturnValue(env, arg, Value(new Object_wx_TextCtrl(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ListCtrl, GetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int which = arg.GetInt(0);
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetImageList(which);
	return ReturnValue(env, arg, Value(new Object_wx_ImageList(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "itemId", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxListItem info;
	long itemId = arg.GetLong(0);
	info.SetId(itemId);
	if (arg.IsValid(1)) {
		int column = arg.GetInt(1);
		info.SetColumn(column);
	}
	info.SetMask(wxLIST_MASK_STATE | wxLIST_MASK_TEXT | wxLIST_MASK_IMAGE |
					wxLIST_MASK_DATA | wxLIST_MASK_WIDTH | wxLIST_MASK_FORMAT);
	bool rtn = pThis->GetEntity()->GetItem(info);
	Value value;
	if (rtn) {
		value = Value(new Object_wx_ListItem(new wxListItem(info), nullptr, OwnerTrue));
	}
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_ListCtrl, GetItemBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxColour rtn = pThis->GetEntity()->GetItemBackgroundColour(item);
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetItemCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long rtn = pThis->GetEntity()->GetItemData(item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxFont rtn = pThis->GetEntity()->GetItemFont(item);
	return ReturnValue(env, arg, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxPoint *pos = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->GetItemPosition(item, *pos);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "code", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxRect rect;
	int code = wxLIST_RECT_BOUNDS;
	if (arg.IsValid(1)) code = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->GetItemRect(item, rect, code);
	Value value;
	if (rtn) value = Value(new Object_wx_Rect(new wxRect(rect), nullptr, OwnerTrue));
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_ListCtrl, GetSubItemRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "subItem", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "code", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetSubItemRect)
{
	Signal &sig = env.GetSignal();
#if defined(__WXMSW__)
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long subItem = arg.GetLong(1);
	wxRect rect;
	int code = wxLIST_RECT_BOUNDS;
	if (arg.IsValid(2)) code = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->GetSubItemRect(item, subItem, rect, code);
	Value value;
	if (rtn) value = Value(new Object_wx_Rect(new wxRect(rect), nullptr, OwnerTrue));
	return ReturnValue(env, arg, value);
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}

Gura_DeclareMethod(wx_ListCtrl, GetItemSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetItemSpacing();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemState)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long stateMask = arg.GetLong(1);
	int rtn = pThis->GetEntity()->GetItemState(item, stateMask);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxString rtn = pThis->GetEntity()->GetItemText(item);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListCtrl, GetItemTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetItemTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxColour rtn = pThis->GetEntity()->GetItemTextColour(item);
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetNextItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "geometry", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetNextItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	int geometry = wxLIST_NEXT_ALL;
	if (arg.IsValid(1)) geometry = arg.GetInt(1);
	int state = wxLIST_STATE_DONTCARE;
	if (arg.IsValid(2)) state = arg.GetInt(2);
	long rtn = pThis->GetEntity()->GetNextItem(item, geometry, state);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetSelectedItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetSelectedItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelectedItemCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour rtn = pThis->GetEntity()->GetTextColour();
	return ReturnValue(env, arg, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, GetTopItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetTopItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetTopItem();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, GetViewRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, GetViewRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetViewRect();
	return ReturnValue(env, arg, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ListCtrl, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, HitTest)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *point = Object_wx_Point::GetObject(arg, 0)->GetEntity();
	int flags = 0;
	long subItem;
	long rtn = pThis->GetEntity()->HitTest(*point, flags, &subItem);
	return ReturnValue(env, arg, Value::CreateList(env, rtn, flags, subItem));
}

Gura_DeclareMethod(wx_ListCtrl, InsertColumnItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "info", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertColumnItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long col = arg.GetLong(0);
	wxListItem *info = Object_wx_ListItem::GetObject(arg, 1)->GetEntity();
	long rtn = pThis->GetEntity()->InsertColumn(col, *info);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "heading", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long col = arg.GetLong(0);
	wxString heading = wxString::FromUTF8(arg.GetString(1));
	int format = wxLIST_FORMAT_LEFT;
	if (arg.IsValid(2)) format = arg.GetInt(2);
	int width = -1;
	if (arg.IsValid(3)) width = arg.GetInt(3);
	long rtn = pThis->GetEntity()->InsertColumn(col, heading, format, width);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxListItem *info = Object_wx_ListItem::GetObject(arg, 0)->GetEntity();
	long rtn = pThis->GetEntity()->InsertItem(*info);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertStringItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertStringItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long index = arg.GetLong(0);
	wxString label = wxString::FromUTF8(arg.GetString(1));
	long rtn = pThis->GetEntity()->InsertItem(index, label);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertImageItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertImageItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long index = arg.GetLong(0);
	int imageIndex = arg.GetInt(1);
	long rtn = pThis->GetEntity()->InsertItem(index, imageIndex);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, InsertImageStringItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageIndex", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, InsertImageStringItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long index = arg.GetLong(0);
	wxString label = wxString::FromUTF8(arg.GetString(1));
	int imageIndex = arg.GetInt(2);
	long rtn = pThis->GetEntity()->InsertItem(index, label, imageIndex);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxListItemAttr *rtn = (wxListItemAttr *)dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemAttr(item);
	return ReturnValue(env, arg, Value(new Object_wx_ListItemAttr(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	int rtn = dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemImage(item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long column = arg.GetLong(1);
	int rtn = dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemColumnImage(item, column);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, OnGetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, OnGetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long column = arg.GetLong(1);
	wxString rtn = dynamic_cast<wx_ListCtrl *>(pThis->GetEntity())->_OnGetItemText(item, column);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ListCtrl, RefreshItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, RefreshItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	pThis->GetEntity()->RefreshItem(item);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, RefreshItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "itemFrom", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "itemTo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, RefreshItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long itemFrom = arg.GetLong(0);
	long itemTo = arg.GetLong(1);
	pThis->GetEntity()->RefreshItems(itemFrom, itemTo);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, ScrollList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, ScrollList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int dx = arg.GetInt(0);
	int dy = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->ScrollList(dx, dy);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *col = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetBackgroundColour(*col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	wxListItem *item = Object_wx_ListItem::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetColumn(col, *item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetColumnWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetColumnWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	int width = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->SetColumnWidth(col, width);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetImageList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "which", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetImageList)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxImageList *imageList = nullptr;
	if (arg.IsValid(0)) imageList = Object_wx_ImageList::GetObject(arg, 0)->GetEntity();
	int which = arg.GetInt(1);
	pThis->GetEntity()->SetImageList(imageList, which);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "info", VTYPE_wx_ListItem, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxListItem *info = Object_wx_ListItem::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetItem(*info);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetStringItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "imageId", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetStringItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long index = arg.GetLong(0);
	int col = arg.GetInt(1);
	wxString label = wxString::FromUTF8(arg.GetString(2));
	int imageId = -1;
	if (arg.IsValid(3)) imageId = arg.GetInt(3);
	long rtn = pThis->GetEntity()->SetItem(index, col, label, imageId);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxColour *col = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetItemBackgroundColour(item, *col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long count = arg.GetLong(0);
	pThis->GetEntity()->SetItemCount(count);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long data = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->SetItemData(item, data);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxFont *font = Object_wx_Font::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetItemFont(item, *font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "selImage", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	int image = arg.GetInt(1);
	int selImage = arg.IsValid(2)? arg.GetInt(2) : -1;
	bool rtn = pThis->GetEntity()->SetItemImage(item, image, selImage);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long column = arg.GetLong(1);
	int image = arg.GetInt(2);
	bool rtn = pThis->GetEntity()->SetItemColumnImage(item, column, image);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxPoint *pos = Object_wx_Point::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetItemPosition(item, *pos);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemPtrData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_UIntPtr, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemPtrData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxUIntPtr *data = Object_wx_UIntPtr::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->SetItemPtrData(item, *data);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemState)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long state = arg.GetLong(1);
	long stateMask = arg.GetLong(2);
	bool rtn = pThis->GetEntity()->SetItemState(item, state, stateMask);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListCtrl, SetItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemText)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxString text = wxString::FromUTF8(arg.GetString(1));
	pThis->GetEntity()->SetItemText(item, text);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetItemTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetItemTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	wxColour *col = Object_wx_Colour::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->SetItemTextColour(item, *col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetSingleStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "add", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListCtrl, SetSingleStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long style = arg.GetLong(0);
	bool add = true;
	if (arg.IsValid(1)) add = arg.GetBoolean(1);
	pThis->GetEntity()->SetSingleStyle(style, add);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *col = Object_wx_Colour::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetTextColour(*col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SetWindowStyleFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListCtrl, SetWindowStyleFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long style = arg.GetLong(0);
	pThis->GetEntity()->SetWindowStyleFlag(style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListCtrl, SortItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "fnSortCallBack", VTYPE_function, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

class wxListCompareFunction {
private:
	Environment &_env;
	const Function *_pFunc;
public:
	inline wxListCompareFunction(Environment &env, const Function *pFunc) :
											_env(env), _pFunc(pFunc) {}
	int Body(long item1, long item2);
	static int wxCALLBACK Stub(long item1, long item2, long sortData);
};

int wxListCompareFunction::Body(long item1, long item2)
{
	AutoPtr<Argument> pArg(new Argument(_pFunc));
	pArg->SetValues(Value(item1), Value(item2));
	Value rtn = _pFunc->Eval(_env, *pArg);
	return rtn.GetInt();
}

int wxCALLBACK wxListCompareFunction::Stub(long item1, long item2, long sortData)
{
	wxListCompareFunction *pThis = reinterpret_cast<wxListCompareFunction *>(sortData);
	return pThis->Body(item1, item2);
}

Gura_ImplementMethod(wx_ListCtrl, SortItems)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListCtrl *pThis = Object_wx_ListCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxListCompareFunction listCompareFunction(env, arg.GetFunction(0));
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
	return nullptr;
}

String Object_wx_ListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ListCtrl:");
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
	return new Object_wx_ListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
