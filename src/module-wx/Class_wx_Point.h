//----------------------------------------------------------------------------
// wxPoint
// extracted from point.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_POINT_H__
#define __CLASS_WX_POINT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPoint
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Point);

//----------------------------------------------------------------------------
// Object declaration for wxPoint
//----------------------------------------------------------------------------
class Object_wx_Point : public Object {
protected:
	wxPoint *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Point)
public:
	inline Object_wx_Point(wxPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Point)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Point(Class *pClass, wxPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Point();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxPoint *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxPoint *GetEntity() { return _pEntity; }
	inline wxPoint *ReleaseEntity() {
		wxPoint *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPoint");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
