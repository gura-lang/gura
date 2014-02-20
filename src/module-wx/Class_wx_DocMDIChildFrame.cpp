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
	Gura::Signal _sig;
	Object_wx_DocMDIChildFrame *_pObj;
public:
	//inline wx_DocMDIChildFrame(wxDocument* doc, wxView* view, wxFrame* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxDocMDIChildFrame(doc, view, parent, id, title, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_DocMDIChildFrame();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DocMDIChildFrame *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DocMDIChildFrame::~wx_DocMDIChildFrame()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DocMDIChildFrame::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(DocMDIChildFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	wxView *view = Object_wx_View::GetObject(args, 1)->GetEntity();
	wxFrame *parent = Object_wx_Frame::GetObject(args, 2)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(3));
	wxString title = wxString::FromUTF8(args.GetString(4));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(5)) pos = Object_wx_Point::GetObject(args, 5)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(6)) size = Object_wx_Size::GetObject(args, 6)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(7)) style = args.GetLong(7);
	wxString name = wxT("frame");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_DocMDIChildFrame *pEntity = new wx_DocMDIChildFrame(doc, view, parent, id, title, *pos, *size, style, name);
	Object_wx_DocMDIChildFrame *pObj = Object_wx_DocMDIChildFrame::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DocMDIChildFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocMDIChildFrame, GetDocument)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, GetDocument)
{
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *rtn = (wxDocument *)pThis->GetEntity()->GetDocument();
	return ReturnValue(env, sig, args, Value(new Object_wx_Document(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DocMDIChildFrame, GetView)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, GetView)
{
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *rtn = (wxView *)pThis->GetEntity()->GetView();
	return ReturnValue(env, sig, args, Value(new Object_wx_View(rtn, NULL, OwnerFalse)));
}

#if 0
Gura_DeclareMethod(wx_DocMDIChildFrame, OnActivate)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_ActivateEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, OnActivate)
{
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxActivateEvent *event = Object_wx_ActivateEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnActivate(*event);
	return Value::Null;
}
#endif

#if 0
Gura_DeclareMethod(wx_DocMDIChildFrame, OnCloseWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, OnCloseWindow)
{
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnCloseWindow(*event);
	return Value::Null;
}
#endif

Gura_DeclareMethod(wx_DocMDIChildFrame, SetDocument)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "doc", VTYPE_wx_Document, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, SetDocument)
{
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDocument *doc = Object_wx_Document::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDocument(doc);
	return Value::Null;
}

Gura_DeclareMethod(wx_DocMDIChildFrame, SetView)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "view", VTYPE_wx_View, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocMDIChildFrame, SetView)
{
	Object_wx_DocMDIChildFrame *pThis = Object_wx_DocMDIChildFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxView *view = Object_wx_View::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetView(view);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Object_wx_DocMDIChildFrame::~Object_wx_DocMDIChildFrame()
{
}

Object *Object_wx_DocMDIChildFrame::Clone() const
{
	return NULL;
}

String Object_wx_DocMDIChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocMDIChildFrame:");
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
	return new Object_wx_DocMDIChildFrame((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
