//----------------------------------------------------------------------------
// wxSizer
// extracted from sizer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value SizerItemListToValue(Environment &env, const wxSizerItemList &list);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Sizer: public wxSizer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Sizer *_pObj;
public:
	//inline wx_Sizer() : wxSizer(), _pObj(nullptr) {}
	~wx_Sizer();
	inline void AssocWithGura(Object_wx_Sizer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Sizer::~wx_Sizer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Sizer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSizer
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Sizer, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_wx_SizerFlags, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizerItem *rtn = nullptr;
	if (arg.IsValid(1)) {
		wxSizerFlags *flags = Object_wx_SizerFlags::GetObject(arg, 1)->GetEntity();
		if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
			wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Add(window, *flags);
		} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
			wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Add(sizer, *flags);
		} else {
			SetError_ArgumentTypeByIndex(env, arg, 0);
			return Value::Nil;
		}
	} else {
		if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
			wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Add(window);
		} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
			wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Add(sizer);
		} else {
			SetError_ArgumentTypeByIndex(env, arg, 0);
			return Value::Nil;
		}
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, false)));
}

Gura_DeclareMethod(wx_Sizer, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int proportion = 0;
	if (arg.IsValid(1)) proportion = arg.GetInt(1);
	int flag = 0;
	if (arg.IsValid(2)) flag = arg.GetInt(2);
	int border = 0;
	if (arg.IsValid(3)) border = arg.GetInt(3);
	wxObject *userData = (wxObject *)(nullptr);
	if (arg.IsValid(4)) userData = Object_wx_Object::GetObject(arg, 4)->GetEntity();
	wxSizerItem *rtn = nullptr;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Add(window, proportion, flag, border, userData);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Add(sizer, proportion, flag, border, userData);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, AddSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, AddSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizerItem *rtn = nullptr;
	if (arg.IsValid(1)) {
		int width = arg.GetInt(0);
		int height = arg.GetInt(1);
		int proportion = 0;
		if (arg.IsValid(2)) proportion = arg.GetInt(2);
		int flag = 0;
		if (arg.IsValid(3)) flag = arg.GetInt(3);
		int border = 0;
		if (arg.IsValid(4)) border = arg.GetInt(4);
		wxObject *userData = (wxObject *)(nullptr);
		if (arg.IsValid(5)) userData = Object_wx_Object::GetObject(arg, 5)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Add(width, height, proportion, flag, border, userData);
	} else {
		int size = arg.GetInt(0);
		rtn = (wxSizerItem *)pThis->GetEntity()->AddSpacer(size);
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, AddStretchSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, AddStretchSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int prop = 1;
	if (arg.IsValid(0)) prop = arg.GetInt(0);
	wxSizerItem *rtn = (wxSizerItem *)pThis->GetEntity()->AddStretchSpacer(prop);
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->CalcMin();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Sizer, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "delete_windows", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool delete_windows = false;
	if (arg.IsValid(0)) delete_windows = arg.GetBoolean(0);
	pThis->GetEntity()->Clear(delete_windows);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, ComputeFittingClientSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, ComputeFittingClientSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ComputeFittingClientSize(window);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Sizer, ComputeFittingWindowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, ComputeFittingWindowSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->ComputeFittingWindowSize(window);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Sizer, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Detach)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = false;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Detach(window);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Detach(sizer);
	} else if (arg.Is_number(0)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->Detach(index);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Sizer, Fit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Fit)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxSize rtn = pThis->GetEntity()->Fit(window);
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Sizer, FitInside)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, FitInside)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->FitInside(window);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, GetChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizerItemList &rtn = pThis->GetEntity()->GetChildren();
	return ReturnValue(env, arg, SizerItemListToValue(env, rtn));
}

