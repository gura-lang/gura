//----------------------------------------------------------------------------
// wxGrid
// extracted from grid.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value GridCellCoordsArrayToValue(Environment &env, const wxGridCellCoordsArray &array);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Grid: public wxGrid, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Grid *_pObj;
public:
	inline wx_Grid() : wxGrid(), _sig(NULL), _pObj(NULL) {}
	inline wx_Grid(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxGrid(parent, id, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	~wx_Grid();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Grid *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
public:
	// reveal private or protected member functions to public
	inline bool _CanHaveAttributes() {
		return wxGrid::CanHaveAttributes();
	}
	inline int _GetColLeft(int col) {
		return wxGrid::GetColLeft(col);
	}
	inline int _GetColMinimalWidth(int col) {
		return wxGrid::GetColMinimalWidth(col);
	}
	inline int _GetColRight(int col) {
		return wxGrid::GetColRight(col);
	}
	inline int _GetRowMinimalHeight(int col) {
		return wxGrid::GetRowMinimalHeight(col);
	}
	inline void _InitColWidths() {
		wxGrid::InitColWidths();
	}
	inline void _InitRowHeights() {
		wxGrid::InitRowHeights();
	}
	inline bool _SetOrCalcColumnSizes(bool calcOnly, bool setAsMin) {
		return wxGrid::SetOrCalcColumnSizes(calcOnly, setAsMin);
	}
	inline bool _SetOrCalcRowSizes(bool calcOnly, bool setAsMin) {
		return wxGrid::SetOrCalcRowSizes(calcOnly, setAsMin);
	}
};

wx_Grid::~wx_Grid()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Grid::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGrid
//----------------------------------------------------------------------------
Gura_DeclareFunction(GridEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Grid));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(GridEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Grid *pEntity = new wx_Grid();
	Object_wx_Grid *pObj = Object_wx_Grid::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Grid(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Grid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Grid));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Grid)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(2)) pos = Object_wx_Point::GetObject(args, 2)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(3)) size = Object_wx_Size::GetObject(args, 3)->GetEntity();
	long style = wxWANTS_CHARS;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxString name = wxPanelNameStr;
	if (args.IsValid(5)) name = wxString::FromUTF8(args.GetString(5));
	wx_Grid *pEntity = new wx_Grid(parent, id, *pos, *size, style, name);
	Object_wx_Grid *pObj = Object_wx_Grid::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Grid(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Grid, AppendCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "updateLabels", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, AppendCols)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int numCols = 1;
	if (args.IsValid(0)) numCols = args.GetInt(0);
	bool updateLabels = true;
	if (args.IsValid(1)) updateLabels = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->AppendCols(numCols, updateLabels);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, AppendRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "updateLabels", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, AppendRows)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int numRows = 1;
	if (args.IsValid(0)) numRows = args.GetInt(0);
	bool updateLabels = true;
	if (args.IsValid(1)) updateLabels = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->AppendRows(numRows, updateLabels);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, AutoSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, AutoSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->AutoSize();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, AutoSizeColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "setAsMin", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, AutoSizeColumn)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	bool setAsMin = true;
	if (args.IsValid(1)) setAsMin = args.GetBoolean(1);
	pThis->GetEntity()->AutoSizeColumn(col, setAsMin);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, AutoSizeColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "setAsMin", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, AutoSizeColumns)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool setAsMin = true;
	if (args.IsValid(0)) setAsMin = args.GetBoolean(0);
	pThis->GetEntity()->AutoSizeColumns(setAsMin);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, AutoSizeRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "setAsMin", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, AutoSizeRow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	bool setAsMin = true;
	if (args.IsValid(1)) setAsMin = args.GetBoolean(1);
	pThis->GetEntity()->AutoSizeRow(row, setAsMin);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, AutoSizeRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "setAsMin", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, AutoSizeRows)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool setAsMin = true;
	if (args.IsValid(0)) setAsMin = args.GetBoolean(0);
	pThis->GetEntity()->AutoSizeRows(setAsMin);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, BeginBatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, BeginBatch)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->BeginBatch();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, BlockToDeviceRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topLeft", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareArg(env, "bottomRight", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, BlockToDeviceRect)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *topLeft = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	wxGridCellCoords *bottomRight = Object_wx_GridCellCoords::GetObject(args, 1)->GetEntity();
	wxRect rtn = pThis->GetEntity()->BlockToDeviceRect(*topLeft, *bottomRight);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, CanDragColMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CanDragColMove)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanDragColMove();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, CanDragColSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CanDragColSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanDragColSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, CanDragRowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CanDragRowSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanDragRowSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, CanDragGridSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CanDragGridSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanDragGridSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, CanEnableCellControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CanEnableCellControl)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CanEnableCellControl();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, CanHaveAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CanHaveAttributes)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = dynamic_cast<wx_Grid *>(pThis->GetEntity())->_CanHaveAttributes();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, CellToRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CellToRect)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxRect rtn = pThis->GetEntity()->CellToRect(row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, CellToRect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "coords", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CellToRect_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *coords = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	wxRect rtn = pThis->GetEntity()->CellToRect(*coords);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, ClearGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, ClearGrid)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearGrid();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, ClearSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, ClearSelection)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ClearSelection();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, CreateGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "selmode", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, CreateGrid)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int numRows = args.GetInt(0);
	int numCols = args.GetInt(1);
	wxGrid::wxGridSelectionModes selmode = wxGrid::wxGridSelectCells;
	if (args.IsValid(2)) selmode = static_cast<wxGrid::wxGridSelectionModes>(args.GetInt(2));
	bool rtn = pThis->GetEntity()->CreateGrid(numRows, numCols, selmode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, DeleteCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "updateLabels", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, DeleteCols)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = 0;
	if (args.IsValid(0)) pos = args.GetInt(0);
	int numCols = 1;
	if (args.IsValid(1)) numCols = args.GetInt(1);
	bool updateLabels = true;
	if (args.IsValid(2)) updateLabels = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->DeleteCols(pos, numCols, updateLabels);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, DeleteRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "updateLabels", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, DeleteRows)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = 0;
	if (args.IsValid(0)) pos = args.GetInt(0);
	int numRows = 1;
	if (args.IsValid(1)) numRows = args.GetInt(1);
	bool updateLabels = true;
	if (args.IsValid(2)) updateLabels = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->DeleteRows(pos, numRows, updateLabels);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, DeselectCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, DeselectCell)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	pThis->GetEntity()->DeselectCell(row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, DeselectCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, DeselectCol)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->DeselectCol(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, DeselectRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, DeselectRow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	pThis->GetEntity()->DeselectRow(row);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, DisableCellEditControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, DisableCellEditControl)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisableCellEditControl();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, DisableDragColMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, DisableDragColMove)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisableDragColMove();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, DisableDragColSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, DisableDragColSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisableDragColSize();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, DisableDragGridSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, DisableDragGridSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisableDragGridSize();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, DisableDragRowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, DisableDragRowSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DisableDragRowSize();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EnableCellEditControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, EnableCellEditControl)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableCellEditControl(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EnableDragColSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, EnableDragColSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableDragColSize(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EnableDragColMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, EnableDragColMove)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableDragColMove(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EnableDragGridSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, EnableDragGridSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableDragGridSize(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EnableDragRowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, EnableDragRowSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableDragRowSize(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EnableEditing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "edit", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, EnableEditing)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool edit = args.GetBoolean(0);
	pThis->GetEntity()->EnableEditing(edit);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EnableGridLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "enable", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, EnableGridLines)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool enable = true;
	if (args.IsValid(0)) enable = args.GetBoolean(0);
	pThis->GetEntity()->EnableGridLines(enable);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, EndBatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, EndBatch)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->EndBatch();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, Fit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, Fit)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Fit();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, ForceRefresh)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, ForceRefresh)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ForceRefresh();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, GetBatchCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetBatchCount)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBatchCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetCellOverflow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellOverflow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	bool rtn = pThis->GetEntity()->GetCellOverflow(row, col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetCellAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	int horiz = 0;
	int vert = 0;
	pThis->GetEntity()->GetCellAlignment(row, col, &horiz, &vert);
	return ReturnValue(env, sig, args, Value::CreateList(env, horiz, vert));
}

