//----------------------------------------------------------------------------
// wxGridCellAttr
// extracted from gridattr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLATTR_H__
#define __OBJECT_WX_GRIDCELLATTR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellAttr);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellAttr
//----------------------------------------------------------------------------
class Object_wx_GridCellAttr : public Object {
protected:
	wxGridCellAttr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GridCellAttr)
public:
	inline Object_wx_GridCellAttr(wxGridCellAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_GridCellAttr)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GridCellAttr(Class *pClass, wxGridCellAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GridCellAttr();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxGridCellAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		//if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxGridCellAttr *GetEntity() { return _pEntity; }
	inline wxGridCellAttr *ReleaseEntity() {
		wxGridCellAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellAttr");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
