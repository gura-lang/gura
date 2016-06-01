//----------------------------------------------------------------------------
// wxAcceleratorTable
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ACCELERATORTABLE_H__
#define __CLASS_WX_ACCELERATORTABLE_H__
#include <wx/accel.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AcceleratorTable);

//----------------------------------------------------------------------------
// Object declaration for wxAcceleratorTable
//----------------------------------------------------------------------------
class Object_wx_AcceleratorTable : public Object {
protected:
	wxAcceleratorTable *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AcceleratorTable)
public:
	inline Object_wx_AcceleratorTable(wxAcceleratorTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AcceleratorTable(Class *pClass, wxAcceleratorTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AcceleratorTable();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAcceleratorTable *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxAcceleratorTable *GetEntity() {
		return static_cast<wxAcceleratorTable *>(_pEntity);
	}
	inline wxAcceleratorTable *ReleaseEntity() {
		wxAcceleratorTable *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxAcceleratorTable");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
