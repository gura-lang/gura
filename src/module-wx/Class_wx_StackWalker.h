//----------------------------------------------------------------------------
// wxStackWalker
// extracted from stackwalker.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STACKWALKER_H__
#define __CLASS_WX_STACKWALKER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStackWalker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StackWalker);

//----------------------------------------------------------------------------
// Object declaration for wxStackWalker
//----------------------------------------------------------------------------
class Object_wx_StackWalker : public Object {
protected:
	wxStackWalker *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StackWalker)
public:
	inline Object_wx_StackWalker(wxStackWalker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StackWalker)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StackWalker(Class *pClass, wxStackWalker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StackWalker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStackWalker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStackWalker *GetEntity() { return _pEntity; }
	inline wxStackWalker *ReleaseEntity() {
		wxStackWalker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStackWalker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
