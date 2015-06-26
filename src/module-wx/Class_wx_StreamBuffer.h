//----------------------------------------------------------------------------
// wxStreamBuffer
// extracted from stream.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STREAMBUFFER_H__
#define __CLASS_WX_STREAMBUFFER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStreamBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StreamBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxStreamBuffer
//----------------------------------------------------------------------------
class Object_wx_StreamBuffer : public Object {
protected:
	wxStreamBuffer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StreamBuffer)
public:
	inline Object_wx_StreamBuffer(wxStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StreamBuffer)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StreamBuffer(Class *pClass, wxStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StreamBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStreamBuffer *GetEntity() { return _pEntity; }
	inline wxStreamBuffer *ReleaseEntity() {
		wxStreamBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStreamBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
