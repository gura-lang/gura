//----------------------------------------------------------------------------
// wxPGCell
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PGCELL_H__
#define __CLASS_WX_PGCELL_H__
#include <wx/propgrid/property.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPGCell
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PGCell);

//----------------------------------------------------------------------------
// Object declaration for wxPGCell
//----------------------------------------------------------------------------
class Object_wx_PGCell : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_PGCell)
public:
	inline Object_wx_PGCell(wxPGCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_PGCell), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PGCell(Class *pClass, wxPGCell *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PGCell();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPGCell *GetEntity() {
		return static_cast<wxPGCell *>(_pEntity);
	}
	inline wxPGCell *ReleaseEntity() {
		wxPGCell *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPGCell");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
