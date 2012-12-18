//----------------------------------------------------------------------------
// wxGridCellNumberRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLNUMBERRENDERER_H__
#define __OBJECT_WX_GRIDCELLNUMBERRENDERER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellNumberRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellNumberRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellNumberRenderer : public Object_wx_GridCellStringRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellNumberRenderer)
public:
	inline Object_wx_GridCellNumberRenderer(wxGridCellNumberRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(Gura_UserClass(wx_GridCellNumberRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellNumberRenderer(Class *pClass, wxGridCellNumberRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellNumberRenderer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridCellNumberRenderer *GetEntity() {
		return dynamic_cast<wxGridCellNumberRenderer *>(_pEntity);
	}
	inline wxGridCellNumberRenderer *ReleaseEntity() {
		wxGridCellNumberRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellNumberRenderer");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
