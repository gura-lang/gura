//----------------------------------------------------------------------------
// wxStreamBase
// extracted from strmbase.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STREAMBASE_H__
#define __CLASS_WX_STREAMBASE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStreamBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StreamBase);

//----------------------------------------------------------------------------
// Object declaration for wxStreamBase
//----------------------------------------------------------------------------
class Object_wx_StreamBase : public Object {
protected:
	wxStreamBase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StreamBase)
public:
	inline Object_wx_StreamBase(wxStreamBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StreamBase)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StreamBase(Class *pClass, wxStreamBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StreamBase();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStreamBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStreamBase *GetEntity() { return _pEntity; }
	inline wxStreamBase *ReleaseEntity() {
		wxStreamBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStreamBase");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
