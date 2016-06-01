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
Gura_DeclareMethod(wx_PropertyGridManager, AddPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, AddPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int bmp = arg.GetNumber(1)
	//int pageObj = arg.GetNumber(2)
	//pThis->GetEntity()->AddPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, ClearPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, ClearPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->ClearPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, CommitChangesFromEditor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, CommitChangesFromEditor)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CommitChangesFromEditor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, EnableCategories)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, EnableCategories)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableCategories();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, EnsureVisible)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->GetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetDescBoxHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetDescBoxHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDescBoxHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetGrid)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGrid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetVIterator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetVIterator)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->GetVIterator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetCurrentPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetCurrentPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ind = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetPage_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetPageByName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetPageByName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageByName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetPageCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetPageCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetPageName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetPageName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetPageRoot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetPageRoot)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetPageRoot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetSelectedPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetSelectedPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetSelectedProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetSelectedProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, GetToolBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, InsertPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pageObj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, InsertPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bmp = arg.GetNumber(2)
	//int pageObj = arg.GetNumber(3)
	//pThis->GetEntity()->InsertPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, IsAnyModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, IsAnyModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAnyModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, IsFrozen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, IsFrozen)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFrozen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, IsPageModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, IsPageModified)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->IsPageModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, IsPropertySelected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, IsPropertySelected)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsPropertySelected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, RemovePage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, RemovePage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->RemovePage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SelectPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SelectPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SelectPage_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SelectPage_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SelectPage_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SelectPage_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->SelectPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SelectProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "focus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SelectProperty)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int focus = arg.GetNumber(1)
	//pThis->GetEntity()->SelectProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetColumnCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colCount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetColumnCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colCount = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetColumnTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetColumnTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//pThis->GetEntity()->SetColumnTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "content", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int label = arg.GetNumber(0)
	//int content = arg.GetNumber(1)
	//pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetDescBoxHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ht", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetDescBoxHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ht = arg.GetNumber(0)
	//int refresh = arg.GetNumber(1)
	//pThis->GetEntity()->SetDescBoxHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetSplitterLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "subProps", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "allPages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetSplitterLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int subProps = arg.GetNumber(0)
	//int allPages = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetPageSplitterLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subProps", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetPageSplitterLeft)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int subProps = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageSplitterLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetPageSplitterPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetPageSplitterPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int column = arg.GetNumber(2)
	//pThis->GetEntity()->SetPageSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, SetSplitterPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, SetSplitterPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int column = arg.GetNumber(1)
	//pThis->GetEntity()->SetSplitterPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, ShowHeader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PropertyGridManager, ShowHeader)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHeader();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PropertyGridManager, CreatePropertyGrid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PropertyGridManager, CreatePropertyGrid)
{
	Signal &sig = env.GetSignal();
	Object_wx_PropertyGridManager *pThis = Object_wx_PropertyGridManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreatePropertyGrid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropertyGridManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridManager)
{
	Gura_AssignMethod(wx_PropertyGridManager, AddPage);
	Gura_AssignMethod(wx_PropertyGridManager, Clear);
	Gura_AssignMethod(wx_PropertyGridManager, ClearPage);
	Gura_AssignMethod(wx_PropertyGridManager, CommitChangesFromEditor);
	Gura_AssignMethod(wx_PropertyGridManager, Create);
	Gura_AssignMethod(wx_PropertyGridManager, EnableCategories);
	Gura_AssignMethod(wx_PropertyGridManager, EnsureVisible);
	Gura_AssignMethod(wx_PropertyGridManager, GetColumnCount);
	Gura_AssignMethod(wx_PropertyGridManager, GetDescBoxHeight);
	Gura_AssignMethod(wx_PropertyGridManager, GetGrid);
	Gura_AssignMethod(wx_PropertyGridManager, GetVIterator);
	Gura_AssignMethod(wx_PropertyGridManager, GetCurrentPage);
	Gura_AssignMethod(wx_PropertyGridManager, GetPage);
	Gura_AssignMethod(wx_PropertyGridManager, GetPage_1);
	Gura_AssignMethod(wx_PropertyGridManager, GetPageByName);
	Gura_AssignMethod(wx_PropertyGridManager, GetPageCount);
	Gura_AssignMethod(wx_PropertyGridManager, GetPageName);
	Gura_AssignMethod(wx_PropertyGridManager, GetPageRoot);
	Gura_AssignMethod(wx_PropertyGridManager, GetSelectedPage);
	Gura_AssignMethod(wx_PropertyGridManager, GetSelectedProperty);
	Gura_AssignMethod(wx_PropertyGridManager, GetSelection);
	Gura_AssignMethod(wx_PropertyGridManager, GetToolBar);
	Gura_AssignMethod(wx_PropertyGridManager, InsertPage);
	Gura_AssignMethod(wx_PropertyGridManager, IsAnyModified);
	Gura_AssignMethod(wx_PropertyGridManager, IsFrozen);
	Gura_AssignMethod(wx_PropertyGridManager, IsPageModified);
	Gura_AssignMethod(wx_PropertyGridManager, IsPropertySelected);
	Gura_AssignMethod(wx_PropertyGridManager, RemovePage);
	Gura_AssignMethod(wx_PropertyGridManager, SelectPage);
	Gura_AssignMethod(wx_PropertyGridManager, SelectPage_1);
	Gura_AssignMethod(wx_PropertyGridManager, SelectPage_2);
	Gura_AssignMethod(wx_PropertyGridManager, SelectProperty);
	Gura_AssignMethod(wx_PropertyGridManager, SetColumnCount);
	Gura_AssignMethod(wx_PropertyGridManager, SetColumnTitle);
	Gura_AssignMethod(wx_PropertyGridManager, SetDescription);
	Gura_AssignMethod(wx_PropertyGridManager, SetDescBoxHeight);
	Gura_AssignMethod(wx_PropertyGridManager, SetSplitterLeft);
	Gura_AssignMethod(wx_PropertyGridManager, SetPageSplitterLeft);
	Gura_AssignMethod(wx_PropertyGridManager, SetPageSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridManager, SetSplitterPosition);
	Gura_AssignMethod(wx_PropertyGridManager, ShowHeader);
	Gura_AssignMethod(wx_PropertyGridManager, CreatePropertyGrid);
}

Gura_ImplementDescendantCreator(wx_PropertyGridManager)
{
	return new Object_wx_PropertyGridManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
