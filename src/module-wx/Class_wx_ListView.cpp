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
	wx_ListView *pEntity = new wx_ListView(parent, id, *pos, *size, style, *validator, name);
	Object_wx_ListView *pObj = Object_wx_ListView::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ListView(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_ListView, ClearColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, ClearColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	pThis->GetEntity()->ClearColumnImage(col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, Focus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, Focus)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long index = arg.GetLong(0);
	pThis->GetEntity()->Focus(index);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, GetFirstSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetFirstSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetFirstSelected();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, GetFocusedItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetFocusedItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->GetFocusedItem();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, GetNextSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, GetNextSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long item = arg.GetLong(0);
	long rtn = pThis->GetEntity()->GetNextSelected(item);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, IsSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long index = arg.GetLong(0);
	bool rtn = pThis->GetEntity()->IsSelected(index);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ListView, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "on", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ListView, Select)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool on = true;
	if (arg.IsValid(0)) on = arg.GetBoolean(0);
	pThis->GetEntity()->Select(on);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListView, SetColumnImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListView, SetColumnImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_ListView *pThis = Object_wx_ListView::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	int image = arg.GetInt(1);
	pThis->GetEntity()->SetColumnImage(col, image);
	return Value::Nil;
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
