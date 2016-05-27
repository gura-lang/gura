//----------------------------------------------------------------------------
// wxSemaphore
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SEMAPHORE_H__
#define __CLASS_WX_SEMAPHORE_H__
#include <wx/thread.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSemaphore
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Semaphore);

//----------------------------------------------------------------------------
// Object declaration for wxSemaphore
//----------------------------------------------------------------------------
class Object_wx_Semaphore : public Object {
protected:
	wxSemaphore *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Semaphore)
public:
	inline Object_wx_Semaphore(wxSemaphore *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Semaphore(Class *pClass, wxSemaphore *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Semaphore();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSemaphore *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxSemaphore *GetEntity() {
		return static_cast<wxSemaphore *>(_pEntity);
	}
	inline wxSemaphore *ReleaseEntity() {
		wxSemaphore *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSemaphore");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
