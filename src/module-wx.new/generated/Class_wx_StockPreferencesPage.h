//----------------------------------------------------------------------------
// wxStockPreferencesPage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STOCKPREFERENCESPAGE_H__
#define __CLASS_WX_STOCKPREFERENCESPAGE_H__
#include <wx/preferences.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStockPreferencesPage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StockPreferencesPage);

//----------------------------------------------------------------------------
// Object declaration for wxStockPreferencesPage
//----------------------------------------------------------------------------
class Object_wx_StockPreferencesPage : public Object_wx_PreferencesPage {
public:
	Gura_DeclareObjectAccessor(wx_StockPreferencesPage)
public:
	inline Object_wx_StockPreferencesPage(wxStockPreferencesPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PreferencesPage(Gura_UserClass(wx_StockPreferencesPage), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StockPreferencesPage(Class *pClass, wxStockPreferencesPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_PreferencesPage(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StockPreferencesPage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStockPreferencesPage *GetEntity() {
		return static_cast<wxStockPreferencesPage *>(_pEntity);
	}
	inline wxStockPreferencesPage *ReleaseEntity() {
		wxStockPreferencesPage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStockPreferencesPage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
