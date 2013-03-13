//----------------------------------------------------------------------------
// wxGridTableBase
// extracted from gridtbl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(GetNumberRows);
Gura_DeclarePrivUserSymbol(GetNumberCols);
Gura_DeclarePrivUserSymbol(IsEmptyCell);
Gura_DeclarePrivUserSymbol(GetValue);
Gura_DeclarePrivUserSymbol(SetValue);

Gura_DeclarePrivUserSymbol(GetTypeName);
Gura_DeclarePrivUserSymbol(CanGetValueAs);
Gura_DeclarePrivUserSymbol(CanSetValueAs);
Gura_DeclarePrivUserSymbol(GetValueAsLong);
Gura_DeclarePrivUserSymbol(GetValueAsDouble);
Gura_DeclarePrivUserSymbol(GetValueAsBool);
Gura_DeclarePrivUserSymbol(SetValueAsLong);
Gura_DeclarePrivUserSymbol(SetValueAsDouble);
Gura_DeclarePrivUserSymbol(SetValueAsBool);

Gura_DeclarePrivUserSymbol(GetRowLabelValue);
Gura_DeclarePrivUserSymbol(GetColLabelValue);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GridTableBase: public wxGridTableBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	AutoPtr<Object_wx_GridTableBase> _pObj;
public:
	inline wx_GridTableBase() : wxGridTableBase(), _sig(NULL), _pObj(NULL) {}
	~wx_GridTableBase();
	virtual int GetNumberRows();
	virtual int GetNumberCols();
	virtual bool IsEmptyCell(int row, int col);
	virtual wxString GetValue(int row, int col);
	virtual void SetValue(int row, int col, const wxString &value);
	virtual wxString GetTypeName(int row, int col);
	virtual bool CanGetValueAs(int row, int col, const wxString& typeName);
	virtual bool CanSetValueAs(int row, int col, const wxString& typeName);
	virtual long GetValueAsLong(int row, int col);
	virtual double GetValueAsDouble(int row, int col);
	virtual bool GetValueAsBool(int row, int col);
	virtual void SetValueAsLong(int row, int col, long value);
	virtual void SetValueAsDouble(int row, int col, double value);
	virtual void SetValueAsBool(int row, int col, bool value);
	virtual wxString GetRowLabelValue(int row);
	virtual wxString GetColLabelValue(int col);
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GridTableBase *pObj) {
		_sig = sig, _pObj.reset(Object_wx_GridTableBase::Reference(pObj));
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GridTableBase::~wx_GridTableBase()
{
}

void wx_GridTableBase::GuraObjectDeleted()
{
}

int wx_GridTableBase::GetNumberRows()
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetNumberRows), true);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.GridTableBase#GetNumberRows method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return 0;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

int wx_GridTableBase::GetNumberCols()
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetNumberCols), true);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.GridTableBase#GetNumberCols method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return 0;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

bool wx_GridTableBase::IsEmptyCell(int row, int col)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(IsEmptyCell), true);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.GridTableBase#IsEmptyCell method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(row));
	valListArg.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

wxString wx_GridTableBase::GetValue(int row, int col)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetValue), true);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.GridTableBase#GetValue method is missing");
		return wxEmptyString;
	}
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(row));
	valListArg.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig)) return wxEmptyString;
	return wxString::FromUTF8(rtn.ToString(_sig, false).c_str());
}

void wx_GridTableBase::SetValue(int row, int col, const wxString &value)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(SetValue), true);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.GridTableBase#SetValue method is missing");
		return;
	}
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.reserve(3);
	valListArg.push_back(Value(row));
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(env, value.ToUTF8()));
	_pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	CheckMethodResult(_sig);
}

wxString wx_GridTableBase::GetTypeName(int row, int col)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetTypeName), true);
	if (pFunc == NULL) return wxGridTableBase::GetTypeName(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_string)) return wxEmptyString;
	return wxString::FromUTF8(rtn.GetString());
}

