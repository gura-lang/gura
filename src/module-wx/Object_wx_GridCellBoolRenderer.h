//----------------------------------------------------------------------------
// wxGridCellBoolRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLBOOLRENDERER_H__
#define __OBJECT_WX_GRIDCELLBOOLRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellBoolRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellBoolRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellBoolRenderer : public Object_wx_GridCellRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellBoolRenderer)
public:
	inline Object_wx_GridCellBoolRenderer(wxGridCellBoolRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellRenderer(Gura_UserClass(wx_GridCellBoolRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellBoolRenderer(Class *pClass, wxGridCellBoolRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellBoolRenderer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridCellBoolRenderer *GetEntity() {
		return dynamic_cast<wxGridCellBoolRenderer *>(_pEntity);
	}
	inline wxGridCellBoolRenderer *ReleaseEntity() {
		wxGridCellBoolRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellBoolRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
