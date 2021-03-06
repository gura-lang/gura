//----------------------------------------------------------------------------
// wxMDIChildFrame
// extracted from mdi.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MDIChildFrame: public wxMDIChildFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MDIChildFrame *_pObj;
public:
	inline wx_MDIChildFrame() : wxMDIChildFrame(), _pObj(nullptr) {}
	inline wx_MDIChildFrame(wxMDIParentFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxMDIChildFrame(parent, id, title, pos, size, style, name), _pObj(nullptr) {}
	~wx_MDIChildFrame();
	inline void AssocWithGura(Object_wx_MDIChildFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MDIChildFrame::~wx_MDIChildFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MDIChildFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIChildFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(MDIChildFrameEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MDIChildFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MDIChildFrameEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_MDIChildFrame *pEntity = new wx_MDIChildFrame();
	Object_wx_MDIChildFrame *pObj = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MDIChildFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareFunction(MDIChildFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MDIChildFrame));
	DeclareArg(env, "parent", VTYPE_wx_MDIParentFrame, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MDIChildFrame)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxMDIParentFrame *parent = Object_wx_MDIParentFrame::GetObject(arg, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("frame");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_MDIChildFrame *pEntity = new wx_MDIChildFrame(parent, id, title, *pos, *size, style, name);
	Object_wx_MDIChildFrame *pObj = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_MDIChildFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_MDIChildFrame, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, Activate)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MDIChildFrame, Create)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = arg.IsValid(0)?
			Object_wx_Window::GetObject(arg, 0)->GetEntity() : nullptr;
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(1));
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("frame");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, Maximize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "maximize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIChildFrame, Maximize)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool maximize = arg.GetBoolean(0);
	pThis->GetEntity()->Maximize(maximize);
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, Restore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, Restore)
{
	Signal &sig = env.GetSignal();
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Restore();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Object_wx_MDIChildFrame::~Object_wx_MDIChildFrame()
{
}

Object *Object_wx_MDIChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MDIChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MDIChildFrame:");
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
// Class implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIChildFrame)
{
	Gura_AssignFunction(MDIChildFrameEmpty);
	Gura_AssignFunction(MDIChildFrame);
	Gura_AssignMethod(wx_MDIChildFrame, Activate);
	Gura_AssignMethod(wx_MDIChildFrame, Create);
	Gura_AssignMethod(wx_MDIChildFrame, Maximize);
	Gura_AssignMethod(wx_MDIChildFrame, Restore);
}

Gura_ImplementDescendantCreator(wx_MDIChildFrame)
{
	return new Object_wx_MDIChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
