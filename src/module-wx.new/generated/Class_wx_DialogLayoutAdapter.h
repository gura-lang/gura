//----------------------------------------------------------------------------
// wxDialogLayoutAdapter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIALOGLAYOUTADAPTER_H__
#define __CLASS_WX_DIALOGLAYOUTADAPTER_H__
#include <wx/dialog.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDialogLayoutAdapter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DialogLayoutAdapter);

//----------------------------------------------------------------------------
// Object declaration for wxDialogLayoutAdapter
//----------------------------------------------------------------------------
class Object_wx_DialogLayoutAdapter : public Object {
protected:
	wxDialogLayoutAdapter *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DialogLayoutAdapter)
public:
	inline Object_wx_DialogLayoutAdapter(wxDialogLayoutAdapter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DialogLayoutAdapter(Class *pClass, wxDialogLayoutAdapter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DialogLayoutAdapter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDialogLayoutAdapter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDialogLayoutAdapter *GetEntity() {
		return static_cast<wxDialogLayoutAdapter *>(_pEntity);
	}
	inline wxDialogLayoutAdapter *ReleaseEntity() {
		wxDialogLayoutAdapter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDialogLayoutAdapter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
