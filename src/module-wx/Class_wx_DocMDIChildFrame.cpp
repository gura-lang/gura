//----------------------------------------------------------------------------
// wxDocMDIChildFrame
// extracted from docmdich.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DocMDIChildFrame: public wxDocMDIChildFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DocMDIChildFrame *_pObj;
public:
	//inline wx_DocMDIChildFrame(wxDocument* doc, wxView* view, wxFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxDocMDIChildFrame(doc, view, parent, id, title, pos, size, style, name), _pObj(nullptr) {}
	~wx_DocMDIChildFrame();
	inline void AssocWithGura(Object_wx_DocMDIChildFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DocMDIChildFrame::~wx_DocMDIChildFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DocMDIChildFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocMDIChildFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DocMDIChildFrame));
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
#endif
}

Gura_ImplementFunction(DocMDIChildFrame)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
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
	wx_DocMDIChildFrame *pEntity = new wx_DocMDIChildFrame(doc, view, parent, id, title, *pos, *size, style, name);
	Object_wx_DocMDIChildFrame *pObj = Object_wx_DocMDIChildFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DocMDIChildFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocMDIChildFrame, GetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, GetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocument *rtn = (wxDocument *)pThis->GetEntity()->GetDocument();
	return ReturnValue(env, arg, Value(new Object_wx_Document(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocMDIChildFrame, GetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, GetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxView *rtn = (wxView *)pThis->GetEntity()->GetView();
	return ReturnValue(env, arg, Value(new Object_wx_View(rtn, nullptr, OwnerFalse)));
}

#if 0
Gura_DeclareMethod(wx_DocMDIChildFrame, OnActivate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_ActivateEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, OnActivate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxActivateEvent *event = Object_wx_ActivateEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnActivate(*event);
	return Value::Nil;
}
#endif

#if 0
Gura_DeclareMethod(wx_DocMDIChildFrame, OnCloseWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, OnCloseWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnCloseWindow(*event);
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_DocMDIChildFrame, SetDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, SetDocument)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDocument *doc = Object_wx_Document::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetDocument(doc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocMDIChildFrame, SetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "view", VTYPE_wx_View, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, SetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxView *view = Object_wx_View::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetView(view);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Object_wx_DocMDIChildFrame::~Object_wx_DocMDIChildFrame()
{
}

Object *Object_wx_DocMDIChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocMDIChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocMDIChildFrame:");
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
// Class implementation for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocMDIChildFrame)
{
	Gura_AssignFunction(DocMDIChildFrame);
	Gura_AssignMethod(wx_DocMDIChildFrame, GetDocument);
	Gura_AssignMethod(wx_DocMDIChildFrame, GetView);
	//Gura_AssignMethod(wx_DocMDIChildFrame, OnActivate);
	//Gura_AssignMethod(wx_DocMDIChildFrame, OnCloseWindow);
	Gura_AssignMethod(wx_DocMDIChildFrame, SetDocument);
	Gura_AssignMethod(wx_DocMDIChildFrame, SetView);
}

Gura_ImplementDescendantCreator(wx_DocMDIChildFrame)
{
	return new Object_wx_DocMDIChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
