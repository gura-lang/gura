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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AuiNotebook, wxAuiNotebook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, wxAuiNotebook)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAuiNotebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, wxAuiNotebook_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, wxAuiNotebook_1)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxAuiNotebook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, AddPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, AddPage)
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

Gura_DeclareMethod(wx_AuiNotebook, AddPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, AddPage_1)
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

Gura_DeclareMethod(wx_AuiNotebook, AdvanceSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "forward", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, AdvanceSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int forward = arg.GetNumber(0)
	//pThis->GetEntity()->AdvanceSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, ChangeSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, ChangeSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, Create)
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

Gura_DeclareMethod(wx_AuiNotebook, DeleteAllPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, DeleteAllPages)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteAllPages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, DeletePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, DeletePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->DeletePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, GetArtProvider)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, GetCurrentPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetHeightForPageHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageHeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, GetHeightForPageHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageHeight = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeightForPageHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page_idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageCount)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page_wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageIndex)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page_wnd = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetPageToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, GetPageToolTip)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageIdx = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageToolTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, GetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, GetTabCtrlHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, GetTabCtrlHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTabCtrlHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page_idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, InsertPage)
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

Gura_DeclareMethod(wx_AuiNotebook, InsertPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, InsertPage_1)
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

Gura_DeclareMethod(wx_AuiNotebook, RemovePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, RemovePage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetArtProvider)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetMeasuringFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetMeasuringFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetNormalFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageBitmap)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "imageId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageImage)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int imageId = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageText)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetPageToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetPageToolTip)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageToolTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetSelectedFont)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetSelection)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_page = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetTabCtrlHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetTabCtrlHeight)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabCtrlHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, SetUniformBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, SetUniformBitmapSize)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetUniformBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, Split)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiNotebook, Split)
{
	Object_wx_AuiNotebook *pThis = Object_wx_AuiNotebook::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int direction = arg.GetNumber(1)
	//pThis->GetEntity()->Split();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiNotebook, ShowWindowMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiNotebook, ShowWindowMenu)
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
	Gura_AssignMethod(wx_AuiNotebook, wxAuiNotebook);
	Gura_AssignMethod(wx_AuiNotebook, wxAuiNotebook_1);
	Gura_AssignMethod(wx_AuiNotebook, AddPage);
	Gura_AssignMethod(wx_AuiNotebook, AddPage_1);
	Gura_AssignMethod(wx_AuiNotebook, AdvanceSelection);
	Gura_AssignMethod(wx_AuiNotebook, ChangeSelection);
	Gura_AssignMethod(wx_AuiNotebook, Create);
	Gura_AssignMethod(wx_AuiNotebook, DeleteAllPages);
	Gura_AssignMethod(wx_AuiNotebook, DeletePage);
	Gura_AssignMethod(wx_AuiNotebook, GetArtProvider);
	Gura_AssignMethod(wx_AuiNotebook, GetCurrentPage);
	Gura_AssignMethod(wx_AuiNotebook, GetHeightForPageHeight);
	Gura_AssignMethod(wx_AuiNotebook, GetPage);
	Gura_AssignMethod(wx_AuiNotebook, GetPageBitmap);
	Gura_AssignMethod(wx_AuiNotebook, GetPageCount);
	Gura_AssignMethod(wx_AuiNotebook, GetPageIndex);
	Gura_AssignMethod(wx_AuiNotebook, GetPageText);
	Gura_AssignMethod(wx_AuiNotebook, GetPageToolTip);
	Gura_AssignMethod(wx_AuiNotebook, GetSelection);
	Gura_AssignMethod(wx_AuiNotebook, GetTabCtrlHeight);
	Gura_AssignMethod(wx_AuiNotebook, InsertPage);
	Gura_AssignMethod(wx_AuiNotebook, InsertPage_1);
	Gura_AssignMethod(wx_AuiNotebook, RemovePage);
	Gura_AssignMethod(wx_AuiNotebook, SetArtProvider);
	Gura_AssignMethod(wx_AuiNotebook, SetFont);
	Gura_AssignMethod(wx_AuiNotebook, SetMeasuringFont);
	Gura_AssignMethod(wx_AuiNotebook, SetNormalFont);
	Gura_AssignMethod(wx_AuiNotebook, SetPageBitmap);
	Gura_AssignMethod(wx_AuiNotebook, SetPageImage);
	Gura_AssignMethod(wx_AuiNotebook, SetPageText);
	Gura_AssignMethod(wx_AuiNotebook, SetPageToolTip);
	Gura_AssignMethod(wx_AuiNotebook, SetSelectedFont);
	Gura_AssignMethod(wx_AuiNotebook, SetSelection);
	Gura_AssignMethod(wx_AuiNotebook, SetTabCtrlHeight);
	Gura_AssignMethod(wx_AuiNotebook, SetUniformBitmapSize);
	Gura_AssignMethod(wx_AuiNotebook, Split);
	Gura_AssignMethod(wx_AuiNotebook, ShowWindowMenu);
}

Gura_ImplementDescendantCreator(wx_AuiNotebook)
{
	return new Object_wx_AuiNotebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
