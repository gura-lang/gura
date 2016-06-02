//----------------------------------------------------------------------------
// wxEventLoopActivator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_EVENTLOOPACTIVATOR_H__
#define __CLASS_WX_EVENTLOOPACTIVATOR_H__
#include <wx/evtloop.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEventLoopActivator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EventLoopActivator);

//----------------------------------------------------------------------------
// Object declaration for wxEventLoopActivator
//----------------------------------------------------------------------------
class Object_wx_EventLoopActivator : public Object {
protected:
	wxEventLoopActivator *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_EventLoopActivator)
public:
	inline Object_wx_EventLoopActivator(wxEventLoopActivator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_EventLoopActivator(Class *pClass, wxEventLoopActivator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_EventLoopActivator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxEventLoopActivator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxEventLoopActivator *GetEntity() {
		return static_cast<wxEventLoopActivator *>(_pEntity);
	}
	inline wxEventLoopActivator *ReleaseEntity() {
		wxEventLoopActivator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxEventLoopActivator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
