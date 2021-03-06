//----------------------------------------------------------------------------
// wxPropertyGridManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridManager
//----------------------------------------------------------------------------
Object_wx_PropertyGridManager::~Object_wx_PropertyGridManager()
{
}

Object *Object_wx_PropertyGridManager::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridManager::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridManager:");
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
Gura_DeclareMethodAlias(wx_PropertyGridManager, __AddPage, "AddPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __AddPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//const wxBitmap& bmp = arg.GetNumber(1)
	//wxPropertyGridPage* pageObj = arg.GetNumber(2)
	//wxPropertyGridPage* _rtn = pThis->GetEntity()->AddPage(label, bmp, pageObj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __Clear)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __ClearPage, "ClearPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __ClearPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->ClearPage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __CommitChangesFromEditor, "CommitChangesFromEditor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __CommitChangesFromEditor)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 flags = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CommitChangesFromEditor(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __Create)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __EnableCategories, "EnableCategories")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __EnableCategories)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->EnableCategories(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __EnsureVisible)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->EnsureVisible(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetColumnCount, "GetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetColumnCount)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetColumnCount(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetDescBoxHeight, "GetDescBoxHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetDescBoxHeight)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetDescBoxHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetGrid, "GetGrid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetGrid)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPropertyGrid* _rtn = pThis->GetEntity()->GetGrid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetVIterator, "GetVIterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetVIterator)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//wxPGVIterator _rtn = pThis->GetEntity()->GetVIterator(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetCurrentPage, "GetCurrentPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetCurrentPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPropertyGridPage* _rtn = pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPage, "GetPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int ind = arg.GetNumber(0)
	//wxPropertyGridPage* _rtn = pThis->GetEntity()->GetPage(ind);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPage_1, "GetPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPage_1)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxPropertyGridPage* _rtn = pThis->GetEntity()->GetPage(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageByName, "GetPageByName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageByName)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetPageByName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageCount, "GetPageCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageCount)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageName, "GetPageName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageName)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//const wxString& _rtn = pThis->GetEntity()->GetPageName(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetPageRoot, "GetPageRoot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetPageRoot)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//wxPGProperty* _rtn = pThis->GetEntity()->GetPageRoot(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetSelectedPage, "GetSelectedPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetSelectedPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSelectedPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetSelectedProperty, "GetSelectedProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetSelectedProperty)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* _rtn = pThis->GetEntity()->GetSelectedProperty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetSelection)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGProperty* _rtn = pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __GetToolBar, "GetToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __GetToolBar)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxToolBar* _rtn = pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __InsertPage, "InsertPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __InsertPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//const wxBitmap& bmp = arg.GetNumber(2)
	//wxPropertyGridPage* pageObj = arg.GetNumber(3)
	//wxPropertyGridPage* _rtn = pThis->GetEntity()->InsertPage(index, label, bmp, pageObj);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsAnyModified, "IsAnyModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsAnyModified)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsAnyModified();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsFrozen, "IsFrozen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsFrozen)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsFrozen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsPageModified, "IsPageModified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsPageModified)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsPageModified(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __IsPropertySelected, "IsPropertySelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __IsPropertySelected)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsPropertySelected(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __RemovePage, "RemovePage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __RemovePage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->RemovePage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectPage, "SelectPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectPage)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectPage_1, "SelectPage_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectPage_1)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage(label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectPage_2, "SelectPage_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectPage_2)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPropertyGridPage* page = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage(page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SelectProperty, "SelectProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SelectProperty)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPGPropArg id = arg.GetNumber(0)
	//bool focus = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SelectProperty(id, focus);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetColumnCount, "SetColumnCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colCount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetColumnCount)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colCount = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnCount(colCount, page);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetColumnTitle, "SetColumnTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetColumnTitle)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//const wxString& title = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnTitle(idx, title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetDescription, "SetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "content", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetDescription)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& label = arg.GetNumber(0)
	//const wxString& content = arg.GetNumber(1)
	//pThis->GetEntity()->SetDescription(label, content);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetDescBoxHeight, "SetDescBoxHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ht", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetDescBoxHeight)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ht = arg.GetNumber(0)
	//bool refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetDescBoxHeight(ht, refresh);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetSplitterLeft, "SetSplitterLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "subProps", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "allPages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetSplitterLeft)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool subProps = arg.GetNumber(0)
	//bool allPages = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterLeft(subProps, allPages);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetPageSplitterLeft, "SetPageSplitterLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subProps", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetPageSplitterLeft)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//bool subProps = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageSplitterLeft(page, subProps);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetPageSplitterPosition, "SetPageSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetPageSplitterPosition)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int column = arg.GetNumber(2)
	//pThis->GetEntity()->SetPageSplitterPosition(page, pos, column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __SetSplitterPosition, "SetSplitterPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __SetSplitterPosition)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterPosition(pos, column);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __ShowHeader, "ShowHeader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, __ShowHeader)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHeader(show);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PropertyGridManager, __CreatePropertyGrid, "CreatePropertyGrid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, __CreatePropertyGrid)
{
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPropertyGrid* _rtn = pThis->GetEntity()->CreatePropertyGrid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridManager)
{
	// Class assignment
	Gura_AssignValueEx("PropertyGridManager", Reference());
	// Method assignment
	Gura_AssignMethod(wx_PropertyGridManager, __AddPage);
	Gura_AssignMethod(wx_PropertyGridManager, __Clear);
	Gura_AssignMethod(wx_PropertyGridManager, __ClearPage);
	Gura_AssignMethod(wx_PropertyGridManager, __CommitChangesFromEditor);
	Gura_AssignMethod(wx_PropertyGridManager, __Create);
	Gura_AssignMethod(wx_PropertyGridManager, __EnableCategories);
	Gura_AssignMethod(wx_PropertyGridManager, __EnsureVisible);
	Gura_AssignMethod(wx_PropertyGridManager, __GetColumnCount);
	Gura_AssignMethod(wx_PropertyGridManager, __GetDescBoxHeight);
	Gura_AssignMethod(wx_PropertyGridManager, __GetGrid);
	Gura_AssignMethod(wx_PropertyGridManager, __GetVIterator);
	Gura_AssignMethod(wx_PropertyGridManager, __GetCurrentPage);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPage);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPage_1);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageByName);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageCount);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageName);
	Gura_AssignMethod(wx_PropertyGridManager, __GetPageRoot);
	Gura_AssignMethod(wx_PropertyGridManager, __GetSelectedPage);
	Gura_AssignMethod(wx_PropertyGridManager, __GetSelectedProperty);
	Gura_AssignMethod(wx_PropertyGridManager, __GetSelection);
	Gura_AssignMethod(wx_PropertyGridManager, __GetToolBar);
	Gura_AssignMethod(wx_PropertyGridManager, __InsertPage);
	Gura_AssignMethod(wx_PropertyGridManager, __IsAnyModified);
	Gura_AssignMethod(wx_PropertyGridManager, __IsFrozen);
	Gura_AssignMethod(wx_PropertyGridManager, __IsPageModified);
	Gura_AssignMethod(wx_PropertyGridManager, __IsPropertySelected);
	Gura_AssignMethod(wx_PropertyGridManager, __RemovePage);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectPage);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectPage_1);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectPage_2);
	Gura_AssignMethod(wx_PropertyGridManager, __SelectProperty);
	Gura_AssignMethod(wx_PropertyGridManager, __SetColumnCount);
	Gura_AssignMethod(wx_PropertyGridManager, __SetColumnTitle);
	Gura_AssignMethod(wx_PropertyGridManager, __SetDescription);
	Gura_AssignMethod(wx_PropertyGridManager, __SetDescBoxHeight);
	Gura_AssignMethod(wx_PropertyGridManager, __SetSplitterLeft);
	Gura_AssignMethod(wx_PropertyGridManager, __SetPageSplitterLeft);
	Gura_AssignMethod(wx_PropertyGridManager, __SetPageSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridManager, __SetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridManager, __ShowHeader);
	Gura_AssignMethod(wx_PropertyGridManager, __CreatePropertyGrid);
}

Gura_ImplementDescendantCreator(wx_PropertyGridManager)
{
	return new Object_wx_PropertyGridManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
