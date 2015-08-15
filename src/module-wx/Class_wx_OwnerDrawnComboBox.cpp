//----------------------------------------------------------------------------
// wxOwnerDrawnComboBox
// extracted from odcbox.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_OwnerDrawnComboBox: public wxOwnerDrawnComboBox, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_OwnerDrawnComboBox *_pObj;
public:
	inline wx_OwnerDrawnComboBox() : wxOwnerDrawnComboBox(), _pObj(nullptr) {}
	//inline wx_OwnerDrawnComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, int n, const wxString choices[], long style, const wxValidator& validator, const wxString& name) : wxOwnerDrawnComboBox(parent, id, value, pos, size, n, choices[], style, validator, name), _pObj(nullptr) {}
	inline wx_OwnerDrawnComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator, const wxString& name) : wxOwnerDrawnComboBox(parent, id, value, pos, size, choices, style, validator, name), _pObj(nullptr) {}
	~wx_OwnerDrawnComboBox();
	inline void AssocWithGura(Object_wx_OwnerDrawnComboBox *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_OwnerDrawnComboBox::~wx_OwnerDrawnComboBox()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_OwnerDrawnComboBox::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Gura_DeclareFunction(OwnerDrawnComboBoxEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_OwnerDrawnComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(OwnerDrawnComboBoxEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_OwnerDrawnComboBox *pEntity = new wx_OwnerDrawnComboBox();
	Object_wx_OwnerDrawnComboBox *pObj = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_OwnerDrawnComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(OwnerDrawnComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_OwnerDrawnComboBox));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(OwnerDrawnComboBox)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(5)));
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("comboBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_OwnerDrawnComboBox *pEntity = new wx_OwnerDrawnComboBox(parent, id, value, *pos, *size, *choices, style, *validator, name);
	Object_wx_OwnerDrawnComboBox *pObj = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_OwnerDrawnComboBox(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "choices", VTYPE_string, OCCUR_Once, FLAG_List);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString value = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	std::unique_ptr<wxArrayString> choices(CreateArrayString(args.GetList(5)));
	long style = 0;
	if (args.IsValid(6)) style = args.GetLong(6);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(7)) validator = Object_wx_Validator::GetObject(args, 7)->GetEntity();
	wxString name = wxT("comboBox");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	bool rtn = pThis->GetEntity()->Create(parent, id, value, *pos, *size, *choices, style, *validator, name);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, GetWidestItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, GetWidestItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWidestItem();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, GetWidestItemWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, GetWidestItemWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWidestItemWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnDrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnDrawBackground)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	int item = args.GetInt(2);
	int flags = args.GetInt(3);
	pThis->GetEntity()->OnDrawBackground(*dc, *rect, item, flags);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnDrawItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnDrawItem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	int item = args.GetInt(2);
	int flags = args.GetInt(3);
	pThis->GetEntity()->OnDrawItem(*dc, *rect, item, flags);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnMeasureItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnMeasureItem)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t item = args.GetSizeT(0);
	wxCoord rtn = pThis->GetEntity()->OnMeasureItem(item);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_OwnerDrawnComboBox, OnMeasureItemWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, OnMeasureItemWidth)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t item = args.GetSizeT(0);
	wxCoord rtn = pThis->GetEntity()->OnMeasureItemWidth(item);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Object_wx_OwnerDrawnComboBox::~Object_wx_OwnerDrawnComboBox()
{
}

Object *Object_wx_OwnerDrawnComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_OwnerDrawnComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.OwnerDrawnComboBox:");
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
// Class implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OwnerDrawnComboBox)
{
	Gura_AssignFunction(OwnerDrawnComboBoxEmpty);
	Gura_AssignFunction(OwnerDrawnComboBox);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, Create);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, GetWidestItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, GetWidestItemWidth);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnDrawBackground);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnDrawItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnMeasureItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, OnMeasureItemWidth);
}

Gura_ImplementDescendantCreator(wx_OwnerDrawnComboBox)
{
	return new Object_wx_OwnerDrawnComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
