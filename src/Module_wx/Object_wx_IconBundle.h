//----------------------------------------------------------------------------
// wxIconBundle
// extracted from iconbndl.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_ICONBUNDLE_H__
#define __OBJECT_WX_ICONBUNDLE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIconBundle
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IconBundle);

//----------------------------------------------------------------------------
// Object declaration for wxIconBundle
//----------------------------------------------------------------------------
class Object_wx_IconBundle : public Object {
protected:
	wxIconBundle *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_IconBundle)
public:
	inline Object_wx_IconBundle(wxIconBundle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_IconBundle)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_IconBundle(Class *pClass, wxIconBundle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_IconBundle();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxIconBundle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxIconBundle *GetEntity() { return _pEntity; }
	inline wxIconBundle *ReleaseEntity() {
		wxIconBundle *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxIconBundle");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
