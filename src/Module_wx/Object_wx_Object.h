//----------------------------------------------------------------------------
// wxObject
// extracted from object.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_OBJECT_H__
#define __OBJECT_WX_OBJECT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxObject
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Object);

//----------------------------------------------------------------------------
// Object declaration for wxObject
//----------------------------------------------------------------------------
class Object_wx_Object : public Object {
protected:
	wxObject *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_Object)
public:
	inline Object_wx_Object(wxObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_Object)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_Object(Class *pClass, wxObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_Object();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxObject *GetEntity() { return _pEntity; }
	inline wxObject *ReleaseEntity() {
		wxObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxObject");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

class wx_Object: public wxObject, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Object *_pObj;
public:
	inline wx_Object() : wxObject(), _sig(NULL), _pObj(NULL) {}
	inline wx_Object(const wxObject& other) : wxObject(other), _sig(NULL), _pObj(NULL) {}
	//inline wx_Object() : wxObject(), _sig(NULL), _pObj(NULL) {}
	~wx_Object();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Object *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

}}

#endif
