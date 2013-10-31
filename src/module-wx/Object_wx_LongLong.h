//----------------------------------------------------------------------------
// wxLongLong
// extracted from longlong.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LONGLONG_H__
#define __OBJECT_WX_LONGLONG_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLongLong
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_LongLong);

//----------------------------------------------------------------------------
// Object declaration for wxLongLong
//----------------------------------------------------------------------------
class Object_wx_LongLong : public Object {
protected:
	wxLongLong *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_LongLong)
public:
	inline Object_wx_LongLong(wxLongLong *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_LongLong)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_LongLong(Class *pClass, wxLongLong *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_LongLong();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxLongLong *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxLongLong *GetEntity() { return _pEntity; }
	inline wxLongLong *ReleaseEntity() {
		wxLongLong *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxLongLong");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
