//----------------------------------------------------------------------------
// wxGridCellCoords
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLCOORDS_H__
#define __OBJECT_WX_GRIDCELLCOORDS_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellCoords
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellCoords);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellCoords
//----------------------------------------------------------------------------
class Object_wx_GridCellCoords : public Object {
protected:
	wxGridCellCoords *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GridCellCoords)
public:
	inline Object_wx_GridCellCoords(wxGridCellCoords *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_GridCellCoords)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GridCellCoords(Class *pClass, wxGridCellCoords *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GridCellCoords();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxGridCellCoords *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxGridCellCoords *GetEntity() { return _pEntity; }
	inline wxGridCellCoords *ReleaseEntity() {
		wxGridCellCoords *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellCoords");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