bool wx_GridTableBase::CanGetValueAs(int row, int col, const wxString& typeName)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(CanGetValueAs), true);
	if (pFunc == NULL) return wxGridTableBase::CanGetValueAs(row, col, typeName);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(env, typeName.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_GridTableBase::CanSetValueAs(int row, int col, const wxString& typeName)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(CanSetValueAs), true);
	if (pFunc == NULL) return wxGridTableBase::CanSetValueAs(row, col, typeName);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(env, typeName.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

long wx_GridTableBase::GetValueAsLong(int row, int col)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetValueAsLong), true);
	if (pFunc == NULL) return wxGridTableBase::GetValueAsLong(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetLong();
}

double wx_GridTableBase::GetValueAsDouble(int row, int col)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetValueAsDouble), true);
	if (pFunc == NULL) return wxGridTableBase::GetValueAsDouble(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return false;
	return rtn.GetDouble();
}

bool wx_GridTableBase::GetValueAsBool(int row, int col)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(GetValueAsBool), true);
	if (pFunc == NULL) return wxGridTableBase::GetValueAsBool(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

void wx_GridTableBase::SetValueAsLong(int row, int col, long value)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(SetValueAsLong), true);
	if (pFunc == NULL) return wxGridTableBase::SetValueAsLong(row, col, value);
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(value));
	_pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	CheckMethodResult(_sig);
}

void wx_GridTableBase::SetValueAsDouble(int row, int col, double value)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(SetValueAsDouble), true);
	if (pFunc == NULL) {
		wxGridTableBase::SetValueAsDouble(row, col, value);
		return;
	}
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(value));
	_pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	CheckMethodResult(_sig);
}

void wx_GridTableBase::SetValueAsBool(int row, int col, bool value)
{
	const Function *pFunc = _pObj->LookupFunctionCustom(Gura_UserSymbol(SetValueAsBool), true);
	if (pFunc == NULL) {
		wxGridTableBase::SetValueAsBool(row, col, value);
		return;
	}
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(value));
	_pObj->EvalMethod(*_pObj, _sig, pFunc, valList);
	CheckMethodResult(_sig);
}

wxString wx_GridTableBase::GetRowLabelValue(int row)
{
	Function *pFunc = _pObj->LookupFunctionCustom(
									Gura_UserSymbol(GetRowLabelValue), true);
	if (pFunc == NULL) return wxGridTableBase::GetRowLabelValue(row);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig)) return wxEmptyString;
	return wxString::FromUTF8(rtn.ToString(_sig, false).c_str());
}

