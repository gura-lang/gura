//----------------------------------------------------------------------------
// wxPrintPreview
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrintPreview: public wxPrintPreview, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PrintPreview *_pObj;
public:
	inline wx_PrintPreview(wxPrintout* printout, wxPrintout* printoutForPrinting, wxPrintData* data) : wxPrintPreview(printout, printoutForPrinting, data), _sig(NULL), _pObj(NULL) {}
	~wx_PrintPreview();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PrintPreview *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrintPreview::~wx_PrintPreview()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PrintPreview::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintPreview
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrintPreview)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintPreview));
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "printoutForPrinting", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_PrintData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintPreview)
{
	wxPrintout *printout = Object_wx_Printout::GetObject(args, 0)->GetEntity();
	wxPrintout *printoutForPrinting = Object_wx_Printout::GetObject(args, 1)->GetEntity();
	wxPrintData *data = (wxPrintData *)(NULL);
	if (args.IsValid(2)) data = Object_wx_PrintData::GetObject(args, 2)->GetEntity();
	wx_PrintPreview *pEntity = new wx_PrintPreview(printout, printoutForPrinting, data);
	Object_wx_PrintPreview *pObj = Object_wx_PrintPreview::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PrintPreview(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_PrintPreview, GetCanvas)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetCanvas)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPreviewCanvas *rtn = (wxPreviewCanvas *)pSelf->GetEntity()->GetCanvas();
	return ReturnValue(env, sig, args, Value(new Object_wx_PreviewCanvas(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetCurrentPage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetCurrentPage)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetCurrentPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetFrame)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetFrame)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFrame *rtn = (wxFrame *)pSelf->GetEntity()->GetFrame();
	return ReturnValue(env, sig, args, Value(new Object_wx_Frame(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetMaxPage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetMaxPage)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetMaxPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetMinPage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetMinPage)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetMinPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintout)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintout)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintout *rtn = (wxPrintout *)pSelf->GetEntity()->GetPrintout();
	return ReturnValue(env, sig, args, Value(new Object_wx_Printout(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintout *rtn = (wxPrintout *)pSelf->GetEntity()->GetPrintoutForPrinting();
	return ReturnValue(env, sig, args, Value(new Object_wx_Printout(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, Ok)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, Ok)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Ok();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, PaintPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "canvas", VTYPE_wx_PreviewCanvas, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, PaintPage)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPreviewCanvas *canvas = Object_wx_PreviewCanvas::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->PaintPage(canvas, *dc);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, Print)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prompt", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, Print)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool prompt = args.GetBoolean(0);
	bool rtn = pSelf->GetEntity()->Print(prompt);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, RenderPage)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, RenderPage)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pageNum = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->RenderPage(pageNum);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, SetCanvas)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_PreviewCanvas, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCanvas)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPreviewCanvas *window = Object_wx_PreviewCanvas::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetCanvas(window);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetCurrentPage)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCurrentPage)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int pageNum = args.GetInt(0);
	pSelf->GetEntity()->SetCurrentPage(pageNum);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetFrame)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetFrame)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetFrame(frame);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetPrintout)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetPrintout)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintout *printout = Object_wx_Printout::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetPrintout(printout);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetZoom)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetZoom)
{
	Object_wx_PrintPreview *pSelf = Object_wx_PrintPreview::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int percent = args.GetInt(0);
	pSelf->GetEntity()->SetZoom(percent);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPrintPreview
//----------------------------------------------------------------------------
Object_wx_PrintPreview::~Object_wx_PrintPreview()
{
}

Object *Object_wx_PrintPreview::Clone() const
{
	return NULL;
}

String Object_wx_PrintPreview::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PrintPreview:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PrintPreview::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PrintPreview);
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintPreview)
{
	Gura_AssignMethod(wx_PrintPreview, GetCanvas);
	Gura_AssignMethod(wx_PrintPreview, GetCurrentPage);
	Gura_AssignMethod(wx_PrintPreview, GetFrame);
	Gura_AssignMethod(wx_PrintPreview, GetMaxPage);
	Gura_AssignMethod(wx_PrintPreview, GetMinPage);
	Gura_AssignMethod(wx_PrintPreview, GetPrintout);
	Gura_AssignMethod(wx_PrintPreview, GetPrintoutForPrinting);
	Gura_AssignMethod(wx_PrintPreview, Ok);
	Gura_AssignMethod(wx_PrintPreview, PaintPage);
	Gura_AssignMethod(wx_PrintPreview, Print);
	Gura_AssignMethod(wx_PrintPreview, RenderPage);
	Gura_AssignMethod(wx_PrintPreview, SetCanvas);
	Gura_AssignMethod(wx_PrintPreview, SetCurrentPage);
	Gura_AssignMethod(wx_PrintPreview, SetFrame);
	Gura_AssignMethod(wx_PrintPreview, SetPrintout);
	Gura_AssignMethod(wx_PrintPreview, SetZoom);
}

Gura_ImplementDescendantCreator(wx_PrintPreview)
{
	return new Object_wx_PrintPreview((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
