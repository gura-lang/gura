//----------------------------------------------------------------------------
// wxPrintData
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrintData: public wxPrintData, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PrintData *_pObj;
public:
	inline wx_PrintData() : wxPrintData(), _sig(NULL), _pObj(NULL) {}
	inline wx_PrintData(const wxPrintData& data) : wxPrintData(data), _sig(NULL), _pObj(NULL) {}
	~wx_PrintData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PrintData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrintData::~wx_PrintData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PrintData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintData
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrintDataEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PrintData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PrintData *pEntity = new wx_PrintData();
	Object_wx_PrintData *pObj = Object_wx_PrintData::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PrintData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(PrintData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintData));
	DeclareArg(env, "data", VTYPE_wx_PrintData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintData *data = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	wx_PrintData *pEntity = new wx_PrintData(*data);
	Object_wx_PrintData *pObj = Object_wx_PrintData::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PrintData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_PrintData, GetCollate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetCollate)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetCollate();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetBin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetBin)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintBin rtn = pSelf->GetEntity()->GetBin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetColour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetColour)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->GetColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetDuplex)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetDuplex)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDuplexMode rtn = pSelf->GetEntity()->GetDuplex();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetNoCopies)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetNoCopies)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetNoCopies();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetOrientation)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetPaperId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetPaperId)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPaperSize rtn = pSelf->GetEntity()->GetPaperId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetPrinterName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetPrinterName)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPrinterName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PrintData, GetQuality)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetQuality)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintQuality rtn = pSelf->GetEntity()->GetQuality();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, IsOk)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, SetBin)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetBin)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintBin flag = static_cast<wxPrintBin>(args.GetInt(0));
	pSelf->GetEntity()->SetBin(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetCollate)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetCollate)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pSelf->GetEntity()->SetCollate(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetColour)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetColour)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pSelf->GetEntity()->SetColour(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetDuplex)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetDuplex)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDuplexMode mode = static_cast<wxDuplexMode>(args.GetInt(0));
	pSelf->GetEntity()->SetDuplex(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetNoCopies)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetNoCopies)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pSelf->GetEntity()->SetNoCopies(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetOrientation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetOrientation)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	pSelf->GetEntity()->SetOrientation(orientation);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetPaperId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "paperId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPaperId)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPaperSize paperId = static_cast<wxPaperSize>(args.GetInt(0));
	pSelf->GetEntity()->SetPaperId(paperId);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetPrinterName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printerName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPrinterName)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString printerName = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetPrinterName(printerName);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetQuality)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetQuality)
{
	Object_wx_PrintData *pSelf = Object_wx_PrintData::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxPrintQuality quality = static_cast<wxPrintQuality>(args.GetInt(0));
	pSelf->GetEntity()->SetQuality(quality);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPrintData
//----------------------------------------------------------------------------
Object_wx_PrintData::~Object_wx_PrintData()
{
}

Object *Object_wx_PrintData::Clone() const
{
	return NULL;
}

String Object_wx_PrintData::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PrintData:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PrintData::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(PrintDataEmpty);
	Gura_AssignFunction(PrintData);
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintData)
{
	Gura_AssignMethod(wx_PrintData, GetCollate);
	Gura_AssignMethod(wx_PrintData, GetBin);
	Gura_AssignMethod(wx_PrintData, GetColour);
	Gura_AssignMethod(wx_PrintData, GetDuplex);
	Gura_AssignMethod(wx_PrintData, GetNoCopies);
	Gura_AssignMethod(wx_PrintData, GetOrientation);
	Gura_AssignMethod(wx_PrintData, GetPaperId);
	Gura_AssignMethod(wx_PrintData, GetPrinterName);
	Gura_AssignMethod(wx_PrintData, GetQuality);
	Gura_AssignMethod(wx_PrintData, IsOk);
	Gura_AssignMethod(wx_PrintData, SetBin);
	Gura_AssignMethod(wx_PrintData, SetCollate);
	Gura_AssignMethod(wx_PrintData, SetColour);
	Gura_AssignMethod(wx_PrintData, SetDuplex);
	Gura_AssignMethod(wx_PrintData, SetNoCopies);
	Gura_AssignMethod(wx_PrintData, SetOrientation);
	Gura_AssignMethod(wx_PrintData, SetPaperId);
	Gura_AssignMethod(wx_PrintData, SetPrinterName);
	Gura_AssignMethod(wx_PrintData, SetQuality);
}

Gura_ImplementDescendantCreator(wx_PrintData)
{
	return new Object_wx_PrintData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
