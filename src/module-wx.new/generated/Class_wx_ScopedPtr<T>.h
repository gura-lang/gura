//----------------------------------------------------------------------------
// wxScopedPtr<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCOPEDPTR<T>_H__
#define __CLASS_WX_SCOPEDPTR<T>_H__
#include <wx/scopedptr.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScopedPtr<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScopedPtr<T>);

//----------------------------------------------------------------------------
// Object declaration for wxScopedPtr<T>
//----------------------------------------------------------------------------
class Object_wx_ScopedPtr<T> : public Object {
protected:
	wxScopedPtr<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ScopedPtr<T>)
public:
	inline Object_wx_ScopedPtr<T>(wxScopedPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ScopedPtr<T>(Class *pClass, wxScopedPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ScopedPtr<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxScopedPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxScopedPtr<T> *GetEntity() {
		return static_cast<wxScopedPtr<T> *>(_pEntity);
	}
	inline wxScopedPtr<T> *ReleaseEntity() {
		wxScopedPtr<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxScopedPtr<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
