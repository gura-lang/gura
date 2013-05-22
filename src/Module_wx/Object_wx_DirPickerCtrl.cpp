//----------------------------------------------------------------------------
// wxDirPickerCtrl
// extracted from dirpicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DirPickerCtrl: public wxDirPickerCtrl, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DirPickerCtrl *_pObj;
public:
	inline wx_DirPickerCtrl(wxWindow * parent, wxWindowID id, const wxString& path, const wxString& message, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxDirPickerCtrl(parent, id, path, message, pos, size, style, validator, name), _sig(NULL), _pObj(NULL) {}
	~wx_DirPickerCtrl();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DirPickerCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DirPickerCtrl::~wx_DirPickerCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DirPickerCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDirPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(DirPickerCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DirPickerCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DirPickerCtrl)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString path = wxEmptyString;
	if (args.IsValid(2)) path = wxString::FromUTF8(args.GetString(2));
	wxString message = wxT("Select a folder");
	if (args.IsValid(3)) message = wxString::FromUTF8(args.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) size = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = wxDIRP_DEFAULT_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("dirpickerctrl");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_DirPickerCtrl *pEntity = new wx_DirPickerCtrl(parent, id, path, message, *pos, *size, style, *validator, name);
	Object_wx_DirPickerCtrl *pObj = Object_wx_DirPickerCtrl::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DirPickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DirPickerCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "path", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirPickerCtrl, Create)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString path = wxEmptyString;
	if (args.IsValid(2)) path = wxString::FromUTF8(args.GetString(2));
	wxString message = wxT("Select a folder");
	if (args.IsValid(3)) message = wxString::FromUTF8(args.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(4)) pos = Object_wx_Point::GetObject(args, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(5)) size = Object_wx_Size::GetObject(args, 5)->GetEntity();
	long style = wxDIRP_DEFAULT_STYLE;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("dirpickerctrl");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, path, message, *pos, *size, style, *validator, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DirPickerCtrl, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirPickerCtrl, GetPath)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DirPickerCtrl, SetPath)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, SetPath)
{
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString dirname = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetPath(dirname);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDirPickerCtrl
//----------------------------------------------------------------------------
Object_wx_DirPickerCtrl::~Object_wx_DirPickerCtrl()
{
}

Object *Object_wx_DirPickerCtrl::Clone() const
{
	return NULL;
}

String Object_wx_DirPickerCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DirPickerCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DirPickerCtrl::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(DirPickerCtrl);
}

//----------------------------------------------------------------------------
// Class implementation for wxDirPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirPickerCtrl)
{
	Gura_AssignMethod(wx_DirPickerCtrl, Create);
	Gura_AssignMethod(wx_DirPickerCtrl, GetPath);
	Gura_AssignMethod(wx_DirPickerCtrl, SetPath);
}

Gura_ImplementDescendantCreator(wx_DirPickerCtrl)
{
	return new Object_wx_DirPickerCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
