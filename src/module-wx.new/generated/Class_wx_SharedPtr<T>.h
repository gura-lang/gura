//----------------------------------------------------------------------------
// wxSharedPtr<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SHAREDPTR<T>_H__
#define __CLASS_WX_SHAREDPTR<T>_H__
#include <wx/sharedptr.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSharedPtr<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SharedPtr<T>);

//----------------------------------------------------------------------------
// Object declaration for wxSharedPtr<T>
//----------------------------------------------------------------------------
class Object_wx_SharedPtr<T> : public Object {
protected:
	wxSharedPtr<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SharedPtr<T>)
public:
	inline Object_wx_SharedPtr<T>(wxSharedPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SharedPtr<T>(Class *pClass, wxSharedPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SharedPtr<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSharedPtr<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxSharedPtr<T> *GetEntity() {
		return static_cast<wxSharedPtr<T> *>(_pEntity);
	}
	inline wxSharedPtr<T> *ReleaseEntity() {
		wxSharedPtr<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxSharedPtr<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
