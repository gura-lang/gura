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
	Gura::Signal *_pSig;
	Object_wx_PrintPreview *_pObj;
public:
	inline wx_PrintPreview(wxPrintout* printout, wxPrintout* printoutForPrinting, wxPrintData* data) : wxPrintPreview(printout, printoutForPrinting, data), _pSig(nullptr), _pObj(nullptr) {}
	~wx_PrintPreview();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PrintPreview *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintout *printout = Object_wx_Printout::GetObject(args, 0)->GetEntity();
	wxPrintout *printoutForPrinting = Object_wx_Printout::GetObject(args, 1)->GetEntity();
	wxPrintData *data = (wxPrintData *)(nullptr);
	if (args.IsValid(2)) data = Object_wx_PrintData::GetObject(args, 2)->GetEntity();
	wx_PrintPreview *pEntity = new wx_PrintPreview(printout, printoutForPrinting, data);
	Object_wx_PrintPreview *pObj = Object_wx_PrintPreview::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintPreview(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_PrintPreview, GetCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetCanvas)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPreviewCanvas *rtn = (wxPreviewCanvas *)pThis->GetEntity()->GetCanvas();
	return ReturnValue(env, args, Value(new Object_wx_PreviewCanvas(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetCurrentPage)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCurrentPage();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetFrame)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFrame *rtn = (wxFrame *)pThis->GetEntity()->GetFrame();
	return ReturnValue(env, args, Value(new Object_wx_Frame(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetMaxPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetMaxPage)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMaxPage();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetMinPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetMinPage)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMinPage();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintout)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintout *rtn = (wxPrintout *)pThis->GetEntity()->GetPrintout();
	return ReturnValue(env, args, Value(new Object_wx_Printout(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, GetPrintoutForPrinting)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintout *rtn = (wxPrintout *)pThis->GetEntity()->GetPrintoutForPrinting();
	return ReturnValue(env, args, Value(new Object_wx_Printout(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_PrintPreview, Ok)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, Ok)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Ok();
	return ReturnValue(env, args, Value(rtn));
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
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPreviewCanvas *canvas = Object_wx_PreviewCanvas::GetObject(args, 0)->GetEntity();
	wxDC *dc = Object_wx_DC::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->PaintPage(canvas, *dc);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, Print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prompt", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, Print)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool prompt = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Print(prompt);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, RenderPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintPreview, RenderPage)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pageNum = args.GetInt(0);
	bool rtn = pThis->GetEntity()->RenderPage(pageNum);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintPreview, SetCanvas)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_PreviewCanvas, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCanvas)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPreviewCanvas *window = Object_wx_PreviewCanvas::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCanvas(window);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pageNum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetCurrentPage)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pageNum = args.GetInt(0);
	pThis->GetEntity()->SetCurrentPage(pageNum);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "frame", VTYPE_wx_Frame, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetFrame)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFrame *frame = Object_wx_Frame::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFrame(frame);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetPrintout)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintout *printout = Object_wx_Printout::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPrintout(printout);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintPreview, SetZoom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "percent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintPreview, SetZoom)
{
	Object_wx_PrintPreview *pThis = Object_wx_PrintPreview::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int percent = args.GetInt(0);
	pThis->GetEntity()->SetZoom(percent);
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
