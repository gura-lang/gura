//----------------------------------------------------------------------------
// wxDataViewListModel
// extracted from dataviewmodel.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(GetColType);
Gura_DeclarePrivUserSymbol(GetNumberOfCols);
Gura_DeclarePrivUserSymbol(GetNumberOfRows);
Gura_DeclarePrivUserSymbol(GetValue);
Gura_DeclarePrivUserSymbol(RowAppended);
Gura_DeclarePrivUserSymbol(RowChanged);
Gura_DeclarePrivUserSymbol(RowDeleted);
Gura_DeclarePrivUserSymbol(RowInserted);
Gura_DeclarePrivUserSymbol(RowPrepended);
Gura_DeclarePrivUserSymbol(RowsReordered);
Gura_DeclarePrivUserSymbol(SetValue);
Gura_DeclarePrivUserSymbol(ValueChanged);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewListModel: public wxDataViewListModel, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DataViewListModel *_pObj;
public:
	inline wx_DataViewListModel() : wxDataViewListModel(), _sig(NULL), _pObj(NULL) {}
	virtual wxString GetColType(unsigned int col);
	virtual unsigned int GetNumberOfCols();
	virtual unsigned int GetNumberOfRows();
	virtual void GetValue(wxVariant& variant, unsigned int col, unsigned int row);
	virtual bool RowAppended();
	virtual bool RowChanged(unsigned int row);
	virtual bool RowDeleted(unsigned int row);
	virtual bool RowInserted(unsigned int before);
	virtual bool RowPrepended();
	virtual bool RowsReordered(unsigned int* new_order);
	virtual bool SetValue(wxVariant& variant, unsigned int col, unsigned int row);
	virtual bool ValueChanged(unsigned int col, unsigned int row);
	~wx_DataViewListModel();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewListModel *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewListModel::~wx_DataViewListModel()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewListModel::GuraObjectDeleted()
{
	_pObj = NULL;
}

// pure virtual function
wxString wx_DataViewListModel::GetColType(unsigned int col)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetColType);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.DataViewListModel#GetColType method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return wxEmptyString;
	}
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(col));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_string)) return wxEmptyString;
	return wxString::FromUTF8(rtn.GetString());
}

// pure virtual function
unsigned int wx_DataViewListModel::GetNumberOfCols()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetNumberOfCols);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.DataViewListModel#GetNumberOfCols method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return 0;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetUInt();
}

// pure virtual function
unsigned int wx_DataViewListModel::GetNumberOfRows()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetNumberOfRows);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.DataViewListModel#GetNumberOfRows method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return 0;
	}
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_number)) return 0;
	return rtn.GetUInt();
}

// pure virtual function
void wx_DataViewListModel::GetValue(wxVariant& variant, unsigned int col, unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, GetValue);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.DataViewListModel#GetValue method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return;
	}
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_wx_Variant)) return;
	variant = *Object_wx_Variant::GetObject(rtn)->GetEntity();
}

