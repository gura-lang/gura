//----------------------------------------------------------------------------
// wxMemoryBuffer
// extracted from membuf.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MEMORYBUFFER_H__
#define __OBJECT_WX_MEMORYBUFFER_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MemoryBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxMemoryBuffer
//----------------------------------------------------------------------------
class Object_wx_MemoryBuffer : public Object {
protected:
	wxMemoryBuffer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_MemoryBuffer)
public:
	inline Object_wx_MemoryBuffer(wxMemoryBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_MemoryBuffer)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_MemoryBuffer(Class *pClass, wxMemoryBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_MemoryBuffer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxMemoryBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxMemoryBuffer *GetEntity() { return _pEntity; }
	inline wxMemoryBuffer *ReleaseEntity() {
		wxMemoryBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMemoryBuffer");
		return true;
	}
};

}}

#endif
