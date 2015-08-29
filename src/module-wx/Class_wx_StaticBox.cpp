//----------------------------------------------------------------------------
// wxStaticBox
// extracted from statbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StaticBox: public wxStaticBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StaticBox *_pObj;
public:
	inline wx_StaticBox() : wxStaticBox(), _pObj(nullptr) {}
	inline wx_StaticBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxStaticBox(parent, id, label, pos, size, style, name), _pObj(nullptr) {}
	~wx_StaticBox();
	inline void AssocWithGura(Object_wx_StaticBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StaticBox::~wx_StaticBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StaticBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(StaticBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StaticBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticBoxEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_StaticBox *pEntity = new wx_StaticBox();
	Object_wx_StaticBox *pObj = Object_wx_StaticBox::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_StaticBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(StaticBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StaticBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticBox)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString label = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = 0;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("staticBox");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_StaticBox *pEntity = new wx_StaticBox(parent, id, label, *pos, *size, style, name);
	Object_wx_StaticBox *pObj = Object_wx_StaticBox::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_StaticBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_StaticBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_StaticBox *pThis = Object_wx_StaticBox::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString label = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = 0;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("staticBox");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, label, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxStaticBox
//----------------------------------------------------------------------------
Object_wx_StaticBox::~Object_wx_StaticBox()
{
}

Object *Object_wx_StaticBox::Clone() const
{
	return nullptr;
}

String Object_wx_StaticBox::ToString(bool exprFlag)
{
	String rtn("<wx.StaticBox:");
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
// Class implementation for wxStaticBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBox)
{
	Gura_AssignFunction(StaticBoxEmpty);
	Gura_AssignFunction(StaticBox);
	Gura_AssignMethod(wx_StaticBox, Create);
}

Gura_ImplementDescendantCreator(wx_StaticBox)
{
	return new Object_wx_StaticBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
