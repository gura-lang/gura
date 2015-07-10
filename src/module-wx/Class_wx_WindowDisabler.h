//----------------------------------------------------------------------------
// wxWindowDisabler
// extracted from wnddisbl.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOWDISABLER_H__
#define __CLASS_WX_WINDOWDISABLER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WindowDisabler);

//----------------------------------------------------------------------------
// Object declaration for wxWindowDisabler
//----------------------------------------------------------------------------
class Object_wx_WindowDisabler : public Object {
protected:
	wxWindowDisabler *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_WindowDisabler)
public:
	inline Object_wx_WindowDisabler(wxWindowDisabler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_WindowDisabler)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_WindowDisabler(Class *pClass, wxWindowDisabler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_WindowDisabler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxWindowDisabler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxWindowDisabler *GetEntity() { return _pEntity; }
	inline wxWindowDisabler *ReleaseEntity() {
		wxWindowDisabler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWindowDisabler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
