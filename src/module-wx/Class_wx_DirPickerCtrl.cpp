//----------------------------------------------------------------------------
// wxDirPickerCtrl
// extracted from dirpicker.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DirPickerCtrl: public wxDirPickerCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DirPickerCtrl *_pObj;
public:
	inline wx_DirPickerCtrl(wxWindow * parent, wxWindowID id, const wxString& path, const wxString& message, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxDirPickerCtrl(parent, id, path, message, pos, size, style, validator, name), _pObj(nullptr) {}
	~wx_DirPickerCtrl();
	inline void AssocWithGura(Object_wx_DirPickerCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DirPickerCtrl::~wx_DirPickerCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DirPickerCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDirPickerCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(DirPickerCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString path = wxEmptyString;
	if (arg.IsValid(2)) path = wxString::FromUTF8(arg.GetString(2));
	wxString message = wxT("Select a folder");
	if (arg.IsValid(3)) message = wxString::FromUTF8(arg.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(4)) pos = Object_wx_Point::GetObject(arg, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(5)) size = Object_wx_Size::GetObject(arg, 5)->GetEntity();
	long style = wxDIRP_DEFAULT_STYLE;
	if (arg.IsValid(6)) style = arg.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(7)) validator = Object_wx_Validator::GetObject(arg, 7)->GetEntity();
	wxString name = wxT("dirpickerctrl");
	if (arg.IsValid(8)) name = wxString::FromUTF8(arg.GetString(8));
	wx_DirPickerCtrl *pEntity = new wx_DirPickerCtrl(parent, id, path, message, *pos, *size, style, *validator, name);
	Object_wx_DirPickerCtrl *pObj = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DirPickerCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_DirPickerCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString path = wxEmptyString;
	if (arg.IsValid(2)) path = wxString::FromUTF8(arg.GetString(2));
	wxString message = wxT("Select a folder");
	if (arg.IsValid(3)) message = wxString::FromUTF8(arg.GetString(3));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(4)) pos = Object_wx_Point::GetObject(arg, 4)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(5)) size = Object_wx_Size::GetObject(arg, 5)->GetEntity();
	long style = wxDIRP_DEFAULT_STYLE;
	if (arg.IsValid(6)) style = arg.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(7)) validator = Object_wx_Validator::GetObject(arg, 7)->GetEntity();
	wxString name = wxT("dirpickerctrl");
	if (arg.IsValid(8)) name = wxString::FromUTF8(arg.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, path, message, *pos, *size, style, *validator, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DirPickerCtrl, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DirPickerCtrl, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DirPickerCtrl, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dirname", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirPickerCtrl, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_DirPickerCtrl *pThis = Object_wx_DirPickerCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString dirname = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->SetPath(dirname);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDirPickerCtrl
//----------------------------------------------------------------------------
Object_wx_DirPickerCtrl::~Object_wx_DirPickerCtrl()
{
}

Object *Object_wx_DirPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DirPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DirPickerCtrl:");
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
// Class implementation for wxDirPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirPickerCtrl)
{
	Gura_AssignFunction(DirPickerCtrl);
	Gura_AssignMethod(wx_DirPickerCtrl, Create);
	Gura_AssignMethod(wx_DirPickerCtrl, GetPath);
	Gura_AssignMethod(wx_DirPickerCtrl, SetPath);
}

Gura_ImplementDescendantCreator(wx_DirPickerCtrl)
{
	return new Object_wx_DirPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
