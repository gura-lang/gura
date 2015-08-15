//----------------------------------------------------------------------------
// wxContextHelpButton
// extracted from cshelp.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ContextHelpButton: public wxContextHelpButton, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ContextHelpButton *_pObj;
public:
	//inline wx_ContextHelpButton() : wxContextHelpButton(), _pObj(nullptr) {}
	inline wx_ContextHelpButton(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) : wxContextHelpButton(parent, id, pos, size, style), _pObj(nullptr) {}
	~wx_ContextHelpButton();
	inline void AssocWithGura(Object_wx_ContextHelpButton *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ContextHelpButton::~wx_ContextHelpButton()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ContextHelpButton::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelpButton
//----------------------------------------------------------------------------
Gura_DeclareFunction(ContextHelpButtonEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ContextHelpButton));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ContextHelpButtonEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_ContextHelpButton *pEntity = new wx_ContextHelpButton();
	Object_wx_ContextHelpButton *pObj = Object_wx_ContextHelpButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ContextHelpButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(ContextHelpButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ContextHelpButton));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ContextHelpButton)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_CONTEXT_HELP;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxBU_AUTODRAW;
	if (args.IsValid(4)) style = args.GetLong(4);
	wx_ContextHelpButton *pEntity = new wx_ContextHelpButton(parent, id, *pos, *size, style);
	Object_wx_ContextHelpButton *pObj = Object_wx_ContextHelpButton::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ContextHelpButton(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Object_wx_ContextHelpButton::~Object_wx_ContextHelpButton()
{
}

Object *Object_wx_ContextHelpButton::Clone() const
{
	return nullptr;
}

String Object_wx_ContextHelpButton::ToString(bool exprFlag)
{
	String rtn("<wx.ContextHelpButton:");
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
// Class implementation for wxContextHelpButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelpButton)
{
	Gura_AssignFunction(ContextHelpButtonEmpty);
	Gura_AssignFunction(ContextHelpButton);
}

Gura_ImplementDescendantCreator(wx_ContextHelpButton)
{
	return new Object_wx_ContextHelpButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
