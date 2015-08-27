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
	//Gura::Signal *_pSig;
	Object_wx_PrinterDC *_pObj;
public:
	inline wx_PrinterDC(const wxPrintData& printData) : wxPrinterDC(printData), _pObj(nullptr) {}
	//inline wx_PrinterDC(const wxString& driver, const wxString& device, const wxString& output, const bool interactive, int orientation) : wxPrinterDC(driver, device, output, interactive, orientation), _pObj(nullptr) {}
	~wx_PrinterDC();
	inline void AssocWithGura(Object_wx_PrinterDC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrinterDC::~wx_PrinterDC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PrinterDC::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	wx_PrinterDC *pEntity = new wx_PrinterDC(*printData);
	Object_wx_PrinterDC *pObj = Object_wx_PrinterDC::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrinterDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString driver = wxString::FromUTF8(args.GetString(0));
	wxString device = wxString::FromUTF8(args.GetString(1));
	wxString output = wxString::FromUTF8(args.GetString(2));
	bool interactive = true;
	if (args.IsValid(3)) interactive = args.GetBoolean(3);
	int orientation = wxPORTRAIT;
	if (args.IsValid(4)) orientation = args.GetInt(4);
	wx_PrinterDC *pEntity = new wx_PrinterDC(driver, device, output, interactive, orientation);
	Object_wx_PrinterDC *pObj = Object_wx_PrinterDC::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrinterDC(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}
#endif

Gura_DeclareMethod(wx_PrinterDC, GetPaperRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrinterDC, GetPaperRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrinterDC *pThis = Object_wx_PrinterDC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->wxPrinterDC::GetPaperRect();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxPrinterDC
//----------------------------------------------------------------------------
Object_wx_PrinterDC::~Object_wx_PrinterDC()
{
}

Object *Object_wx_PrinterDC::Clone() const
{
	return nullptr;
}

String Object_wx_PrinterDC::ToString(bool exprFlag)
{
	String rtn("<wx.PrinterDC:");
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
	return new Object_wx_PrinterDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
