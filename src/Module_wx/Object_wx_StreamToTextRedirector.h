//----------------------------------------------------------------------------
// wxStreamToTextRedirector
// extracted from strtotxt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STREAMTOTEXTREDIRECTOR_H__
#define __OBJECT_WX_STREAMTOTEXTREDIRECTOR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStreamToTextRedirector
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StreamToTextRedirector);

//----------------------------------------------------------------------------
// Object declaration for wxStreamToTextRedirector
//----------------------------------------------------------------------------
class Object_wx_StreamToTextRedirector : public Object {
protected:
	wxStreamToTextRedirector *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StreamToTextRedirector)
public:
	inline Object_wx_StreamToTextRedirector(wxStreamToTextRedirector *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StreamToTextRedirector)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StreamToTextRedirector(Class *pClass, wxStreamToTextRedirector *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StreamToTextRedirector();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxStreamToTextRedirector *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxStreamToTextRedirector *GetEntity() { return _pEntity; }
	inline wxStreamToTextRedirector *ReleaseEntity() {
		wxStreamToTextRedirector *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStreamToTextRedirector");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
