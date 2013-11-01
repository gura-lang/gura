//----------------------------------------------------------------------------
// wxAppConsole
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_APPCONSOLE_H__
#define __CLASS_WX_APPCONSOLE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxAppConsole
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_AppConsole);

//----------------------------------------------------------------------------
// Object declaration for wxAppConsole
//----------------------------------------------------------------------------
class Object_wx_AppConsole : public Object {
protected:
	wxAppConsole *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_AppConsole)
public:
	inline Object_wx_AppConsole(wxAppConsole *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AppConsole)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_AppConsole(Class *pClass, wxAppConsole *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_AppConsole();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxAppConsole *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxAppConsole *GetEntity() { return _pEntity; }
	inline wxAppConsole *ReleaseEntity() {
		wxAppConsole *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxAppConsole");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
