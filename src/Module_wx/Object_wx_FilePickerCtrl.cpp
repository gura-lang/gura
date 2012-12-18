//----------------------------------------------------------------------------
// wxFilePickerCtrl
// extracted from filepicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FilePickerCtrl: public wxFilePickerCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FilePickerCtrl *_pObj;
public:
	inline wx_FilePickerCtrl(wxWindow * parent, wxWindowID id, const wxString& path, const wxString& message, const wxString& wildcard, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxFilePickerCtrl(parent, id, path, message, wildcard, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_FilePickerCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FilePickerCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FilePickerCtrl::~wx_FilePickerCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FilePickerCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(FilePickerCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString path = wxEmptyString;
	if (args.IsValid(2)) path = wxString::FromUTF8(args.GetString(2));
	wxString message = wxT("Select a file");
	if (args.IsValid(3)) message = wxString::FromUTF8(args.GetString(3));
	wxString wildcard = wxT("*.*");
	if (args.IsValid(4)) wildcard = wxString::FromUTF8(args.GetString(4));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) pos = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(6)) size = Object_wx_Size::GetObject(args, 6)->GetEntity();
	long style = wxFLP_DEFAULT_STYLE;
	if (args.IsValid(7)) style = args.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(8)) validator = Object_wx_Validator::GetObject(args, 8)->GetEntity();
	wxString name = wxT("filepickerctrl");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	wx_FilePickerCtrl *pEntity = new wx_FilePickerCtrl(parent, id, path, message, wildcard, *pos, *size, style, *validator, name);
	Object_wx_FilePickerCtrl *pObj = Object_wx_FilePickerCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FilePickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_FilePickerCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_FilePickerCtrl *pSelf = Object_wx_FilePickerCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString path = wxEmptyString;
	if (args.IsValid(2)) path = wxString::FromUTF8(args.GetString(2));
	wxString message = wxT("Select a file");
	if (args.IsValid(3)) message = wxString::FromUTF8(args.GetString(3));
	wxString wildcard = wxT("*.*");
	if (args.IsValid(4)) wildcard = wxString::FromUTF8(args.GetString(4));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) pos = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(6)) size = Object_wx_Size::GetObject(args, 6)->GetEntity();
	long style = wxFLP_DEFAULT_STYLE;
	if (args.IsValid(7)) style = args.GetLong(7);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(8)) validator = Object_wx_Validator::GetObject(args, 8)->GetEntity();
	wxString name = wxT("filepickerctrl");
	if (args.IsValid(9)) name = wxString::FromUTF8(args.GetString(9));
	bool rtn = pSelf->GetEntity()->Create(parent, id, path, message, wildcard, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FilePickerCtrl, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilePickerCtrl, GetPath)
{
	Object_wx_FilePickerCtrl *pSelf = Object_wx_FilePickerCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FilePickerCtrl, SetPath)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilePickerCtrl, SetPath)
{
	Object_wx_FilePickerCtrl *pSelf = Object_wx_FilePickerCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString filename = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetPath(filename);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Object_wx_FilePickerCtrl::~Object_wx_FilePickerCtrl()
{
}

Object *Object_wx_FilePickerCtrl::Clone() const
{
	return NULL;
}

String Object_wx_FilePickerCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FilePickerCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FilePickerCtrl::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(FilePickerCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilePickerCtrl)
{
	Gura_AssignMethod(wx_FilePickerCtrl, Create);
	Gura_AssignMethod(wx_FilePickerCtrl, GetPath);
	Gura_AssignMethod(wx_FilePickerCtrl, SetPath);
}

Gura_ImplementDescendantCreator(wx_FilePickerCtrl)
{
	return new Object_wx_FilePickerCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
