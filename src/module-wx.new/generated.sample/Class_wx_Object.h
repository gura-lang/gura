//----------------------------------------------------------------------------
// wxObject
// extracted from object.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_CLASS_H__
#define __CLASS_WX_CLASS_H__

Gura_BeginModuleScope(wx)

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
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxObject *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxObject *GetEntity() { return _pEntity; }
	inline wxObject *ReleaseEntity() {
		wxObject *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxObject");
		return true;
	}
};

class wx_Object: public wxObject, public GuraObjectObserver {
private:
	Object_wx_Object *_pObj;
public:
	inline wx_Object() : wxObject(), _pObj(nullptr) {}
	inline wx_Object(const wxObject& other) : wxObject(other), _pObj(nullptr) {}
	//inline wx_Object() : wxObject(), _pObj(nullptr) {}
	~wx_Object();
	inline void AssocWithGura(Object_wx_Object *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

Gura_EndModuleScope(wx)

#endif
