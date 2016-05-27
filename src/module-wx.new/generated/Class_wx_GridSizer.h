//----------------------------------------------------------------------------
// wxGridSizer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDSIZER_H__
#define __CLASS_WX_GRIDSIZER_H__
#include <wx/sizer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridSizer);

//----------------------------------------------------------------------------
// Object declaration for wxGridSizer
//----------------------------------------------------------------------------
class Object_wx_GridSizer : public Object_wx_Sizer {
public:
	Gura_DeclareObjectAccessor(wx_GridSizer)
public:
	inline Object_wx_GridSizer(wxGridSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(Gura_UserClass(wx_GridSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridSizer(Class *pClass, wxGridSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridSizer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridSizer *GetEntity() {
		return static_cast<wxGridSizer *>(_pEntity);
	}
	inline wxGridSizer *ReleaseEntity() {
		wxGridSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridSizer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
