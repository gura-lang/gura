//----------------------------------------------------------------------------
// wxStockPreferencesPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStockPreferencesPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStockPreferencesPage
//----------------------------------------------------------------------------
Object_wx_StockPreferencesPage::~Object_wx_StockPreferencesPage()
{
}

Object *Object_wx_StockPreferencesPage::Clone() const
{
	return nullptr;
}

String Object_wx_StockPreferencesPage::ToString(bool exprFlag)
{
	String rtn("<wx.StockPreferencesPage:");
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


//----------------------------------------------------------------------------
// Class implementation for wxStockPreferencesPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StockPreferencesPage)
{
	
}

Gura_ImplementDescendantCreator(wx_StockPreferencesPage)
{
	return new Object_wx_StockPreferencesPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
