//----------------------------------------------------------------------------
// wxDCClipper
// extracted from dcclipper.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DCCLIPPER_H__
#define __OBJECT_WX_DCCLIPPER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDCClipper
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DCClipper);

//----------------------------------------------------------------------------
// Object declaration for wxDCClipper
//----------------------------------------------------------------------------
class Object_wx_DCClipper : public Object {
protected:
	wxDCClipper *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DCClipper)
public:
	inline Object_wx_DCClipper(wxDCClipper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DCClipper)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DCClipper(Class *pClass, wxDCClipper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DCClipper();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDCClipper *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDCClipper *GetEntity() { return _pEntity; }
	inline wxDCClipper *ReleaseEntity() {
		wxDCClipper *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDCClipper");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
