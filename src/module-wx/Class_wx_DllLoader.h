//----------------------------------------------------------------------------
// wxDllLoader
// extracted from dllload.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DLLLOADER_H__
#define __CLASS_WX_DLLLOADER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDllLoader
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DllLoader);

//----------------------------------------------------------------------------
// Object declaration for wxDllLoader
//----------------------------------------------------------------------------
class Object_wx_DllLoader : public Object {
protected:
	wxDllLoader *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DllLoader)
public:
	inline Object_wx_DllLoader(wxDllLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DllLoader)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DllLoader(Class *pClass, wxDllLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DllLoader();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDllLoader *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxDllLoader *GetEntity() { return _pEntity; }
	inline wxDllLoader *ReleaseEntity() {
		wxDllLoader *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDllLoader");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