Gura_DeclareMethod(wx_Grid, GetCellBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellBackgroundColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxColour rtn = pThis->GetEntity()->GetCellBackgroundColour(row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetCellEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellEditor)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->GetCellEditor(row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_GridCellEditor(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Grid, GetCellFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellFont)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxFont rtn = pThis->GetEntity()->GetCellFont(row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetCellHighlightPenWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellHighlightPenWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCellHighlightPenWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetCellHighlightROPenWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellHighlightROPenWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCellHighlightROPenWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetCellRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellRenderer)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellRenderer *rtn = (wxGridCellRenderer *)pThis->GetEntity()->GetCellRenderer(row, col);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellRenderer(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetCellTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellTextColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxColour rtn = pThis->GetEntity()->GetCellTextColour(row, col);
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetCellValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellValue)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxString rtn = pThis->GetEntity()->GetCellValue(row, col);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Grid, GetCellValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "coords", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetCellValue_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *coords = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	wxString rtn = pThis->GetEntity()->GetCellValue(*coords);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Grid, GetColAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colPos", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColAt)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int colPos = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetColAt(colPos);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetColLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColLeft)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int rtn = dynamic_cast<wx_Grid *>(pThis->GetEntity())->_GetColLeft(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetColLabelAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColLabelAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int horiz = 0;
	int vert = 0;
	pThis->GetEntity()->GetColLabelAlignment(&horiz, &vert);
	return ReturnValue(env, sig, args, Value::CreateList(env, horiz, vert));
}

Gura_DeclareMethod(wx_Grid, GetColLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColLabelSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColLabelSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColLabelValue)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetColLabelValue(col);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Grid, GetColMinimalAcceptableWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColMinimalAcceptableWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetColMinimalAcceptableWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetColMinimalWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColMinimalWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int rtn = dynamic_cast<wx_Grid *>(pThis->GetEntity())->_GetColMinimalWidth(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetColPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "colID", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColPos)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int colID = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetColPos(colID);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetColRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColRight)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int rtn = dynamic_cast<wx_Grid *>(pThis->GetEntity())->_GetColRight(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetColSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetColSize(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetDefaultCellAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultCellAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int horiz = 0;
	int vert = 0;
	pThis->GetEntity()->GetDefaultCellAlignment(&horiz, &vert);
	return ReturnValue(env, sig, args, Value::CreateList(env, horiz, vert));
}

Gura_DeclareMethod(wx_Grid, GetDefaultCellBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultCellBackgroundColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetDefaultCellBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetDefaultCellFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultCellFont)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pThis->GetEntity()->GetDefaultCellFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetDefaultCellOverflow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultCellOverflow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetDefaultCellOverflow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetDefaultCellTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultCellTextColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetDefaultCellTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetDefaultColLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultColLabelSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDefaultColLabelSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetDefaultColSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultColSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDefaultColSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetDefaultEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultEditor)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->GetDefaultEditor();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellEditor(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetDefaultEditorForCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultEditorForCell)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->GetDefaultEditorForCell(row, col);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellEditor(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetDefaultEditorForCell_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "c", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultEditorForCell_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *c = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->GetDefaultEditorForCell(*c);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellEditor(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetDefaultEditorForType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultEditorForType)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString typeName = wxString::FromUTF8(args.GetString(0));
	wxGridCellEditor *rtn = (wxGridCellEditor *)pThis->GetEntity()->GetDefaultEditorForType(typeName);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellEditor(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetDefaultRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultRenderer)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellRenderer *rtn = (wxGridCellRenderer *)pThis->GetEntity()->GetDefaultRenderer();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellRenderer(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetDefaultRendererForCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultRendererForCell)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellRenderer *rtn = (wxGridCellRenderer *)pThis->GetEntity()->GetDefaultRendererForCell(row, col);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellRenderer(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetDefaultRendererForType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultRendererForType)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString typeName = wxString::FromUTF8(args.GetString(0));
	wxGridCellRenderer *rtn = (wxGridCellRenderer *)pThis->GetEntity()->GetDefaultRendererForType(typeName);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellRenderer(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetDefaultRowLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultRowLabelSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDefaultRowLabelSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetDefaultRowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultRowSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDefaultRowSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetGridCursorCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetGridCursorCol)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetGridCursorCol();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetGridCursorRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetGridCursorRow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetGridCursorRow();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetGridLineColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetGridLineColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetGridLineColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetDefaultGridLinePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetDefaultGridLinePen)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPen rtn = pThis->GetEntity()->GetDefaultGridLinePen();
	return ReturnValue(env, sig, args, Value(new Object_wx_Pen(new wxPen(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetRowGridLinePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetRowGridLinePen)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	wxPen rtn = pThis->GetEntity()->GetRowGridLinePen(row);
	return ReturnValue(env, sig, args, Value(new Object_wx_Pen(new wxPen(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetColGridLinePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetColGridLinePen)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxPen rtn = pThis->GetEntity()->GetColGridLinePen(col);
	return ReturnValue(env, sig, args, Value(new Object_wx_Pen(new wxPen(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GridLinesEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GridLinesEnabled)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GridLinesEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetLabelBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetLabelBackgroundColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetLabelBackgroundColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetLabelFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetLabelFont)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont rtn = pThis->GetEntity()->GetLabelFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetLabelTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetLabelTextColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetLabelTextColour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetNumberCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetNumberCols)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNumberCols();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetNumberRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetNumberRows)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNumberRows();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetOrCreateCellAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetOrCreateCellAttr)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellAttr *rtn = (wxGridCellAttr *)pThis->GetEntity()->GetOrCreateCellAttr(row, col);
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridCellAttr(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetRowMinimalAcceptableHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetRowMinimalAcceptableHeight)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRowMinimalAcceptableHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetRowMinimalHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetRowMinimalHeight)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int rtn = dynamic_cast<wx_Grid *>(pThis->GetEntity())->_GetRowMinimalHeight(col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetRowLabelAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetRowLabelAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int horiz = 0;
	int vert = 0;
	pThis->GetEntity()->GetRowLabelAlignment(&horiz, &vert);
	return ReturnValue(env, sig, args, Value::CreateList(env, horiz, vert));
}

Gura_DeclareMethod(wx_Grid, GetRowLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetRowLabelSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRowLabelSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetRowLabelValue)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	wxString rtn = pThis->GetEntity()->GetRowLabelValue(row);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Grid, GetRowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetRowSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int rtn = pThis->GetEntity()->GetRowSize(row);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetScrollLineX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetScrollLineX)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetScrollLineX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetScrollLineY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetScrollLineY)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetScrollLineY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, GetSelectionMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectionMode)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_Grid, GetSelectedCells)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectedCells)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoordsArray rtn = pThis->GetEntity()->GetSelectedCells();
	return ReturnValue(env, sig, args, GridCellCoordsArrayToValue(env, rtn));
}

