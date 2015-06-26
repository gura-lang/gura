//----------------------------------------------------------------------------
// wxThread
// extracted from thread.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_THREAD_H__
#define __CLASS_WX_THREAD_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxThread
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Thread);

//----------------------------------------------------------------------------
// Object declaration for wxThread
//----------------------------------------------------------------------------
class Object_wx_Thread : public Object {
protected:
	wxThread *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Thread)
public:
	inline Object_wx_Thread(wxThread *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Thread)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Thread(Class *pClass, wxThread *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Thread();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxThread *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxThread *GetEntity() { return _pEntity; }
	inline wxThread *ReleaseEntity() {
		wxThread *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxThread");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
