//----------------------------------------------------------------------------
// wxStdInputStreamBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STDINPUTSTREAMBUFFER_H__
#define __CLASS_WX_STDINPUTSTREAMBUFFER_H__
#include <wx/stdstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStdInputStreamBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StdInputStreamBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxStdInputStreamBuffer
//----------------------------------------------------------------------------
class Object_wx_StdInputStreamBuffer : public Object {
protected:
	wxStdInputStreamBuffer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StdInputStreamBuffer)
public:
	inline Object_wx_StdInputStreamBuffer(wxStdInputStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StdInputStreamBuffer(Class *pClass, wxStdInputStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StdInputStreamBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStdInputStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStdInputStreamBuffer *GetEntity() {
		return static_cast<wxStdInputStreamBuffer *>(_pEntity);
	}
	inline wxStdInputStreamBuffer *ReleaseEntity() {
		wxStdInputStreamBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStdInputStreamBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