Gura_DeclareMethod(wx_Sizer, GetContainingWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, GetContainingWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *rtn = (wxWindow *)pThis->GetEntity()->GetContainingWindow();
	return ReturnValue(env, arg, Value(new Object_wx_Window(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "recursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, GetItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool recursive = false;
	if (arg.IsValid(1)) recursive = arg.GetBoolean(1);
	wxSizerItem *rtn = nullptr;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->GetItem(window, recursive);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->GetItem(sizer, recursive);
	} else if (arg.Is_number(0)) {
		size_t index = arg.GetSizeT(0);
		rtn = (wxSizerItem *)pThis->GetEntity()->GetItem(index);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Sizer, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Sizer, GetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, GetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetMinSize();
	return ReturnValue(env, arg, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Sizer, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any);
	DeclareArg(env, "recursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool recursive = false;
	if (arg.IsValid(1)) recursive = arg.GetBoolean(1);
	bool rtn = false;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Hide(window, recursive);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Hide(sizer, recursive);
	} else if (arg.Is_number(0)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->Hide(index);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Sizer, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_wx_SizerFlags, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t index = arg.GetSizeT(0);
	wxSizerFlags *flags = Object_wx_SizerFlags::GetObject(arg, 2)->GetEntity();
	wxSizerItem *rtn = nullptr;
	if (arg.IsInstanceOf(1, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 1)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Insert(index, window, *flags);
	} else if (arg.IsInstanceOf(1, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 1)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Insert(index, sizer, *flags);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 1);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, false)));
}

Gura_DeclareMethod(wx_Sizer, InsertSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, InsertSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t index = arg.GetSizeT(0);
	wxSizerItem *rtn = nullptr;
	if (arg.IsValid(2)) {
		int width = arg.GetInt(1);
		int height = arg.GetInt(2);
		int proportion = 0;
		if (arg.IsValid(3)) proportion = arg.GetInt(3);
		int flag = 0;
		if (arg.IsValid(4)) flag = arg.GetInt(4);
		int border = 0;
		if (arg.IsValid(5)) border = arg.GetInt(5);
		wxObject *userData = (wxObject *)(nullptr);
		if (arg.IsValid(6)) userData = Object_wx_Object::GetObject(arg, 6)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Insert(index, width, height, proportion, flag, border, userData);
	} else {
		int size = arg.GetInt(1);
		rtn = (wxSizerItem *)pThis->GetEntity()->InsertSpacer(index, size);
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, InsertStretchSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "prop", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, InsertStretchSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t index = arg.GetSizeT(0);
	int prop = 1;
	if (arg.IsValid(1)) prop = arg.GetInt(1);
	wxSizerItem *rtn = (wxSizerItem *)pThis->GetEntity()->InsertStretchSpacer(index, prop);
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = false;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->IsShown(window);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->IsShown(sizer);
	} else if (arg.Is_number(0)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->IsShown(index);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Sizer, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, Layout)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Prepend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_wx_SizerFlags, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Prepend)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizerItem *rtn = nullptr;
	if (arg.IsValid(1)) {
		wxSizerFlags *flags = Object_wx_SizerFlags::GetObject(arg, 1)->GetEntity();
		if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
			wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Prepend(window, *flags);
		} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
			wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Prepend(sizer, *flags);
		} else {
			SetError_ArgumentTypeByIndex(env, arg, 0);
			return Value::Nil;
		}
	} else {
		if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
			wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Prepend(window);
		} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
			wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
			rtn = (wxSizerItem *)pThis->GetEntity()->Prepend(sizer);
		} else {
			SetError_ArgumentTypeByIndex(env, arg, 0);
			return Value::Nil;
		}
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, false)));
}

