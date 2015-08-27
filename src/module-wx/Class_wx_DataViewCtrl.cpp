//----------------------------------------------------------------------------
// wxDataViewCtrl
// extracted from dataviewctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(AppendColumn);
Gura_DeclarePrivUserSymbol(AssociateModel);
Gura_DeclarePrivUserSymbol(ClearColumns);
Gura_DeclarePrivUserSymbol(DeleteColumn);
Gura_DeclarePrivUserSymbol(GetColumn);
Gura_DeclarePrivUserSymbol(GetModel);
Gura_DeclarePrivUserSymbol(GetNumberOfColumns);
Gura_DeclarePrivUserSymbol(GetSelection);
Gura_DeclarePrivUserSymbol(GetSelections);
Gura_DeclarePrivUserSymbol(IsSelected);
Gura_DeclarePrivUserSymbol(SetSelection);
Gura_DeclarePrivUserSymbol(SetSelectionRange);
Gura_DeclarePrivUserSymbol(SetSelections);
Gura_DeclarePrivUserSymbol(Unselect);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DataViewCtrl: public wxDataViewCtrl, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DataViewCtrl *_pObj;
public:
	inline wx_DataViewCtrl() : wxDataViewCtrl(), _pObj(nullptr) {}
	inline wx_DataViewCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator) : wxDataViewCtrl(parent, id, pos, size, style, validator), _pObj(nullptr) {}
	//virtual bool AppendColumn(wxDataViewColumn* col);
	//virtual bool AssociateModel(wxDataViewListModel* model);
	//virtual bool ClearColumns();
	//virtual bool DeleteColumn(unsigned int pos);
	//virtual wxDataViewColumn* GetColumn(unsigned int pos);
	//virtual wxDataViewListModel* GetModel();
	//virtual unsigned int GetNumberOfColumns();
	//virtual int GetSelection();
	//virtual int GetSelections(wxArrayInt& aSelections);
	//virtual bool IsSelected(unsigned int row);
	//virtual void SetSelection(int row);
	//virtual void SetSelectionRange(unsigned int from, unsigned int to);
	//virtual void SetSelections(const wxArrayInt& aSelections);
	//virtual void Unselect(unsigned int row);
	~wx_DataViewCtrl();
	inline void AssocWithGura(Object_wx_DataViewCtrl *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewCtrl::~wx_DataViewCtrl()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DataViewCtrl::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewCtrlEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewCtrlEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_DataViewCtrl *pEntity = new wx_DataViewCtrl();
	Object_wx_DataViewCtrl *pObj = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(DataViewCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DataViewCtrl));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewCtrl)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(5)) validator = Object_wx_Validator::GetObject(args, 5)->GetEntity();
	wx_DataViewCtrl *pEntity = new wx_DataViewCtrl(parent, id, *pos, *size, style, *validator);
	Object_wx_DataViewCtrl *pObj = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DataViewCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_DataViewColumn, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataViewColumn *col = Object_wx_DataViewColumn::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AppendColumn(col);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendBitmapColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendBitmapColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendBitmapColumn(label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendBitmapColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendBitmapColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendBitmapColumn(*label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendDateColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendDateColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendDateColumn(label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendDateColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendDateColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendDateColumn(*label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendProgressColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendProgressColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 80;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendProgressColumn(label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendProgressColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendProgressColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 80;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendProgressColumn(*label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendTextColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendTextColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendTextColumn(label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendTextColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendTextColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendTextColumn(*label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendToggleColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendToggleColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 30;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendToggleColumn(label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendToggleColumn_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendToggleColumn_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 30;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pThis->GetEntity()->AppendToggleColumn(*label, model_column, mode, width);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AssociateModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AssociateModel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->AssociateModel(model);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "validator", VTYPE_wx_Validator, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxValidator *validator = (wxValidator *)(&wxDefaultValidator);
	if (args.IsValid(5)) validator = Object_wx_Validator::GetObject(args, 5)->GetEntity();
	bool rtn = pThis->GetEntity()->Create(parent, id, *pos, *size, style, *validator);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, ClearColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, ClearColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ClearColumns();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, ClearSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, ClearSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ClearSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, DeleteColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, DeleteColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned pos = args.GetInt(0);
	bool rtn = pThis->GetEntity()->DeleteColumn(pos);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned pos = args.GetInt(0);
	wxDataViewColumn *rtn = (wxDataViewColumn *)pThis->GetEntity()->GetColumn(pos);
	return ReturnValue(env, args, Value(new Object_wx_DataViewColumn(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetModel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetModel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDataViewListModel *rtn = (wxDataViewListModel *)pThis->GetEntity()->GetModel();
	return ReturnValue(env, args, Value(new Object_wx_DataViewListModel(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetNumberOfColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetNumberOfColumns)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->GetNumberOfColumns();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetSelection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "aSelections", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayInt> aSelections(CreateArrayInt(args.GetList(0)));
	int rtn = pThis->GetEntity()->GetSelections(*aSelections);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, IsSelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, IsSelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned row = args.GetInt(0);
	bool rtn = pThis->GetEntity()->IsSelected(row);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int row = args.GetInt(0);
	pThis->GetEntity()->SetSelection(row);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetSelectionRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetSelectionRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned from = args.GetInt(0);
	unsigned to = args.GetInt(1);
	pThis->GetEntity()->SetSelectionRange(from, to);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "aSelections", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetSelections)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	std::unique_ptr<wxArrayInt> aSelections(CreateArrayInt(args.GetList(0)));
	pThis->GetEntity()->SetSelections(*aSelections);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewCtrl, Unselect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, Unselect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataViewCtrl *pThis = Object_wx_DataViewCtrl::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned row = args.GetInt(0);
	pThis->GetEntity()->Unselect(row);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewCtrl::~Object_wx_DataViewCtrl()
{
}

Object *Object_wx_DataViewCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewCtrl:");
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
// Class implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCtrl)
{
	Gura_RealizeUserSymbol(AppendColumn);
	Gura_RealizeUserSymbol(AssociateModel);
	Gura_RealizeUserSymbol(ClearColumns);
	Gura_RealizeUserSymbol(DeleteColumn);
	Gura_RealizeUserSymbol(GetColumn);
	Gura_RealizeUserSymbol(GetModel);
	Gura_RealizeUserSymbol(GetNumberOfColumns);
	Gura_RealizeUserSymbol(GetSelection);
	Gura_RealizeUserSymbol(GetSelections);
	Gura_RealizeUserSymbol(IsSelected);
	Gura_RealizeUserSymbol(SetSelection);
	Gura_RealizeUserSymbol(SetSelectionRange);
	Gura_RealizeUserSymbol(SetSelections);
	Gura_RealizeUserSymbol(Unselect);
	Gura_AssignFunction(DataViewCtrlEmpty);
	Gura_AssignFunction(DataViewCtrl);
	Gura_AssignMethod(wx_DataViewCtrl, AppendColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendBitmapColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendBitmapColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendDateColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendDateColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendProgressColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendProgressColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendTextColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendTextColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AppendToggleColumn);
	Gura_AssignMethod(wx_DataViewCtrl, AppendToggleColumn_1);
	Gura_AssignMethod(wx_DataViewCtrl, AssociateModel);
	Gura_AssignMethod(wx_DataViewCtrl, Create);
	Gura_AssignMethod(wx_DataViewCtrl, ClearColumns);
	Gura_AssignMethod(wx_DataViewCtrl, ClearSelection);
	Gura_AssignMethod(wx_DataViewCtrl, DeleteColumn);
	Gura_AssignMethod(wx_DataViewCtrl, GetColumn);
	Gura_AssignMethod(wx_DataViewCtrl, GetModel);
	Gura_AssignMethod(wx_DataViewCtrl, GetNumberOfColumns);
	Gura_AssignMethod(wx_DataViewCtrl, GetSelection);
	Gura_AssignMethod(wx_DataViewCtrl, GetSelections);
	Gura_AssignMethod(wx_DataViewCtrl, IsSelected);
	Gura_AssignMethod(wx_DataViewCtrl, SetSelection);
	Gura_AssignMethod(wx_DataViewCtrl, SetSelectionRange);
	Gura_AssignMethod(wx_DataViewCtrl, SetSelections);
	Gura_AssignMethod(wx_DataViewCtrl, Unselect);
}

Gura_ImplementDescendantCreator(wx_DataViewCtrl)
{
	return new Object_wx_DataViewCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
