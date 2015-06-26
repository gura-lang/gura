//----------------------------------------------------------------------------
// wxSizerFlags
// extracted from sizer.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SIZERFLAGS_H__
#define __CLASS_WX_SIZERFLAGS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSizerFlags
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SizerFlags);

//----------------------------------------------------------------------------
// Object declaration for wxSizerFlags
//----------------------------------------------------------------------------
class Object_wx_SizerFlags : public Object {
protected:
	wxSizerFlags *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_SizerFlags)
public:
	inline Object_wx_SizerFlags(wxSizerFlags *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_SizerFlags)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_SizerFlags(Class *pClass, wxSizerFlags *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_SizerFlags();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxSizerFlags *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxSizerFlags *GetEntity() { return _pEntity; }
	inline wxSizerFlags *ReleaseEntity() {
		wxSizerFlags *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSizerFlags");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
