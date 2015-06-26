//----------------------------------------------------------------------------
// wxMouseState
// (handcoded)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MOUSESTATE_H__
#define __CLASS_WX_MOUSESTATE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMouseState
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MouseState);

//----------------------------------------------------------------------------
// Object declaration for wxMouseState
//----------------------------------------------------------------------------
class Object_wx_MouseState : public Object {
protected:
	wxMouseState *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MouseState)
public:
	inline Object_wx_MouseState(wxMouseState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_MouseState)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MouseState(Class *pClass, wxMouseState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MouseState();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxMouseState *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxMouseState *GetEntity() { return _pEntity; }
	inline wxMouseState *ReleaseEntity() {
		wxMouseState *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMouseState");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
