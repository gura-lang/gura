//----------------------------------------------------------------------------
// wxDateSpan
// extracted from datespan.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DATESPAN_H__
#define __CLASS_WX_DATESPAN_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDateSpan
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DateSpan);

//----------------------------------------------------------------------------
// Object declaration for wxDateSpan
//----------------------------------------------------------------------------
class Object_wx_DateSpan : public Object {
protected:
	wxDateSpan *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DateSpan)
public:
	inline Object_wx_DateSpan(wxDateSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DateSpan)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DateSpan(Class *pClass, wxDateSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DateSpan();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDateSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDateSpan *GetEntity() { return _pEntity; }
	inline wxDateSpan *ReleaseEntity() {
		wxDateSpan *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDateSpan");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
