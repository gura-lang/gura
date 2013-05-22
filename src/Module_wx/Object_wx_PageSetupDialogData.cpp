//----------------------------------------------------------------------------
// wxPageSetupDialogData
// extracted from pagedlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PageSetupDialogData: public wxPageSetupDialogData, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PageSetupDialogData *_pObj;
public:
	inline wx_PageSetupDialogData() : wxPageSetupDialogData(), _sig(NULL), _pObj(NULL) {}
	inline wx_PageSetupDialogData(wxPageSetupDialogData& data) : wxPageSetupDialogData(data), _sig(NULL), _pObj(NULL) {}
	inline wx_PageSetupDialogData(wxPrintData& printData) : wxPageSetupDialogData(printData), _sig(NULL), _pObj(NULL) {}
	~wx_PageSetupDialogData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PageSetupDialogData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PageSetupDialogData::~wx_PageSetupDialogData()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PageSetupDialogData::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupDialogData
//----------------------------------------------------------------------------
Gura_DeclareFunction(PageSetupDialogDataEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PageSetupDialogData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PageSetupDialogDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PageSetupDialogData *pEntity = new wx_PageSetupDialogData();
	Object_wx_PageSetupDialogData *pObj = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PageSetupDialogData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(PageSetupDialogData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PageSetupDialogData));
	DeclareArg(env, "data", VTYPE_wx_PageSetupDialogData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PageSetupDialogData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPageSetupDialogData *data = Object_wx_PageSetupDialogData::GetObject(args, 0)->GetEntity();
	wx_PageSetupDialogData *pEntity = new wx_PageSetupDialogData(*data);
	Object_wx_PageSetupDialogData *pObj = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PageSetupDialogData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(PageSetupDialogData_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PageSetupDialogData));
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PageSetupDialogData_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	wx_PageSetupDialogData *pEntity = new wx_PageSetupDialogData(*printData);
	Object_wx_PageSetupDialogData *pObj = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_PageSetupDialogData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnableHelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnableHelp)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnableHelp(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnableMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnableMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnableMargins(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnableOrientation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnableOrientation)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnableOrientation(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnablePaper)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnablePaper)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnablePaper(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, EnablePrinter)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, EnablePrinter)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnablePrinter(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetDefaultMinMargins)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetDefaultMinMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetDefaultMinMargins();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnableMargins)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnableMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetEnableMargins();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnableOrientation)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnableOrientation)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetEnableOrientation();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnablePaper)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnablePaper)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetEnablePaper();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnablePrinter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnablePrinter)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetEnablePrinter();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetEnableHelp)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetEnableHelp)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetEnableHelp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetDefaultInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetDefaultInfo)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetDefaultInfo();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMarginTopLeft)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetMarginTopLeft();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMarginBottomRight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetMarginBottomRight();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMinMarginTopLeft)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMinMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetMinMarginTopLeft();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetMinMarginBottomRight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetMinMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetMinMarginBottomRight();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetPaperId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetPaperId)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPaperSize rtn = pThis->GetEntity()->GetPaperId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetPaperSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetPaperSize)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetPaperSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_PageSetupDialogData, GetPrintData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, GetPrintData)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintData &rtn = pThis->GetEntity()->GetPrintData();
	return ReturnValue(env, sig, args, Value(new Object_wx_PrintData(new wxPrintData(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_PageSetupDialogData, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PageSetupDialogData, IsOk)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetDefaultInfo)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetDefaultInfo)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetDefaultInfo(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetDefaultMinMargins)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetDefaultMinMargins)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetDefaultMinMargins(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMarginTopLeft)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMarginTopLeft(*pt);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMarginBottomRight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMarginBottomRight(*pt);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMinMarginTopLeft)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMinMarginTopLeft)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMinMarginTopLeft(*pt);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetMinMarginBottomRight)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetMinMarginBottomRight)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetMinMarginBottomRight(*pt);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetPaperId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetPaperId)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPaperSize id = static_cast<wxPaperSize>(args.GetInt(0));
	pThis->GetEntity()->SetPaperId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetPaperSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetPaperSize)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPaperSize(*size);
	return Value::Null;
}

Gura_DeclareMethod(wx_PageSetupDialogData, SetPrintData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialogData, SetPrintData)
{
	Object_wx_PageSetupDialogData *pThis = Object_wx_PageSetupDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPrintData(*printData);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupDialogData
//----------------------------------------------------------------------------
Object_wx_PageSetupDialogData::~Object_wx_PageSetupDialogData()
{
}

Object *Object_wx_PageSetupDialogData::Clone() const
{
	return NULL;
}

String Object_wx_PageSetupDialogData::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PageSetupDialogData:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_PageSetupDialogData::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(PageSetupDialogDataEmpty);
	Gura_AssignFunction(PageSetupDialogData);
	Gura_AssignFunction(PageSetupDialogData_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxPageSetupDialogData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupDialogData)
{
	Gura_AssignMethod(wx_PageSetupDialogData, EnableHelp);
	Gura_AssignMethod(wx_PageSetupDialogData, EnableMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, EnableOrientation);
	Gura_AssignMethod(wx_PageSetupDialogData, EnablePaper);
	Gura_AssignMethod(wx_PageSetupDialogData, EnablePrinter);
	Gura_AssignMethod(wx_PageSetupDialogData, GetDefaultMinMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnableMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnableOrientation);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnablePaper);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnablePrinter);
	Gura_AssignMethod(wx_PageSetupDialogData, GetEnableHelp);
	Gura_AssignMethod(wx_PageSetupDialogData, GetDefaultInfo);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMinMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, GetMinMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, GetPaperId);
	Gura_AssignMethod(wx_PageSetupDialogData, GetPaperSize);
	Gura_AssignMethod(wx_PageSetupDialogData, GetPrintData);
	Gura_AssignMethod(wx_PageSetupDialogData, IsOk);
	Gura_AssignMethod(wx_PageSetupDialogData, SetDefaultInfo);
	Gura_AssignMethod(wx_PageSetupDialogData, SetDefaultMinMargins);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMinMarginTopLeft);
	Gura_AssignMethod(wx_PageSetupDialogData, SetMinMarginBottomRight);
	Gura_AssignMethod(wx_PageSetupDialogData, SetPaperId);
	Gura_AssignMethod(wx_PageSetupDialogData, SetPaperSize);
	Gura_AssignMethod(wx_PageSetupDialogData, SetPrintData);
}

Gura_ImplementDescendantCreator(wx_PageSetupDialogData)
{
	return new Object_wx_PageSetupDialogData((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
