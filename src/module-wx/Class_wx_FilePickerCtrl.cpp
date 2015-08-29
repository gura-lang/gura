//----------------------------------------------------------------------------
// wxFilePickerCtrl
// extracted from filepicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FilePickerCtrl: public wxFilePickerCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FilePickerCtrl *_pObj;
public:
	inline wx_FilePickerCtrl(wxWindow * parent, wxWindowID id, const wxString& path, const wxString& message, const wxString& wildcard, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxFilePickerCtrl(parent, id, path, message, wildcard, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_FilePickerCtrl();
	inline void AssocWithGura(Object_wx_FilePickerCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FilePickerCtrl::~wx_FilePickerCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FilePickerCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(FilePickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FilePickerCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FilePickerCtrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString path = wxEmptyString;
	if (arg.IsValid(2)) path = wxString::FromUTF8(arg.GetString(2));
	wxString message = wxT("Select a file");
	if (arg.IsValid(3)) message = wxString::FromUTF8(arg.GetString(3));
	wxString wildcard = wxT("*.*");
	if (arg.IsValid(4)) wildcard = wxString::FromUTF8(arg.GetString(4));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(5)) pos = Object_wx_Point::GetObject(arg, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(6)) size = Object_wx_Size::GetObject(arg, 6)->GetEntity();
	long style = wxFLP_DEFAULT_STYLE;
	if (arg.IsValid(7)) style = arg.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(8)) validator = Object_wx_Validator::GetObject(arg, 8)->GetEntity();
	wxString name = wxT("filepickerctrl");
	if (arg.IsValid(9)) name = wxString::FromUTF8(arg.GetString(9));
	wx_FilePickerCtrl *pEntity = new wx_FilePickerCtrl(parent, id, path, message, wildcard, *pos, *size, style, *validator, name);
	Object_wx_FilePickerCtrl *pObj = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_FilePickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_FilePickerCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilePickerCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString path = wxEmptyString;
	if (arg.IsValid(2)) path = wxString::FromUTF8(arg.GetString(2));
	wxString message = wxT("Select a file");
	if (arg.IsValid(3)) message = wxString::FromUTF8(arg.GetString(3));
	wxString wildcard = wxT("*.*");
	if (arg.IsValid(4)) wildcard = wxString::FromUTF8(arg.GetString(4));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(5)) pos = Object_wx_Point::GetObject(arg, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(6)) size = Object_wx_Size::GetObject(arg, 6)->GetEntity();
	long style = wxFLP_DEFAULT_STYLE;
	if (arg.IsValid(7)) style = arg.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(8)) validator = Object_wx_Validator::GetObject(arg, 8)->GetEntity();
	wxString name = wxT("filepickerctrl");
	if (arg.IsValid(9)) name = wxString::FromUTF8(arg.GetString(9));
	bool rtn = pThis->GetEntity()->Create(parent, id, path, message, wildcard, *pos, *size, style, *validator, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_FilePickerCtrl, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilePickerCtrl, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FilePickerCtrl, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FilePickerCtrl *pThis = Object_wx_FilePickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString filename = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetPath(filename);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Object_wx_FilePickerCtrl::~Object_wx_FilePickerCtrl()
{
}

Object *Object_wx_FilePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FilePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FilePickerCtrl:");
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
// Class implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilePickerCtrl)
{
	Gura_AssignFunction(FilePickerCtrl);
	Gura_AssignMethod(wx_FilePickerCtrl, Create);
	Gura_AssignMethod(wx_FilePickerCtrl, GetPath);
	Gura_AssignMethod(wx_FilePickerCtrl, SetPath);
}

Gura_ImplementDescendantCreator(wx_FilePickerCtrl)
{
	return new Object_wx_FilePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
