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
	Gura::Signal *_pSig;
	Object_wx_PreviewFrame *_pObj;
public:
	inline wx_PreviewFrame(wxPrintPreview* preview, wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPreviewFrame(preview, parent, title, pos, size, style, name), _pSig(nullptr), _pObj(nullptr) {}
	~wx_PreviewFrame();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PreviewFrame *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintPreview *preview = Object_wx_PrintPreview::GetObject(args, 0)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_FRAME_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("frame");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_PreviewFrame *pEntity = new wx_PreviewFrame(preview, parent, title, *pos, *size, style, name);
	Object_wx_PreviewFrame *pObj = Object_wx_PreviewFrame::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PreviewFrame(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PreviewFrame, CreateControlBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, CreateControlBar)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CreateControlBar();
	return Value::Null;
}

Gura_DeclareMethod(wx_PreviewFrame, CreateCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, CreateCanvas)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->CreateCanvas();
	return Value::Null;
}

Gura_DeclareMethod(wx_PreviewFrame, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PreviewFrame, Initialize)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Initialize();
	return Value::Null;
}

Gura_DeclareMethod(wx_PreviewFrame, OnCloseWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_CloseEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewFrame, OnCloseWindow)
{
	Object_wx_PreviewFrame *pThis = Object_wx_PreviewFrame::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCloseEvent *event = Object_wx_CloseEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnCloseWindow(*event);
	return Value::Null;
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
