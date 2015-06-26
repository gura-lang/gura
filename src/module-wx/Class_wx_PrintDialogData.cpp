//----------------------------------------------------------------------------
// wxPrintDialogData
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PrintDialogData: public wxPrintDialogData, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PrintDialogData *_pObj;
public:
	inline wx_PrintDialogData() : wxPrintDialogData(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_PrintDialogData(wxPrintDialogData& dialogData) : wxPrintDialogData(dialogData), _sig(nullptr), _pObj(nullptr) {}
	inline wx_PrintDialogData(wxPrintData& printData) : wxPrintDialogData(printData), _sig(nullptr), _pObj(nullptr) {}
	~wx_PrintDialogData();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PrintDialogData *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PrintDialogData::~wx_PrintDialogData()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PrintDialogData::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintDialogData
//----------------------------------------------------------------------------
Gura_DeclareFunction(PrintDialogDataEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PrintDialogData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintDialogDataEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PrintDialogData *pEntity = new wx_PrintDialogData();
	Object_wx_PrintDialogData *pObj = Object_wx_PrintDialogData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintDialogData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(PrintDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintDialogData));
	DeclareArg(env, "dialogData", VTYPE_wx_PrintDialogData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintDialogData)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintDialogData *dialogData = Object_wx_PrintDialogData::GetObject(args, 0)->GetEntity();
	wx_PrintDialogData *pEntity = new wx_PrintDialogData(*dialogData);
	Object_wx_PrintDialogData *pObj = Object_wx_PrintDialogData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintDialogData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(PrintDialogData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PrintDialogData));
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PrintDialogData_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	wx_PrintDialogData *pEntity = new wx_PrintDialogData(*printData);
	Object_wx_PrintDialogData *pObj = Object_wx_PrintDialogData::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PrintDialogData(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PrintDialogData, EnableHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnableHelp)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnableHelp(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, EnablePageNumbers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnablePageNumbers)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnablePageNumbers(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, EnablePrintToFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnablePrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnablePrintToFile(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, EnableSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, EnableSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->EnableSelection(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, GetAllPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetAllPages)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetAllPages();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetCollate)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetCollate();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetFromPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetFromPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFromPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetMaxPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetMaxPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMaxPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetMinPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetMinPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMinPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetNoCopies)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNoCopies();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetPrintData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintData &rtn = pThis->GetEntity()->GetPrintData();
	return ReturnValue(env, sig, args, Value(new Object_wx_PrintData(new wxPrintData(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_PrintDialogData, GetPrintToFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetPrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetPrintToFile();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, GetToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, GetToPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetToPage();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PrintDialogData, IsOk)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PrintDialogData, SetCollate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetCollate)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetCollate(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetFromPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetFromPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetFromPage(page);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetMaxPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetMaxPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetMaxPage(page);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetMinPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetMinPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetMinPage(page);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetNoCopies)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetNoCopies)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	pThis->GetEntity()->SetNoCopies(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "printData", VTYPE_wx_PrintData, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetPrintData)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPrintData *printData = Object_wx_PrintData::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPrintData(*printData);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetPrintToFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetPrintToFile)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetPrintToFile(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetSelection)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetSelection(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetSetupDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_PrintDialogData, SetSetupDialog)
{
#if 0
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pThis->GetEntity()->SetSetupDialog(flag);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_PrintDialogData, SetToPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialogData, SetToPage)
{
	Object_wx_PrintDialogData *pThis = Object_wx_PrintDialogData::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int page = args.GetInt(0);
	pThis->GetEntity()->SetToPage(page);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPrintDialogData
//----------------------------------------------------------------------------
Object_wx_PrintDialogData::~Object_wx_PrintDialogData()
{
}

Object *Object_wx_PrintDialogData::Clone() const
{
	return nullptr;
}

String Object_wx_PrintDialogData::ToString(bool exprFlag)
{
	String rtn("<wx.PrintDialogData:");
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
// Class implementation for wxPrintDialogData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialogData)
{
	Gura_AssignFunction(PrintDialogDataEmpty);
	Gura_AssignFunction(PrintDialogData);
	Gura_AssignFunction(PrintDialogData_1);
	Gura_AssignMethod(wx_PrintDialogData, EnableHelp);
	Gura_AssignMethod(wx_PrintDialogData, EnablePageNumbers);
	Gura_AssignMethod(wx_PrintDialogData, EnablePrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, EnableSelection);
	Gura_AssignMethod(wx_PrintDialogData, GetAllPages);
	Gura_AssignMethod(wx_PrintDialogData, GetCollate);
	Gura_AssignMethod(wx_PrintDialogData, GetFromPage);
	Gura_AssignMethod(wx_PrintDialogData, GetMaxPage);
	Gura_AssignMethod(wx_PrintDialogData, GetMinPage);
	Gura_AssignMethod(wx_PrintDialogData, GetNoCopies);
	Gura_AssignMethod(wx_PrintDialogData, GetPrintData);
	Gura_AssignMethod(wx_PrintDialogData, GetPrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, GetSelection);
	Gura_AssignMethod(wx_PrintDialogData, GetToPage);
	Gura_AssignMethod(wx_PrintDialogData, IsOk);
	Gura_AssignMethod(wx_PrintDialogData, SetCollate);
	Gura_AssignMethod(wx_PrintDialogData, SetFromPage);
	Gura_AssignMethod(wx_PrintDialogData, SetMaxPage);
	Gura_AssignMethod(wx_PrintDialogData, SetMinPage);
	Gura_AssignMethod(wx_PrintDialogData, SetNoCopies);
	Gura_AssignMethod(wx_PrintDialogData, SetPrintData);
	Gura_AssignMethod(wx_PrintDialogData, SetPrintToFile);
	Gura_AssignMethod(wx_PrintDialogData, SetSelection);
	Gura_AssignMethod(wx_PrintDialogData, SetSetupDialog);
	Gura_AssignMethod(wx_PrintDialogData, SetToPage);
}

Gura_ImplementDescendantCreator(wx_PrintDialogData)
{
	return new Object_wx_PrintDialogData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
