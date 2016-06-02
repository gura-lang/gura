//----------------------------------------------------------------------------
// wxMessageQueue<T>
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MESSAGEQUEUE<T>_H__
#define __CLASS_WX_MESSAGEQUEUE<T>_H__
#include <wx/msgqueue.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMessageQueue<T>
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MessageQueue<T>);

//----------------------------------------------------------------------------
// Object declaration for wxMessageQueue<T>
//----------------------------------------------------------------------------
class Object_wx_MessageQueue<T> : public Object {
protected:
	wxMessageQueue<T> *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MessageQueue<T>)
public:
	inline Object_wx_MessageQueue<T>(wxMessageQueue<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MessageQueue<T>(Class *pClass, wxMessageQueue<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MessageQueue<T>();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxMessageQueue<T> *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxMessageQueue<T> *GetEntity() {
		return static_cast<wxMessageQueue<T> *>(_pEntity);
	}
	inline wxMessageQueue<T> *ReleaseEntity() {
		wxMessageQueue<T> *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxMessageQueue<T>");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