wxString wx_GridTableBase::GetColLabelValue(int col)
{
	Function *pFunc = _pObj->LookupFunctionCustom(
									Gura_UserSymbol(GetColLabelValue), true);
	if (pFunc == NULL) return wxGridTableBase::GetColLabelValue(col);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig)) return wxEmptyString;
	return wxString::FromUTF8(rtn.ToString(_sig, false).c_str());
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridTableBase
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridTableBase)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridTableBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridTableBase)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_GridTableBase *pEntity = new wx_GridTableBase();
	Object_wx_GridTableBase *pObj = Object_wx_GridTableBase::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_GridTableBase(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_GridTableBase, GetTypeName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetTypeName)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxString rtn = pThis->GetEntity()->wxGridTableBase::GetTypeName(row, col);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GridTableBase, CanGetValueAs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, CanGetValueAs)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxString typeName = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->wxGridTableBase::CanGetValueAs(row, col, typeName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, CanSetValueAs)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, CanSetValueAs)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxString typeName = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->wxGridTableBase::CanSetValueAs(row, col, typeName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsLong)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsLong)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	long rtn = pThis->GetEntity()->wxGridTableBase::GetValueAsLong(row, col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsDouble)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsDouble)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	double rtn = pThis->GetEntity()->wxGridTableBase::GetValueAsDouble(row, col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsBool)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsBool)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::GetValueAsBool(row, col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsLong)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsLong)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	long value = args.GetLong(2);
	pThis->GetEntity()->wxGridTableBase::SetValueAsLong(row, col, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsDouble)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsDouble)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	double value = args.GetDouble(2);
	pThis->GetEntity()->wxGridTableBase::SetValueAsDouble(row, col, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsBool)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsBool)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	bool value = args.GetBoolean(2);
	pThis->GetEntity()->wxGridTableBase::SetValueAsBool(row, col, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsCustom)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsCustom)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxString typeName = wxString::FromUTF8(args.GetString(2));
	pThis->GetEntity()->wxGridTableBase::GetValueAsCustom(row, col, typeName);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsCustom)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsCustom)
{
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxString typeName = wxString::FromUTF8(args.GetString(2));
	int value = args.GetInt(3);
	pThis->GetEntity()->wxGridTableBase::SetValueAsCustom(row, col, typeName, value);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetView)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetView)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid *grid = Object_wx_Grid::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxGridTableBase::SetView(grid);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, GetView)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetView)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid *rtn = (wxGrid *)pThis->GetEntity()->wxGridTableBase::GetView();
	return ReturnValue(env, sig, args, Value(new Object_wx_Grid(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridTableBase, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, Clear)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->wxGridTableBase::Clear();
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, InsertRows)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, InsertRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = 0;
	if (args.IsValid(0)) pos = args.GetSizeT(0);
	size_t numRows = 1;
	if (args.IsValid(1)) numRows = args.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::InsertRows(pos, numRows);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, AppendRows)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, AppendRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t numRows = 1;
	if (args.IsValid(0)) numRows = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->wxGridTableBase::AppendRows(numRows);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, DeleteRows)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, DeleteRows)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = 0;
	if (args.IsValid(0)) pos = args.GetSizeT(0);
	size_t numRows = 1;
	if (args.IsValid(1)) numRows = args.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::DeleteRows(pos, numRows);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, InsertCols)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, InsertCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = 0;
	if (args.IsValid(0)) pos = args.GetSizeT(0);
	size_t numCols = 1;
	if (args.IsValid(1)) numCols = args.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::InsertCols(pos, numCols);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, AppendCols)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, AppendCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t numCols = 1;
	if (args.IsValid(0)) numCols = args.GetSizeT(0);
	bool rtn = pThis->GetEntity()->wxGridTableBase::AppendCols(numCols);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, DeleteCols)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, DeleteCols)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = 0;
	if (args.IsValid(0)) pos = args.GetSizeT(0);
	size_t numCols = 1;
	if (args.IsValid(1)) numCols = args.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::DeleteCols(pos, numCols);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetRowLabelValue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetRowLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->wxGridTableBase::GetRowLabelValue(row);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GridTableBase, GetColLabelValue)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetColLabelValue)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->wxGridTableBase::GetColLabelValue(col);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GridTableBase, SetRowLabelValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "WXUNUSED(row)", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, SetRowLabelValue)
{
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int WXUNUSED(row) = args.GetInt(0);
	pThis->GetEntity()->wxGridTableBase::SetRowLabelValue(WXUNUSED(row), );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetColLabelValue)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "WXUNUSED(col)", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, SetColLabelValue)
{
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int WXUNUSED(col) = args.GetInt(0);
	pThis->GetEntity()->wxGridTableBase::SetColLabelValue(WXUNUSED(col), );
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetAttrProvider)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attrProvider", VTYPE_wx_GridCellAttrProvider, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetAttrProvider)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellAttrProvider *attrProvider = Object_wx_GridCellAttrProvider::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->wxGridTableBase::SetAttrProvider(attrProvider);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, GetAttrProvider)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetAttrProvider)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellAttrProvider *rtn = (wxGridCellAttrProvider *)pThis->GetEntity()->wxGridTableBase::GetAttrProvider();
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellAttrProvider(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridTableBase, CanHaveAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, CanHaveAttributes)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxGridTableBase::CanHaveAttributes();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, UpdateAttrRows)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, UpdateAttrRows)
{
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	int numRows = args.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::UpdateAttrRows(pos, numRows);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, UpdateAttrCols)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, UpdateAttrCols)
{
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t pos = args.GetSizeT(0);
	int numCols = args.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::UpdateAttrCols(pos, numCols);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, GetAttr)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetAttr)
{
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellAttr *rtn = (wxGridCellAttr *)pThis->GetEntity()->wxGridTableBase::GetAttr(row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellAttr(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetAttr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 0)->GetEntity();
	int row = args.GetInt(1);
	int col = args.GetInt(2);
	pThis->GetEntity()->wxGridTableBase::SetAttr(attr, row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetRowAttr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetRowAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 0)->GetEntity();
	int row = args.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::SetRowAttr(attr, row);
	return Value::Null;
}

Gura_DeclareMethod(wx_GridTableBase, SetColAttr)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetColAttr)
{
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 0)->GetEntity();
	int col = args.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::SetColAttr(attr, col);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridTableBase
