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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//wxAuiNotebook();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiNotebook, __AddPage, "AddPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __AddPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int caption = arg.GetNumber(1)
	//int select = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//pThis->GetEntity()->AddPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __AddPage_1, "AddPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __AddPage_1)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//int select = arg.GetNumber(2)
	//int imageId = arg.GetNumber(3)
	//pThis->GetEntity()->AddPage();
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
	//int forward = arg.GetNumber(0)
	//pThis->GetEntity()->AdvanceSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __ChangeSelection, "ChangeSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __ChangeSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __DeleteAllPages, "DeleteAllPages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __DeleteAllPages)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllPages();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __DeletePage, "DeletePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __DeletePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->DeletePage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetArtProvider, "GetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetArtProvider)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetCurrentPage, "GetCurrentPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetCurrentPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetHeightForPageHeight, "GetHeightForPageHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetHeightForPageHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageHeight = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeightForPageHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page_idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageBitmap, "GetPageBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageCount, "GetPageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageCount)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageIndex, "GetPageIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page_wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageIndex)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page_wnd = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageText, "GetPageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetPageToolTip, "GetPageToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetPageToolTip)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageIdx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageToolTip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __GetTabCtrlHeight, "GetTabCtrlHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __GetTabCtrlHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTabCtrlHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __InsertPage, "InsertPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int page_idx = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int select = arg.GetNumber(3)
	//int bitmap = arg.GetNumber(4)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __InsertPage_1, "InsertPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	//int index = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int select = arg.GetNumber(3)
	//int imageId = arg.GetNumber(4)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __RemovePage, "RemovePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __RemovePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePage();
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
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
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
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont();
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
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageBitmap, "SetPageBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageImage, "SetPageImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageImage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int imageId = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageText, "SetPageText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetPageToolTip, "SetPageToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetPageToolTip)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageToolTip();
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
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, __SetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_page = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
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
	//pThis->GetEntity()->SetTabCtrlHeight();
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
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetUniformBitmapSize();
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
	//int page = arg.GetNumber(0)
	//int direction = arg.GetNumber(1)
	//pThis->GetEntity()->Split();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiNotebook, __ShowWindowMenu, "ShowWindowMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, __ShowWindowMenu)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowWindowMenu();
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
