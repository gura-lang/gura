//----------------------------------------------------------------------------
// wxSettableHeaderColumn
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SETTABLEHEADERCOLUMN_H__
#define __CLASS_WX_SETTABLEHEADERCOLUMN_H__
#include <wx/headercol.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSettableHeaderColumn
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SettableHeaderColumn);

//----------------------------------------------------------------------------
// Object declaration for wxSettableHeaderColumn
//----------------------------------------------------------------------------
class Object_wx_SettableHeaderColumn : public Object_wx_HeaderColumn {
public:
	Gura_DeclareObjectAccessor(wx_SettableHeaderColumn)
public:
	inline Object_wx_SettableHeaderColumn(wxSettableHeaderColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HeaderColumn(Gura_UserClass(wx_SettableHeaderColumn), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SettableHeaderColumn(Class *pClass, wxSettableHeaderColumn *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_HeaderColumn(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SettableHeaderColumn();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSettableHeaderColumn *GetEntity() {
		return static_cast<wxSettableHeaderColumn *>(_pEntity);
	}
	inline wxSettableHeaderColumn *ReleaseEntity() {
		wxSettableHeaderColumn *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSettableHeaderColumn");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
