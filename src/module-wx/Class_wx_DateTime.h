//----------------------------------------------------------------------------
// wxDateTime
// extracted from datetime.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATETIME_H__
#define __OBJECT_WX_DATETIME_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDateTime
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DateTime);

//----------------------------------------------------------------------------
// Object declaration for wxDateTime
//----------------------------------------------------------------------------
class Object_wx_DateTime : public Object {
protected:
	wxDateTime *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DateTime)
public:
	inline Object_wx_DateTime(wxDateTime *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DateTime)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DateTime(Class *pClass, wxDateTime *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DateTime();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDateTime *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDateTime *GetEntity() { return _pEntity; }
	inline wxDateTime *ReleaseEntity() {
		wxDateTime *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDateTime");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
