//----------------------------------------------------------------------------
// wxStringBuffer
// extracted from wxstring.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STRINGBUFFER_H__
#define __CLASS_WX_STRINGBUFFER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStringBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StringBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxStringBuffer
//----------------------------------------------------------------------------
class Object_wx_StringBuffer : public Object {
protected:
	wxStringBuffer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StringBuffer)
public:
	inline Object_wx_StringBuffer(wxStringBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_StringBuffer)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StringBuffer(Class *pClass, wxStringBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StringBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStringBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStringBuffer *GetEntity() { return _pEntity; }
	inline wxStringBuffer *ReleaseEntity() {
		wxStringBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStringBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
