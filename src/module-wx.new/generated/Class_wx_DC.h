//----------------------------------------------------------------------------
// wxDC
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DC_H__
#define __CLASS_WX_DC_H__
#include <wx/dc.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDC
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DC);

//----------------------------------------------------------------------------
// Object declaration for wxDC
//----------------------------------------------------------------------------
class Object_wx_DC : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_DC)
public:
	inline Object_wx_DC(wxDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_DC), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DC(Class *pClass, wxDC *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DC();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDC *GetEntity() {
		return static_cast<wxDC *>(_pEntity);
	}
	inline wxDC *ReleaseEntity() {
		wxDC *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDC");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
