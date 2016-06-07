//----------------------------------------------------------------------------
// wxAuiNotebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiNotebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Object_wx_AuiNotebook::~Object_wx_AuiNotebook()
{
}

Object *Object_wx_AuiNotebook::Clone() const
{
	return nullptr;
}

String Object_wx_AuiNotebook::ToString(bool exprFlag)
{
	String rtn("<wx.AuiNotebook:");
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
Gura_DeclareFunctionAlias(__AuiNotebook, "AuiNotebook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiNotebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiNotebook)
{
	//wxAuiNotebook();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__AuiNotebook_1, "AuiNotebook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AuiNotebook));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiNotebook_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//wxAuiNotebook(parent, id, pos, size, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiNotebook, __AddPage, "AddPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __AddPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//const wxString& caption = arg.GetNumber(1)
	//bool select = arg.GetNumber(2)
	//const wxBitmap& bitmap = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->AddPage(page, caption, select, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __AddPage_1, "AddPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __AddPage_1)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//bool select = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//bool _rtn = pThis->GetEntity()->AddPage(page, text, select, imageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __AdvanceSelection, "AdvanceSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "forward", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __AdvanceSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool forward = arg.GetNumber(0)
	//pThis->GetEntity()->AdvanceSelection(forward);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __ChangeSelection, "ChangeSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __ChangeSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->ChangeSelection(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __Create)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __DeleteAllPages, "DeleteAllPages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __DeleteAllPages)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DeleteAllPages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __DeletePage, "DeletePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __DeletePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeletePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetArtProvider, "GetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetArtProvider)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiTabArt* _rtn = pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetCurrentPage, "GetCurrentPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetCurrentPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetHeightForPageHeight, "GetHeightForPageHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pageHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetHeightForPageHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageHeight = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetHeightForPageHeight(pageHeight);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page_idx = arg.GetNumber(0)
	//wxWindow* _rtn = pThis->GetEntity()->GetPage(page_idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageBitmap, "GetPageBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//wxBitmap _rtn = pThis->GetEntity()->GetPageBitmap(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageCount, "GetPageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageCount)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageIndex, "GetPageIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page_wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageIndex)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* page_wnd = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetPageIndex(page_wnd);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageText, "GetPageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetPageText(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageToolTip, "GetPageToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pageIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageToolTip)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pageIdx = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetPageToolTip(pageIdx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetTabCtrlHeight, "GetTabCtrlHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetTabCtrlHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetTabCtrlHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __InsertPage, "InsertPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __InsertPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page_idx = arg.GetNumber(0)
	//wxWindow* page = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//bool select = arg.GetNumber(3)
	//const wxBitmap& bitmap = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->InsertPage(page_idx, page, caption, select, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __InsertPage_1, "InsertPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __InsertPage_1)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//wxWindow* page = arg.GetNumber(1)
	//const wxString& text = arg.GetNumber(2)
	//bool select = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->InsertPage(index, page, text, select, imageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __RemovePage, "RemovePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __RemovePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->RemovePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetArtProvider)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiTabArt* art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider(art);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetMeasuringFont, "SetMeasuringFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetMeasuringFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetNormalFont, "SetNormalFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetNormalFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageBitmap, "SetPageBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetPageBitmap(page, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageImage, "SetPageImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageImage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//int imageId = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetPageImage(n, imageId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageText, "SetPageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetPageText(page, text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageToolTip, "SetPageToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageToolTip)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetPageToolTip(page, text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetSelectedFont, "SetSelectedFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetSelectedFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "new_page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t new_page = arg.GetNumber(0)
	//size_t _rtn = pThis->GetEntity()->SetSelection(new_page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetTabCtrlHeight, "SetTabCtrlHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetTabCtrlHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabCtrlHeight(height);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetUniformBitmapSize, "SetUniformBitmapSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetUniformBitmapSize)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetUniformBitmapSize(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __Split, "Split")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __Split)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t page = arg.GetNumber(0)
	//int direction = arg.GetNumber(1)
	//pThis->GetEntity()->Split(page, direction);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __ShowWindowMenu, "ShowWindowMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __ShowWindowMenu)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->ShowWindowMenu();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiNotebook)
{
	// Constructor assignment
	Gura_AssignFunction(__AuiNotebook);
	Gura_AssignFunction(__AuiNotebook_1);
	// Method assignment
	Gura_AssignMethod(wx_AuiNotebook, __AddPage);
	Gura_AssignMethod(wx_AuiNotebook, __AddPage_1);
	Gura_AssignMethod(wx_AuiNotebook, __AdvanceSelection);
	Gura_AssignMethod(wx_AuiNotebook, __ChangeSelection);
	Gura_AssignMethod(wx_AuiNotebook, __Create);
	Gura_AssignMethod(wx_AuiNotebook, __DeleteAllPages);
	Gura_AssignMethod(wx_AuiNotebook, __DeletePage);
	Gura_AssignMethod(wx_AuiNotebook, __GetArtProvider);
	Gura_AssignMethod(wx_AuiNotebook, __GetCurrentPage);
	Gura_AssignMethod(wx_AuiNotebook, __GetHeightForPageHeight);
	Gura_AssignMethod(wx_AuiNotebook, __GetPage);
	Gura_AssignMethod(wx_AuiNotebook, __GetPageBitmap);
	Gura_AssignMethod(wx_AuiNotebook, __GetPageCount);
	Gura_AssignMethod(wx_AuiNotebook, __GetPageIndex);
	Gura_AssignMethod(wx_AuiNotebook, __GetPageText);
	Gura_AssignMethod(wx_AuiNotebook, __GetPageToolTip);
	Gura_AssignMethod(wx_AuiNotebook, __GetSelection);
	Gura_AssignMethod(wx_AuiNotebook, __GetTabCtrlHeight);
	Gura_AssignMethod(wx_AuiNotebook, __InsertPage);
	Gura_AssignMethod(wx_AuiNotebook, __InsertPage_1);
	Gura_AssignMethod(wx_AuiNotebook, __RemovePage);
	Gura_AssignMethod(wx_AuiNotebook, __SetArtProvider);
	Gura_AssignMethod(wx_AuiNotebook, __SetFont);
	Gura_AssignMethod(wx_AuiNotebook, __SetMeasuringFont);
	Gura_AssignMethod(wx_AuiNotebook, __SetNormalFont);
	Gura_AssignMethod(wx_AuiNotebook, __SetPageBitmap);
	Gura_AssignMethod(wx_AuiNotebook, __SetPageImage);
	Gura_AssignMethod(wx_AuiNotebook, __SetPageText);
	Gura_AssignMethod(wx_AuiNotebook, __SetPageToolTip);
	Gura_AssignMethod(wx_AuiNotebook, __SetSelectedFont);
	Gura_AssignMethod(wx_AuiNotebook, __SetSelection);
	Gura_AssignMethod(wx_AuiNotebook, __SetTabCtrlHeight);
	Gura_AssignMethod(wx_AuiNotebook, __SetUniformBitmapSize);
	Gura_AssignMethod(wx_AuiNotebook, __Split);
	Gura_AssignMethod(wx_AuiNotebook, __ShowWindowMenu);
}

Gura_ImplementDescendantCreator(wx_AuiNotebook)
{
	return new Object_wx_AuiNotebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
