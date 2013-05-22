//----------------------------------------------------------------------------
// wxDisplay
// extracted from display.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DISPLAY_H__
#define __OBJECT_WX_DISPLAY_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDisplay
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Display);

//----------------------------------------------------------------------------
// Object declaration for wxDisplay
//----------------------------------------------------------------------------
class Object_wx_Display : public Object {
protected:
	wxDisplay *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Display)
public:
	inline Object_wx_Display(wxDisplay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Display)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Display(Class *pClass, wxDisplay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Display();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDisplay *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDisplay *GetEntity() { return _pEntity; }
	inline wxDisplay *ReleaseEntity() {
		wxDisplay *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDisplay");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
