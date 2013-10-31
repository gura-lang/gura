//----------------------------------------------------------------------------
// wxBusyCursor
// extracted from busycurs.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_BUSYCURSOR_H__
#define __OBJECT_WX_BUSYCURSOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBusyCursor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_BusyCursor);

//----------------------------------------------------------------------------
// Object declaration for wxBusyCursor
//----------------------------------------------------------------------------
class Object_wx_BusyCursor : public Object {
protected:
	wxBusyCursor *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_BusyCursor)
public:
	inline Object_wx_BusyCursor(wxBusyCursor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_BusyCursor)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_BusyCursor(Class *pClass, wxBusyCursor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_BusyCursor();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxBusyCursor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxBusyCursor *GetEntity() { return _pEntity; }
	inline wxBusyCursor *ReleaseEntity() {
		wxBusyCursor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxBusyCursor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
