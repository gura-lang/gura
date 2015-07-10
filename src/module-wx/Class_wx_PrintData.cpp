//----------------------------------------------------------------------------
// wxPrintData
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrintData: public wxPrintData, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_PrintData *_pObj;
public:
	inline wx_PrintData() : wxPrintData(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_PrintData(const wxPrintData& data) : wxPrintData(data), _pSig(nullptr), _pObj(nullptr) {}
	~wx_PrintData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PrintData *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrintData::~wx_PrintData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PrintData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintData
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrintDataEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PrintData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PrintData *pEntity = new wx_PrintData();
	Object_wx_PrintData *pObj = Object_wx_PrintData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(PrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintData));
	DeclareArg(env, "data", VTYPE_wx_PrintData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintData *data = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	wx_PrintData *pEntity = new wx_PrintData(*data);
	Object_wx_PrintData *pObj = Object_wx_PrintData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PrintData, GetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetCollate)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetCollate();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetBin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetBin)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintBin rtn = pThis->GetEntity()->GetBin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetColour)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetColour();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetDuplex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetDuplex)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDuplexMode rtn = pThis->GetEntity()->GetDuplex();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetNoCopies)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNoCopies();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetOrientation)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetPaperId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetPaperId)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPaperSize rtn = pThis->GetEntity()->GetPaperId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, GetPrinterName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetPrinterName)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPrinterName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PrintData, GetQuality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, GetQuality)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintQuality rtn = pThis->GetEntity()->GetQuality();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintData, IsOk)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintData, SetBin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetBin)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintBin flag = static_cast<wxPrintBin>(args.GetInt(0));
	pThis->GetEntity()->SetBin(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetCollate)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetCollate(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetColour)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetColour(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetDuplex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetDuplex)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDuplexMode mode = static_cast<wxDuplexMode>(args.GetInt(0));
	pThis->GetEntity()->SetDuplex(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetNoCopies)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetNoCopies(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetOrientation)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int orientation = args.GetInt(0);
	pThis->GetEntity()->SetOrientation(orientation);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetPaperId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "paperId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPaperId)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPaperSize paperId = static_cast<wxPaperSize>(args.GetInt(0));
	pThis->GetEntity()->SetPaperId(paperId);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetPrinterName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printerName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetPrinterName)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString printerName = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetPrinterName(printerName);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintData, SetQuality)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "quality", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintData, SetQuality)
{
	Object_wx_PrintData *pThis = Object_wx_PrintData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintQuality quality = static_cast<wxPrintQuality>(args.GetInt(0));
	pThis->GetEntity()->SetQuality(quality);
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
	return nullptr;
}

String Object_wx_PrintData::ToString(bool exprFlag)
{
	String rtn("<wx.PrintData:");
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
// Class implementation for wxPrintData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintData)
{
	Gura_AssignFunction(PrintDataEmpty);
	Gura_AssignFunction(PrintData);
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
	return new Object_wx_PrintData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
