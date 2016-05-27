//----------------------------------------------------------------------------
// wxDataViewItemAttr
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWITEMATTR_H__
#define __CLASS_WX_DATAVIEWITEMATTR_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewItemAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewItemAttr);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewItemAttr
//----------------------------------------------------------------------------
class Object_wx_DataViewItemAttr : public Object {
protected:
	wxDataViewItemAttr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DataViewItemAttr)
public:
	inline Object_wx_DataViewItemAttr(wxDataViewItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataViewItemAttr(Class *pClass, wxDataViewItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataViewItemAttr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataViewItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDataViewItemAttr *GetEntity() {
		return static_cast<wxDataViewItemAttr *>(_pEntity);
	}
	inline wxDataViewItemAttr *ReleaseEntity() {
		wxDataViewItemAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewItemAttr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
