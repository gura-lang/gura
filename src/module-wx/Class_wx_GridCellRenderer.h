//----------------------------------------------------------------------------
// wxGridCellRenderer
// extracted from gridrend.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLRENDERER_H__
#define __CLASS_WX_GRIDCELLRENDERER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellRenderer : public Object_wx_GridCellWorker {
public:
	Gura_DeclareObjectAccessor(wx_GridCellRenderer)
public:
	inline Object_wx_GridCellRenderer(wxGridCellRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellWorker(Gura_UserClass(wx_GridCellRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellRenderer(Class *pClass, wxGridCellRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellWorker(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellRenderer *GetEntity() {
		return dynamic_cast<wxGridCellRenderer *>(_pEntity);
	}
	inline wxGridCellRenderer *ReleaseEntity() {
		wxGridCellRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellRenderer");
		return true;
	}
public:
	void EvalMethod_Draw(Signal sig, bool &evaluatedFlag,
					wxGrid &grid, wxGridCellAttr &attr, wxDC &dc,
					const wxRect &rect, int row, int col, bool isSelected);
};

Gura_EndModuleScope(wx)

#endif
