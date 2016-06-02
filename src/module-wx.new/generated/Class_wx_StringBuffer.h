//----------------------------------------------------------------------------
// wxStringBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STRINGBUFFER_H__
#define __CLASS_WX_STRINGBUFFER_H__
#include <wx/string.h>

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
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_StringBuffer(Class *pClass, wxStringBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
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
	inline wxStringBuffer *GetEntity() {
		return static_cast<wxStringBuffer *>(_pEntity);
	}
	inline wxStringBuffer *ReleaseEntity() {
		wxStringBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStringBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
