//----------------------------------------------------------------------------
// wxChoice
// extracted from choice.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Choice: public wxChoice, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Choice *_pObj;
public:
	inline wx_Choice() : wxChoice(), _pObj(nullptr) {}
	//inline wx_Choice(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style, const wxValidator& validator, const wxString& name) : wxChoice(parent, id, pos, size, n, choices[], style, validator, name), _pObj(nullptr) {}
	inline wx_Choice(wxWindow * parent, wxWindowID id, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator, const wxString& name) : wxChoice(parent, id, pos, size, choices, style, validator, name), _pObj(nullptr) {}
	~wx_Choice();
	inline void AssocWithGura(Object_wx_Choice *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Choice::~wx_Choice()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Choice::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxChoice
//----------------------------------------------------------------------------
Gura_DeclareFunction(ChoiceEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Choice));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ChoiceEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Choice *pEntity = new wx_Choice();
	Object_wx_Choice *pObj = Object_wx_Choice::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Choice(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(Choice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	std::unique_ptr<wxArrayString> choices;
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
	Object_wx_Choice *pObj = Object_wx_Choice::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Choice(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_Choice, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(4)));
	long style = 0;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("choice");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, *choices, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Choice, GetColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Choice, GetColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetColumns();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Choice, GetCurrentSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Choice, GetCurrentSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCurrentSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Choice, SetColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Choice, SetColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_Choice *pThis = Object_wx_Choice::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = 1;
	if (args.IsValid(0)) n = args.GetInt(0);
	pThis->GetEntity()->SetColumns(n);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxChoice
//----------------------------------------------------------------------------
Object_wx_Choice::~Object_wx_Choice()
{
}

Object *Object_wx_Choice::Clone() const
{
	return nullptr;
}

String Object_wx_Choice::ToString(bool exprFlag)
{
	String rtn("<wx.Choice:");
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
// Class implementation for wxChoice
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choice)
{
	Gura_AssignWxStringValue(ChoiceNameStr);
	Gura_AssignFunction(ChoiceEmpty);
	Gura_AssignFunction(Choice);
	Gura_AssignMethod(wx_Choice, Create);
	Gura_AssignMethod(wx_Choice, GetColumns);
	Gura_AssignMethod(wx_Choice, GetCurrentSelection);
	Gura_AssignMethod(wx_Choice, SetColumns);
}

Gura_ImplementDescendantCreator(wx_Choice)
{
	return new Object_wx_Choice((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
