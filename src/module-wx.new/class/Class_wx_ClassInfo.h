//----------------------------------------------------------------------------
// wxClassInfo
// extracted from clasinfo.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLASSINFO_H__
#define __CLASS_WX_CLASSINFO_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClassInfo
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClassInfo);

//----------------------------------------------------------------------------
// Object declaration for wxClassInfo
//----------------------------------------------------------------------------
class Object_wx_ClassInfo : public Object {
protected:
	wxClassInfo *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ClassInfo)
public:
	inline Object_wx_ClassInfo(wxClassInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ClassInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ClassInfo(Class *pClass, wxClassInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ClassInfo();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxClassInfo *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxClassInfo *GetEntity() { return _pEntity; }
	inline wxClassInfo *ReleaseEntity() {
		wxClassInfo *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxClassInfo");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
