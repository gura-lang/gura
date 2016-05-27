//----------------------------------------------------------------------------
// wxDataViewItem
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATAVIEWITEM_H__
#define __CLASS_WX_DATAVIEWITEM_H__
#include <wx/dataview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDataViewItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DataViewItem);

//----------------------------------------------------------------------------
// Object declaration for wxDataViewItem
//----------------------------------------------------------------------------
class Object_wx_DataViewItem : public Object {
protected:
	wxDataViewItem *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DataViewItem)
public:
	inline Object_wx_DataViewItem(wxDataViewItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DataViewItem(Class *pClass, wxDataViewItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DataViewItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDataViewItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDataViewItem *GetEntity() {
		return static_cast<wxDataViewItem *>(_pEntity);
	}
	inline wxDataViewItem *ReleaseEntity() {
		wxDataViewItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDataViewItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
