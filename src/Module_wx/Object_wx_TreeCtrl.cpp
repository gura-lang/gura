//----------------------------------------------------------------------------
// wxTreeCtrl
// extracted from treectrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnCompareItems);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TreeCtrl: public wxTreeCtrl, public GuraObjectObserver {
private:
	DECLARE_DYNAMIC_CLASS(wx_TreeCtrl)
	Gura::Signal _sig;
	AutoPtr<Object_wx_TreeCtrl> _pObj;
public:
	inline wx_TreeCtrl() : wxTreeCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_TreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxTreeCtrl(parent, id, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	//inline wx_TreeCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxTreeCtrl(parent, id, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_TreeCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TreeCtrl *pObj) {
		_sig = sig, _pObj.reset(Object_wx_TreeCtrl::Reference(pObj));
	}
	virtual int OnCompareItems(const wxTreeItemId& item1, const wxTreeItemId& item2);
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

IMPLEMENT_DYNAMIC_CLASS(wx_TreeCtrl, wxTreeCtrl)

wx_TreeCtrl::~wx_TreeCtrl()
{
}

void wx_TreeCtrl::GuraObjectDeleted()
{
}

int wx_TreeCtrl::OnCompareItems(const wxTreeItemId& item1, const wxTreeItemId& item2)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, OnCompareItems);
	if (pFunc == NULL) return wxTreeCtrl::OnCompareItems(item1, item2);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(new Object_wx_TreeItemId(new wxTreeItemId(item1), NULL, OwnerTrue)));
	valList.push_back(Value(new Object_wx_TreeItemId(new wxTreeItemId(item2), NULL, OwnerTrue)));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

//-----------------------------------------------------------------------------
// Iterator_TreeCtrl_ItemChildren
//-----------------------------------------------------------------------------
class Iterator_TreeCtrl_ItemChildren : public Iterator {
private:
	AutoPtr<Object_wx_TreeCtrl> _pObj;
	wxTreeItemId _item;
	wxTreeItemId _itemChild;
	wxTreeItemIdValue _cookie;
public:
	inline Iterator_TreeCtrl_ItemChildren(Object_wx_TreeCtrl *pObj,
			wxTreeItemId item, wxTreeItemId itemChild, wxTreeItemIdValue cookie) :
		Iterator(false), _pObj(pObj),
		_item(item), _itemChild(itemChild), _cookie(cookie) {}
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Iterator *Iterator_TreeCtrl_ItemChildren::GetSource()
{
	return NULL;
}

bool Iterator_TreeCtrl_ItemChildren::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_pObj->IsInvalid(sig)) return false;
	if (!_item.IsOk() || !_itemChild.IsOk()) return false;
	value = Value(new Object_wx_TreeItemId(new wxTreeItemId(_itemChild), NULL, true));
	_itemChild = _pObj->GetEntity()->GetNextChild(_item, _cookie);
	return true;
}

String Iterator_TreeCtrl_ItemChildren::ToString(Signal sig) const
{
	String str;
	str = "<iterator:wx.TreeCtrl.ItemChildren>";
	return str;
}

