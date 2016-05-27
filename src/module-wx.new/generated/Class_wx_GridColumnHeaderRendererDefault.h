//----------------------------------------------------------------------------
// wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCOLUMNHEADERRENDERERDEFAULT_H__
#define __CLASS_WX_GRIDCOLUMNHEADERRENDERERDEFAULT_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridColumnHeaderRendererDefault);

//----------------------------------------------------------------------------
// Object declaration for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
class Object_wx_GridColumnHeaderRendererDefault : public Object_wx_GridColumnHeaderRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridColumnHeaderRendererDefault)
public:
	inline Object_wx_GridColumnHeaderRendererDefault(wxGridColumnHeaderRendererDefault *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridColumnHeaderRenderer(Gura_UserClass(wx_GridColumnHeaderRendererDefault), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridColumnHeaderRendererDefault(Class *pClass, wxGridColumnHeaderRendererDefault *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridColumnHeaderRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridColumnHeaderRendererDefault();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridColumnHeaderRendererDefault *GetEntity() {
		return static_cast<wxGridColumnHeaderRendererDefault *>(_pEntity);
	}
	inline wxGridColumnHeaderRendererDefault *ReleaseEntity() {
		wxGridColumnHeaderRendererDefault *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridColumnHeaderRendererDefault");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
