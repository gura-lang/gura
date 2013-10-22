//----------------------------------------------------------------------------
// wxListbook
// extracted from listbook.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Listbook: public wxListbook, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Listbook *_pObj;
public:
	inline wx_Listbook() : wxListbook(), _sig(NULL), _pObj(NULL) {}
	inline wx_Listbook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxListbook(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_Listbook();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Listbook *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Listbook::~wx_Listbook()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Listbook::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListbook
//----------------------------------------------------------------------------
Gura_DeclareFunction(Listbook)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxNotebookNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_Listbook *pEntity = new wx_Listbook(parent, id, *pos, *size, style, name);
	Object_wx_Listbook *pObj = Object_wx_Listbook::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Listbook(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxListbook
//----------------------------------------------------------------------------
Object_wx_Listbook::~Object_wx_Listbook()
{
}

Object *Object_wx_Listbook::Clone() const
{
	return NULL;
}

String Object_wx_Listbook::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Listbook:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_Listbook((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
