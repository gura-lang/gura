//----------------------------------------------------------------------------
// wxList
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LIST_H__
#define __OBJECT_WX_LIST_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_List);

//----------------------------------------------------------------------------
// Object declaration for wxList
//----------------------------------------------------------------------------
class Object_wx_List : public Object {
protected:
	wxList *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_List)
public:
	inline Object_wx_List(wxList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_List)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_List(Class *pClass, wxList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_List();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxList *GetEntity() { return _pEntity; }
	inline wxList *ReleaseEntity() {
		wxList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxList");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
