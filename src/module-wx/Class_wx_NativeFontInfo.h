//----------------------------------------------------------------------------
// wxNativeEncodingInfo
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NATIVEFONTINFO_H__
#define __CLASS_WX_NATIVEFONTINFO_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNativeFontInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NativeFontInfo);

//----------------------------------------------------------------------------
// Object declaration for wxNativeFontInfo
//----------------------------------------------------------------------------
class Object_wx_NativeFontInfo : public Object {
protected:
	wxNativeFontInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_NativeFontInfo)
public:
	inline Object_wx_NativeFontInfo(wxNativeFontInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_NativeFontInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_NativeFontInfo(Class *pClass, wxNativeFontInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_NativeFontInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxNativeFontInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxNativeFontInfo *GetEntity() { return _pEntity; }
	inline wxNativeFontInfo *ReleaseEntity() {
		wxNativeFontInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxNativeFontInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