void Iterator_TreeCtrl_ItemChildren::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(TreeCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TreeCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TreeCtrl *pEntity = new wx_TreeCtrl();
	Object_wx_TreeCtrl *pObj = Object_wx_TreeCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TreeCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(TreeCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TreeCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TreeCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxTR_HAS_BUTTONS;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(5)) validator = Object_wx_Validator::GetObject(args, 5)->GetEntity();
	wxString name = wxT("treeCtrl");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_TreeCtrl *pEntity = new wx_TreeCtrl(parent, id, *pos, *size, style, *validator, name);
	Object_wx_TreeCtrl *pObj = Object_wx_TreeCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TreeCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TreeCtrl, AddRoot)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "selImage", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_TreeItemData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, AddRoot)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	int image = -1;
	if (args.IsValid(1)) image = args.GetInt(1);
	int selImage = -1;
	if (args.IsValid(2)) selImage = args.GetInt(2);
	wxTreeItemData *data = (wxTreeItemData *)(NULL);
	if (args.IsValid(3)) data = new wx_TreeItemData(*Object_wx_TreeItemData::GetObject(args, 3)->GetEntity());
	wxTreeItemId rtn = pThis->GetEntity()->AddRoot(text, image, selImage, data);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, AppendItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "selImage", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_TreeItemData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, AppendItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *parent = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	int image = -1;
	if (args.IsValid(2)) image = args.GetInt(2);
	int selImage = -1;
	if (args.IsValid(3)) selImage = args.GetInt(3);
	wxTreeItemData *data = (wxTreeItemData *)(NULL);
	if (args.IsValid(4)) data = new wx_TreeItemData(*Object_wx_TreeItemData::GetObject(args, 4)->GetEntity());
	wxTreeItemId rtn = pThis->GetEntity()->AppendItem(*parent, text, image, selImage, data);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, AssignImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, AssignImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AssignImageList(new wxImageList(*imageList));
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, AssignStateImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, AssignStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AssignStateImageList(new wxImageList(*imageList));
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, Collapse)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Collapse)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Collapse(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, CollapseAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, CollapseAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CollapseAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, CollapseAllChildren)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, CollapseAllChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->CollapseAllChildren(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, CollapseAndReset)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, CollapseAndReset)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->CollapseAndReset(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, Delete)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Delete)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Delete(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, DeleteAllItems)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, DeleteAllItems)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DeleteAllItems();
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, DeleteChildren)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, DeleteChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DeleteChildren(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, EditLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, EditLabel)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->EditLabel(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, EndEditLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "cancelEdit", VTYPE_boolean, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TreeCtrl, EndEditLabel)
{
#if 0
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool cancelEdit = args.GetBoolean(0);
	pThis->GetEntity()->EndEditLabel(cancelEdit);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, EnsureVisible)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, EnsureVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->EnsureVisible(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, Expand)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Expand)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Expand(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, ExpandAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, ExpandAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ExpandAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, ExpandAllChildren)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, ExpandAllChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->ExpandAllChildren(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, GetBoundingRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "textOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetBoundingRect)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxRect rect;
	bool textOnly = false;
	if (args.IsValid(1)) textOnly = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->GetBoundingRect(*item, rect, textOnly);
	Value value;
	if (rtn) {
		value = Value(new Object_wx_Rect(new wxRect(rect), NULL, OwnerTrue));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_TreeCtrl, GetChildrenCount)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "recursively", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetChildrenCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool recursively = true;
	if (args.IsValid(1)) recursively = args.GetBoolean(1);
	unsigned rtn = pThis->GetEntity()->GetChildrenCount(*item, recursively);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, GetCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetCount)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, GetEditControl)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetEditControl)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTextCtrl *rtn = (wxTextCtrl *)pThis->GetEntity()->GetEditControl();
	return ReturnValue(env, sig, args, Value(new Object_wx_TextCtrl(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetFirstChild)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetFirstChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemIdValue cookie;
	wxTreeItemId rtn = pThis->GetEntity()->GetFirstChild(*item, cookie);
	return ReturnValue(env, sig, args, Value::CreateAsList(env,
		Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)),
		Value(reinterpret_cast<int>(cookie))));
}

