//----------------------------------------------------------------------------
// wxSimpleHtmlListBox
// extracted from htmllbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SimpleHtmlListBox: public wxSimpleHtmlListBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SimpleHtmlListBox *_pObj;
public:
	inline wx_SimpleHtmlListBox() : wxSimpleHtmlListBox(), _pObj(nullptr) {}
	~wx_SimpleHtmlListBox();
	inline void AssocWithGura(Object_wx_SimpleHtmlListBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SimpleHtmlListBox::~wx_SimpleHtmlListBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SimpleHtmlListBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SimpleHtmlListBox, wxHtmlListBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "choices[]", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_SimpleHtmlListBox, wxHtmlListBox)
{
#if 0
	Object_wx_SimpleHtmlListBox *pThis = Object_wx_SimpleHtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	int n = 0;
	if (args.IsValid(4)) n = args.GetInt(4);
	wxString choices[] = nullptr;
	if (args.IsValid(5)) choices[] = wxString::FromUTF8(args.GetString(5));
	long style = wxHLB_DEFAULT_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("simpleHtmlListBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	pThis->GetEntity()->wxHtmlListBox(parent, id, *pos, *size, n, choices[], style, *validator, name);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SimpleHtmlListBox, wxHtmlListBox_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_SimpleHtmlListBox, wxHtmlListBox_1)
{
#if 0
	Object_wx_SimpleHtmlListBox *pThis = Object_wx_SimpleHtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(4)));
	long style = wxHLB_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("simpleHtmlListBox");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	pThis->GetEntity()->wxHtmlListBox(parent, id, *pos, *size, *choices, style, *validator, name);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(SimpleHtmlListBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SimpleHtmlListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SimpleHtmlListBoxEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_SimpleHtmlListBox *pEntity = new wx_SimpleHtmlListBox();
	Object_wx_SimpleHtmlListBox *pObj = Object_wx_SimpleHtmlListBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SimpleHtmlListBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_SimpleHtmlListBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "choices[]", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SimpleHtmlListBox, Create)
{
#if 0
	Object_wx_SimpleHtmlListBox *pThis = Object_wx_SimpleHtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	int n = args.GetInt(4);
	wxString choices[] = nullptr;
	if (args.IsValid(5)) choices[] = wxString::FromUTF8(args.GetString(5));
	long style = wxHLB_DEFAULT_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("simpleHtmlListBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, n, choices[], style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SimpleHtmlListBox, Create_1)
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

Gura_ImplementMethod(wx_SimpleHtmlListBox, Create_1)
{
	Object_wx_SimpleHtmlListBox *pThis = Object_wx_SimpleHtmlListBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(4)));
	long style = wxHLB_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(6)) validator = Object_wx_Validator::GetObject(args, 6)->GetEntity();
	wxString name = wxT("simpleHtmlListBox");
	if (args.IsValid(7)) name = wxString::FromUTF8(args.GetString(7));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, *choices, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Object_wx_SimpleHtmlListBox::~Object_wx_SimpleHtmlListBox()
{
}

Object *Object_wx_SimpleHtmlListBox::Clone() const
{
	return nullptr;
}

String Object_wx_SimpleHtmlListBox::ToString(bool exprFlag)
{
	String rtn("<wx.SimpleHtmlListBox:");
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
// Class implementation for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SimpleHtmlListBox)
{
	Gura_AssignFunction(SimpleHtmlListBoxEmpty);
	Gura_AssignMethod(wx_SimpleHtmlListBox, wxHtmlListBox);
	Gura_AssignMethod(wx_SimpleHtmlListBox, wxHtmlListBox_1);
	Gura_AssignMethod(wx_SimpleHtmlListBox, Create);
	Gura_AssignMethod(wx_SimpleHtmlListBox, Create_1);
}

Gura_ImplementDescendantCreator(wx_SimpleHtmlListBox)
{
	return new Object_wx_SimpleHtmlListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
