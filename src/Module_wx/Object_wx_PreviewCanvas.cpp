//----------------------------------------------------------------------------
// wxPreviewCanvas
// extracted from prevwin.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PreviewCanvas: public wxPreviewCanvas, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PreviewCanvas *_pObj;
public:
	inline wx_PreviewCanvas(wxPrintPreview* preview, wxWindow* parent, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPreviewCanvas(preview, parent, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_PreviewCanvas();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PreviewCanvas *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PreviewCanvas::~wx_PreviewCanvas()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PreviewCanvas::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewCanvas
//----------------------------------------------------------------------------
Gura_DeclareFunction(PreviewCanvas)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PreviewCanvas));
	DeclareArg(env, "preview", VTYPE_wx_PrintPreview, OCCUR_Once);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PreviewCanvas)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintPreview *preview = Object_wx_PrintPreview::GetObject(args, 0)->GetEntity();
	wxWindow *parent = Object_wx_Window::GetObject(args, 1)->GetEntity();
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxT("canvas");
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_PreviewCanvas *pEntity = new wx_PreviewCanvas(preview, parent, *pos, *size, style, name);
	Object_wx_PreviewCanvas *pObj = Object_wx_PreviewCanvas::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PreviewCanvas(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PreviewCanvas, OnPaint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "event", VTYPE_wx_PaintEvent, OCCUR_Once);
}

Gura_ImplementMethod(wx_PreviewCanvas, OnPaint)
{
	Object_wx_PreviewCanvas *pThis = Object_wx_PreviewCanvas::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPaintEvent *event = Object_wx_PaintEvent::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->OnPaint(*event);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPreviewCanvas
//----------------------------------------------------------------------------
Object_wx_PreviewCanvas::~Object_wx_PreviewCanvas()
{
}

Object *Object_wx_PreviewCanvas::Clone() const
{
	return NULL;
}

String Object_wx_PreviewCanvas::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PreviewCanvas:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PreviewCanvas::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(PreviewCanvas);
}

//----------------------------------------------------------------------------
// Class implementation for wxPreviewCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewCanvas)
{
	Gura_AssignMethod(wx_PreviewCanvas, OnPaint);
}

Gura_ImplementDescendantCreator(wx_PreviewCanvas)
{
	return new Object_wx_PreviewCanvas((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
