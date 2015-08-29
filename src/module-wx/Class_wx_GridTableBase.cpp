//----------------------------------------------------------------------------
// wxGridTableBase
// extracted from gridtbl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	//Gura::Signal *_pSig;
	AutoPtr<Object_wx_GridTableBase> _pObj;
public:
	inline wx_GridTableBase() : wxGridTableBase(), _pObj(nullptr) {}
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
	inline void AssocWithGura(Object_wx_GridTableBase *pObj) {
		_pObj.reset(Object_wx_GridTableBase::Reference(pObj));
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
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetNumberRows);
	if (pFunc == nullptr) {
		_pObj->GetSignal().SetError(ERR_NotImplementedError, "wx.GridTableBase#GetNumberRows method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return 0;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

int wx_GridTableBase::GetNumberCols()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetNumberCols);
	if (pFunc == nullptr) {
		_pObj->GetSignal().SetError(ERR_NotImplementedError, "wx.GridTableBase#GetNumberCols method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return 0;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, ValueList::Empty);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return 0;
	return rtn.GetInt();
}

bool wx_GridTableBase::IsEmptyCell(int row, int col)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, IsEmptyCell);
	if (pFunc == nullptr) {
		_pObj->GetSignal().SetError(ERR_NotImplementedError, "wx.GridTableBase#IsEmptyCell method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(row));
	valListArg.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

wxString wx_GridTableBase::GetValue(int row, int col)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetValue);
	if (pFunc == nullptr) {
		_pObj->GetSignal().SetError(ERR_NotImplementedError, "wx.GridTableBase#GetValue method is missing");
		return wxEmptyString;
	}
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(row));
	valListArg.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal())) return wxEmptyString;
	return wxString::FromUTF8(rtn.ToString(false).c_str());
}

void wx_GridTableBase::SetValue(int row, int col, const wxString &value)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, SetValue);
	if (pFunc == nullptr) {
		_pObj->GetSignal().SetError(ERR_NotImplementedError, "wx.GridTableBase#SetValue method is missing");
		return;
	}
	Environment &env = *_pObj;
	ValueList valListArg;
	valListArg.reserve(3);
	valListArg.push_back(Value(row));
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(value.ToUTF8()));
	_pObj->EvalMethod(*_pObj, pFunc, valListArg);
	CheckMethodResult(_pObj->GetSignal());
}

wxString wx_GridTableBase::GetTypeName(int row, int col)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetTypeName);
	if (pFunc == nullptr) return wxGridTableBase::GetTypeName(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_string)) return wxEmptyString;
	return wxString::FromUTF8(rtn.GetString());
}

bool wx_GridTableBase::CanGetValueAs(int row, int col, const wxString& typeName)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, CanGetValueAs);
	if (pFunc == nullptr) return wxGridTableBase::CanGetValueAs(row, col, typeName);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(typeName.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_GridTableBase::CanSetValueAs(int row, int col, const wxString& typeName)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, CanSetValueAs);
	if (pFunc == nullptr) return wxGridTableBase::CanSetValueAs(row, col, typeName);
	Environment &env = *_pObj;
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(typeName.ToUTF8()));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

long wx_GridTableBase::GetValueAsLong(int row, int col)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetValueAsLong);
	if (pFunc == nullptr) return wxGridTableBase::GetValueAsLong(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return 0;
	return rtn.GetLong();
}

double wx_GridTableBase::GetValueAsDouble(int row, int col)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetValueAsDouble);
	if (pFunc == nullptr) return wxGridTableBase::GetValueAsDouble(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_number)) return false;
	return rtn.GetDouble();
}

bool wx_GridTableBase::GetValueAsBool(int row, int col)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetValueAsBool);
	if (pFunc == nullptr) return wxGridTableBase::GetValueAsBool(row, col);
	ValueList valList;
	valList.reserve(2);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valList);
	if (!CheckMethodResult(_pObj->GetSignal(), rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

void wx_GridTableBase::SetValueAsLong(int row, int col, long value)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, SetValueAsLong);
	if (pFunc == nullptr) return wxGridTableBase::SetValueAsLong(row, col, value);
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(value));
	_pObj->EvalMethod(*_pObj, pFunc, valList);
	CheckMethodResult(_pObj->GetSignal());
}