Gura_DeclareMethod(wx_Grid, GetSelectedCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectedCols)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayInt rtn = pThis->GetEntity()->GetSelectedCols();
	return ReturnValue(env, sig, args, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_Grid, GetSelectedRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectedRows)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArrayInt rtn = pThis->GetEntity()->GetSelectedRows();
	return ReturnValue(env, sig, args, ArrayIntToValue(env, rtn));
}

Gura_DeclareMethod(wx_Grid, GetSelectionBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectionBackground)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetSelectionBackground();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetSelectionBlockTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectionBlockTopLeft)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoordsArray rtn = pThis->GetEntity()->GetSelectionBlockTopLeft();
	return ReturnValue(env, sig, args, GridCellCoordsArrayToValue(env, rtn));
}

Gura_DeclareMethod(wx_Grid, GetSelectionBlockBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectionBlockBottomRight)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoordsArray rtn = pThis->GetEntity()->GetSelectionBlockBottomRight();
	return ReturnValue(env, sig, args, GridCellCoordsArrayToValue(env, rtn));
}

Gura_DeclareMethod(wx_Grid, GetSelectionForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetSelectionForeground)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour rtn = pThis->GetEntity()->GetSelectionForeground();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Grid, GetTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetTable)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridTableBase *rtn = (wxGridTableBase *)pThis->GetEntity()->GetTable();
	Value value;
	if (rtn != NULL) value = Value(new Object_wx_GridTableBase(rtn, NULL, OwnerFalse));
	return ReturnValue(env, sig, args, value);
}

