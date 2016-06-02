//----------------------------------------------------------------------------
// wxEventFilter
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_EVENTFILTER_H__
#define __CLASS_WX_EVENTFILTER_H__
#include <wx/eventfilter.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEventFilter
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EventFilter);

//----------------------------------------------------------------------------
// Object declaration for wxEventFilter
//----------------------------------------------------------------------------
class Object_wx_EventFilter : public Object {
protected:
	wxEventFilter *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_EventFilter)
public:
	inline Object_wx_EventFilter(wxEventFilter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_EventFilter(Class *pClass, wxEventFilter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_EventFilter();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxEventFilter *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxEventFilter *GetEntity() {
		return static_cast<wxEventFilter *>(_pEntity);
	}
	inline wxEventFilter *ReleaseEntity() {
		wxEventFilter *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxEventFilter");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
