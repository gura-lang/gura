//----------------------------------------------------------------------------
// wxObjectRefData
// extracted from object.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_OBJECTREFDATA_H__
#define __OBJECT_WX_OBJECTREFDATA_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxObjectRefData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ObjectRefData);

//----------------------------------------------------------------------------
// Object declaration for wxObjectRefData
//----------------------------------------------------------------------------
class Object_wx_ObjectRefData : public Object {
protected:
	wxObjectRefData *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ObjectRefData)
public:
	inline Object_wx_ObjectRefData(wxObjectRefData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ObjectRefData)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ObjectRefData(Class *pClass, wxObjectRefData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ObjectRefData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxObjectRefData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxObjectRefData *GetEntity() { return _pEntity; }
	inline wxObjectRefData *ReleaseEntity() {
		wxObjectRefData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxObjectRefData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
