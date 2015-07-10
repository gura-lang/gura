//----------------------------------------------------------------------------
// wxDropSource
// extracted from dropsrc.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DROPSOURCE_H__
#define __CLASS_WX_DROPSOURCE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDropSource
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DropSource);

//----------------------------------------------------------------------------
// Object declaration for wxDropSource
//----------------------------------------------------------------------------
class Object_wx_DropSource : public Object {
protected:
	wxDropSource *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DropSource)
public:
	inline Object_wx_DropSource(wxDropSource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DropSource)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DropSource(Class *pClass, wxDropSource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DropSource();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDropSource *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDropSource *GetEntity() { return _pEntity; }
	inline wxDropSource *ReleaseEntity() {
		wxDropSource *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDropSource");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
