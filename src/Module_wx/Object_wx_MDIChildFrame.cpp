//----------------------------------------------------------------------------
// wxMDIChildFrame
// extracted from mdi.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MDIChildFrame: public wxMDIChildFrame, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MDIChildFrame *_pObj;
public:
	inline wx_MDIChildFrame() : wxMDIChildFrame(), _sig(NULL), _pObj(NULL) {}
	inline wx_MDIChildFrame(wxMDIParentFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxMDIChildFrame(parent, id, title, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_MDIChildFrame();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MDIChildFrame *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MDIChildFrame::~wx_MDIChildFrame()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MDIChildFrame::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIChildFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(MDIChildFrameEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MDIChildFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MDIChildFrameEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_MDIChildFrame *pEntity = new wx_MDIChildFrame();
	Object_wx_MDIChildFrame *pObj = Object_wx_MDIChildFrame::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MDIChildFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(MDIChildFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxMDIParentFrame *parent = Object_wx_MDIParentFrame::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("frame");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_MDIChildFrame *pEntity = new wx_MDIChildFrame(parent, id, title, *pos, *size, style, name);
	Object_wx_MDIChildFrame *pObj = Object_wx_MDIChildFrame::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MDIChildFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MDIChildFrame, Activate)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, Activate)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Activate();
	return Value::Null;
}

Gura_DeclareMethod(wx_MDIChildFrame, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
#if 0
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("frame");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pThis->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_MDIChildFrame, Maximize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "maximize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIChildFrame, Maximize)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool maximize = args.GetBoolean(0);
	pThis->GetEntity()->Maximize(maximize);
	return Value::Null;
}

Gura_DeclareMethod(wx_MDIChildFrame, Restore)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, Restore)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Restore();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Object_wx_MDIChildFrame::~Object_wx_MDIChildFrame()
{
}

Object *Object_wx_MDIChildFrame::Clone() const
{
	return NULL;
}

String Object_wx_MDIChildFrame::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MDIChildFrame:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_MDIChildFrame::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(MDIChildFrameEmpty);
	Gura_AssignFunction(MDIChildFrame);
}

//----------------------------------------------------------------------------
// Class implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIChildFrame)
{
	Gura_AssignMethod(wx_MDIChildFrame, Activate);
	Gura_AssignMethod(wx_MDIChildFrame, Create);
	Gura_AssignMethod(wx_MDIChildFrame, Maximize);
	Gura_AssignMethod(wx_MDIChildFrame, Restore);
}

Gura_ImplementDescendantCreator(wx_MDIChildFrame)
{
	return new Object_wx_MDIChildFrame((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
