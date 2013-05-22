//----------------------------------------------------------------------------
// wxListItemAttr
// extracted from listattr.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_LISTITEMATTR_H__
#define __OBJECT_WX_LISTITEMATTR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListItemAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListItemAttr);

//----------------------------------------------------------------------------
// Object declaration for wxListItemAttr
//----------------------------------------------------------------------------
class Object_wx_ListItemAttr : public Object {
protected:
	wxListItemAttr *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ListItemAttr)
public:
	inline Object_wx_ListItemAttr(wxListItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_ListItemAttr)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ListItemAttr(Class *pClass, wxListItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ListItemAttr();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxListItemAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxListItemAttr *GetEntity() { return _pEntity; }
	inline wxListItemAttr *ReleaseEntity() {
		wxListItemAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxListItemAttr");
		return true;
	}
};

}}

#endif
