//----------------------------------------------------------------------------
// wxLocale
// extracted from locale.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LOCALE_H__
#define __CLASS_WX_LOCALE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxLocale
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Locale);

//----------------------------------------------------------------------------
// Object declaration for wxLocale
//----------------------------------------------------------------------------
class Object_wx_Locale : public Object {
protected:
	wxLocale *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Locale)
public:
	inline Object_wx_Locale(wxLocale *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Locale)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Locale(Class *pClass, wxLocale *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Locale();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxLocale *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxLocale *GetEntity() { return _pEntity; }
	inline wxLocale *ReleaseEntity() {
		wxLocale *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxLocale");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
