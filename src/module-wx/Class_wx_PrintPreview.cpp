//----------------------------------------------------------------------------
// wxPrintPreview
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrintPreview: public wxPrintPreview, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PrintPreview *_pObj;
public:
	inline wx_PrintPreview(wxPrintout* printout, wxPrintout* printoutForPrinting, wxPrintData* data) : wxPrintPreview(printout, printoutForPrinting, data), _pObj(nullptr) {}
	~wx_PrintPreview();
	inline void AssocWithGura(Object_wx_PrintPreview *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrintPreview::~wx_PrintPreview()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PrintPreview::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintPreview
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrintPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintPreview));
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "printoutForPrinting", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "data", VTYPE_wx_PrintData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintPreview)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPrintout *printout = Object_wx_Printout::GetObject(arg, 0)->GetEntity();
	wxPrintout *printoutForPrinting = Object_wx_Printout::GetObject(arg, 1)->GetEntity();
	wxPrintData *data = (wxPrintData *)(nullptr);
	if (arg.IsValid(2)) data = Object_wx_PrintData::GetObject(arg, 2)->GetEntity();
	wx_PrintPreview *pEntity = new wx_PrintPreview(printout, printoutForPrinting, data);
	Object_wx_PrintPreview *pObj = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintPreview(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_PrintPreview, GetCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPreviewCanvas *rtn = (wxPreviewCanvas *)pThis->GetEntity()->GetCanvas();
	return ReturnValue(env, arg, Value(new Object_wx_PreviewCanvas(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetCurrentPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetCurrentPage();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame *rtn = (wxFrame *)pThis->GetEntity()->GetFrame();
	return ReturnValue(env, arg, Value(new Object_wx_Frame(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetMaxPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetMaxPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMaxPage();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetMinPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetMinPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMinPage();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintout)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintout *rtn = (wxPrintout *)pThis->GetEntity()->GetPrintout();
	return ReturnValue(env, arg, Value(new Object_wx_Printout(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintout *rtn = (wxPrintout *)pThis->GetEntity()->GetPrintoutForPrinting();
	return ReturnValue(env, arg, Value(new Object_wx_Printout(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, Ok)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, Ok)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Ok();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, PaintPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "canvas", VTYPE_wx_PreviewCanvas, OCCUR_Once);
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, PaintPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPreviewCanvas *canvas = Object_wx_PreviewCanvas::GetObject(arg, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(arg, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->PaintPage(canvas, *dc);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, Print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prompt", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, Print)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool prompt = arg.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Print(prompt);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, RenderPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, RenderPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pageNum = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->RenderPage(pageNum);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, SetCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_PreviewCanvas, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCanvas)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPreviewCanvas *window = Object_wx_PreviewCanvas::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetCanvas(window);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCurrentPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int pageNum = arg.GetInt(0);
	pThis->GetEntity()->SetCurrentPage(pageNum);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFrame *frame = Object_wx_Frame::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetFrame(frame);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetPrintout)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintout *printout = Object_wx_Printout::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->SetPrintout(printout);
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintPreview, SetZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetZoom)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int percent = arg.GetInt(0);
	pThis->GetEntity()->SetZoom(percent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxPrintPreview
//----------------------------------------------------------------------------
Object_wx_PrintPreview::~Object_wx_PrintPreview()
{
}

Object *Object_wx_PrintPreview::Clone() const
{
	return nullptr;
}

String Object_wx_PrintPreview::ToString(bool exprFlag)
{
	String rtn("<wx.PrintPreview:");
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
// Class implementation for wxPrintPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintPreview)
{
	Gura_AssignFunction(PrintPreview);
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
	return new Object_wx_PrintPreview((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
