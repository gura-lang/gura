//----------------------------------------------------------------------------
// wxGridRowHeaderRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDROWHEADERRENDERER_H__
#define __CLASS_WX_GRIDROWHEADERRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridRowHeaderRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridRowHeaderRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridRowHeaderRenderer
//----------------------------------------------------------------------------
class Object_wx_GridRowHeaderRenderer : public Object_wx_GridHeaderLabelsRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridRowHeaderRenderer)
public:
	inline Object_wx_GridRowHeaderRenderer(wxGridRowHeaderRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridHeaderLabelsRenderer(Gura_UserClass(wx_GridRowHeaderRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridRowHeaderRenderer(Class *pClass, wxGridRowHeaderRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridHeaderLabelsRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridRowHeaderRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridRowHeaderRenderer *GetEntity() {
		return static_cast<wxGridRowHeaderRenderer *>(_pEntity);
	}
	inline wxGridRowHeaderRenderer *ReleaseEntity() {
		wxGridRowHeaderRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridRowHeaderRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
