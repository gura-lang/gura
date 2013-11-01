//----------------------------------------------------------------------------
// wxTimeSpan
// extracted from timespan.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TIMESPAN_H__
#define __CLASS_WX_TIMESPAN_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTimeSpan
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TimeSpan);

//----------------------------------------------------------------------------
// Object declaration for wxTimeSpan
//----------------------------------------------------------------------------
class Object_wx_TimeSpan : public Object {
protected:
	wxTimeSpan *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TimeSpan)
public:
	inline Object_wx_TimeSpan(wxTimeSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_TimeSpan)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TimeSpan(Class *pClass, wxTimeSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TimeSpan();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxTimeSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxTimeSpan *GetEntity() { return _pEntity; }
	inline wxTimeSpan *ReleaseEntity() {
		wxTimeSpan *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTimeSpan");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
