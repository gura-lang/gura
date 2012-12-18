//----------------------------------------------------------------------------
// wxChoice
// extracted from choice.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Choice: public wxChoice, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Choice *_pObj;
public:
	inline wx_Choice() : wxChoice(), _sig(NULL), _pObj(NULL) {}
	//inline wx_Choice(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style, const wxValidator& validator, const wxString& name) : wxChoice(parent, id, pos, size, n, choices[], style, validator, name), _sig(NULL), _pObj(NULL) {}
	inline wx_Choice(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator, const wxString& name) : wxChoice(parent, id, pos, size, choices, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_Choice();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Choice *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Choice::~wx_Choice()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Choice::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxChoice
//----------------------------------------------------------------------------
Gura_DeclareFunction(ChoiceEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Choice));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ChoiceEmpty)
{
	wx_Choice *pEntity = new wx_Choice();
	Object_wx_Choice *pObj = Object_wx_Choice::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Choice(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Choice)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Choice));
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

Gura_ImplementFunction(Choice)
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
	wxString name = wxT("choice");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	wx_Choice *pEntity = new wx_Choice(parent, id, *pos, *size, *choices, style, *validator, name);
	Object_wx_Choice *pObj = Object_wx_Choice::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Choice(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Choice, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Choice, Create)
{
	Object_wx_Choice *pSelf = Object_wx_Choice::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	std::auto_ptr<wxArrayString> choices(CreateArrayString(args.GetList(4)));
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("choice");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pSelf->GetEntity()->Create(parent, id, *pos, *size, *choices, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Choice, GetColumns)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Choice, GetColumns)
{
	Object_wx_Choice *pSelf = Object_wx_Choice::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetColumns();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Choice, GetCurrentSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Choice, GetCurrentSelection)
{
	Object_wx_Choice *pSelf = Object_wx_Choice::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCurrentSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Choice, SetColumns)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Choice, SetColumns)
{
	Object_wx_Choice *pSelf = Object_wx_Choice::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int n = 1;
	if (args.IsValid(0)) n = args.GetInt(0);
	pSelf->GetEntity()->SetColumns(n);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxChoice
//----------------------------------------------------------------------------
Object_wx_Choice::~Object_wx_Choice()
{
}

Object *Object_wx_Choice::Clone() const
{
	return NULL;
}

String Object_wx_Choice::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Choice:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Choice::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignWxStringValue(ChoiceNameStr);
	Gura_AssignFunction(ChoiceEmpty);
	Gura_AssignFunction(Choice);
}

//----------------------------------------------------------------------------
// Class implementation for wxChoice
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choice)
{
	Gura_AssignMethod(wx_Choice, Create);
	Gura_AssignMethod(wx_Choice, GetColumns);
	Gura_AssignMethod(wx_Choice, GetCurrentSelection);
	Gura_AssignMethod(wx_Choice, SetColumns);
}

Gura_ImplementDescendantCreator(wx_Choice)
{
	return new Object_wx_Choice((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
