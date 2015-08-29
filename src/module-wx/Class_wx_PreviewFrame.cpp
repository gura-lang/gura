//----------------------------------------------------------------------------
// wxPreviewFrame
// extracted from prevwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PreviewFrame: public wxPreviewFrame, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PreviewFrame *_pObj;
public:
	inline wx_PreviewFrame(wxPrintPreview* preview, wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPreviewFrame(preview, parent, title, pos, size, style, name), _pObj(nullptr) {}
	~wx_PreviewFrame();
	inline void AssocWithGura(Object_wx_PreviewFrame *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PreviewFrame::~wx_PreviewFrame()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PreviewFrame::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewFrame
//----------------------------------------------------------------------------
Gura_DeclareFunction(PreviewFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PreviewFrame));
	DeclareArg(env, "preview", VTYPE_wx_PrintPreview, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PreviewFrame)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPrintPreview *preview = Object_wx_PrintPreview::GetObject(arg, 0)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(arg, 1)->GetEntity();
	wxString title = wxString::FromUTF8(arg.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (arg.IsValid(3)) pos = Object_wx_Point::GetObject(arg, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (arg.IsValid(4)) size = Object_wx_Size::GetObject(arg, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (arg.IsValid(5)) style = arg.GetLong(5);
	wxString name = wxT("frame");
	if (arg.IsValid(6)) name = wxString::FromUTF8(arg.GetString(6));
	wx_PreviewFrame *pEntity = new wx_PreviewFrame(preview, parent, title, *pos, *size, style, name);
	Object_wx_PreviewFrame *pObj = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_PreviewFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_PreviewFrame, CreateControlBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, CreateControlBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->CreateControlBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, CreateCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, CreateCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->CreateCanvas();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, Initialize)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PreviewFrame, OnCloseWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewFrame, OnCloseWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->OnCloseWindow(*event);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxPreviewFrame
//----------------------------------------------------------------------------
Object_wx_PreviewFrame::~Object_wx_PreviewFrame()
{
}

Object *Object_wx_PreviewFrame::Clone() const
{
	return nullptr;
}

String Object_wx_PreviewFrame::ToString(bool exprFlag)
{
	String rtn("<wx.PreviewFrame:");
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
// Class implementation for wxPreviewFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewFrame)
{
	Gura_AssignFunction(PreviewFrame);
	Gura_AssignMethod(wx_PreviewFrame, CreateControlBar);
	Gura_AssignMethod(wx_PreviewFrame, CreateCanvas);
	Gura_AssignMethod(wx_PreviewFrame, Initialize);
	Gura_AssignMethod(wx_PreviewFrame, OnCloseWindow);
}

Gura_ImplementDescendantCreator(wx_PreviewFrame)
{
	return new Object_wx_PreviewFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
