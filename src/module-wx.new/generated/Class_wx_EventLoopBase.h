//----------------------------------------------------------------------------
// wxEventLoopBase
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_EVENTLOOPBASE_H__
#define __CLASS_WX_EVENTLOOPBASE_H__
#include <wx/evtloop.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEventLoopBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EventLoopBase);

//----------------------------------------------------------------------------
// Object declaration for wxEventLoopBase
//----------------------------------------------------------------------------
class Object_wx_EventLoopBase : public Object {
protected:
	wxEventLoopBase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_EventLoopBase)
public:
	inline Object_wx_EventLoopBase(wxEventLoopBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_EventLoopBase(Class *pClass, wxEventLoopBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_EventLoopBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxEventLoopBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxEventLoopBase *GetEntity() {
		return static_cast<wxEventLoopBase *>(_pEntity);
	}
	inline wxEventLoopBase *ReleaseEntity() {
		wxEventLoopBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxEventLoopBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