void wx_GridTableBase::SetValueAsDouble(int row, int col, double value)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, SetValueAsDouble);
	if (pFunc == nullptr) {
		wxGridTableBase::SetValueAsDouble(row, col, value);
		return;
	}
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(value));
	_pObj->EvalMethod(*_pObj, pFunc, valList);
	CheckMethodResult(_pObj->GetSignal());
}

void wx_GridTableBase::SetValueAsBool(int row, int col, bool value)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, SetValueAsBool);
	if (pFunc == nullptr) {
		wxGridTableBase::SetValueAsBool(row, col, value);
		return;
	}
	ValueList valList;
	valList.reserve(3);
	valList.push_back(Value(row));
	valList.push_back(Value(col));
	valList.push_back(Value(value));
	_pObj->EvalMethod(*_pObj, pFunc, valList);
	CheckMethodResult(_pObj->GetSignal());
}

wxString wx_GridTableBase::GetRowLabelValue(int row)
{
	Function *pFunc = _pObj->LookupFunctionCustom(
									Gura_UserSymbol(GetRowLabelValue), ENVREF_Escalate);
	if (pFunc == nullptr) return wxGridTableBase::GetRowLabelValue(row);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal())) return wxEmptyString;
	return wxString::FromUTF8(rtn.ToString(false).c_str());
}

