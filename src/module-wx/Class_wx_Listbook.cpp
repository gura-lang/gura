//----------------------------------------------------------------------------
// wxListbook
// extracted from listbook.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Listbook: public wxListbook, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Listbook *_pObj;
public:
	inline wx_Listbook() : wxListbook(), _pObj(nullptr) {}
	inline wx_Listbook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxListbook(parent, id, pos, size, style, name), _pObj(nullptr) {}
	~wx_Listbook();
	inline void AssocWithGura(Object_wx_Listbook *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Listbook::~wx_Listbook()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Listbook::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListbook
//----------------------------------------------------------------------------
Gura_DeclareFunction(Listbook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Listbook));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Listbook)
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
	wx_Listbook *pEntity = new wx_Listbook(parent, id, *pos, *size, style, name);
	Object_wx_Listbook *pObj = Object_wx_Listbook::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Listbook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxListbook
//----------------------------------------------------------------------------
Object_wx_Listbook::~Object_wx_Listbook()
{
}

Object *Object_wx_Listbook::Clone() const
{
	return nullptr;
}

String Object_wx_Listbook::ToString(bool exprFlag)
{
	String rtn("<wx.Listbook:");
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
// Class implementation for wxListbook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Listbook)
{
	Gura_AssignFunction(Listbook);
}

Gura_ImplementDescendantCreator(wx_Listbook)
{
	return new Object_wx_Listbook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
