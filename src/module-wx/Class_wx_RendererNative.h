//----------------------------------------------------------------------------
// wxRendererNative
// extracted from renderer.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_RENDERERNATIVE_H__
#define __CLASS_WX_RENDERERNATIVE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRendererNative
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_RendererNative);

//----------------------------------------------------------------------------
// Object declaration for wxRendererNative
//----------------------------------------------------------------------------
class Object_wx_RendererNative : public Object {
protected:
	wxRendererNative *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_RendererNative)
public:
	inline Object_wx_RendererNative(wxRendererNative *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_RendererNative)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_RendererNative(Class *pClass, wxRendererNative *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_RendererNative();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxRendererNative *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxRendererNative *GetEntity() { return _pEntity; }
	inline wxRendererNative *ReleaseEntity() {
		wxRendererNative *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxRendererNative");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
