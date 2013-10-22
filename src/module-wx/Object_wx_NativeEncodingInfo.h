//----------------------------------------------------------------------------
// wxNativeEncodingInfo
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_NATIVEENCODINGINFO_H__
#define __OBJECT_WX_NATIVEENCODINGINFO_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNativeEncodingInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NativeEncodingInfo);

//----------------------------------------------------------------------------
// Object declaration for wxNativeEncodingInfo
//----------------------------------------------------------------------------
class Object_wx_NativeEncodingInfo : public Object {
protected:
	wxNativeEncodingInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_NativeEncodingInfo)
public:
	inline Object_wx_NativeEncodingInfo(wxNativeEncodingInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_NativeEncodingInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_NativeEncodingInfo(Class *pClass, wxNativeEncodingInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_NativeEncodingInfo();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxNativeEncodingInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxNativeEncodingInfo *GetEntity() { return _pEntity; }
	inline wxNativeEncodingInfo *ReleaseEntity() {
		wxNativeEncodingInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxNativeEncodingInfo");
		return true;
	}
};

}}

#endif
