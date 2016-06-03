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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextTable, "RichTextTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextTable)
{
	//wxRichTextObject* parent = arg.GetNumber(0)
	//wxRichTextTable();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextTable_1, "RichTextTable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextTable_1)
{
	//const wxRichTextTable& obj = arg.GetNumber(0)
	//wxRichTextTable();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextTable, __Draw, "Draw")
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

Gura_ImplementMethod(wx_RichTextTable, __Draw)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRichTextRange& range = arg.GetNumber(2)
	//const wxRichTextSelection& selection = arg.GetNumber(3)
	//const wxRect& rect = arg.GetNumber(4)
	//int descent = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Draw();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __HitTest, "HitTest")
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

Gura_ImplementMethod(wx_RichTextTable, __HitTest)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxPoint& pt = arg.GetNumber(2)
	//long& textPosition = arg.GetNumber(3)
	//wxRichTextObject** obj = arg.GetNumber(4)
	//wxRichTextObject** contextObj = arg.GetNumber(5)
	//int flags = arg.GetNumber(6)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetXMLNodeName, "GetXMLNodeName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __GetXMLNodeName)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetXMLNodeName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __Layout, "Layout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __Layout)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//const wxRect& parentRect = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetRangeSize, "GetRangeSize")
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

Gura_ImplementMethod(wx_RichTextTable, __GetRangeSize)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//wxSize& size = arg.GetNumber(1)
	//int& descent = arg.GetNumber(2)
	//wxDC& dc = arg.GetNumber(3)
	//wxRichTextDrawingContext& context = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//const wxPoint& position = arg.GetNumber(6)
	//const wxSize& parentSize = arg.GetNumber(7)
	//wxArrayInt* partialExtents = arg.GetNumber(8)
	//pThis->GetEntity()->GetRangeSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __DeleteRange, "DeleteRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __DeleteRange)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetTextForRange, "GetTextForRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __GetTextForRange)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextRange& range = arg.GetNumber(0)
	//pThis->GetEntity()->GetTextForRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __ImportFromXML, "ImportFromXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "node", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __ImportFromXML)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextBuffer* buffer = arg.GetNumber(0)
	//wxXmlNode* node = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//bool* recurse = arg.GetNumber(3)
	//pThis->GetEntity()->ImportFromXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __ExportXML, "ExportXML")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __ExportXML)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream& stream = arg.GetNumber(0)
	//int indent = arg.GetNumber(1)
	//wxRichTextXMLHandler* handler = arg.GetNumber(2)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __ExportXML_1, "ExportXML_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __ExportXML_1)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxXmlNode* parent = arg.GetNumber(0)
	//wxRichTextXMLHandler* handler = arg.GetNumber(1)
	//pThis->GetEntity()->ExportXML();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __FindPosition, "FindPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceLineStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __FindPosition)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxRichTextDrawingContext& context = arg.GetNumber(1)
	//long index = arg.GetNumber(2)
	//wxPoint& pt = arg.GetNumber(3)
	//int* height = arg.GetNumber(4)
	//bool forceLineStart = arg.GetNumber(5)
	//pThis->GetEntity()->FindPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __CalculateRange, "CalculateRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __CalculateRange)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//long& end = arg.GetNumber(1)
	//pThis->GetEntity()->CalculateRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __HandlesChildSelections, "HandlesChildSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __HandlesChildSelections)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HandlesChildSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __GetSelection)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long start = arg.GetNumber(0)
	//long end = arg.GetNumber(1)
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __CanEditProperties, "CanEditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __CanEditProperties)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanEditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __EditProperties, "EditProperties")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __EditProperties)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxRichTextBuffer* buffer = arg.GetNumber(1)
	//pThis->GetEntity()->EditProperties();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetPropertiesMenuLabel, "GetPropertiesMenuLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __GetPropertiesMenuLabel)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPropertiesMenuLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __AcceptsFocus, "AcceptsFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __AcceptsFocus)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetCells, "GetCells")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __GetCells)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCells();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetCells_1, "GetCells_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __GetCells_1)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCells();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetRowCount, "GetRowCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __GetRowCount)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __GetColumnCount)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetCell, "GetCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __GetCell)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetCell_1, "GetCell_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __GetCell_1)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetCellRowColumnPosition, "GetCellRowColumnPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __GetCellRowColumnPosition)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long pos = arg.GetNumber(0)
	//int& row = arg.GetNumber(1)
	//int& col = arg.GetNumber(2)
	//pThis->GetEntity()->GetCellRowColumnPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __GetFocusedCell, "GetFocusedCell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __GetFocusedCell)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFocusedCell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __ClearTable, "ClearTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __ClearTable)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __CreateTable, "CreateTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __CreateTable)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//pThis->GetEntity()->CreateTable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __SetCellStyle, "SetCellStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __SetCellStyle)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextSelection& selection = arg.GetNumber(0)
	//const wxRichTextAttr& style = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->SetCellStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __DeleteRows, "DeleteRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startRow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noRows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __DeleteRows)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startRow = arg.GetNumber(0)
	//int noRows = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __DeleteColumns, "DeleteColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noCols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __DeleteColumns)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startCol = arg.GetNumber(0)
	//int noCols = arg.GetNumber(1)
	//pThis->GetEntity()->DeleteColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __AddRows, "AddRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startRow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noRows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __AddRows)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startRow = arg.GetNumber(0)
	//int noRows = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//pThis->GetEntity()->AddRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __AddColumns, "AddColumns")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noCols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __AddColumns)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int startCol = arg.GetNumber(0)
	//int noCols = arg.GetNumber(1)
	//const wxRichTextAttr& attr = arg.GetNumber(2)
	//pThis->GetEntity()->AddColumns();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextTable, __Clone)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextTable, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextTable, __Copy)
{
	Object_wx_RichTextTable *pThis = Object_wx_RichTextTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextTable& obj = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextTable)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextTable);
	Gura_AssignFunction(__RichTextTable_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextTable, __Draw);
	Gura_AssignMethod(wx_RichTextTable, __HitTest);
	Gura_AssignMethod(wx_RichTextTable, __GetXMLNodeName);
	Gura_AssignMethod(wx_RichTextTable, __Layout);
	Gura_AssignMethod(wx_RichTextTable, __GetRangeSize);
	Gura_AssignMethod(wx_RichTextTable, __DeleteRange);
	Gura_AssignMethod(wx_RichTextTable, __GetTextForRange);
	Gura_AssignMethod(wx_RichTextTable, __ImportFromXML);
	Gura_AssignMethod(wx_RichTextTable, __ExportXML);
	Gura_AssignMethod(wx_RichTextTable, __ExportXML_1);
	Gura_AssignMethod(wx_RichTextTable, __FindPosition);
	Gura_AssignMethod(wx_RichTextTable, __CalculateRange);
	Gura_AssignMethod(wx_RichTextTable, __HandlesChildSelections);
	Gura_AssignMethod(wx_RichTextTable, __GetSelection);
	Gura_AssignMethod(wx_RichTextTable, __CanEditProperties);
	Gura_AssignMethod(wx_RichTextTable, __EditProperties);
	Gura_AssignMethod(wx_RichTextTable, __GetPropertiesMenuLabel);
	Gura_AssignMethod(wx_RichTextTable, __AcceptsFocus);
	Gura_AssignMethod(wx_RichTextTable, __GetCells);
	Gura_AssignMethod(wx_RichTextTable, __GetCells_1);
	Gura_AssignMethod(wx_RichTextTable, __GetRowCount);
	Gura_AssignMethod(wx_RichTextTable, __GetColumnCount);
	Gura_AssignMethod(wx_RichTextTable, __GetCell);
	Gura_AssignMethod(wx_RichTextTable, __GetCell_1);
	Gura_AssignMethod(wx_RichTextTable, __GetCellRowColumnPosition);
	Gura_AssignMethod(wx_RichTextTable, __GetFocusedCell);
	Gura_AssignMethod(wx_RichTextTable, __ClearTable);
	Gura_AssignMethod(wx_RichTextTable, __CreateTable);
	Gura_AssignMethod(wx_RichTextTable, __SetCellStyle);
	Gura_AssignMethod(wx_RichTextTable, __DeleteRows);
	Gura_AssignMethod(wx_RichTextTable, __DeleteColumns);
	Gura_AssignMethod(wx_RichTextTable, __AddRows);
	Gura_AssignMethod(wx_RichTextTable, __AddColumns);
	Gura_AssignMethod(wx_RichTextTable, __Clone);
	Gura_AssignMethod(wx_RichTextTable, __Copy);
}

Gura_ImplementDescendantCreator(wx_RichTextTable)
{
	return new Object_wx_RichTextTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
