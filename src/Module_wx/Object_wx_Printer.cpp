//----------------------------------------------------------------------------
// wxPrinter
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Printer: public wxPrinter, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Printer *_pObj;
public:
	inline wx_Printer(wxPrintDialogData* data) : wxPrinter(data), _sig(NULL), _pObj(NULL) {}
	~wx_Printer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Printer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Printer::~wx_Printer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Printer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrinter
//----------------------------------------------------------------------------
Gura_DeclareFunction(Printer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Printer));
	DeclareArg(env, "data", VTYPE_wx_PrintDialogData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Printer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintDialogData *data = (wxPrintDialogData *)(NULL);
	if (args.IsValid(0)) data = Object_wx_PrintDialogData::GetObject(args, 0)->GetEntity();
	wx_Printer *pEntity = new wx_Printer(data);
	Object_wx_Printer *pObj = Object_wx_Printer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Printer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Printer, CreateAbortWindow)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, CreateAbortWindow)
{
	Object_wx_Printer *pSelf = Object_wx_Printer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxPrintout *printout = Object_wx_Printout::GetObject(args, 1)->GetEntity();
	pSelf->GetEntity()->CreateAbortWindow(parent, printout);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printer, GetAbort)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, GetAbort)
{
	Object_wx_Printer *pSelf = Object_wx_Printer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetAbort();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Printer, GetLastError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Printer, GetLastError)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrinterError rtn = wxPrinter::GetLastError();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printer, GetPrintDialogData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, GetPrintDialogData)
{
	Object_wx_Printer *pSelf = Object_wx_Printer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintDialogData &rtn = pSelf->GetEntity()->GetPrintDialogData();
	return ReturnValue(env, sig, args, Value(new Object_wx_PrintDialogData(new wxPrintDialogData(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printer, Print)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "prompt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, Print)
{
	Object_wx_Printer *pSelf = Object_wx_Printer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxPrintout *printout = Object_wx_Printout::GetObject(args, 1)->GetEntity();
	bool prompt = true;
	if (args.IsValid(2)) prompt = args.GetBoolean(2);
	bool rtn = pSelf->GetEntity()->Print(parent, printout, prompt);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Printer, PrintDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, PrintDialog)
{
	Object_wx_Printer *pSelf = Object_wx_Printer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxDC *rtn = (wxDC *)pSelf->GetEntity()->PrintDialog(parent);
	return ReturnValue(env, sig, args, Value(new Object_wx_DC(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Printer, ReportError)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, ReportError)
{
	Object_wx_Printer *pSelf = Object_wx_Printer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxPrintout *printout = Object_wx_Printout::GetObject(args, 1)->GetEntity();
	wxString message = wxString::FromUTF8(args.GetString(2));
	pSelf->GetEntity()->ReportError(parent, printout, message);
	return Value::Null;
}

Gura_DeclareMethod(wx_Printer, Setup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, Setup)
{
	Object_wx_Printer *pSelf = Object_wx_Printer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->Setup(parent);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPrinter
//----------------------------------------------------------------------------
Object_wx_Printer::~Object_wx_Printer()
{
}

Object *Object_wx_Printer::Clone() const
{
	return NULL;
}

String Object_wx_Printer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Printer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Printer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(Printer);
}

//----------------------------------------------------------------------------
// Class implementation for wxPrinter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Printer)
{
	Gura_AssignMethod(wx_Printer, CreateAbortWindow);
	Gura_AssignMethod(wx_Printer, GetAbort);
	Gura_AssignMethod(wx_Printer, GetLastError);
	Gura_AssignMethod(wx_Printer, GetPrintDialogData);
	Gura_AssignMethod(wx_Printer, Print);
	Gura_AssignMethod(wx_Printer, PrintDialog);
	Gura_AssignMethod(wx_Printer, ReportError);
	Gura_AssignMethod(wx_Printer, Setup);
}

Gura_ImplementDescendantCreator(wx_Printer)
{
	return new Object_wx_Printer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
