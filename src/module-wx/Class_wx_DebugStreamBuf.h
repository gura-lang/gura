//----------------------------------------------------------------------------
// wxDebugStreamBuf
// extracted from debugcxt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DEBUGSTREAMBUF_H__
#define __CLASS_WX_DEBUGSTREAMBUF_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDebugStreamBuf
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DebugStreamBuf);

//----------------------------------------------------------------------------
// Object declaration for wxDebugStreamBuf
//----------------------------------------------------------------------------
class Object_wx_DebugStreamBuf : public Object {
protected:
	wxDebugStreamBuf *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_DebugStreamBuf)
public:
	inline Object_wx_DebugStreamBuf(wxDebugStreamBuf *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_DebugStreamBuf)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_DebugStreamBuf(Class *pClass, wxDebugStreamBuf *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_DebugStreamBuf();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxDebugStreamBuf *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxDebugStreamBuf *GetEntity() { return _pEntity; }
	inline wxDebugStreamBuf *ReleaseEntity() {
		wxDebugStreamBuf *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDebugStreamBuf");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
