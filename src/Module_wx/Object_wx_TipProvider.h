//----------------------------------------------------------------------------
// wxTipProvider
// extracted from tipprov.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TIPPROVIDER_H__
#define __OBJECT_WX_TIPPROVIDER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTipProvider
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TipProvider);

//----------------------------------------------------------------------------
// Object declaration for wxTipProvider
//----------------------------------------------------------------------------
class Object_wx_TipProvider : public Object {
protected:
	wxTipProvider *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_TipProvider)
public:
	inline Object_wx_TipProvider(wxTipProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_TipProvider)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_TipProvider(Class *pClass, wxTipProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_TipProvider();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxTipProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxTipProvider *GetEntity() { return _pEntity; }
	inline wxTipProvider *ReleaseEntity() {
		wxTipProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTipProvider");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