Gura_DeclareMethod(wx_Grid, GetViewWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, GetViewWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetViewWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, HideCellEditControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, HideCellEditControl)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->HideCellEditControl();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, InitColWidths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, InitColWidths)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	dynamic_cast<wx_Grid *>(pThis->GetEntity())->_InitColWidths();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, InitRowHeights)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, InitRowHeights)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	dynamic_cast<wx_Grid *>(pThis->GetEntity())->_InitRowHeights();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, InsertCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numCols", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "updateLabels", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, InsertCols)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = 0;
	if (args.IsValid(0)) pos = args.GetInt(0);
	int numCols = 1;
	if (args.IsValid(1)) numCols = args.GetInt(1);
	bool updateLabels = true;
	if (args.IsValid(2)) updateLabels = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->InsertCols(pos, numCols, updateLabels);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, InsertRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pos", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "numRows", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "updateLabels", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, InsertRows)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int pos = 0;
	if (args.IsValid(0)) pos = args.GetInt(0);
	int numRows = 1;
	if (args.IsValid(1)) numRows = args.GetInt(1);
	bool updateLabels = true;
	if (args.IsValid(2)) updateLabels = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->InsertRows(pos, numRows, updateLabels);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsCellEditControlEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsCellEditControlEnabled)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsCellEditControlEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsCurrentCellReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsCurrentCellReadOnly)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsCurrentCellReadOnly();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsEditable)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEditable();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsInSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsInSelection)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	bool rtn = pThis->GetEntity()->IsInSelection(row, col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsInSelection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "coords", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsInSelection_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *coords = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsInSelection(*coords);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsReadOnly)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	bool rtn = pThis->GetEntity()->IsReadOnly(row, col);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsSelection)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsSelection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "wholeCellVisible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsVisible)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	bool wholeCellVisible = true;
	if (args.IsValid(2)) wholeCellVisible = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->IsVisible(row, col, wholeCellVisible);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, IsVisible_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "coords", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareArg(env, "wholeCellVisible", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, IsVisible_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *coords = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	bool wholeCellVisible = true;
	if (args.IsValid(1)) wholeCellVisible = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->IsVisible(*coords, wholeCellVisible);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MakeCellVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, MakeCellVisible)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	pThis->GetEntity()->MakeCellVisible(row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, MakeCellVisible_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coords", VTYPE_wx_GridCellCoords, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, MakeCellVisible_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *coords = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->MakeCellVisible(*coords);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, MoveCursorDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorDown)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorDown(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MoveCursorLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorLeft)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorLeft(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MoveCursorRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorRight)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorRight(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MoveCursorUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorUp)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorUp(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MoveCursorDownBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorDownBlock)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorDownBlock(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MoveCursorLeftBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorLeftBlock)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorLeftBlock(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MoveCursorRightBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorRightBlock)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorRightBlock(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MoveCursorUpBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expandSelection", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MoveCursorUpBlock)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool expandSelection = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->MoveCursorUpBlock(expandSelection);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MovePageDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MovePageDown)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MovePageDown();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, MovePageUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, MovePageUp)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MovePageUp();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, RegisterDataType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "renderer", VTYPE_wx_GridCellRenderer, OCCUR_Once);
	DeclareArg(env, "editor", VTYPE_wx_GridCellEditor, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, RegisterDataType)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString typeName = wxString::FromUTF8(args.GetString(0));
	wxGridCellRenderer *renderer = Object_wx_GridCellRenderer::GetObject(args, 1)->GetEntity();
	wxGridCellEditor *editor = Object_wx_GridCellEditor::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->RegisterDataType(typeName, renderer, editor);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SaveEditControlValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, SaveEditControlValue)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SaveEditControlValue();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SelectAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, SelectAll)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->SelectAll();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SelectBlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "topRow", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "leftCol", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "bottomRow", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "rightCol", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "addToSelected", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SelectBlock)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int topRow = args.GetInt(0);
	int leftCol = args.GetInt(1);
	int bottomRow = args.GetInt(2);
	int rightCol = args.GetInt(3);
	bool addToSelected = false;
	if (args.IsValid(4)) addToSelected = args.GetBoolean(4);
	pThis->GetEntity()->SelectBlock(topRow, leftCol, bottomRow, rightCol, addToSelected);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SelectBlock_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "topLeft", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareArg(env, "bottomRight", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareArg(env, "addToSelected", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SelectBlock_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *topLeft = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	wxGridCellCoords *bottomRight = Object_wx_GridCellCoords::GetObject(args, 1)->GetEntity();
	bool addToSelected = false;
	if (args.IsValid(2)) addToSelected = args.GetBoolean(2);
	pThis->GetEntity()->SelectBlock(*topLeft, *bottomRight, addToSelected);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SelectCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "addToSelected", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SelectCol)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	bool addToSelected = false;
	if (args.IsValid(1)) addToSelected = args.GetBoolean(1);
	pThis->GetEntity()->SelectCol(col, addToSelected);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SelectRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "addToSelected", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SelectRow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	bool addToSelected = false;
	if (args.IsValid(1)) addToSelected = args.GetBoolean(1);
	pThis->GetEntity()->SelectRow(row, addToSelected);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellOverflow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "allow", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellOverflow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	int allow = args.GetBoolean(2);
	pThis->GetEntity()->SetCellOverflow(row, col, allow);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "num_rows", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "num_cols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	int num_rows = args.GetInt(2);
	int num_cols = args.GetInt(3);
	pThis->GetEntity()->SetCellSize(row, col, num_rows, num_cols);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "horiz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	int horiz = args.GetInt(2);
	int vert = args.GetInt(3);
	pThis->GetEntity()->SetCellAlignment(row, col, horiz, vert);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellAlignment_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellAlignment_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int align = args.GetInt(0);
	int row = args.GetInt(1);
	int col = args.GetInt(2);
	pThis->GetEntity()->SetCellAlignment(align, row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellBackgroundColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxColour *colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetCellBackgroundColour(row, col, *colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "editor", VTYPE_wx_GridCellEditor, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellEditor)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellEditor *editor = Object_wx_GridCellEditor::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetCellEditor(row, col, editor);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellFont)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxFont *font = Object_wx_Font::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetCellFont(row, col, *font);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellHighlightPenWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellHighlightPenWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetCellHighlightPenWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellHighlightROPenWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellHighlightROPenWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetCellHighlightROPenWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "renderer", VTYPE_wx_GridCellRenderer, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellRenderer)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxGridCellRenderer *renderer = Object_wx_GridCellRenderer::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetCellRenderer(row, col, renderer);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellTextColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxColour *colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->SetCellTextColour(row, col, *colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellTextColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "val", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellTextColour_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *val = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	int row = args.GetInt(1);
	int col = args.GetInt(2);
	pThis->GetEntity()->SetCellTextColour(*val, row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellTextColour_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellTextColour_2)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCellTextColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellValue)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	wxString s = wxString::FromUTF8(args.GetString(2));
	pThis->GetEntity()->SetCellValue(row, col, s);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellValue_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "coords", VTYPE_wx_GridCellCoords, OCCUR_Once);
	DeclareArg(env, "s", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellValue_1)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellCoords *coords = Object_wx_GridCellCoords::GetObject(args, 0)->GetEntity();
	wxString s = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetCellValue(*coords, s);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetCellValue_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "val", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetCellValue_2)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString val = wxString::FromUTF8(args.GetString(0));
	int row = args.GetInt(1);
	int col = args.GetInt(2);
	pThis->GetEntity()->SetCellValue(val, row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColAttr)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetColAttr(col, attr);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColFormatBool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColFormatBool)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->SetColFormatBool(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColFormatNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColFormatNumber)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	pThis->GetEntity()->SetColFormatNumber(col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColFormatFloat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "precision", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SetColFormatFloat)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int width = -1;
	if (args.IsValid(1)) width = args.GetInt(1);
	int precision = -1;
	if (args.IsValid(2)) precision = args.GetInt(2);
	pThis->GetEntity()->SetColFormatFloat(col, width, precision);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColFormatCustom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "typeName", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColFormatCustom)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxString typeName = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetColFormatCustom(col, typeName);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColLabelAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "horiz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColLabelAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int horiz = args.GetInt(0);
	int vert = args.GetInt(1);
	pThis->GetEntity()->SetColLabelAlignment(horiz, vert);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColLabelSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetColLabelSize(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColLabelValue)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	wxString value = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetColLabelValue(col, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColMinimalWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColMinimalWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int width = args.GetInt(1);
	pThis->GetEntity()->SetColMinimalWidth(col, width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColMinimalAcceptableWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColMinimalAcceptableWidth)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetColMinimalAcceptableWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colID", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "newPos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColPos)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int colID = args.GetInt(0);
	int newPos = args.GetInt(1);
	pThis->GetEntity()->SetColPos(colID, newPos);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetColSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetColSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int col = args.GetInt(0);
	int width = args.GetInt(1);
	pThis->GetEntity()->SetColSize(col, width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultCellAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "horiz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetDefaultCellAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int horiz = args.GetInt(0);
	int vert = args.GetInt(1);
	pThis->GetEntity()->SetDefaultCellAlignment(horiz, vert);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultCellBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetDefaultCellBackgroundColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultCellBackgroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultCellFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetDefaultCellFont)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultCellFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultCellOverflow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "allow", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetDefaultCellOverflow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool allow = args.GetBoolean(0);
	pThis->GetEntity()->SetDefaultCellOverflow(allow);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultCellTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetDefaultCellTextColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultCellTextColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "editor", VTYPE_wx_GridCellEditor, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetDefaultEditor)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellEditor *editor = Object_wx_GridCellEditor::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultEditor(editor);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "renderer", VTYPE_wx_GridCellRenderer, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetDefaultRenderer)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridCellRenderer *renderer = Object_wx_GridCellRenderer::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDefaultRenderer(renderer);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultColSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "resizeExistingCols", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SetDefaultColSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	bool resizeExistingCols = false;
	if (args.IsValid(1)) resizeExistingCols = args.GetBoolean(1);
	pThis->GetEntity()->SetDefaultColSize(width, resizeExistingCols);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetDefaultRowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "resizeExistingRows", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SetDefaultRowSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	bool resizeExistingRows = false;
	if (args.IsValid(1)) resizeExistingRows = args.GetBoolean(1);
	pThis->GetEntity()->SetDefaultRowSize(height, resizeExistingRows);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetGridCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetGridCursor)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	pThis->GetEntity()->SetGridCursor(row, col);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetGridLineColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetGridLineColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetGridLineColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetLabelBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetLabelBackgroundColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetLabelBackgroundColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetLabelFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetLabelFont)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetLabelFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetLabelTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetLabelTextColour)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetLabelTextColour(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "extraWidth", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "extraHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetMargins)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int extraWidth = args.GetInt(0);
	int extraHeight = args.GetInt(1);
	pThis->GetEntity()->SetMargins(extraWidth, extraHeight);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetOrCalcColumnSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "calcOnly", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "setAsMin", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SetOrCalcColumnSizes)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool calcOnly = args.GetBoolean(0);
	bool setAsMin = true;
	if (args.IsValid(1)) setAsMin = args.GetBoolean(1);
	int rtn = dynamic_cast<wx_Grid *>(pThis->GetEntity())->_SetOrCalcColumnSizes(calcOnly, setAsMin);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, SetOrCalcRowSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "calcOnly", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "setAsMin", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SetOrCalcRowSizes)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool calcOnly = args.GetBoolean(0);
	bool setAsMin = true;
	if (args.IsValid(1)) setAsMin = args.GetBoolean(1);
	int rtn = dynamic_cast<wx_Grid *>(pThis->GetEntity())->_SetOrCalcRowSizes(calcOnly, setAsMin);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, SetReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "isReadOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SetReadOnly)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int col = args.GetInt(1);
	bool isReadOnly = true;
	if (args.IsValid(2)) isReadOnly = args.GetBoolean(2);
	pThis->GetEntity()->SetReadOnly(row, col, isReadOnly);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetRowAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "attr", VTYPE_wx_GridCellAttr, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetRowAttr)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	wxGridCellAttr *attr = Object_wx_GridCellAttr::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetRowAttr(row, attr);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetRowLabelAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "horiz", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "vert", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetRowLabelAlignment)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int horiz = args.GetInt(0);
	int vert = args.GetInt(1);
	pThis->GetEntity()->SetRowLabelAlignment(horiz, vert);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetRowLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetRowLabelSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetRowLabelSize(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetRowLabelValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetRowLabelValue)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	wxString value = wxString::FromUTF8(args.GetString(1));
	pThis->GetEntity()->SetRowLabelValue(row, value);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetRowMinimalHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetRowMinimalHeight)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->SetRowMinimalHeight(row, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetRowMinimalAcceptableHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetRowMinimalAcceptableHeight)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetRowMinimalAcceptableHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetRowSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetRowSize)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int row = args.GetInt(0);
	int height = args.GetInt(1);
	pThis->GetEntity()->SetRowSize(row, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetScrollLineX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetScrollLineX)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	pThis->GetEntity()->SetScrollLineX(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetScrollLineY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetScrollLineY)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int y = args.GetInt(0);
	pThis->GetEntity()->SetScrollLineY(y);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetSelectionBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetSelectionBackground)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *c = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSelectionBackground(*c);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetSelectionForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "c", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetSelectionForeground)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *c = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSelectionForeground(*c);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetSelectionMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "selmode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Grid, SetSelectionMode)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGrid::wxGridSelectionModes selmode =
					static_cast<wxGrid::wxGridSelectionModes>(args.GetInt(0));
	pThis->GetEntity()->SetSelectionMode(selmode);
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, SetTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "table", VTYPE_wx_GridTableBase, OCCUR_Once);
	DeclareArg(env, "takeOwnership", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "selmode", VTYPE_wx_Grid, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, SetTable)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGridTableBase *table = Object_wx_GridTableBase::GetObject(args, 0)->GetEntity();
	bool takeOwnership = false;
	if (args.IsValid(1)) takeOwnership = args.GetBoolean(1);
	wxGrid::wxGridSelectionModes selmode = wxGrid::wxGridSelectCells;
	if (args.IsValid(2)) selmode = static_cast<wxGrid::wxGridSelectionModes>(args.GetInt(2));
	bool rtn = pThis->GetEntity()->SetTable(table, takeOwnership, selmode);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, ShowCellEditControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Grid, ShowCellEditControl)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ShowCellEditControl();
	return Value::Null;
}

