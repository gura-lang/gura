//----------------------------------------------------------------------------
// wxStdOutputStreamBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STDOUTPUTSTREAMBUFFER_H__
#define __CLASS_WX_STDOUTPUTSTREAMBUFFER_H__
#include <wx/stdstream.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStdOutputStreamBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StdOutputStreamBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxStdOutputStreamBuffer
//----------------------------------------------------------------------------
class Object_wx_StdOutputStreamBuffer : public Object {
protected:
	wxStdOutputStreamBuffer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_StdOutputStreamBuffer)
public:
	inline Object_wx_StdOutputStreamBuffer(wxStdOutputStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StdOutputStreamBuffer(Class *pClass, wxStdOutputStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_StdOutputStreamBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxStdOutputStreamBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxStdOutputStreamBuffer *GetEntity() {
		return static_cast<wxStdOutputStreamBuffer *>(_pEntity);
	}
	inline wxStdOutputStreamBuffer *ReleaseEntity() {
		wxStdOutputStreamBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStdOutputStreamBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