bool wx_DataViewListModel::RowAppended()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, RowAppended);
	if (pFunc == NULL) return wxDataViewListModel::RowAppended();
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewListModel::RowChanged(unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, RowChanged);
	if (pFunc == NULL) return wxDataViewListModel::RowChanged(row);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewListModel::RowDeleted(unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, RowDeleted);
	if (pFunc == NULL) return wxDataViewListModel::RowDeleted(row);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewListModel::RowInserted(unsigned int before)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, RowInserted);
	if (pFunc == NULL) return wxDataViewListModel::RowInserted(before);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(before));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewListModel::RowPrepended()
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, RowPrepended);
	if (pFunc == NULL) return wxDataViewListModel::RowPrepended();
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, ValueList::Null);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewListModel::RowsReordered(unsigned int* new_order)
{
	Environment &env = *_pObj;
	const Function *pFunc = Gura_LookupWxMethod(_pObj, RowsReordered);
	if (pFunc == NULL) return wxDataViewListModel::RowsReordered(new_order);
	size_t nRows = GetNumberOfRows();
	if (_sig.IsSignalled()) return false;
	Value v;
	do {
		ValueList &valList = v.InitAsList(env);
		valList.reserve(nRows);
		for (size_t iRow = 0; iRow < nRows; iRow++) valList.push_back(Value(new_order[iRow]));
	} while (0);
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(v);
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

// pure virtual function
bool wx_DataViewListModel::SetValue(wxVariant& variant, unsigned int col, unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, SetValue);
	if (pFunc == NULL) {
		_sig.SetError(ERR_NotImplementedError, "wx.DataViewListModel#SetValue method is missing");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	ValueList valListArg;
	valListArg.reserve(3);
	valListArg.push_back(Value(new Object_wx_Variant(new wxVariant(variant), NULL, OwnerTrue)));
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

bool wx_DataViewListModel::ValueChanged(unsigned int col, unsigned int row)
{
	const Function *pFunc = Gura_LookupWxMethod(_pObj, ValueChanged);
	if (pFunc == NULL) return wxDataViewListModel::ValueChanged(col, row);
	ValueList valListArg;
	valListArg.reserve(2);
	valListArg.push_back(Value(col));
	valListArg.push_back(Value(row));
	Value rtn = _pObj->EvalMethod(*_pObj, _sig, pFunc, valListArg);
	if (!CheckMethodResult(_sig, rtn, VTYPE_boolean)) return false;
	return rtn.GetBoolean();
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListModel
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewListModel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewListModel));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewListModel)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DataViewListModel *pEntity = new wx_DataViewListModel();
	Object_wx_DataViewListModel *pObj = Object_wx_DataViewListModel::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewListModel(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DataViewListModel, AddNotifier)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "notifier", VTYPE_wx_DataViewListModelNotifier, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, AddNotifier)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewListModelNotifier *notifier = Object_wx_DataViewListModelNotifier::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->AddNotifier(notifier);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewListModel, AddViewingColumn)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "view_column", VTYPE_wx_DataViewColumn, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, AddViewingColumn)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewColumn *view_column = Object_wx_DataViewColumn::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	pThis->GetEntity()->AddViewingColumn(view_column, model_column);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewListModel, Cleared)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, Cleared)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Cleared();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModel, RemoveNotifier)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "notifier", VTYPE_wx_DataViewListModelNotifier, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, RemoveNotifier)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewListModelNotifier *notifier = Object_wx_DataViewListModelNotifier::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->RemoveNotifier(notifier);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewListModel, RemoveViewingColumn)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "column", VTYPE_wx_DataViewColumn, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewListModel, RemoveViewingColumn)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDataViewColumn *column = Object_wx_DataViewColumn::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->RemoveViewingColumn(column);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewListModel, RowAppended)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, RowAppended)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxDataViewListModel::RowAppended();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModel, RowChanged)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, RowChanged)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned row = args.GetInt(0);
	bool rtn = pThis->GetEntity()->wxDataViewListModel::RowChanged(row);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModel, RowDeleted)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, RowDeleted)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned row = args.GetInt(0);
	bool rtn = pThis->GetEntity()->wxDataViewListModel::RowDeleted(row);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModel, RowInserted)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, RowInserted)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned before = args.GetInt(0);
	bool rtn = pThis->GetEntity()->wxDataViewListModel::RowInserted(before);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModel, RowPrepended)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, RowPrepended)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->wxDataViewListModel::RowPrepended();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModel, RowsReordered)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "new_order", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, RowsReordered)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	CArrayOfInt new_order(args.GetList(0));
	bool rtn = pThis->GetEntity()->wxDataViewListModel::RowsReordered(
					reinterpret_cast<unsigned int *>(new_order.Data()));
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewListModel, ValueChanged)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewListModel, ValueChanged)
{
	Object_wx_DataViewListModel *pThis = Object_wx_DataViewListModel::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned col = args.GetInt(0);
	unsigned row = args.GetInt(1);
	bool rtn = pThis->GetEntity()->wxDataViewListModel::ValueChanged(col, row);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListModel
//----------------------------------------------------------------------------
Object_wx_DataViewListModel::~Object_wx_DataViewListModel()
{
}

Object *Object_wx_DataViewListModel::Clone() const
{
	return NULL;
}

String Object_wx_DataViewListModel::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataViewListModel:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataViewListModel::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(GetColType);
	Gura_RealizeUserSymbol(GetNumberOfCols);
	Gura_RealizeUserSymbol(GetNumberOfRows);
	Gura_RealizeUserSymbol(GetValue);
	Gura_RealizeUserSymbol(RowAppended);
	Gura_RealizeUserSymbol(RowChanged);
	Gura_RealizeUserSymbol(RowDeleted);
	Gura_RealizeUserSymbol(RowInserted);
	Gura_RealizeUserSymbol(RowPrepended);
	Gura_RealizeUserSymbol(RowsReordered);
	Gura_RealizeUserSymbol(SetValue);
	Gura_RealizeUserSymbol(ValueChanged);
	Gura_AssignFunction(DataViewListModel);
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListModel)
{
	Gura_AssignMethod(wx_DataViewListModel, AddNotifier);
	Gura_AssignMethod(wx_DataViewListModel, AddViewingColumn);
	Gura_AssignMethod(wx_DataViewListModel, Cleared);
	Gura_AssignMethod(wx_DataViewListModel, RemoveNotifier);
	Gura_AssignMethod(wx_DataViewListModel, RemoveViewingColumn);
	Gura_AssignMethod(wx_DataViewListModel, RowAppended);
	Gura_AssignMethod(wx_DataViewListModel, RowChanged);
	Gura_AssignMethod(wx_DataViewListModel, RowDeleted);
	Gura_AssignMethod(wx_DataViewListModel, RowInserted);
	Gura_AssignMethod(wx_DataViewListModel, RowPrepended);
	Gura_AssignMethod(wx_DataViewListModel, RowsReordered);
	Gura_AssignMethod(wx_DataViewListModel, ValueChanged);
}

Gura_ImplementDescendantCreator(wx_DataViewListModel)
{
	return new Object_wx_DataViewListModel((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
