//----------------------------------------------------------------------------
// wxDataViewCtrl
// extracted from dataviewctrl.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

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
	Gura::Signal _sig;
	Object_wx_DataViewCtrl *_pObj;
public:
	inline wx_DataViewCtrl() : wxDataViewCtrl(), _sig(NULL), _pObj(NULL) {}
	inline wx_DataViewCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator) : wxDataViewCtrl(parent, id, pos, size, style, validator), _sig(NULL), _pObj(NULL) {}
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
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DataViewCtrl *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DataViewCtrl::~wx_DataViewCtrl()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DataViewCtrl::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_DeclareFunction(DataViewCtrlEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DataViewCtrlEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DataViewCtrl *pEntity = new wx_DataViewCtrl();
	Object_wx_DataViewCtrl *pObj = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(DataViewCtrl)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (!CheckWxReady(sig)) return Value::Null;
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
	Object_wx_DataViewCtrl *pObj = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DataViewCtrl(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_wx_DataViewColumn, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataViewColumn *col = Object_wx_DataViewColumn::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->AppendColumn(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendBitmapColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendBitmapColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendBitmapColumn(label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendBitmapColumn_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendBitmapColumn_1)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendBitmapColumn(*label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendDateColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendDateColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendDateColumn(label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendDateColumn_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendDateColumn_1)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_ACTIVATABLE;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendDateColumn(*label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendProgressColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendProgressColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 80;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendProgressColumn(label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendProgressColumn_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendProgressColumn_1)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 80;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendProgressColumn(*label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendTextColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendTextColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendTextColumn(label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendTextColumn_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendTextColumn_1)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = -1;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendTextColumn(*label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendToggleColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendToggleColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString label = wxString::FromUTF8(args.GetString(0));
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 30;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendToggleColumn(label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AppendToggleColumn_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "label", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "model_column", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AppendToggleColumn_1)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxBitmap *label = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	unsigned model_column = args.GetInt(1);
	wxDataViewCellMode mode = wxDATAVIEW_CELL_INERT;
	if (args.IsValid(2)) mode = static_cast<wxDataViewCellMode>(args.GetInt(2));
	int width = 30;
	if (args.IsValid(3)) width = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->AppendToggleColumn(*label, model_column, mode, width);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, AssociateModel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "model", VTYPE_wx_DataViewListModel, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, AssociateModel)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataViewListModel *model = Object_wx_DataViewListModel::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->AssociateModel(model);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
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
	bool rtn = pSelf->GetEntity()->Create(parent, id, *pos, *size, style, *validator);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, ClearColumns)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, ClearColumns)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->ClearColumns();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, ClearSelection)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewCtrl, ClearSelection)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->ClearSelection();
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewCtrl, DeleteColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, DeleteColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned pos = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->DeleteColumn(pos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetColumn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetColumn)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned pos = args.GetInt(0);
	wxDataViewColumn *rtn = (wxDataViewColumn *)pSelf->GetEntity()->GetColumn(pos);
	return ReturnValue(env, sig, args, Value(new Object_wx_DataViewColumn(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetModel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetModel)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDataViewListModel *rtn = (wxDataViewListModel *)pSelf->GetEntity()->GetModel();
	return ReturnValue(env, sig, args, Value(new Object_wx_DataViewListModel(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetNumberOfColumns)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetNumberOfColumns)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pSelf->GetEntity()->GetNumberOfColumns();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSelection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSelection)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, GetSelections)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "aSelections", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, GetSelections)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayInt> aSelections(CreateArrayInt(args.GetList(0)));
	int rtn = pSelf->GetEntity()->GetSelections(*aSelections);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, IsSelected)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DataViewCtrl, IsSelected)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned row = args.GetInt(0);
	bool rtn = pSelf->GetEntity()->IsSelected(row);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DataViewCtrl, SetSelection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetSelection)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	pSelf->GetEntity()->SetSelection(row);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetSelectionRange)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetSelectionRange)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned from = args.GetInt(0);
	unsigned to = args.GetInt(1);
	pSelf->GetEntity()->SetSelectionRange(from, to);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewCtrl, SetSelections)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "aSelections", VTYPE_number, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_DataViewCtrl, SetSelections)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	std::auto_ptr<wxArrayInt> aSelections(CreateArrayInt(args.GetList(0)));
	pSelf->GetEntity()->SetSelections(*aSelections);
	return Value::Null;
}

Gura_DeclareMethod(wx_DataViewCtrl, Unselect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewCtrl, Unselect)
{
	Object_wx_DataViewCtrl *pSelf = Object_wx_DataViewCtrl::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned row = args.GetInt(0);
	pSelf->GetEntity()->Unselect(row);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewCtrl::~Object_wx_DataViewCtrl()
{
}

Object *Object_wx_DataViewCtrl::Clone() const
{
	return NULL;
}

String Object_wx_DataViewCtrl::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DataViewCtrl:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DataViewCtrl::OnModuleEntry(Environment &env, Signal sig)
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
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCtrl)
{
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
	return new Object_wx_DataViewCtrl((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
