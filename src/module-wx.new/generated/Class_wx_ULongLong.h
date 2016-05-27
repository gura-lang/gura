//----------------------------------------------------------------------------
// wxULongLong
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ULONGLONG_H__
#define __CLASS_WX_ULONGLONG_H__
#include <wx/longlong.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxULongLong
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ULongLong);

//----------------------------------------------------------------------------
// Object declaration for wxULongLong
//----------------------------------------------------------------------------
class Object_wx_ULongLong : public Object {
protected:
	wxULongLong *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ULongLong)
public:
	inline Object_wx_ULongLong(wxULongLong *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ULongLong(Class *pClass, wxULongLong *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ULongLong();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxULongLong *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxULongLong *GetEntity() {
		return static_cast<wxULongLong *>(_pEntity);
	}
	inline wxULongLong *ReleaseEntity() {
		wxULongLong *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxULongLong");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
