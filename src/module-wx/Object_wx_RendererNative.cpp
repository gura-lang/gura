//----------------------------------------------------------------------------
// wxRendererNative
// extracted from renderer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RendererNative: public wxRendererNative, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RendererNative *_pObj;
public:
	~wx_RendererNative();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RendererNative *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RendererNative::~wx_RendererNative()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RendererNative::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRendererNative
//----------------------------------------------------------------------------

Gura_DeclareMethod(wx_RendererNative, DrawCheckBox)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawCheckBox)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = args.GetInt(3);
	pThis->GetEntity()->DrawCheckBox(win, *dc, *rect, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawComboBoxDropButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawComboBoxDropButton)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = args.GetInt(3);
	pThis->GetEntity()->DrawComboBoxDropButton(win, *dc, *rect, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawDropArrow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawDropArrow)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = args.GetInt(3);
	pThis->GetEntity()->DrawDropArrow(win, *dc, *rect, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawHeaderButton)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sortArrow", VTYPE_wx_HeaderSortIconType, OCCUR_ZeroOrOnce);
	DeclareArg(env, "params", VTYPE_wx_HeaderButtonParams, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, DrawHeaderButton)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	wxHeaderSortIconType *sortArrow = (wxHeaderSortIconType *)(&wxHDR_SORT_ICON_NONE);
	if (args.IsValid(4)) sortArrow = Object_wx_HeaderSortIconType::GetObject(args, 4)->GetEntity();
	wxHeaderButtonParams *params = (wxHeaderButtonParams *)(NULL);
	if (args.IsValid(5)) params = Object_wx_HeaderButtonParams::GetObject(args, 5)->GetEntity();
	int rtn = pThis->GetEntity()->DrawHeaderButton(win, *dc, *rect, flags, *sortArrow, params);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawItemSelectionRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawItemSelectionRect)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	pThis->GetEntity()->DrawItemSelectionRect(win, *dc, *rect, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawPushButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawPushButton)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = args.GetInt(3);
	pThis->GetEntity()->DrawPushButton(win, *dc, *rect, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawSplitterBorder)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawSplitterBorder)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	pThis->GetEntity()->DrawSplitterBorder(win, *dc, *rect, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawSplitterSash)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawSplitterSash)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 2)->GetEntity();
	wxCoord position = static_cast<wxCoord>(args.GetInt(3));
	wxOrientation orient = static_cast<wxOrientation>(args.GetInt(4));
	int flags = 0;
	if (args.IsValid(5)) flags = args.GetInt(5);
	pThis->GetEntity()->DrawSplitterSash(win, *dc, *size, position, orient, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, DrawTreeItemButton)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_RendererNative, DrawTreeItemButton)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int flags = 0;
	if (args.IsValid(3)) flags = args.GetInt(3);
	pThis->GetEntity()->DrawTreeItemButton(win, *dc, *rect, flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, Get)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, Get)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRendererNative &rtn = pThis->GetEntity()->Get();
	return ReturnValue(env, sig, args, Value(new Object_wx_RendererNative(new wxRendererNative(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, GetDefault)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, GetDefault)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRendererNative &rtn = pThis->GetEntity()->GetDefault();
	return ReturnValue(env, sig, args, Value(new Object_wx_RendererNative(new wxRendererNative(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, GetGeneric)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, GetGeneric)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRendererNative &rtn = pThis->GetEntity()->GetGeneric();
	return ReturnValue(env, sig, args, Value(new Object_wx_RendererNative(new wxRendererNative(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, GetHeaderButtonHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, GetHeaderButtonHeight)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int rtn = pThis->GetEntity()->GetHeaderButtonHeight(win);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, GetSplitterParams)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, GetSplitterParams)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxSplitterRenderParams rtn = pThis->GetEntity()->GetSplitterParams(win);
	return ReturnValue(env, sig, args, Value(new Object_wx_SplitterRenderParams(new wxSplitterRenderParams(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, GetVersion)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, GetVersion)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRendererVersion rtn = pThis->GetEntity()->GetVersion();
	return ReturnValue(env, sig, args, Value(new Object_wx_RendererVersion(new wxRendererVersion(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_RendererNative, Load)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, Load)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxRendererNative *rtn = (wxRendererNative *)pThis->GetEntity()->Load(name);
	return ReturnValue(env, sig, args, Value(new Object_wx_RendererNative(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RendererNative, Set)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "renderer", VTYPE_wx_RendererNative, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RendererNative, Set)
{
#if 0
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRendererNative *renderer = Object_wx_RendererNative::GetObject(args, 0)->GetEntity();
	wxRendererNative *rtn = (wxRendererNative *)pThis->GetEntity()->Set(renderer);
	return ReturnValue(env, sig, args, Value(new Object_wx_RendererNative(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxRendererNative
//----------------------------------------------------------------------------
Object_wx_RendererNative::~Object_wx_RendererNative()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RendererNative::Clone() const
{
	return NULL;
}

String Object_wx_RendererNative::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RendererNative:");
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
// Class implementation for wxRendererNative
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RendererNative)
{
	Gura_AssignMethod(wx_RendererNative, DrawCheckBox);
	Gura_AssignMethod(wx_RendererNative, DrawComboBoxDropButton);
	Gura_AssignMethod(wx_RendererNative, DrawDropArrow);
	Gura_AssignMethod(wx_RendererNative, DrawHeaderButton);
	Gura_AssignMethod(wx_RendererNative, DrawItemSelectionRect);
	Gura_AssignMethod(wx_RendererNative, DrawPushButton);
	Gura_AssignMethod(wx_RendererNative, DrawSplitterBorder);
	Gura_AssignMethod(wx_RendererNative, DrawSplitterSash);
	Gura_AssignMethod(wx_RendererNative, DrawTreeItemButton);
	Gura_AssignMethod(wx_RendererNative, Get);
	Gura_AssignMethod(wx_RendererNative, GetDefault);
	Gura_AssignMethod(wx_RendererNative, GetGeneric);
	Gura_AssignMethod(wx_RendererNative, GetHeaderButtonHeight);
	Gura_AssignMethod(wx_RendererNative, GetSplitterParams);
	Gura_AssignMethod(wx_RendererNative, GetVersion);
	Gura_AssignMethod(wx_RendererNative, Load);
	Gura_AssignMethod(wx_RendererNative, Set);
}

Gura_ImplementDescendantCreator(wx_RendererNative)
{
	return new Object_wx_RendererNative((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
