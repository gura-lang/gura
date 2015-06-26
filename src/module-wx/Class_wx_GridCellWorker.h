//----------------------------------------------------------------------------
// wxGridCellWorker
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLWORKER_H__
#define __CLASS_WX_GRIDCELLWORKER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellWorker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellWorker);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellWorker
//----------------------------------------------------------------------------
class Object_wx_GridCellWorker : public Object {
protected:
	wxGridCellWorker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GridCellWorker)
public:
	inline Object_wx_GridCellWorker(wxGridCellWorker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_GridCellWorker)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GridCellWorker(Class *pClass, wxGridCellWorker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GridCellWorker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxGridCellWorker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		//if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxGridCellWorker *GetEntity() { return _pEntity; }
	inline wxGridCellWorker *ReleaseEntity() {
		wxGridCellWorker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellWorker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
