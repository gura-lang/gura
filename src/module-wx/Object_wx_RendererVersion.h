//----------------------------------------------------------------------------
// wxRendererVersion
// extracted from rendver.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_RENDERERVERSION_H__
#define __OBJECT_WX_RENDERERVERSION_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRendererVersion
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RendererVersion);

//----------------------------------------------------------------------------
// Object declaration for wxRendererVersion
//----------------------------------------------------------------------------
class Object_wx_RendererVersion : public Object {
protected:
	wxRendererVersion *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RendererVersion)
public:
	inline Object_wx_RendererVersion(wxRendererVersion *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RendererVersion)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RendererVersion(Class *pClass, wxRendererVersion *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RendererVersion();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxRendererVersion *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxRendererVersion *GetEntity() { return _pEntity; }
	inline wxRendererVersion *ReleaseEntity() {
		wxRendererVersion *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRendererVersion");
		return true;
	}
};

}}

#endif
