//----------------------------------------------------------------------------
// wxDebugContext
// extracted from debugcxt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DEBUGCONTEXT_H__
#define __OBJECT_WX_DEBUGCONTEXT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDebugContext
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DebugContext);

//----------------------------------------------------------------------------
// Object declaration for wxDebugContext
//----------------------------------------------------------------------------
class Object_wx_DebugContext : public Object {
protected:
	wxDebugContext *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DebugContext)
public:
	inline Object_wx_DebugContext(wxDebugContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DebugContext)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DebugContext(Class *pClass, wxDebugContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DebugContext();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxDebugContext *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDebugContext *GetEntity() { return _pEntity; }
	inline wxDebugContext *ReleaseEntity() {
		wxDebugContext *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDebugContext");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