Gura_DeclareMethod(wx_Grid, XToCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "clipToMinMax", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, XToCol)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	bool clipToMinMax = false;
	if (args.IsValid(1)) clipToMinMax = args.GetBoolean(1);
	int rtn = pThis->GetEntity()->XToCol(x, clipToMinMax);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, XToEdgeOfCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, XToEdgeOfCol)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int rtn = pThis->GetEntity()->XToEdgeOfCol(x);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, YToEdgeOfRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, YToEdgeOfRow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int y = args.GetInt(0);
	int rtn = pThis->GetEntity()->YToEdgeOfRow(y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Grid, YToRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Grid, YToRow)
{
	Object_wx_Grid *pThis = Object_wx_Grid::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int y = args.GetInt(0);
	int rtn = pThis->GetEntity()->YToRow(y);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxGrid
//----------------------------------------------------------------------------
Object_wx_Grid::~Object_wx_Grid()
{
}

Object *Object_wx_Grid::Clone() const
{
	return NULL;
}

String Object_wx_Grid::ToString(bool exprFlag)
{
	String rtn("<wx.Grid:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxGrid
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Grid)
{
	Gura_AssignFunction(GridEmpty);
	Gura_AssignFunction(Grid);
	Gura_AssignMethod(wx_Grid, AppendCols);
	Gura_AssignMethod(wx_Grid, AppendRows);
	Gura_AssignMethod(wx_Grid, AutoSize);
	Gura_AssignMethod(wx_Grid, AutoSizeColumn);
	Gura_AssignMethod(wx_Grid, AutoSizeColumns);
	Gura_AssignMethod(wx_Grid, AutoSizeRow);
	Gura_AssignMethod(wx_Grid, AutoSizeRows);
	Gura_AssignMethod(wx_Grid, BeginBatch);
	Gura_AssignMethod(wx_Grid, BlockToDeviceRect);
	Gura_AssignMethod(wx_Grid, CanDragColMove);
	Gura_AssignMethod(wx_Grid, CanDragColSize);
	Gura_AssignMethod(wx_Grid, CanDragRowSize);
	Gura_AssignMethod(wx_Grid, CanDragGridSize);
	Gura_AssignMethod(wx_Grid, CanEnableCellControl);
	Gura_AssignMethod(wx_Grid, CanHaveAttributes);
	Gura_AssignMethod(wx_Grid, CellToRect);
	Gura_AssignMethod(wx_Grid, CellToRect_1);
	Gura_AssignMethod(wx_Grid, ClearGrid);
	Gura_AssignMethod(wx_Grid, ClearSelection);
	Gura_AssignMethod(wx_Grid, CreateGrid);
	Gura_AssignMethod(wx_Grid, DeleteCols);
	Gura_AssignMethod(wx_Grid, DeleteRows);
	Gura_AssignMethod(wx_Grid, DeselectCell);
	Gura_AssignMethod(wx_Grid, DeselectCol);
	Gura_AssignMethod(wx_Grid, DeselectRow);
	Gura_AssignMethod(wx_Grid, DisableCellEditControl);
	Gura_AssignMethod(wx_Grid, DisableDragColMove);
	Gura_AssignMethod(wx_Grid, DisableDragColSize);
	Gura_AssignMethod(wx_Grid, DisableDragGridSize);
	Gura_AssignMethod(wx_Grid, DisableDragRowSize);
	Gura_AssignMethod(wx_Grid, EnableCellEditControl);
	Gura_AssignMethod(wx_Grid, EnableDragColSize);
	Gura_AssignMethod(wx_Grid, EnableDragColMove);
	Gura_AssignMethod(wx_Grid, EnableDragGridSize);
	Gura_AssignMethod(wx_Grid, EnableDragRowSize);
	Gura_AssignMethod(wx_Grid, EnableEditing);
	Gura_AssignMethod(wx_Grid, EnableGridLines);
	Gura_AssignMethod(wx_Grid, EndBatch);
	Gura_AssignMethod(wx_Grid, Fit);
	Gura_AssignMethod(wx_Grid, ForceRefresh);
	Gura_AssignMethod(wx_Grid, GetBatchCount);
	Gura_AssignMethod(wx_Grid, GetCellOverflow);
	Gura_AssignMethod(wx_Grid, GetCellAlignment);
	Gura_AssignMethod(wx_Grid, GetCellBackgroundColour);
	Gura_AssignMethod(wx_Grid, GetCellEditor);
	Gura_AssignMethod(wx_Grid, GetCellFont);
	Gura_AssignMethod(wx_Grid, GetCellHighlightPenWidth);
	Gura_AssignMethod(wx_Grid, GetCellHighlightROPenWidth);
	Gura_AssignMethod(wx_Grid, GetCellRenderer);
	Gura_AssignMethod(wx_Grid, GetCellTextColour);
	Gura_AssignMethod(wx_Grid, GetCellValue);
	Gura_AssignMethod(wx_Grid, GetCellValue_1);
	Gura_AssignMethod(wx_Grid, GetColAt);
	Gura_AssignMethod(wx_Grid, GetColLeft);
	Gura_AssignMethod(wx_Grid, GetColLabelAlignment);
	Gura_AssignMethod(wx_Grid, GetColLabelSize);
	Gura_AssignMethod(wx_Grid, GetColLabelValue);
	Gura_AssignMethod(wx_Grid, GetColMinimalAcceptableWidth);
	Gura_AssignMethod(wx_Grid, GetColMinimalWidth);
	Gura_AssignMethod(wx_Grid, GetColPos);
	Gura_AssignMethod(wx_Grid, GetColRight);
	Gura_AssignMethod(wx_Grid, GetColSize);
	Gura_AssignMethod(wx_Grid, GetDefaultCellAlignment);
	Gura_AssignMethod(wx_Grid, GetDefaultCellBackgroundColour);
	Gura_AssignMethod(wx_Grid, GetDefaultCellFont);
	Gura_AssignMethod(wx_Grid, GetDefaultCellOverflow);
	Gura_AssignMethod(wx_Grid, GetDefaultCellTextColour);
	Gura_AssignMethod(wx_Grid, GetDefaultColLabelSize);
	Gura_AssignMethod(wx_Grid, GetDefaultColSize);
	Gura_AssignMethod(wx_Grid, GetDefaultEditor);
	Gura_AssignMethod(wx_Grid, GetDefaultEditorForCell);
	Gura_AssignMethod(wx_Grid, GetDefaultEditorForCell_1);
	Gura_AssignMethod(wx_Grid, GetDefaultEditorForType);
	Gura_AssignMethod(wx_Grid, GetDefaultRenderer);
	Gura_AssignMethod(wx_Grid, GetDefaultRendererForCell);
	Gura_AssignMethod(wx_Grid, GetDefaultRendererForType);
	Gura_AssignMethod(wx_Grid, GetDefaultRowLabelSize);
	Gura_AssignMethod(wx_Grid, GetDefaultRowSize);
	Gura_AssignMethod(wx_Grid, GetGridCursorCol);
	Gura_AssignMethod(wx_Grid, GetGridCursorRow);
	Gura_AssignMethod(wx_Grid, GetGridLineColour);
	Gura_AssignMethod(wx_Grid, GetDefaultGridLinePen);
	Gura_AssignMethod(wx_Grid, GetRowGridLinePen);
	Gura_AssignMethod(wx_Grid, GetColGridLinePen);
	Gura_AssignMethod(wx_Grid, GridLinesEnabled);
	Gura_AssignMethod(wx_Grid, GetLabelBackgroundColour);
	Gura_AssignMethod(wx_Grid, GetLabelFont);
	Gura_AssignMethod(wx_Grid, GetLabelTextColour);
	Gura_AssignMethod(wx_Grid, GetNumberCols);
	Gura_AssignMethod(wx_Grid, GetNumberRows);
	Gura_AssignMethod(wx_Grid, GetOrCreateCellAttr);
	Gura_AssignMethod(wx_Grid, GetRowMinimalAcceptableHeight);
	Gura_AssignMethod(wx_Grid, GetRowMinimalHeight);
	Gura_AssignMethod(wx_Grid, GetRowLabelAlignment);
	Gura_AssignMethod(wx_Grid, GetRowLabelSize);
	Gura_AssignMethod(wx_Grid, GetRowLabelValue);
	Gura_AssignMethod(wx_Grid, GetRowSize);
	Gura_AssignMethod(wx_Grid, GetScrollLineX);
	Gura_AssignMethod(wx_Grid, GetScrollLineY);
	Gura_AssignMethod(wx_Grid, GetSelectionMode);
	Gura_AssignMethod(wx_Grid, GetSelectedCells);
	Gura_AssignMethod(wx_Grid, GetSelectedCols);
	Gura_AssignMethod(wx_Grid, GetSelectedRows);
	Gura_AssignMethod(wx_Grid, GetSelectionBackground);
	Gura_AssignMethod(wx_Grid, GetSelectionBlockTopLeft);
	Gura_AssignMethod(wx_Grid, GetSelectionBlockBottomRight);
	Gura_AssignMethod(wx_Grid, GetSelectionForeground);
	Gura_AssignMethod(wx_Grid, GetTable);
	Gura_AssignMethod(wx_Grid, GetViewWidth);
	Gura_AssignMethod(wx_Grid, HideCellEditControl);
	Gura_AssignMethod(wx_Grid, InitColWidths);
	Gura_AssignMethod(wx_Grid, InitRowHeights);
	Gura_AssignMethod(wx_Grid, InsertCols);
	Gura_AssignMethod(wx_Grid, InsertRows);
	Gura_AssignMethod(wx_Grid, IsCellEditControlEnabled);
	Gura_AssignMethod(wx_Grid, IsCurrentCellReadOnly);
	Gura_AssignMethod(wx_Grid, IsEditable);
	Gura_AssignMethod(wx_Grid, IsInSelection);
	Gura_AssignMethod(wx_Grid, IsInSelection_1);
	Gura_AssignMethod(wx_Grid, IsReadOnly);
	Gura_AssignMethod(wx_Grid, IsSelection);
	Gura_AssignMethod(wx_Grid, IsVisible);
	Gura_AssignMethod(wx_Grid, IsVisible_1);
	Gura_AssignMethod(wx_Grid, MakeCellVisible);
	Gura_AssignMethod(wx_Grid, MakeCellVisible_1);
	Gura_AssignMethod(wx_Grid, MoveCursorDown);
	Gura_AssignMethod(wx_Grid, MoveCursorLeft);
	Gura_AssignMethod(wx_Grid, MoveCursorRight);
	Gura_AssignMethod(wx_Grid, MoveCursorUp);
	Gura_AssignMethod(wx_Grid, MoveCursorDownBlock);
	Gura_AssignMethod(wx_Grid, MoveCursorLeftBlock);
	Gura_AssignMethod(wx_Grid, MoveCursorRightBlock);
	Gura_AssignMethod(wx_Grid, MoveCursorUpBlock);
	Gura_AssignMethod(wx_Grid, MovePageDown);
	Gura_AssignMethod(wx_Grid, MovePageUp);
	Gura_AssignMethod(wx_Grid, RegisterDataType);
	Gura_AssignMethod(wx_Grid, SaveEditControlValue);
	Gura_AssignMethod(wx_Grid, SelectAll);
	Gura_AssignMethod(wx_Grid, SelectBlock);
	Gura_AssignMethod(wx_Grid, SelectBlock_1);
	Gura_AssignMethod(wx_Grid, SelectCol);
	Gura_AssignMethod(wx_Grid, SelectRow);
	Gura_AssignMethod(wx_Grid, SetCellOverflow);
	Gura_AssignMethod(wx_Grid, SetCellSize);
	Gura_AssignMethod(wx_Grid, SetCellAlignment);
	Gura_AssignMethod(wx_Grid, SetCellAlignment_1);
	Gura_AssignMethod(wx_Grid, SetCellBackgroundColour);
	Gura_AssignMethod(wx_Grid, SetCellEditor);
	Gura_AssignMethod(wx_Grid, SetCellFont);
	Gura_AssignMethod(wx_Grid, SetCellHighlightPenWidth);
	Gura_AssignMethod(wx_Grid, SetCellHighlightROPenWidth);
	Gura_AssignMethod(wx_Grid, SetCellRenderer);
	Gura_AssignMethod(wx_Grid, SetCellTextColour);
	Gura_AssignMethod(wx_Grid, SetCellTextColour_1);
	Gura_AssignMethod(wx_Grid, SetCellTextColour_2);
	Gura_AssignMethod(wx_Grid, SetCellValue);
	Gura_AssignMethod(wx_Grid, SetCellValue_1);
	Gura_AssignMethod(wx_Grid, SetCellValue_2);
	Gura_AssignMethod(wx_Grid, SetColAttr);
	Gura_AssignMethod(wx_Grid, SetColFormatBool);
	Gura_AssignMethod(wx_Grid, SetColFormatNumber);
	Gura_AssignMethod(wx_Grid, SetColFormatFloat);
	Gura_AssignMethod(wx_Grid, SetColFormatCustom);
	Gura_AssignMethod(wx_Grid, SetColLabelAlignment);
	Gura_AssignMethod(wx_Grid, SetColLabelSize);
	Gura_AssignMethod(wx_Grid, SetColLabelValue);
	Gura_AssignMethod(wx_Grid, SetColMinimalWidth);
	Gura_AssignMethod(wx_Grid, SetColMinimalAcceptableWidth);
	Gura_AssignMethod(wx_Grid, SetColPos);
	Gura_AssignMethod(wx_Grid, SetColSize);
	Gura_AssignMethod(wx_Grid, SetDefaultCellAlignment);
	Gura_AssignMethod(wx_Grid, SetDefaultCellBackgroundColour);
	Gura_AssignMethod(wx_Grid, SetDefaultCellFont);
	Gura_AssignMethod(wx_Grid, SetDefaultCellOverflow);
	Gura_AssignMethod(wx_Grid, SetDefaultCellTextColour);
	Gura_AssignMethod(wx_Grid, SetDefaultEditor);
	Gura_AssignMethod(wx_Grid, SetDefaultRenderer);
	Gura_AssignMethod(wx_Grid, SetDefaultColSize);
	Gura_AssignMethod(wx_Grid, SetDefaultRowSize);
	Gura_AssignMethod(wx_Grid, SetGridCursor);
	Gura_AssignMethod(wx_Grid, SetGridLineColour);
	Gura_AssignMethod(wx_Grid, SetLabelBackgroundColour);
	Gura_AssignMethod(wx_Grid, SetLabelFont);
	Gura_AssignMethod(wx_Grid, SetLabelTextColour);
	Gura_AssignMethod(wx_Grid, SetMargins);
	Gura_AssignMethod(wx_Grid, SetOrCalcColumnSizes);
	Gura_AssignMethod(wx_Grid, SetOrCalcRowSizes);
	Gura_AssignMethod(wx_Grid, SetReadOnly);
	Gura_AssignMethod(wx_Grid, SetRowAttr);
	Gura_AssignMethod(wx_Grid, SetRowLabelAlignment);
	Gura_AssignMethod(wx_Grid, SetRowLabelSize);
	Gura_AssignMethod(wx_Grid, SetRowLabelValue);
	Gura_AssignMethod(wx_Grid, SetRowMinimalHeight);
	Gura_AssignMethod(wx_Grid, SetRowMinimalAcceptableHeight);
	Gura_AssignMethod(wx_Grid, SetRowSize);
	Gura_AssignMethod(wx_Grid, SetScrollLineX);
	Gura_AssignMethod(wx_Grid, SetScrollLineY);
	Gura_AssignMethod(wx_Grid, SetSelectionBackground);
	Gura_AssignMethod(wx_Grid, SetSelectionForeground);
	Gura_AssignMethod(wx_Grid, SetSelectionMode);
	Gura_AssignMethod(wx_Grid, SetTable);
	Gura_AssignMethod(wx_Grid, ShowCellEditControl);
	Gura_AssignMethod(wx_Grid, XToCol);
	Gura_AssignMethod(wx_Grid, XToEdgeOfCol);
	Gura_AssignMethod(wx_Grid, YToEdgeOfRow);
	Gura_AssignMethod(wx_Grid, YToRow);
	Gura_AssignClassValue(wxGridSelectCells, wxGrid::wxGridSelectCells);
	Gura_AssignClassValue(wxGridSelectRows, wxGrid::wxGridSelectRows);
	Gura_AssignClassValue(wxGridSelectColumns, wxGrid::wxGridSelectColumns);
}

Gura_ImplementDescendantCreator(wx_Grid)
{
	return new Object_wx_Grid((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value GridCellCoordsArrayToValue(Environment &env, const wxGridCellCoordsArray &array)
{
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	valList.reserve(array.GetCount());
	for (size_t i = 0; i < array.GetCount(); i++) {
		const wxGridCellCoords &coords = array.Item(i);
		valList.push_back(Value(new Object_wx_GridCellCoords(
								new wxGridCellCoords(coords), NULL, OwnerTrue)));
	}
	return rtn;
}

Gura_EndModuleScope(wx)
