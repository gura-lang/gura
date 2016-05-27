//----------------------------------------------------------------------------
// wxScopedArray
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCOPEDARRAY_H__
#define __CLASS_WX_SCOPEDARRAY_H__
#include <wx/scopedarray.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScopedArray
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScopedArray);

//----------------------------------------------------------------------------
// Object declaration for wxScopedArray
//----------------------------------------------------------------------------
class Object_wx_ScopedArray : public Object {
protected:
	wxScopedArray *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ScopedArray)
public:
	inline Object_wx_ScopedArray(wxScopedArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ScopedArray(Class *pClass, wxScopedArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ScopedArray();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxScopedArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxScopedArray *GetEntity() {
		return static_cast<wxScopedArray *>(_pEntity);
	}
	inline wxScopedArray *ReleaseEntity() {
		wxScopedArray *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxScopedArray");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
