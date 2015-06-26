//----------------------------------------------------------------------------
// wxGridCellFloatRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLFLOATRENDERER_H__
#define __CLASS_WX_GRIDCELLFLOATRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellFloatRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellFloatRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellFloatRenderer : public Object_wx_GridCellStringRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellFloatRenderer)
public:
	inline Object_wx_GridCellFloatRenderer(wxGridCellFloatRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(Gura_UserClass(wx_GridCellFloatRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellFloatRenderer(Class *pClass, wxGridCellFloatRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellFloatRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellFloatRenderer *GetEntity() {
		return dynamic_cast<wxGridCellFloatRenderer *>(_pEntity);
	}
	inline wxGridCellFloatRenderer *ReleaseEntity() {
		wxGridCellFloatRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellFloatRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
