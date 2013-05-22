//----------------------------------------------------------------------------
// wxConfigBase
// extracted from config.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CONFIGBASE_H__
#define __OBJECT_WX_CONFIGBASE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxConfigBase
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ConfigBase);

//----------------------------------------------------------------------------
// Object declaration for wxConfigBase
//----------------------------------------------------------------------------
class Object_wx_ConfigBase : public Object {
protected:
	wxConfigBase *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ConfigBase)
public:
	inline Object_wx_ConfigBase(wxConfigBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ConfigBase)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ConfigBase(Class *pClass, wxConfigBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ConfigBase();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxConfigBase *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxConfigBase *GetEntity() { return _pEntity; }
	inline wxConfigBase *ReleaseEntity() {
		wxConfigBase *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxConfigBase");
		return true;
	}
};

}}

#endif
