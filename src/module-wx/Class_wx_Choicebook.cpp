//----------------------------------------------------------------------------
// wxChoicebook
// extracted from choicebk.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Choicebook: public wxChoicebook, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Choicebook *_pObj;
public:
	inline wx_Choicebook() : wxChoicebook(), _pObj(nullptr) {}
	inline wx_Choicebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxChoicebook(parent, id, pos, size, style, name), _pObj(nullptr) {}
	~wx_Choicebook();
	inline void AssocWithGura(Object_wx_Choicebook *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Choicebook::~wx_Choicebook()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Choicebook::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxChoicebook
//----------------------------------------------------------------------------
Gura_DeclareFunction(Choicebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Choicebook));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Choicebook)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = 0;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxString name = wxNotebookNameStr;
	if (arg.IsValid(5)) name = wxString::FromUTF8(arg.GetString(5));
	wx_Choicebook *pEntity = new wx_Choicebook(parent, id, *pos, *size, style, name);
	Object_wx_Choicebook *pObj = Object_wx_Choicebook::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Choicebook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxChoicebook
//----------------------------------------------------------------------------
Object_wx_Choicebook::~Object_wx_Choicebook()
{
}

Object *Object_wx_Choicebook::Clone() const
{
	return nullptr;
}

String Object_wx_Choicebook::ToString(bool exprFlag)
{
	String rtn("<wx.Choicebook:");
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
// Class implementation for wxChoicebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choicebook)
{
	Gura_AssignFunction(Choicebook);
}

Gura_ImplementDescendantCreator(wx_Choicebook)
{
	return new Object_wx_Choicebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
