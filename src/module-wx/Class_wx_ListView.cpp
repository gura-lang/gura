//----------------------------------------------------------------------------
// wxListView
// extracted from listview.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListView: public wxListView, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ListView *_pObj;
public:
	inline wx_ListView(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxListView(parent, id, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_ListView();
	inline void AssocWithGura(Object_wx_ListView *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListView::~wx_ListView()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ListView::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListView
//----------------------------------------------------------------------------
Gura_DeclareFunction(ListView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ListView));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ListView)
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
	wx_ListView *pEntity = new wx_ListView(parent, id, *pos, *size, style, *validator, name);
	Object_wx_ListView *pObj = Object_wx_ListView::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListView(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_ListView, ClearColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, ClearColumnImage)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->ClearColumnImage(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListView, Focus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, Focus)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	pThis->GetEntity()->Focus(index);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListView, GetFirstSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetFirstSelected)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetFirstSelected();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, GetFocusedItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetFocusedItem)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->GetFocusedItem();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, GetNextSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetNextSelected)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long item = args.GetLong(0);
	long rtn = pThis->GetEntity()->GetNextSelected(item);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, IsSelected)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long index = args.GetLong(0);
	bool rtn = pThis->GetEntity()->IsSelected(index);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "on", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, Select)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool on = true;
	if (args.IsValid(0)) on = args.GetBoolean(0);
	pThis->GetEntity()->Select(on);
	return Value::Null;
}

Gura_DeclareMethod(wx_ListView, SetColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, SetColumnImage)
{
	Object_wx_ListView *pThis = Object_wx_ListView::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int image = args.GetInt(1);
	pThis->GetEntity()->SetColumnImage(col, image);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxListView
//----------------------------------------------------------------------------
Object_wx_ListView::~Object_wx_ListView()
{
}

Object *Object_wx_ListView::Clone() const
{
	return nullptr;
}

String Object_wx_ListView::ToString(bool exprFlag)
{
	String rtn("<wx.ListView:");
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
// Class implementation for wxListView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListView)
{
	Gura_AssignFunction(ListView);
	Gura_AssignMethod(wx_ListView, ClearColumnImage);
	Gura_AssignMethod(wx_ListView, Focus);
	Gura_AssignMethod(wx_ListView, GetFirstSelected);
	Gura_AssignMethod(wx_ListView, GetFocusedItem);
	Gura_AssignMethod(wx_ListView, GetNextSelected);
	Gura_AssignMethod(wx_ListView, IsSelected);
	Gura_AssignMethod(wx_ListView, Select);
	Gura_AssignMethod(wx_ListView, SetColumnImage);
}

Gura_ImplementDescendantCreator(wx_ListView)
{
	return new Object_wx_ListView((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
