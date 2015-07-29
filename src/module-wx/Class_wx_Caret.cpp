//----------------------------------------------------------------------------
// wxCaret
// extracted from caret.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Caret: public wxCaret, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Caret *_pObj;
public:
	inline wx_Caret() : wxCaret(), _pObj(nullptr) {}
	inline wx_Caret(wxWindow* window, int width, int height) : wxCaret(window, width, height), _pObj(nullptr) {}
	inline wx_Caret(wxWindowBase* window, const wxSize& size) : wxCaret(window, size), _pObj(nullptr) {}
	~wx_Caret();
	inline void AssocWithGura(Object_wx_Caret *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Caret::~wx_Caret()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Caret::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCaret
//----------------------------------------------------------------------------
Gura_DeclareFunction(CaretEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Caret));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CaretEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Caret *pEntity = new wx_Caret();
	Object_wx_Caret *pObj = Object_wx_Caret::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Caret(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Caret)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Caret));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Caret)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	wx_Caret *pEntity = new wx_Caret(window, width, height);
	Object_wx_Caret *pObj = Object_wx_Caret::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Caret(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Caret_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Caret));
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Caret_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	wx_Caret *pEntity = new wx_Caret(window, *size);
	Object_wx_Caret *pObj = Object_wx_Caret::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Caret(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Caret, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int width = args.GetInt(1);
	int height = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Create(window, width, height);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Caret, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowBase *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(window, *size);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Caret, GetBlinkTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Caret, GetBlinkTime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int rtn = wxCaret::GetBlinkTime();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Caret, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Caret, GetPosition)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->GetPosition(x, y);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Caret, GetPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, GetPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Caret, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Caret, GetSize)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->GetSize(width, height);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Caret, GetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, GetSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Caret, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, GetWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetWindow();
	return ReturnValue(env, args, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Caret, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Caret, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Hide();
	return Value::Null;
}

Gura_DeclareMethod(wx_Caret, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Caret, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, IsVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsVisible();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Caret, Move)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, Move)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	pThis->GetEntity()->Move(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_Caret, Move_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, Move_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Move(*pt);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_Caret, SetBlinkTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_Caret, SetBlinkTime)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	int milliseconds = args.GetInt(0);
	wxCaret::SetBlinkTime(milliseconds);
	return Value::Null;
}

Gura_DeclareMethod(wx_Caret, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->SetSize(width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Caret, SetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Caret, SetSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_Caret, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Caret, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_Caret *pThis = Object_wx_Caret::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool show = true;
	if (args.IsValid(0)) show = args.GetBoolean(0);
	pThis->GetEntity()->Show(show);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxCaret
//----------------------------------------------------------------------------
Object_wx_Caret::~Object_wx_Caret()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Caret::Clone() const
{
	return nullptr;
}

String Object_wx_Caret::ToString(bool exprFlag)
{
	String rtn("<wx.Caret:");
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
// Class implementation for wxCaret
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Caret)
{
	Gura_AssignFunction(CaretEmpty);
	Gura_AssignFunction(Caret);
	Gura_AssignFunction(Caret_1);
	Gura_AssignMethod(wx_Caret, Create);
	Gura_AssignMethod(wx_Caret, Create_1);
	Gura_AssignMethod(wx_Caret, GetBlinkTime);
	Gura_AssignMethod(wx_Caret, GetPosition);
	Gura_AssignMethod(wx_Caret, GetPosition_1);
	Gura_AssignMethod(wx_Caret, GetSize);
	Gura_AssignMethod(wx_Caret, GetSize_1);
	Gura_AssignMethod(wx_Caret, GetWindow);
	Gura_AssignMethod(wx_Caret, Hide);
	Gura_AssignMethod(wx_Caret, IsOk);
	Gura_AssignMethodEx(wx_Caret, IsOk, "Ok");
	Gura_AssignMethod(wx_Caret, IsVisible);
	Gura_AssignMethod(wx_Caret, Move);
	Gura_AssignMethod(wx_Caret, Move_1);
	Gura_AssignMethod(wx_Caret, SetBlinkTime);
	Gura_AssignMethod(wx_Caret, SetSize);
	Gura_AssignMethod(wx_Caret, SetSize_1);
	Gura_AssignMethod(wx_Caret, Show);
}

Gura_ImplementDescendantCreator(wx_Caret)
{
	return new Object_wx_Caret((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
