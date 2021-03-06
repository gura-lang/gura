//----------------------------------------------------------------------------
// wxScrollBar
// extracted from scrolbar.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(SetScrollbar);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ScrollBar: public wxScrollBar, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ScrollBar *_pObj;
public:
	inline wx_ScrollBar() : wxScrollBar(), _pObj(nullptr) {}
	inline wx_ScrollBar(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name) : wxScrollBar(parent, id, pos, size, style, validator, name), _pObj(nullptr) {}
	//virtual void SetScrollbar(int position, int thumbSize, int range, int pageSize, const bool refresh);
	~wx_ScrollBar();
	inline void AssocWithGura(Object_wx_ScrollBar *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ScrollBar::~wx_ScrollBar()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ScrollBar::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(ScrollBarEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ScrollBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScrollBarEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_ScrollBar *pEntity = new wx_ScrollBar();
	Object_wx_ScrollBar *pObj = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ScrollBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(ScrollBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ScrollBar));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ScrollBar)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxSB_HORIZONTAL;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(5)) validator = Object_wx_Validator::GetObject(arg, 5)->GetEntity();
	wxString name = wxT("scrollBar");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_ScrollBar *pEntity = new wx_ScrollBar(parent, id, *pos, *size, style, *validator, name);
	Object_wx_ScrollBar *pObj = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_ScrollBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_ScrollBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollBar, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(2)) pos = Object_wx_Point::GetObject(arg, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(3)) size = Object_wx_Size::GetObject(arg, 3)->GetEntity();
	long style = wxSB_HORIZONTAL;
	if (arg.IsValid(4)) style = arg.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (arg.IsValid(5)) validator = Object_wx_Validator::GetObject(arg, 5)->GetEntity();
	wxString name = wxT("scrollBar");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, *validator, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ScrollBar, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollBar, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRange();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ScrollBar, GetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollBar, GetPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPageSize();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ScrollBar, GetThumbPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollBar, GetThumbPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetThumbPosition();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ScrollBar, GetThumbSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollBar, GetThumbSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetThumbSize();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_ScrollBar, SetObjectLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "objectLength", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_ScrollBar, SetObjectLength)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int objectLength = arg.GetInt(0);
	pThis->GetEntity()->SetObjectLength(objectLength);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, SetPageSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, SetPageSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pageSize = arg.GetInt(0);
	pThis->GetEntity()->SetPageSize(pageSize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, SetThumbPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "viewStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScrollBar, SetThumbPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int viewStart = arg.GetInt(0);
	pThis->GetEntity()->SetThumbPosition(viewStart);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, SetScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "thumbSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pageSize", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "refresh", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ScrollBar, SetScrollbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int position = arg.GetInt(0);
	int thumbSize = arg.GetInt(1);
	int range = arg.GetInt(2);
	int pageSize = arg.GetInt(3);
	bool refresh = true;
	if (arg.IsValid(4)) refresh = arg.GetBoolean(4);
	pThis->GetEntity()->SetScrollbar(position, thumbSize, range, pageSize, refresh);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScrollBar, SetViewLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "viewLength", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_ScrollBar, SetViewLength)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_ScrollBar *pThis = Object_wx_ScrollBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int viewLength = arg.GetInt(0);
	pThis->GetEntity()->SetViewLength(viewLength);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxScrollBar
//----------------------------------------------------------------------------
Object_wx_ScrollBar::~Object_wx_ScrollBar()
{
}

Object *Object_wx_ScrollBar::Clone() const
{
	return nullptr;
}

String Object_wx_ScrollBar::ToString(bool exprFlag)
{
	String rtn("<wx.ScrollBar:");
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
// Class implementation for wxScrollBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollBar)
{
	Gura_RealizeUserSymbol(SetScrollbar);
	Gura_AssignFunction(ScrollBarEmpty);
	Gura_AssignFunction(ScrollBar);
	Gura_AssignMethod(wx_ScrollBar, Create);
	Gura_AssignMethod(wx_ScrollBar, GetRange);
	Gura_AssignMethod(wx_ScrollBar, GetPageSize);
	Gura_AssignMethod(wx_ScrollBar, GetThumbPosition);
	Gura_AssignMethod(wx_ScrollBar, GetThumbSize);
	Gura_AssignMethod(wx_ScrollBar, SetObjectLength);
	Gura_AssignMethod(wx_ScrollBar, SetPageSize);
	Gura_AssignMethod(wx_ScrollBar, SetThumbPosition);
	Gura_AssignMethod(wx_ScrollBar, SetScrollbar);
	Gura_AssignMethod(wx_ScrollBar, SetViewLength);
}

Gura_ImplementDescendantCreator(wx_ScrollBar)
{
	return new Object_wx_ScrollBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
