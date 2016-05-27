//----------------------------------------------------------------------------
// wxDataViewModelNotifier
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWMODELNOTIFIER_H__
#define __CLASS_WX_DATAVIEWMODELNOTIFIER_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewModelNotifier
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewModelNotifier);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewModelNotifier
//----------------------------------------------------------------------------
class Object_wx_DataViewModelNotifier : public Object {
protected:
	wxDataViewModelNotifier *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DataViewModelNotifier)
public:
	inline Object_wx_DataViewModelNotifier(wxDataViewModelNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataViewModelNotifier(Class *pClass, wxDataViewModelNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataViewModelNotifier();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataViewModelNotifier *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDataViewModelNotifier *GetEntity() {
		return static_cast<wxDataViewModelNotifier *>(_pEntity);
	}
	inline wxDataViewModelNotifier *ReleaseEntity() {
		wxDataViewModelNotifier *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewModelNotifier");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
