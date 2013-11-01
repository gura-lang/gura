//----------------------------------------------------------------------------
// wxStandardPaths
// extracted from stdpaths.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STANDARDPATHS_H__
#define __CLASS_WX_STANDARDPATHS_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStandardPaths
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StandardPaths);

//----------------------------------------------------------------------------
// Object declaration for wxStandardPaths
//----------------------------------------------------------------------------
class Object_wx_StandardPaths : public Object {
protected:
	wxStandardPaths *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StandardPaths)
public:
	inline Object_wx_StandardPaths(wxStandardPaths *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StandardPaths)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StandardPaths(Class *pClass, wxStandardPaths *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StandardPaths();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStandardPaths *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxStandardPaths *GetEntity() { return _pEntity; }
	inline wxStandardPaths *ReleaseEntity() {
		wxStandardPaths *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxStandardPaths");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
