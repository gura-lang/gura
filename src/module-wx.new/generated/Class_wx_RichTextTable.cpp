//----------------------------------------------------------------------------
// wxRichTextTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextTable
//----------------------------------------------------------------------------
Object_wx_RichTextTable::~Object_wx_RichTextTable()
{
}

Object *Object_wx_RichTextTable::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextTable::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextTable:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextTable, wxRichTextTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, wxRichTextTable)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, wxRichTextTable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, wxRichTextTable_1)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, Draw)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, Draw)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int selection = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textPosition", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "contextObj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, HitTest)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int pt = arg.GetNumber(2)
	//int textPosition = arg.GetNumber(3)
	//int obj = arg.GetNumber(4)
	//int contextObj = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetXMLNodeName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, GetXMLNodeName)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, Layout)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetRangeSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "partialExtents", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, GetRangeSize)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int descent = arg.GetNumber(2)
	//int dc = arg.GetNumber(3)
	//int context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//int position = arg.GetNumber(6)
	//int parentSize = arg.GetNumber(7)
	//int partialExtents = arg.GetNumber(8)
	//pThis->GetEntity()->GetRangeSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, DeleteRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, DeleteRange)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetTextForRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, GetTextForRange)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, ImportFromXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, ImportFromXML)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int node = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//int recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, ExportXML)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, ExportXML)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//int handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, ExportXML_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, ExportXML_1)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, FindPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, FindPosition)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int context = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//int pt = arg.GetNumber(3)
	//int height = arg.GetNumber(4)
	//int forceLineStart = arg.GetNumber(5)
	//pThis->GetEntity()->FindPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, CalculateRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, CalculateRange)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, HandlesChildSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, HandlesChildSelections)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HandlesChildSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, GetSelection)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, CanEditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, CanEditProperties)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, EditProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, EditProperties)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetPropertiesMenuLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, GetPropertiesMenuLabel)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, AcceptsFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, AcceptsFocus)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetCells)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, GetCells)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCells();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetCells_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, GetCells_1)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCells();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetRowCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, GetRowCount)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, GetColumnCount)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, GetCell)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetCell_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, GetCell_1)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetCellRowColumnPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, GetCellRowColumnPosition)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int row = arg.GetNumber(1)
	//int col = arg.GetNumber(2)
	//pThis->GetEntity()->GetCellRowColumnPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, GetFocusedCell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, GetFocusedCell)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFocusedCell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, ClearTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, ClearTable)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, CreateTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, CreateTable)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//pThis->GetEntity()->CreateTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, SetCellStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, SetCellStyle)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetCellStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, DeleteRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startRow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, DeleteRows)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startRow = arg.GetNumber(0)
	//int noRows = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, DeleteColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, DeleteColumns)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startCol = arg.GetNumber(0)
	//int noCols = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, AddRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startRow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noRows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, AddRows)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startRow = arg.GetNumber(0)
	//int noRows = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//pThis->GetEntity()->AddRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, AddColumns)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noCols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, AddColumns)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startCol = arg.GetNumber(0)
	//int noCols = arg.GetNumber(1)
	//int attr = arg.GetNumber(2)
	//pThis->GetEntity()->AddColumns();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, Clone)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextTable, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, Copy)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextTable)
{
	Gura_AssignMethod(wx_RichTextTable, wxRichTextTable);
	Gura_AssignMethod(wx_RichTextTable, wxRichTextTable_1);
	Gura_AssignMethod(wx_RichTextTable, Draw);
	Gura_AssignMethod(wx_RichTextTable, HitTest);
	Gura_AssignMethod(wx_RichTextTable, GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextTable, Layout);
	Gura_AssignMethod(wx_RichTextTable, GetRangeSize);
	Gura_AssignMethod(wx_RichTextTable, DeleteRange);
	Gura_AssignMethod(wx_RichTextTable, GetTextForRange);
	Gura_AssignMethod(wx_RichTextTable, ImportFromXML);
	Gura_AssignMethod(wx_RichTextTable, ExportXML);
	Gura_AssignMethod(wx_RichTextTable, ExportXML_1);
	Gura_AssignMethod(wx_RichTextTable, FindPosition);
	Gura_AssignMethod(wx_RichTextTable, CalculateRange);
	Gura_AssignMethod(wx_RichTextTable, HandlesChildSelections);
	Gura_AssignMethod(wx_RichTextTable, GetSelection);
	Gura_AssignMethod(wx_RichTextTable, CanEditProperties);
	Gura_AssignMethod(wx_RichTextTable, EditProperties);
	Gura_AssignMethod(wx_RichTextTable, GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextTable, AcceptsFocus);
	Gura_AssignMethod(wx_RichTextTable, GetCells);
	Gura_AssignMethod(wx_RichTextTable, GetCells_1);
	Gura_AssignMethod(wx_RichTextTable, GetRowCount);
	Gura_AssignMethod(wx_RichTextTable, GetColumnCount);
	Gura_AssignMethod(wx_RichTextTable, GetCell);
	Gura_AssignMethod(wx_RichTextTable, GetCell_1);
	Gura_AssignMethod(wx_RichTextTable, GetCellRowColumnPosition);
	Gura_AssignMethod(wx_RichTextTable, GetFocusedCell);
	Gura_AssignMethod(wx_RichTextTable, ClearTable);
	Gura_AssignMethod(wx_RichTextTable, CreateTable);
	Gura_AssignMethod(wx_RichTextTable, SetCellStyle);
	Gura_AssignMethod(wx_RichTextTable, DeleteRows);
	Gura_AssignMethod(wx_RichTextTable, DeleteColumns);
	Gura_AssignMethod(wx_RichTextTable, AddRows);
	Gura_AssignMethod(wx_RichTextTable, AddColumns);
	Gura_AssignMethod(wx_RichTextTable, Clone);
	Gura_AssignMethod(wx_RichTextTable, Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextTable)
{
	return new Object_wx_RichTextTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
