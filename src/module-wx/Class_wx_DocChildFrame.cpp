//----------------------------------------------------------------------------
// wxDocChildFrame
// extracted from docchfrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DocChildFrame: public wxDocChildFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DocChildFrame *_pObj;
public:
	inline wx_DocChildFrame(wxDocument* doc, wxView* view, wxFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxDocChildFrame(doc, view, parent, id, title, pos, size, style, name), _pObj(nullptr) {}
	~wx_DocChildFrame();
	inline void AssocWithGura(Object_wx_DocChildFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DocChildFrame::~wx_DocChildFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DocChildFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocChildFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocChildFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DocChildFrame));
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
	DeclareArg(env, "view", VTYPE_wx_View, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Frame, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DocChildFrame)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDocument *doc = Object_wx_Document::GetObject(arg, 0)->GetEntity();
	wxView *view = Object_wx_View::GetObject(arg, 1)->GetEntity();
	wxFrame *parent = Object_wx_Frame::GetObject(arg, 2)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(arg.GetInt(3));
	wxString title = wxString::FromUTF8(arg.GetString(4));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(5)) pos = Object_wx_Point::GetObject(arg, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(6)) size = Object_wx_Size::GetObject(arg, 6)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (arg.IsValid(7)) style = arg.GetLong(7);
	wxString name = wxT("frame");
	if (arg.IsValid(8)) name = wxString::FromUTF8(arg.GetString(8));
	wx_DocChildFrame *pEntity = new wx_DocChildFrame(doc, view, parent, id, title, *pos, *size, style, name);
	Object_wx_DocChildFrame *pObj = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DocChildFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_DocChildFrame, GetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocChildFrame, GetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocument *rtn = (wxDocument *)pThis->GetEntity()->GetDocument();
	return ReturnValue(env, arg, Value(new Object_wx_Document(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocChildFrame, GetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocChildFrame, GetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxView *rtn = (wxView *)pThis->GetEntity()->GetView();
	return ReturnValue(env, arg, Value(new Object_wx_View(rtn, nullptr, OwnerFalse)));
}

#if 0
Gura_DeclareMethod(wx_DocChildFrame, OnActivate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_ActivateEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocChildFrame, OnActivate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxActivateEvent *event = Object_wx_ActivateEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnActivate(*event);
	return Value::Nil;
}
#endif

#if 0
Gura_DeclareMethod(wx_DocChildFrame, OnCloseWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocChildFrame, OnCloseWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnCloseWindow(*event);
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_DocChildFrame, SetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocChildFrame, SetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocument *doc = Object_wx_Document::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDocument(doc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocChildFrame, SetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "view", VTYPE_wx_View, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocChildFrame, SetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocChildFrame *pThis = Object_wx_DocChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxView *view = Object_wx_View::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetView(view);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDocChildFrame
//----------------------------------------------------------------------------
Object_wx_DocChildFrame::~Object_wx_DocChildFrame()
{
}

Object *Object_wx_DocChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocChildFrame:");
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
// Class implementation for wxDocChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocChildFrame)
{
	Gura_AssignFunction(DocChildFrame);
	Gura_AssignMethod(wx_DocChildFrame, GetDocument);
	Gura_AssignMethod(wx_DocChildFrame, GetView);
	//Gura_AssignMethod(wx_DocChildFrame, OnActivate);
	//Gura_AssignMethod(wx_DocChildFrame, OnCloseWindow);
	Gura_AssignMethod(wx_DocChildFrame, SetDocument);
	Gura_AssignMethod(wx_DocChildFrame, SetView);
}

Gura_ImplementDescendantCreator(wx_DocChildFrame)
{
	return new Object_wx_DocChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