Gura_DeclareMethod(wx_TreeCtrl, GetFirstVisibleItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetFirstVisibleItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId rtn = pThis->GetEntity()->GetFirstVisibleItem();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetImageList)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetImageList();
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageList(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetIndent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetIndent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetIndent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, GetSpacing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetSpacing)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned int rtn = pThis->GetEntity()->GetSpacing();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemBackgroundColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemBackgroundColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxColour rtn = pThis->GetEntity()->GetItemBackgroundColour(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wx_TreeItemData *rtn = dynamic_cast<wx_TreeItemData *>(pThis->GetEntity()->GetItemData(*item));
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_TreeItemData(
									new wx_TreeItemData(*rtn), NULL, OwnerTrue));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_TreeCtrl, GetGuraData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetGuraData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wx_TreeItemData *rtn = dynamic_cast<wx_TreeItemData *>(pThis->GetEntity()->GetItemData(*item));
	Value result;
	if (rtn != NULL) result = rtn->GetValue();
	return ReturnValue(env, sig, args, result);
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemChildren)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemIdValue cookie;
	wxTreeItemId rtn = pThis->GetEntity()->GetFirstChild(*item, cookie);
	Iterator_TreeCtrl_ItemChildren *pIterator = new Iterator_TreeCtrl_ItemChildren(
		Object_wx_TreeCtrl::Reference(pThis), *item, rtn, cookie);
	return ReturnIterator(env, sig, args, pIterator);
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemFont)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemFont)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxFont rtn = pThis->GetEntity()->GetItemFont(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemImage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "which", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemImage)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemIcon which = wxTreeItemIcon_Normal;
	if (args.IsValid(1)) which = static_cast<wxTreeItemIcon>(args.GetInt(1));
	int rtn = pThis->GetEntity()->GetItemImage(*item, which);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemText)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetItemText(*item);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemTextColour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemTextColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxColour rtn = pThis->GetEntity()->GetItemTextColour(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetLastChild)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetLastChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId rtn = pThis->GetEntity()->GetLastChild(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetNextChild)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetNextChild)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemIdValue cookie = reinterpret_cast<wxTreeItemIdValue>(args.GetInt(1));
	wxTreeItemId rtn = pThis->GetEntity()->GetNextChild(*item, cookie);
	return ReturnValue(env, sig, args, Value::CreateAsList(env,
		Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)),
		Value(reinterpret_cast<int>(cookie))));
}

Gura_DeclareMethod(wx_TreeCtrl, GetNextSibling)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetNextSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId rtn = pThis->GetEntity()->GetNextSibling(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetNextVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetNextVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId rtn = pThis->GetEntity()->GetNextVisible(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetItemParent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetItemParent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId rtn = pThis->GetEntity()->GetItemParent(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetPrevSibling)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetPrevSibling)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId rtn = pThis->GetEntity()->GetPrevSibling(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetPrevVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetPrevVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId rtn = pThis->GetEntity()->GetPrevVisible(*item);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetQuickBestSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetQuickBestSize)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetQuickBestSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, GetRootItem)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetRootItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId rtn = pThis->GetEntity()->GetRootItem();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetSelection)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, GetSelections)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetSelections)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayTreeItemIds selection;
	unsigned int rtn = pThis->GetEntity()->GetSelections(selection);
	Value result;
	ValueList &valList = result.InitAsList(env);
	foreach (wxArrayTreeItemIds, pTreeItemId, selection) {
		valList.push_back(Value(new Object_wx_TreeItemId(
						new wxTreeItemId(*pTreeItemId), NULL, OwnerTrue)));
	}
	return ReturnValue(env, sig, args, result);
}

