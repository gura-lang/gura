//----------------------------------------------------------------------------
// wxHashMap
// extracted from hashmap.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HASHMAP_H__
#define __OBJECT_WX_HASHMAP_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHashMap
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HashMap);

//----------------------------------------------------------------------------
// Object declaration for wxHashMap
//----------------------------------------------------------------------------
class Object_wx_HashMap : public Object {
protected:
	wxHashMap *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HashMap)
public:
	inline Object_wx_HashMap(wxHashMap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_HashMap)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HashMap(Class *pClass, wxHashMap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HashMap();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxHashMap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxHashMap *GetEntity() { return _pEntity; }
	inline wxHashMap *ReleaseEntity() {
		wxHashMap *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHashMap");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
