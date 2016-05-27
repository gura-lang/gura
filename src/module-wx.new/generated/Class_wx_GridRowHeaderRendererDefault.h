//----------------------------------------------------------------------------
// wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDROWHEADERRENDERERDEFAULT_H__
#define __CLASS_WX_GRIDROWHEADERRENDERERDEFAULT_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridRowHeaderRendererDefault);

//----------------------------------------------------------------------------
// Object declaration for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
class Object_wx_GridRowHeaderRendererDefault : public Object_wx_GridRowHeaderRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridRowHeaderRendererDefault)
public:
	inline Object_wx_GridRowHeaderRendererDefault(wxGridRowHeaderRendererDefault *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridRowHeaderRenderer(Gura_UserClass(wx_GridRowHeaderRendererDefault), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridRowHeaderRendererDefault(Class *pClass, wxGridRowHeaderRendererDefault *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridRowHeaderRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridRowHeaderRendererDefault();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridRowHeaderRendererDefault *GetEntity() {
		return static_cast<wxGridRowHeaderRendererDefault *>(_pEntity);
	}
	inline wxGridRowHeaderRendererDefault *ReleaseEntity() {
		wxGridRowHeaderRendererDefault *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridRowHeaderRendererDefault");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
