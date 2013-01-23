//----------------------------------------------------------------------------
// wxStaticLine
// extracted from statline.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StaticLine: public wxStaticLine, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StaticLine *_pObj;
public:
	inline wx_StaticLine() : wxStaticLine(), _sig(NULL), _pObj(NULL) {}
	inline wx_StaticLine(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxStaticLine(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_StaticLine();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StaticLine *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StaticLine::~wx_StaticLine()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StaticLine::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticLine
//----------------------------------------------------------------------------
Gura_DeclareFunction(StaticLineEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StaticLine));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticLineEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_StaticLine *pEntity = new wx_StaticLine();
	Object_wx_StaticLine *pObj = Object_wx_StaticLine::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StaticLine(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(StaticLine)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StaticLine));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StaticLine)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxLI_HORIZONTAL;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("staticLine");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_StaticLine *pEntity = new wx_StaticLine(parent, id, *pos, *size, style, name);
	Object_wx_StaticLine *pObj = Object_wx_StaticLine::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StaticLine(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_StaticLine, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticLine, Create)
{
	Object_wx_StaticLine *pSelf = Object_wx_StaticLine::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("staticLine");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	bool rtn = pSelf->GetEntity()->Create(parent, id, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StaticLine, IsVertical)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticLine, IsVertical)
{
	Object_wx_StaticLine *pSelf = Object_wx_StaticLine::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsVertical();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StaticLine, GetDefaultSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StaticLine, GetDefaultSize)
{
	Object_wx_StaticLine *pSelf = Object_wx_StaticLine::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetDefaultSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxStaticLine
//----------------------------------------------------------------------------
Object_wx_StaticLine::~Object_wx_StaticLine()
{
}

Object *Object_wx_StaticLine::Clone() const
{
	return NULL;
}

String Object_wx_StaticLine::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StaticLine:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StaticLine::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(StaticLineEmpty);
	Gura_AssignFunction(StaticLine);
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticLine
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticLine)
{
	Gura_AssignMethod(wx_StaticLine, Create);
	Gura_AssignMethod(wx_StaticLine, IsVertical);
	Gura_AssignMethod(wx_StaticLine, GetDefaultSize);
}

Gura_ImplementDescendantCreator(wx_StaticLine)
{
	return new Object_wx_StaticLine((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
