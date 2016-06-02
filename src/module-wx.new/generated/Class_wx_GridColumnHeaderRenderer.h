//----------------------------------------------------------------------------
// wxGridColumnHeaderRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCOLUMNHEADERRENDERER_H__
#define __CLASS_WX_GRIDCOLUMNHEADERRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridColumnHeaderRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridColumnHeaderRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridColumnHeaderRenderer
//----------------------------------------------------------------------------
class Object_wx_GridColumnHeaderRenderer : public Object_wx_GridHeaderLabelsRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridColumnHeaderRenderer)
public:
	inline Object_wx_GridColumnHeaderRenderer(wxGridColumnHeaderRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridHeaderLabelsRenderer(Gura_UserClass(wx_GridColumnHeaderRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridColumnHeaderRenderer(Class *pClass, wxGridColumnHeaderRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridHeaderLabelsRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridColumnHeaderRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridColumnHeaderRenderer *GetEntity() {
		return static_cast<wxGridColumnHeaderRenderer *>(_pEntity);
	}
	inline wxGridColumnHeaderRenderer *ReleaseEntity() {
		wxGridColumnHeaderRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridColumnHeaderRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
