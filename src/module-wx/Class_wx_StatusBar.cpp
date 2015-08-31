//----------------------------------------------------------------------------
// wxStatusBar
// extracted from statusbr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(GetFieldRect);
Gura_DeclarePrivUserSymbol(GetStatusText);
Gura_DeclarePrivUserSymbol(SetFieldsCount);
Gura_DeclarePrivUserSymbol(SetStatusText);
Gura_DeclarePrivUserSymbol(SetStatusWidths);
Gura_DeclarePrivUserSymbol(SetStatusStyles);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StatusBar: public wxStatusBar, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StatusBar *_pObj;
public:
	inline wx_StatusBar() : wxStatusBar(), _pObj(nullptr) {}
	inline wx_StatusBar(wxWindow* parent, wxWindowID id, long style, const wxString& name) : wxStatusBar(parent, id, style, name), _pObj(nullptr) {}
	//virtual bool GetFieldRect(int i, wxRect& rect);
	//virtual wxString GetStatusText(int i);
	//virtual void SetFieldsCount(int number, int* widths);
	//virtual void SetStatusText(const wxString& text, int i);
	//virtual void SetStatusWidths(int n, int * widths);
	//virtual void SetStatusStyles(int n, int * styles);
	~wx_StatusBar();
	inline void AssocWithGura(Object_wx_StatusBar *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StatusBar::~wx_StatusBar()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StatusBar::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStatusBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(StatusBarEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StatusBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StatusBarEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_StatusBar *pEntity = new wx_StatusBar();
	Object_wx_StatusBar *pObj = Object_wx_StatusBar::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_StatusBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(StatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StatusBar));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StatusBar)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	long style = wxST_SIZEGRIP;
	if (arg.IsValid(2)) style = arg.GetLong(2);
	wxString name = wxT("statusBar");
	if (arg.IsValid(3)) name = wxString::FromUTF8(arg.GetString(3));
	wx_StatusBar *pEntity = new wx_StatusBar(parent, id, style, name);
	Object_wx_StatusBar *pObj = Object_wx_StatusBar::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_StatusBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_StatusBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (arg.IsValid(1)) id = static_cast<wxWindowID>(arg.GetInt(1));
	long style = wxST_SIZEGRIP;
	if (arg.IsValid(2)) style = arg.GetLong(2);
	wxString name = wxT("statusBar");
	if (arg.IsValid(3)) name = wxString::FromUTF8(arg.GetString(3));
	bool rtn = pThis->GetEntity()->Create(parent, id, style, name);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_StatusBar, GetFieldRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, GetFieldRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int i = arg.GetInt(0);
	wxRect rect;
	bool rtn = pThis->GetEntity()->GetFieldRect(i, rect);
	Value value;
	if (rtn) {
		value = Value(new Object_wx_Rect(new wxRect(rect), nullptr, OwnerTrue));
	}
	return ReturnValue(env, arg, value);
}

Gura_DeclareMethod(wx_StatusBar, GetFieldsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, GetFieldsCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFieldsCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_StatusBar, GetStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, GetStatusText)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int i = 0;
	if (arg.IsValid(0)) i = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetStatusText(i);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StatusBar, PopStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "field", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, PopStatusText)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int field = 0;
	if (arg.IsValid(0)) field = arg.GetInt(0);
	pThis->GetEntity()->PopStatusText(field);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, PushStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "field", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, PushStatusText)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(arg.GetString(0));
	int field = 0;
	if (arg.IsValid(1)) field = arg.GetInt(1);
	pThis->GetEntity()->PushStatusText(string, field);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetFieldsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetFieldsCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int number = arg.GetInt(0);
	int *widths = nullptr;
	pThis->GetEntity()->SetFieldsCount(number, widths);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetMinHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetMinHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int height = arg.GetInt(0);
	pThis->GetEntity()->SetMinHeight(height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "i", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusText)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(arg.GetString(0));
	int i = 0;
	if (arg.IsValid(1)) i = arg.GetInt(1);
	pThis->GetEntity()->SetStatusText(text, i);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusWidths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "widths", VTYPE_number, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusWidths)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	CArrayOfInt widths(arg.GetList(0));
	pThis->GetEntity()->SetStatusWidths(widths.Count(), widths.Data());
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styles", VTYPE_number, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusStyles)
{
	Signal &sig = env.GetSignal();
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	CArrayOfInt styles(arg.GetList(0));
	pThis->GetEntity()->SetStatusStyles(styles.Count(), styles.Data());
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxStatusBar
//----------------------------------------------------------------------------
Object_wx_StatusBar::~Object_wx_StatusBar()
{
}

Object *Object_wx_StatusBar::Clone() const
{
	return nullptr;
}

String Object_wx_StatusBar::ToString(bool exprFlag)
{
	String rtn("<wx.StatusBar:");
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
// Class implementation for wxStatusBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StatusBar)
{
	Gura_RealizeUserSymbol(GetFieldRect);
	Gura_RealizeUserSymbol(GetStatusText);
	Gura_RealizeUserSymbol(SetFieldsCount);
	Gura_RealizeUserSymbol(SetStatusText);
	Gura_RealizeUserSymbol(SetStatusWidths);
	Gura_RealizeUserSymbol(SetStatusStyles);
	Gura_AssignFunction(StatusBarEmpty);
	Gura_AssignFunction(StatusBar);
	Gura_AssignMethod(wx_StatusBar, Create);
	Gura_AssignMethod(wx_StatusBar, GetFieldRect);
	Gura_AssignMethod(wx_StatusBar, GetFieldsCount);
	Gura_AssignMethod(wx_StatusBar, GetStatusText);
	Gura_AssignMethod(wx_StatusBar, PopStatusText);
	Gura_AssignMethod(wx_StatusBar, PushStatusText);
	Gura_AssignMethod(wx_StatusBar, SetFieldsCount);
	Gura_AssignMethod(wx_StatusBar, SetMinHeight);
	Gura_AssignMethod(wx_StatusBar, SetStatusText);
	Gura_AssignMethod(wx_StatusBar, SetStatusWidths);
	Gura_AssignMethod(wx_StatusBar, SetStatusStyles);
}

Gura_ImplementDescendantCreator(wx_StatusBar)
{
	return new Object_wx_StatusBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
