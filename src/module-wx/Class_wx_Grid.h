//----------------------------------------------------------------------------
// wxGrid
// extracted from grid.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRID_H__
#define __CLASS_WX_GRID_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGrid
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Grid);

//----------------------------------------------------------------------------
// Object declaration for wxGrid
//----------------------------------------------------------------------------
class Object_wx_Grid : public Object_wx_ScrolledWindow {
public:
	Gura_DeclareObjectAccessor(wx_Grid)
public:
	inline Object_wx_Grid(wxGrid *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScrolledWindow(Gura_UserClass(wx_Grid), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Grid(Class *pClass, wxGrid *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ScrolledWindow(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Grid();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGrid *GetEntity() {
		return dynamic_cast<wxGrid *>(_pEntity);
	}
	inline wxGrid *ReleaseEntity() {
		wxGrid *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGrid");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
