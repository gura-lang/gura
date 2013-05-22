//----------------------------------------------------------------------------
// wxStatusBar
// extracted from statusbr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

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
	Gura::Signal _sig;
	Object_wx_StatusBar *_pObj;
public:
	inline wx_StatusBar() : wxStatusBar(), _sig(NULL), _pObj(NULL) {}
	inline wx_StatusBar(wxWindow* parent, wxWindowID id, long style, const wxString& name) : wxStatusBar(parent, id, style, name), _sig(NULL), _pObj(NULL) {}
	//virtual bool GetFieldRect(int i, wxRect& rect);
	//virtual wxString GetStatusText(int i);
	//virtual void SetFieldsCount(int number, int* widths);
	//virtual void SetStatusText(const wxString& text, int i);
	//virtual void SetStatusWidths(int n, int * widths);
	//virtual void SetStatusStyles(int n, int * styles);
	~wx_StatusBar();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StatusBar *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StatusBar::~wx_StatusBar()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StatusBar::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStatusBar
//----------------------------------------------------------------------------
Gura_DeclareFunction(StatusBarEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StatusBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StatusBarEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_StatusBar *pEntity = new wx_StatusBar();
	Object_wx_StatusBar *pObj = Object_wx_StatusBar::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StatusBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(StatusBar)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_StatusBar));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StatusBar)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	long style = wxST_SIZEGRIP;
	if (args.IsValid(2)) style = args.GetLong(2);
	wxString name = wxT("statusBar");
	if (args.IsValid(3)) name = wxString::FromUTF8(args.GetString(3));
	wx_StatusBar *pEntity = new wx_StatusBar(parent, id, style, name);
	Object_wx_StatusBar *pObj = Object_wx_StatusBar::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StatusBar(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_StatusBar, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, Create)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = wxID_ANY;
	if (args.IsValid(1)) id = static_cast<wxWindowID>(args.GetInt(1));
	long style = wxST_SIZEGRIP;
	if (args.IsValid(2)) style = args.GetLong(2);
	wxString name = wxT("statusBar");
	if (args.IsValid(3)) name = wxString::FromUTF8(args.GetString(3));
	bool rtn = pThis->GetEntity()->Create(parent, id, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StatusBar, GetFieldRect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, GetFieldRect)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int i = args.GetInt(0);
	wxRect rect;
	bool rtn = pThis->GetEntity()->GetFieldRect(i, rect);
	Value value;
	if (rtn) {
		value = Value(new Object_wx_Rect(new wxRect(rect), NULL, OwnerTrue));
	}
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_StatusBar, GetFieldsCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, GetFieldsCount)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFieldsCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_StatusBar, GetStatusText)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "i", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, GetStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int i = 0;
	if (args.IsValid(0)) i = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetStatusText(i);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_StatusBar, PopStatusText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "field", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, PopStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int field = 0;
	if (args.IsValid(0)) field = args.GetInt(0);
	pThis->GetEntity()->PopStatusText(field);
	return Value::Null;
}

Gura_DeclareMethod(wx_StatusBar, PushStatusText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "field", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, PushStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	int field = 0;
	if (args.IsValid(1)) field = args.GetInt(1);
	pThis->GetEntity()->PushStatusText(string, field);
	return Value::Null;
}

Gura_DeclareMethod(wx_StatusBar, SetFieldsCount)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetFieldsCount)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int number = args.GetInt(0);
	int *widths = NULL;
	pThis->GetEntity()->SetFieldsCount(number, widths);
	return Value::Null;
}

Gura_DeclareMethod(wx_StatusBar, SetMinHeight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetMinHeight)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetMinHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "i", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	int i = 0;
	if (args.IsValid(1)) i = args.GetInt(1);
	pThis->GetEntity()->SetStatusText(text, i);
	return Value::Null;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusWidths)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "widths", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusWidths)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	CArrayOfInt widths(args.GetList(0));
	pThis->GetEntity()->SetStatusWidths(widths.Count(), widths.Data());
	return Value::Null;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusStyles)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "styles", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusStyles)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	CArrayOfInt styles(args.GetList(0));
	pThis->GetEntity()->SetStatusStyles(styles.Count(), styles.Data());
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxStatusBar
//----------------------------------------------------------------------------
Object_wx_StatusBar::~Object_wx_StatusBar()
{
}

Object *Object_wx_StatusBar::Clone() const
{
	return NULL;
}

String Object_wx_StatusBar::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StatusBar:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StatusBar::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(GetFieldRect);
	Gura_RealizeUserSymbol(GetStatusText);
	Gura_RealizeUserSymbol(SetFieldsCount);
	Gura_RealizeUserSymbol(SetStatusText);
	Gura_RealizeUserSymbol(SetStatusWidths);
	Gura_RealizeUserSymbol(SetStatusStyles);
	Gura_AssignFunction(StatusBarEmpty);
	Gura_AssignFunction(StatusBar);
}

//----------------------------------------------------------------------------
// Class implementation for wxStatusBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StatusBar)
{
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
	return new Object_wx_StatusBar((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
