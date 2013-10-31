//----------------------------------------------------------------------------
// wxDirTraverser
// extracted from dirtrav.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DIRTRAVERSER_H__
#define __OBJECT_WX_DIRTRAVERSER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDirTraverser
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DirTraverser);

//----------------------------------------------------------------------------
// Object declaration for wxDirTraverser
//----------------------------------------------------------------------------
class Object_wx_DirTraverser : public Object {
protected:
	wxDirTraverser *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DirTraverser)
public:
	inline Object_wx_DirTraverser(wxDirTraverser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DirTraverser)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DirTraverser(Class *pClass, wxDirTraverser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DirTraverser();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDirTraverser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDirTraverser *GetEntity() { return _pEntity; }
	inline wxDirTraverser *ReleaseEntity() {
		wxDirTraverser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDirTraverser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