//----------------------------------------------------------------------------
Object_wx_GridTableBase::~Object_wx_GridTableBase()
{
}

Object *Object_wx_GridTableBase::Clone() const
{
	return NULL;
}

String Object_wx_GridTableBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.GridTableBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_GridTableBase::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(GetNumberRows);
	Gura_RealizeUserSymbol(GetNumberCols);
	Gura_RealizeUserSymbol(IsEmptyCell);
	Gura_RealizeUserSymbol(GetValue);
	Gura_RealizeUserSymbol(SetValue);
	Gura_RealizeUserSymbol(GetTypeName);
	Gura_RealizeUserSymbol(CanGetValueAs);
	Gura_RealizeUserSymbol(CanSetValueAs);
	Gura_RealizeUserSymbol(GetValueAsLong);
	Gura_RealizeUserSymbol(GetValueAsDouble);
	Gura_RealizeUserSymbol(GetValueAsBool);
	Gura_RealizeUserSymbol(SetValueAsLong);
	Gura_RealizeUserSymbol(SetValueAsDouble);
	Gura_RealizeUserSymbol(SetValueAsBool);
	Gura_RealizeUserSymbol(GetRowLabelValue);
	Gura_RealizeUserSymbol(GetColLabelValue);
	Gura_AssignFunction(GridTableBase);
}

//----------------------------------------------------------------------------
// Class implementation for wxGridTableBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridTableBase)
{
	Gura_AssignMethod(wx_GridTableBase, GetTypeName);
	Gura_AssignMethod(wx_GridTableBase, CanGetValueAs);
	Gura_AssignMethod(wx_GridTableBase, CanSetValueAs);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsLong);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsDouble);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsBool);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsLong);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsDouble);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsBool);
	Gura_AssignMethod(wx_GridTableBase, GetValueAsCustom);
	Gura_AssignMethod(wx_GridTableBase, SetValueAsCustom);
	Gura_AssignMethod(wx_GridTableBase, SetView);
	Gura_AssignMethod(wx_GridTableBase, GetView);
	Gura_AssignMethod(wx_GridTableBase, Clear);
	Gura_AssignMethod(wx_GridTableBase, InsertRows);
	Gura_AssignMethod(wx_GridTableBase, AppendRows);
	Gura_AssignMethod(wx_GridTableBase, DeleteRows);
	Gura_AssignMethod(wx_GridTableBase, InsertCols);
	Gura_AssignMethod(wx_GridTableBase, AppendCols);
	Gura_AssignMethod(wx_GridTableBase, DeleteCols);
	Gura_AssignMethod(wx_GridTableBase, GetRowLabelValue);
	Gura_AssignMethod(wx_GridTableBase, GetColLabelValue);
	Gura_AssignMethod(wx_GridTableBase, SetRowLabelValue);
	Gura_AssignMethod(wx_GridTableBase, SetColLabelValue);
	Gura_AssignMethod(wx_GridTableBase, SetAttrProvider);
	Gura_AssignMethod(wx_GridTableBase, GetAttrProvider);
	Gura_AssignMethod(wx_GridTableBase, CanHaveAttributes);
	Gura_AssignMethod(wx_GridTableBase, UpdateAttrRows);
	Gura_AssignMethod(wx_GridTableBase, UpdateAttrCols);
	Gura_AssignMethod(wx_GridTableBase, GetAttr);
	Gura_AssignMethod(wx_GridTableBase, SetAttr);
	Gura_AssignMethod(wx_GridTableBase, SetRowAttr);
	Gura_AssignMethod(wx_GridTableBase, SetColAttr);
}

Gura_ImplementDescendantCreator(wx_GridTableBase)
{
	return new Object_wx_GridTableBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
