//----------------------------------------------------------------------------
// wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDHEADERLABELSRENDERER_H__
#define __CLASS_WX_GRIDHEADERLABELSRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridHeaderLabelsRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
class Object_wx_GridHeaderLabelsRenderer : public Object_wx_GridCornerHeaderRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridHeaderLabelsRenderer)
public:
	inline Object_wx_GridHeaderLabelsRenderer(wxGridHeaderLabelsRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCornerHeaderRenderer(Gura_UserClass(wx_GridHeaderLabelsRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridHeaderLabelsRenderer(Class *pClass, wxGridHeaderLabelsRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCornerHeaderRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridHeaderLabelsRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridHeaderLabelsRenderer *GetEntity() {
		return static_cast<wxGridHeaderLabelsRenderer *>(_pEntity);
	}
	inline wxGridHeaderLabelsRenderer *ReleaseEntity() {
		wxGridHeaderLabelsRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridHeaderLabelsRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