Gura_DeclareMethod(wx_TreeCtrl, GetStateImageList)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, GetStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *rtn = (wxImageList *)pThis->GetEntity()->GetStateImageList();
	return ReturnValue(env, sig, args, Value(new Object_wx_ImageList(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_TreeCtrl, HitTest)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "point", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, HitTest)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *point = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int flags = args.GetInt(1);
	wxTreeItemId rtn = pThis->GetEntity()->HitTest(*point, flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, InsertItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "previous", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "selImage", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_TreeItemData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, InsertItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *parent = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId *previous = Object_wx_TreeItemId::GetObject(args, 1)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(2));
	int image = -1;
	if (args.IsValid(3)) image = args.GetInt(3);
	int selImage = -1;
	if (args.IsValid(4)) selImage = args.GetInt(4);
	wxTreeItemData *data = (wxTreeItemData *)(NULL);
	if (args.IsValid(5)) data = new wx_TreeItemData(*Object_wx_TreeItemData::GetObject(args, 5)->GetEntity());
	wxTreeItemId rtn = pThis->GetEntity()->InsertItem(*parent, *previous, text, image, selImage, data);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, InsertItemBefore)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "selImage", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_TreeItemData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, InsertItemBefore)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *parent = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	size_t before = args.GetSizeT(1);
	wxString text = wxString::FromUTF8(args.GetString(2));
	int image = -1;
	if (args.IsValid(3)) image = args.GetInt(3);
	int selImage = -1;
	if (args.IsValid(4)) selImage = args.GetInt(4);
	wxTreeItemData *data = (wxTreeItemData *)(NULL);
	if (args.IsValid(5)) data = new wx_TreeItemData(*Object_wx_TreeItemData::GetObject(args, 5)->GetEntity());
	wxTreeItemId rtn = pThis->GetEntity()->InsertItem(*parent, before, text, image, selImage, data);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, IsBold)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, IsBold)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsBold(*item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, IsEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, IsEmpty)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, IsExpanded)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, IsExpanded)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsExpanded(*item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, IsSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, IsSelected)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsSelected(*item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, IsVisible)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, IsVisible)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsVisible(*item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, ItemHasChildren)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, ItemHasChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->ItemHasChildren(*item);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, OnCompareItems)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item1", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, OnCompareItems)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item1 = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemId *item2 = Object_wx_TreeItemId::GetObject(args, 1)->GetEntity();
	int rtn = pThis->GetEntity()->wxTreeCtrl::OnCompareItems(*item1, *item2);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TreeCtrl, PrependItem)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "selImage", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "data", VTYPE_wx_TreeItemData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, PrependItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *parent = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	int image = -1;
	if (args.IsValid(2)) image = args.GetInt(2);
	int selImage = -1;
	if (args.IsValid(3)) selImage = args.GetInt(3);
	wxTreeItemData *data = (wxTreeItemData *)(NULL);
	if (args.IsValid(4)) data = new wx_TreeItemData(*Object_wx_TreeItemData::GetObject(args, 4)->GetEntity());
	wxTreeItemId rtn = pThis->GetEntity()->PrependItem(*parent, text, image, selImage, data);
	return ReturnValue(env, sig, args, Value(new Object_wx_TreeItemId(new wxTreeItemId(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TreeCtrl, ScrollTo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, ScrollTo)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->ScrollTo(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SelectItem)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "select", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, SelectItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool select = true;
	if (args.IsValid(1)) select = args.GetBoolean(1);
	pThis->GetEntity()->SelectItem(*item, select);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetIndent)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetIndent)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int indent = args.GetInt(0);
	pThis->GetEntity()->SetIndent(indent);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetSpacing)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetSpacing)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned int spacing = args.GetUInt(0);
	pThis->GetEntity()->SetSpacing(spacing);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once, FLAG_Nil);
}

Gura_ImplementMethod(wx_TreeCtrl, SetImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = NULL;
	if (args.IsValid(0)) imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemBackgroundColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemBackgroundColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxColour *col = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetItemBackgroundColour(*item, *col);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemBold)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "bold", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemBold)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool bold = true;
	if (args.IsValid(1)) bold = args.GetBoolean(1);
	pThis->GetEntity()->SetItemBold(*item, bold);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_TreeItemData, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxTreeItemData *data = data = new wx_TreeItemData(*Object_wx_TreeItemData::GetObject(args, 1)->GetEntity());
	pThis->GetEntity()->SetItemData(*item, data);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetGuraData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_any, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetGuraData)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wx_TreeItemData *data = new wx_TreeItemData(args.GetValue(1));
	pThis->GetEntity()->SetItemData(*item, data);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemDropHighlight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "highlight", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemDropHighlight)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool highlight = true;
	if (args.IsValid(1)) highlight = args.GetBoolean(1);
	pThis->GetEntity()->SetItemDropHighlight(*item, highlight);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemFont)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxFont *font = Object_wx_Font::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetItemFont(*item, *font);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemHasChildren)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "hasChildren", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemHasChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	bool hasChildren = true;
	if (args.IsValid(1)) hasChildren = args.GetBoolean(1);
	pThis->GetEntity()->SetItemHasChildren(*item, hasChildren);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemImage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "which", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemImage)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	int image = args.GetInt(1);
	wxTreeItemIcon which = wxTreeItemIcon_Normal;
	if (args.IsValid(2)) which = static_cast<wxTreeItemIcon>(args.GetInt(2));
	pThis->GetEntity()->SetItemImage(*item, image, which);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemText)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxString text = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetItemText(*item, text);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetItemTextColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetItemTextColour)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	wxColour *col = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetItemTextColour(*item, *col);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetQuickBestSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "quickBestSize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetQuickBestSize)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool quickBestSize = args.GetBoolean(0);
	pThis->GetEntity()->SetQuickBestSize(quickBestSize);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetStateImageList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "imageList", VTYPE_wx_ImageList, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetStateImageList)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxImageList *imageList = Object_wx_ImageList::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetStateImageList(imageList);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SetWindowStyle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SetWindowStyle)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long styles = args.GetLong(0);
	pThis->GetEntity()->SetWindowStyle(styles);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, SortChildren)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, SortChildren)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SortChildren(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, Toggle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, Toggle)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Toggle(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, ToggleItemSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, ToggleItemSelection)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->ToggleItemSelection(*item);
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, Unselect)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, Unselect)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Unselect();
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, UnselectAll)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TreeCtrl, UnselectAll)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->UnselectAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_TreeCtrl, UnselectItem)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_wx_TreeItemId, OCCUR_Once);
}

