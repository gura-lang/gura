//----------------------------------------------------------------------------
// wxWeakRefDynamic<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEAKREFDYNAMIC<T>_H__
#define __CLASS_WX_WEAKREFDYNAMIC<T>_H__
#include <wx/weakref.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWeakRefDynamic<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WeakRefDynamic<T>);

//----------------------------------------------------------------------------
// Object declaration for wxWeakRefDynamic<T>
//----------------------------------------------------------------------------
class Object_wx_WeakRefDynamic<T> : public Object {
protected:
	wxWeakRefDynamic<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_WeakRefDynamic<T>)
public:
	inline Object_wx_WeakRefDynamic<T>(wxWeakRefDynamic<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_WeakRefDynamic<T>(Class *pClass, wxWeakRefDynamic<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_WeakRefDynamic<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxWeakRefDynamic<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxWeakRefDynamic<T> *GetEntity() {
		return static_cast<wxWeakRefDynamic<T> *>(_pEntity);
	}
	inline wxWeakRefDynamic<T> *ReleaseEntity() {
		wxWeakRefDynamic<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWeakRefDynamic<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
