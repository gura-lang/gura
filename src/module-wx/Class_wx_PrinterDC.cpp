//----------------------------------------------------------------------------
// wxPrinterDC
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrinterDC: public wxPrinterDC, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PrinterDC *_pObj;
public:
	inline wx_PrinterDC(const wxPrintData& printData) : wxPrinterDC(printData), _sig(NULL), _pObj(NULL) {}
	//inline wx_PrinterDC(const wxString& driver, const wxString& device, const wxString& output, const bool interactive, int orientation) : wxPrinterDC(driver, device, output, interactive, orientation), _sig(NULL), _pObj(NULL) {}
	~wx_PrinterDC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PrinterDC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrinterDC::~wx_PrinterDC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PrinterDC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrinterDC
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrinterDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrinterDC));
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrinterDC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	wx_PrinterDC *pEntity = new wx_PrinterDC(*printData);
	Object_wx_PrinterDC *pObj = Object_wx_PrinterDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PrinterDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

#if 0
Gura_DeclareFunction(PrinterDC_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrinterDC));
	DeclareArg(env, "driver", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "device", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "output", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "interactive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrinterDC_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString driver = wxString::FromUTF8(args.GetString(0));
	wxString device = wxString::FromUTF8(args.GetString(1));
	wxString output = wxString::FromUTF8(args.GetString(2));
	bool interactive = true;
	if (args.IsValid(3)) interactive = args.GetBoolean(3);
	int orientation = wxPORTRAIT;
	if (args.IsValid(4)) orientation = args.GetInt(4);
	wx_PrinterDC *pEntity = new wx_PrinterDC(driver, device, output, interactive, orientation);
	Object_wx_PrinterDC *pObj = Object_wx_PrinterDC::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PrinterDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}
#endif

Gura_DeclareMethod(wx_PrinterDC, GetPaperRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrinterDC, GetPaperRect)
{
	Object_wx_PrinterDC *pThis = Object_wx_PrinterDC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->wxPrinterDC::GetPaperRect();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxPrinterDC
//----------------------------------------------------------------------------
Object_wx_PrinterDC::~Object_wx_PrinterDC()
{
}

Object *Object_wx_PrinterDC::Clone() const
{
	return NULL;
}

String Object_wx_PrinterDC::ToString(bool exprFlag)
{
	String rtn("<wx.PrinterDC:");
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
// Class implementation for wxPrinterDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrinterDC)
{
	Gura_AssignFunction(PrinterDC);
	//Gura_AssignFunction(PrinterDC_1);
	Gura_AssignMethod(wx_PrinterDC, GetPaperRect);
}

Gura_ImplementDescendantCreator(wx_PrinterDC)
{
	return new Object_wx_PrinterDC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
