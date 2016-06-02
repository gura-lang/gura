//----------------------------------------------------------------------------
// wxCriticalSection
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CRITICALSECTION_H__
#define __CLASS_WX_CRITICALSECTION_H__
#include <wx/thread.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCriticalSection
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CriticalSection);

//----------------------------------------------------------------------------
// Object declaration for wxCriticalSection
//----------------------------------------------------------------------------
class Object_wx_CriticalSection : public Object {
protected:
	wxCriticalSection *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_CriticalSection)
public:
	inline Object_wx_CriticalSection(wxCriticalSection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_CriticalSection(Class *pClass, wxCriticalSection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_CriticalSection();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxCriticalSection *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxCriticalSection *GetEntity() {
		return static_cast<wxCriticalSection *>(_pEntity);
	}
	inline wxCriticalSection *ReleaseEntity() {
		wxCriticalSection *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxCriticalSection");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
