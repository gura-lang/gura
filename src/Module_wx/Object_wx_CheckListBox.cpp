//----------------------------------------------------------------------------
// wxCheckListBox
// extracted from checklst.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CheckListBox: public wxCheckListBox, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_CheckListBox *_pObj;
public:
	inline wx_CheckListBox() : wxCheckListBox(), _sig(NULL), _pObj(NULL) {}
	//inline wx_CheckListBox(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style, const wxValidator& validator, const wxString& name) : wxCheckListBox(parent, id, pos, size, n, choices[], style, validator, name), _sig(NULL), _pObj(NULL) {}
	inline wx_CheckListBox(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator, const wxString& name) : wxCheckListBox(parent, id, pos, size, choices, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_CheckListBox();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_CheckListBox *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CheckListBox::~wx_CheckListBox()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_CheckListBox::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCheckListBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(CheckListBoxEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CheckListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CheckListBoxEmpty)
{
	wx_CheckListBox *pEntity = new wx_CheckListBox();
	Object_wx_CheckListBox *pObj = Object_wx_CheckListBox::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CheckListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(CheckListBox)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CheckListBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_ZeroOrOnce, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CheckListBox)
{
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	std::auto_ptr<wxArrayString> choices;
	if (args.IsValid(4)) {
		choices.reset(CreateArrayString(args.GetList(4)));
	} else {
		choices.reset(new wxArrayString());
	}
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("listBox");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_CheckListBox *pEntity = new wx_CheckListBox(parent, id, *pos, *size, *choices, style, *validator, name);
	Object_wx_CheckListBox *pObj = Object_wx_CheckListBox::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_CheckListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_CheckListBox, Check)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "check", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CheckListBox, Check)
{
	Object_wx_CheckListBox *pSelf = Object_wx_CheckListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int item = args.GetInt(0);
	bool check = true;
	if (args.IsValid(1)) check = args.GetBoolean(1);
	pSelf->GetEntity()->Check(item, check);
	return Value::Null;
}

Gura_DeclareMethod(wx_CheckListBox, IsChecked)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CheckListBox, IsChecked)
{
	Object_wx_CheckListBox *pSelf = Object_wx_CheckListBox::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned item = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->IsChecked(item);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCheckListBox
//----------------------------------------------------------------------------
Object_wx_CheckListBox::~Object_wx_CheckListBox()
{
}

Object *Object_wx_CheckListBox::Clone() const
{
	return NULL;
}

String Object_wx_CheckListBox::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.CheckListBox:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_CheckListBox::OnModuleEntry(Environment &env, Signal sig)
{
	//Gura_AssignWxStringValue(CheckListBoxNameStr);
	Gura_AssignFunction(CheckListBoxEmpty);
	Gura_AssignFunction(CheckListBox);
}

//----------------------------------------------------------------------------
// Class implementation for wxCheckListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CheckListBox)
{
	Gura_AssignMethod(wx_CheckListBox, Check);
	Gura_AssignMethod(wx_CheckListBox, IsChecked);
}

Gura_ImplementDescendantCreator(wx_CheckListBox)
{
	return new Object_wx_CheckListBox((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
