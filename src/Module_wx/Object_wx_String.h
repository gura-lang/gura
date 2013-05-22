//----------------------------------------------------------------------------
// wxString
// extracted from wxstring.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_STRING_H__
#define __OBJECT_WX_STRING_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxString
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_String);

//----------------------------------------------------------------------------
// Object declaration for wxString
//----------------------------------------------------------------------------
class Object_wx_String : public Object {
protected:
	wxString *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_String)
public:
	inline Object_wx_String(wxString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_String)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_String(Class *pClass, wxString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_String();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxString *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxString *GetEntity() { return _pEntity; }
	inline wxString *ReleaseEntity() {
		wxString *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxString");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
