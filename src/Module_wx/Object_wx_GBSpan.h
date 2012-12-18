//----------------------------------------------------------------------------
// wxGBSpan
// extracted from gbspan.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GBSPAN_H__
#define __OBJECT_WX_GBSPAN_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGBSpan
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GBSpan);

//----------------------------------------------------------------------------
// Object declaration for wxGBSpan
//----------------------------------------------------------------------------
class Object_wx_GBSpan : public Object {
protected:
	wxGBSpan *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_GBSpan)
public:
	inline Object_wx_GBSpan(wxGBSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_GBSpan)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_GBSpan(Class *pClass, wxGBSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_GBSpan();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxGBSpan *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxGBSpan *GetEntity() { return _pEntity; }
	inline wxGBSpan *ReleaseEntity() {
		wxGBSpan *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGBSpan");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