Gura_DeclareMethod(wx_Sizer, Prepend_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Prepend_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int proportion = 0;
	if (arg.IsValid(1)) proportion = arg.GetInt(1);
	int flag = 0;
	if (arg.IsValid(2)) flag = arg.GetInt(2);
	int border = 0;
	if (arg.IsValid(3)) border = arg.GetInt(3);
	wxObject *userData = (wxObject *)(nullptr);
	if (arg.IsValid(4)) userData = Object_wx_Object::GetObject(arg, 4)->GetEntity();
	wxSizerItem *rtn = nullptr;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Prepend(window, proportion, flag, border, userData);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Prepend(sizer, proportion, flag, border, userData);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, PrependSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "proportion", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "border", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "userData", VTYPE_wx_Object, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, PrependSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizerItem *rtn = nullptr;
	if (arg.IsValid(1)) {
		int width = arg.GetInt(0);
		int height = arg.GetInt(1);
		int proportion = 0;
		if (arg.IsValid(2)) proportion = arg.GetInt(2);
		int flag = 0;
		if (arg.IsValid(3)) flag = arg.GetInt(3);
		int border = 0;
		if (arg.IsValid(4)) border = arg.GetInt(4);
		wxObject *userData = (wxObject *)(nullptr);
		if (arg.IsValid(5)) userData = Object_wx_Object::GetObject(arg, 5)->GetEntity();
		rtn = (wxSizerItem *)pThis->GetEntity()->Prepend(width, height, proportion, flag, border, userData);
	} else {
		int size = arg.GetInt(0);
		rtn = (wxSizerItem *)pThis->GetEntity()->PrependSpacer(size);
	}
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, PrependStretchSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prop", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, PrependStretchSpacer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int prop = 1;
	if (arg.IsValid(0)) prop = arg.GetInt(0);
	wxSizerItem *rtn = (wxSizerItem *)pThis->GetEntity()->PrependStretchSpacer(prop);
	return ReturnValue(env, arg, Value(new Object_wx_SizerItem(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Sizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Sizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = false;
#if 0
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Remove(window);
#endif
	if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Remove(sizer);
	} else if (arg.Is_number(0)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->Remove(index);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Sizer, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "oldwin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "newwin", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "recursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Replace)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *oldwin = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxWindow *newwin = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	bool recursive = false;
	if (arg.IsValid(2)) recursive = arg.GetBoolean(2);
	bool rtn = pThis->GetEntity()->Replace(oldwin, newwin, recursive);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Sizer, Replace_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "oldsz", VTYPE_wx_Sizer, OCCUR_Once);
	DeclareArg(env, "newsz", VTYPE_wx_Sizer, OCCUR_Once);
	DeclareArg(env, "recursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Replace_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSizer *oldsz = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
	wxSizer *newsz = Object_wx_Sizer::GetObject(arg, 1)->GetEntity();
	bool recursive = false;
	if (arg.IsValid(2)) recursive = arg.GetBoolean(2);
	bool rtn = pThis->GetEntity()->Replace(oldsz, newsz, recursive);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Sizer, Remove_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "oldindex", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "newitem", VTYPE_wx_SizerItem, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Remove_3)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t oldindex = arg.GetSizeT(0);
	wxSizerItem *newitem = Object_wx_SizerItem::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->Remove(oldindex, newitem);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetDimension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetDimension)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int x = arg.GetInt(0);
	int y = arg.GetInt(1);
	int width = arg.GetInt(2);
	int height = arg.GetInt(3);
	pThis->GetEntity()->SetDimension(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(0);
	int height = arg.GetInt(1);
	pThis->GetEntity()->SetMinSize(width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetMinSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetMinSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize *size = Object_wx_Size::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetMinSize(*size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetItemMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetItemMinSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int width = arg.GetInt(1);
	int height = arg.GetInt(2);
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		pThis->GetEntity()->SetItemMinSize(window, width, height);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		pThis->GetEntity()->SetItemMinSize(sizer, width, height);
	} else if (arg.Is_number(0)) {
		size_t index = arg.GetSizeT(0);
		pThis->GetEntity()->SetItemMinSize(index, width, height);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetSizeHints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetSizeHints)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetSizeHints(window);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, SetVirtualSizeHints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
}

Gura_ImplementMethod(wx_Sizer, SetVirtualSizeHints)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetVirtualSizeHints(window);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Sizer, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "obj", VTYPE_any);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "recursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Sizer, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_Sizer *pThis = Object_wx_Sizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool show = true;
	if (arg.IsValid(1)) show = arg.GetBoolean(1);
	bool recursive = false;
	if (arg.IsValid(2)) recursive = arg.GetBoolean(2);
	bool rtn = false;
	if (arg.IsInstanceOf(0, VTYPE_wx_Window)) {
		wxWindow *window = Object_wx_Window::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Show(window, show, recursive);
	} else if (arg.IsInstanceOf(0, VTYPE_wx_Sizer)) {
		wxSizer *sizer = Object_wx_Sizer::GetObject(arg, 0)->GetEntity();
		rtn = pThis->GetEntity()->Show(sizer, show, recursive);
	} else if (arg.Is_number(0)) {
		size_t index = arg.GetSizeT(0);
		rtn = pThis->GetEntity()->Show(index, show);
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSizer
//----------------------------------------------------------------------------
Object_wx_Sizer::~Object_wx_Sizer()
{
}

Object *Object_wx_Sizer::Clone() const
{
	return nullptr;
}

String Object_wx_Sizer::ToString(bool exprFlag)
{
	String rtn("<wx.Sizer:");
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
// Class implementation for wxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sizer)
{
	Gura_AssignMethod(wx_Sizer, Add);
	Gura_AssignMethod(wx_Sizer, Add_1);
	Gura_AssignMethod(wx_Sizer, AddSpacer);
	Gura_AssignMethod(wx_Sizer, AddStretchSpacer);
	Gura_AssignMethod(wx_Sizer, CalcMin);
	Gura_AssignMethod(wx_Sizer, Clear);
	Gura_AssignMethod(wx_Sizer, ComputeFittingClientSize);
	Gura_AssignMethod(wx_Sizer, ComputeFittingWindowSize);
	Gura_AssignMethod(wx_Sizer, Detach);
	Gura_AssignMethod(wx_Sizer, Fit);
	Gura_AssignMethod(wx_Sizer, FitInside);
	Gura_AssignMethod(wx_Sizer, GetChildren);
	Gura_AssignMethod(wx_Sizer, GetContainingWindow);
	Gura_AssignMethod(wx_Sizer, GetItem);
	Gura_AssignMethod(wx_Sizer, GetSize);
	Gura_AssignMethod(wx_Sizer, GetPosition);
	Gura_AssignMethod(wx_Sizer, GetMinSize);
	Gura_AssignMethod(wx_Sizer, Hide);
	Gura_AssignMethod(wx_Sizer, Insert);
	Gura_AssignMethod(wx_Sizer, InsertSpacer);
	Gura_AssignMethod(wx_Sizer, InsertStretchSpacer);
	Gura_AssignMethod(wx_Sizer, IsShown);
	Gura_AssignMethod(wx_Sizer, Layout);
	Gura_AssignMethod(wx_Sizer, Prepend);
	Gura_AssignMethod(wx_Sizer, Prepend_1);
	Gura_AssignMethod(wx_Sizer, PrependSpacer);
	Gura_AssignMethod(wx_Sizer, PrependStretchSpacer);
	Gura_AssignMethod(wx_Sizer, RecalcSizes);
	Gura_AssignMethod(wx_Sizer, Remove);
	Gura_AssignMethod(wx_Sizer, Replace);
	Gura_AssignMethod(wx_Sizer, Replace_1);
	Gura_AssignMethod(wx_Sizer, Remove_3);
	Gura_AssignMethod(wx_Sizer, SetDimension);
	Gura_AssignMethod(wx_Sizer, SetMinSize);
	Gura_AssignMethod(wx_Sizer, SetMinSize_1);
	Gura_AssignMethod(wx_Sizer, SetItemMinSize);
	Gura_AssignMethod(wx_Sizer, SetSizeHints);
	Gura_AssignMethod(wx_Sizer, SetVirtualSizeHints);
	Gura_AssignMethod(wx_Sizer, Show);
}

Gura_ImplementDescendantCreator(wx_Sizer)
{
	return new Object_wx_Sizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value SizerItemListToValue(Environment &env, const wxSizerItemList &list)
{
	Value rtn;
	Object_list *pObjList = rtn.Init_AsList(env);
	pObjList->Reserve(list.GetCount());
	foreach_const (wxSizerItemList, ppSizerItem, list) {
		wxSizerItem *pSizerItem = *ppSizerItem;
		pObjList->Add(Value(new Object_wx_SizerItem(pSizerItem, nullptr, OwnerFalse)));
	}
	return rtn;
}

Gura_EndModuleScope(wx)