Gura_ImplementMethod(wx_TreeCtrl, UnselectItem)
{
	Object_wx_TreeCtrl *pThis = Object_wx_TreeCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTreeItemId *item = Object_wx_TreeItemId::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->UnselectItem(*item);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTreeCtrl
//----------------------------------------------------------------------------
Object_wx_TreeCtrl::~Object_wx_TreeCtrl()
{
}

Object *Object_wx_TreeCtrl::Clone() const
{
	return NULL;
}

String Object_wx_TreeCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TreeCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TreeCtrl::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnCompareItems);
	Gura_AssignWxStringValue(TreeCtrlNameStr);
	Gura_AssignFunction(TreeCtrlEmpty);
	Gura_AssignFunction(TreeCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxTreeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeCtrl)
{
	Gura_AssignMethod(wx_TreeCtrl, AddRoot);
	Gura_AssignMethod(wx_TreeCtrl, AppendItem);
	Gura_AssignMethod(wx_TreeCtrl, AssignImageList);
	Gura_AssignMethod(wx_TreeCtrl, AssignStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, Collapse);
	Gura_AssignMethod(wx_TreeCtrl, CollapseAll);
	Gura_AssignMethod(wx_TreeCtrl, CollapseAllChildren);
	Gura_AssignMethod(wx_TreeCtrl, CollapseAndReset);
	Gura_AssignMethod(wx_TreeCtrl, Delete);
	Gura_AssignMethod(wx_TreeCtrl, DeleteAllItems);
	Gura_AssignMethod(wx_TreeCtrl, DeleteChildren);
	Gura_AssignMethod(wx_TreeCtrl, EditLabel);
	Gura_AssignMethod(wx_TreeCtrl, EndEditLabel);
	Gura_AssignMethod(wx_TreeCtrl, EnsureVisible);
	Gura_AssignMethod(wx_TreeCtrl, Expand);
	Gura_AssignMethod(wx_TreeCtrl, ExpandAll);
	Gura_AssignMethod(wx_TreeCtrl, ExpandAllChildren);
	Gura_AssignMethod(wx_TreeCtrl, GetBoundingRect);
	Gura_AssignMethod(wx_TreeCtrl, GetChildrenCount);
	Gura_AssignMethod(wx_TreeCtrl, GetCount);
	Gura_AssignMethod(wx_TreeCtrl, GetEditControl);
	Gura_AssignMethod(wx_TreeCtrl, GetFirstChild);
	Gura_AssignMethod(wx_TreeCtrl, GetFirstVisibleItem);
	Gura_AssignMethod(wx_TreeCtrl, GetImageList);
	Gura_AssignMethod(wx_TreeCtrl, GetIndent);
	Gura_AssignMethod(wx_TreeCtrl, GetSpacing);
	Gura_AssignMethod(wx_TreeCtrl, GetItemBackgroundColour);
	Gura_AssignMethod(wx_TreeCtrl, GetItemData);
	Gura_AssignMethod(wx_TreeCtrl, GetGuraData);
	Gura_AssignMethod(wx_TreeCtrl, GetItemChildren);
	Gura_AssignMethod(wx_TreeCtrl, GetItemFont);
	Gura_AssignMethod(wx_TreeCtrl, GetItemImage);
	Gura_AssignMethod(wx_TreeCtrl, GetItemText);
	Gura_AssignMethod(wx_TreeCtrl, GetItemTextColour);
	Gura_AssignMethod(wx_TreeCtrl, GetLastChild);
	Gura_AssignMethod(wx_TreeCtrl, GetNextChild);
	Gura_AssignMethod(wx_TreeCtrl, GetNextSibling);
	Gura_AssignMethod(wx_TreeCtrl, GetNextVisible);
	Gura_AssignMethod(wx_TreeCtrl, GetItemParent);
	Gura_AssignMethod(wx_TreeCtrl, GetPrevSibling);
	Gura_AssignMethod(wx_TreeCtrl, GetPrevVisible);
	Gura_AssignMethod(wx_TreeCtrl, GetQuickBestSize);
	Gura_AssignMethod(wx_TreeCtrl, GetRootItem);
	Gura_AssignMethod(wx_TreeCtrl, GetSelection);
	Gura_AssignMethod(wx_TreeCtrl, GetSelections);
	Gura_AssignMethod(wx_TreeCtrl, GetStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, HitTest);
	Gura_AssignMethod(wx_TreeCtrl, InsertItem);
	Gura_AssignMethod(wx_TreeCtrl, InsertItemBefore);
	Gura_AssignMethod(wx_TreeCtrl, IsBold);
	Gura_AssignMethod(wx_TreeCtrl, IsEmpty);
	Gura_AssignMethod(wx_TreeCtrl, IsExpanded);
	Gura_AssignMethod(wx_TreeCtrl, IsSelected);
	Gura_AssignMethod(wx_TreeCtrl, IsVisible);
	Gura_AssignMethod(wx_TreeCtrl, ItemHasChildren);
	Gura_AssignMethod(wx_TreeCtrl, OnCompareItems);
	Gura_AssignMethod(wx_TreeCtrl, PrependItem);
	Gura_AssignMethod(wx_TreeCtrl, ScrollTo);
	Gura_AssignMethod(wx_TreeCtrl, SelectItem);
	Gura_AssignMethod(wx_TreeCtrl, SetIndent);
	Gura_AssignMethod(wx_TreeCtrl, SetSpacing);
	Gura_AssignMethod(wx_TreeCtrl, SetImageList);
	Gura_AssignMethod(wx_TreeCtrl, SetItemBackgroundColour);
	Gura_AssignMethod(wx_TreeCtrl, SetItemBold);
	Gura_AssignMethod(wx_TreeCtrl, SetItemData);
	Gura_AssignMethod(wx_TreeCtrl, SetGuraData);
	Gura_AssignMethod(wx_TreeCtrl, SetItemDropHighlight);
	Gura_AssignMethod(wx_TreeCtrl, SetItemFont);
	Gura_AssignMethod(wx_TreeCtrl, SetItemHasChildren);
	Gura_AssignMethod(wx_TreeCtrl, SetItemImage);
	Gura_AssignMethod(wx_TreeCtrl, SetItemText);
	Gura_AssignMethod(wx_TreeCtrl, SetItemTextColour);
	Gura_AssignMethod(wx_TreeCtrl, SetQuickBestSize);
	Gura_AssignMethod(wx_TreeCtrl, SetStateImageList);
	Gura_AssignMethod(wx_TreeCtrl, SetWindowStyle);
	Gura_AssignMethod(wx_TreeCtrl, SortChildren);
	Gura_AssignMethod(wx_TreeCtrl, Toggle);
	Gura_AssignMethod(wx_TreeCtrl, ToggleItemSelection);
	Gura_AssignMethod(wx_TreeCtrl, Unselect);
	Gura_AssignMethod(wx_TreeCtrl, UnselectAll);
	Gura_AssignMethod(wx_TreeCtrl, UnselectItem);
}

Gura_ImplementDescendantCreator(wx_TreeCtrl)
{
	return new Object_wx_TreeCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