wxString wx_GridTableBase::GetColLabelValue(int col)
{
	Function *pFunc = _pObj->LookupFunctionCustom(
									Gura_UserSymbol(GetColLabelValue), ENVREF_Escalate);
	if (pFunc == nullptr) return wxGridTableBase::GetColLabelValue(col);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, pFunc, valListArg);
	if (!CheckMethodResult(_pObj->GetSignal())) return wxEmptyString;
	return wxString::FromUTF8(rtn.ToString(false).c_str());
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGridTableBase
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridTableBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridTableBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridTableBase)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_GridTableBase *pEntity = new wx_GridTableBase();
	Object_wx_GridTableBase *pObj = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_GridTableBase(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_GridTableBase, GetTypeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetTypeName)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	wxString rtn = pThis->GetEntity()->wxGridTableBase::GetTypeName(row, col);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GridTableBase, CanGetValueAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, CanGetValueAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	wxString typeName = wxString::FromUTF8(arg.GetString(2));
	bool rtn = pThis->GetEntity()->wxGridTableBase::CanGetValueAs(row, col, typeName);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, CanSetValueAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, CanSetValueAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	wxString typeName = wxString::FromUTF8(arg.GetString(2));
	bool rtn = pThis->GetEntity()->wxGridTableBase::CanSetValueAs(row, col, typeName);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	long rtn = pThis->GetEntity()->wxGridTableBase::GetValueAsLong(row, col);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	double rtn = pThis->GetEntity()->wxGridTableBase::GetValueAsDouble(row, col);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsBool)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::GetValueAsBool(row, col);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	long value = arg.GetLong(2);
	pThis->GetEntity()->wxGridTableBase::SetValueAsLong(row, col, value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	double value = arg.GetDouble(2);
	pThis->GetEntity()->wxGridTableBase::SetValueAsDouble(row, col, value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsBool)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	bool value = arg.GetBoolean(2);
	pThis->GetEntity()->wxGridTableBase::SetValueAsBool(row, col, value);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetValueAsCustom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, GetValueAsCustom)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	wxString typeName = wxString::FromUTF8(arg.GetString(2));
	pThis->GetEntity()->wxGridTableBase::GetValueAsCustom(row, col, typeName);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetValueAsCustom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, SetValueAsCustom)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	wxString typeName = wxString::FromUTF8(arg.GetString(2));
	int value = arg.GetInt(3);
	pThis->GetEntity()->wxGridTableBase::SetValueAsCustom(row, col, typeName, value);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "grid", VTYPE_wx_Grid, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGrid *grid = Object_wx_Grid::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->wxGridTableBase::SetView(grid);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetView)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGrid *rtn = (wxGrid *)pThis->GetEntity()->wxGridTableBase::GetView();
	return ReturnValue(env, arg, Value(new Object_wx_Grid(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridTableBase, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridTableBase, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->wxGridTableBase::Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, InsertRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, InsertRows)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = 0;
	if (arg.IsValid(0)) pos = arg.GetSizeT(0);
	size_t numRows = 1;
	if (arg.IsValid(1)) numRows = arg.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::InsertRows(pos, numRows);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, AppendRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, AppendRows)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t numRows = 1;
	if (arg.IsValid(0)) numRows = arg.GetSizeT(0);
	bool rtn = pThis->GetEntity()->wxGridTableBase::AppendRows(numRows);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, DeleteRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, DeleteRows)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = 0;
	if (arg.IsValid(0)) pos = arg.GetSizeT(0);
	size_t numRows = 1;
	if (arg.IsValid(1)) numRows = arg.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::DeleteRows(pos, numRows);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, InsertCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, InsertCols)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = 0;
	if (arg.IsValid(0)) pos = arg.GetSizeT(0);
	size_t numCols = 1;
	if (arg.IsValid(1)) numCols = arg.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::InsertCols(pos, numCols);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, AppendCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, AppendCols)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t numCols = 1;
	if (arg.IsValid(0)) numCols = arg.GetSizeT(0);
	bool rtn = pThis->GetEntity()->wxGridTableBase::AppendCols(numCols);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, DeleteCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, DeleteCols)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = 0;
	if (arg.IsValid(0)) pos = arg.GetSizeT(0);
	size_t numCols = 1;
	if (arg.IsValid(1)) numCols = arg.GetSizeT(1);
	bool rtn = pThis->GetEntity()->wxGridTableBase::DeleteCols(pos, numCols);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, GetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetRowLabelValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->wxGridTableBase::GetRowLabelValue(row);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GridTableBase, GetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetColLabelValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int col = arg.GetInt(0);
	wxString rtn = pThis->GetEntity()->wxGridTableBase::GetColLabelValue(col);
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_GridTableBase, SetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "WXUNUSED(row)", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, SetRowLabelValue)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int WXUNUSED(row) = arg.GetInt(0);
	pThis->GetEntity()->wxGridTableBase::SetRowLabelValue(WXUNUSED(row), );
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "WXUNUSED(col)", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, SetColLabelValue)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int WXUNUSED(col) = arg.GetInt(0);
	pThis->GetEntity()->wxGridTableBase::SetColLabelValue(WXUNUSED(col), );
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetAttrProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attrProvider", VTYPE_wx_GridCellAttrProvider, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetAttrProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellAttrProvider *attrProvider = Object_wx_GridCellAttrProvider::GetObject(arg, 0)->GetEntity();
	pThis->GetEntity()->wxGridTableBase::SetAttrProvider(attrProvider);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetAttrProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetAttrProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellAttrProvider *rtn = (wxGridCellAttrProvider *)pThis->GetEntity()->wxGridTableBase::GetAttrProvider();
	return ReturnValue(env, arg, Value(new Object_wx_GridCellAttrProvider(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GridTableBase, CanHaveAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, CanHaveAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->wxGridTableBase::CanHaveAttributes();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_GridTableBase, UpdateAttrRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, UpdateAttrRows)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	int numRows = arg.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::UpdateAttrRows(pos, numRows);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, UpdateAttrCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_GridTableBase, UpdateAttrCols)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	size_t pos = arg.GetSizeT(0);
	int numCols = arg.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::UpdateAttrCols(pos, numCols);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, GetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GridTableBase, GetAttr)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = arg.GetInt(0);
	int col = arg.GetInt(1);
	wxGridCellAttr *rtn = (wxGridCellAttr *)pThis->GetEntity()->wxGridTableBase::GetAttr(row, col);
	return ReturnValue(env, arg, Value(new Object_wx_GridCellAttr(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(arg, 0)->GetEntity();
	int row = arg.GetInt(1);
	int col = arg.GetInt(2);
	pThis->GetEntity()->wxGridTableBase::SetAttr(attr, row, col);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetRowAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetRowAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(arg, 0)->GetEntity();
	int row = arg.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::SetRowAttr(attr, row);
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridTableBase, SetColAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridTableBase, SetColAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridTableBase *pThis = Object_wx_GridTableBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(arg, 0)->GetEntity();
	int col = arg.GetInt(1);
	pThis->GetEntity()->wxGridTableBase::SetColAttr(attr, col);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxGridTableBase
//----------------------------------------------------------------------------
Object_wx_GridTableBase::~Object_wx_GridTableBase()
{
}

Object *Object_wx_GridTableBase::Clone() const
{
	return nullptr;
}

String Object_wx_GridTableBase::ToString(bool exprFlag)
{
	String rtn("<wx.GridTableBase:");
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
// Class implementation for wxGridTableBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridTableBase)
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
	return new Object_wx_GridTableBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
