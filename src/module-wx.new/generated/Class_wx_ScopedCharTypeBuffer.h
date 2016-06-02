//----------------------------------------------------------------------------
// wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SCOPEDCHARTYPEBUFFER_H__
#define __CLASS_WX_SCOPEDCHARTYPEBUFFER_H__
#include <wx/buffer.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ScopedCharTypeBuffer);

//----------------------------------------------------------------------------
// Object declaration for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
class Object_wx_ScopedCharTypeBuffer : public Object {
protected:
	wxScopedCharTypeBuffer *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_ScopedCharTypeBuffer)
public:
	inline Object_wx_ScopedCharTypeBuffer(wxScopedCharTypeBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_ScopedCharTypeBuffer(Class *pClass, wxScopedCharTypeBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_ScopedCharTypeBuffer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxScopedCharTypeBuffer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxScopedCharTypeBuffer *GetEntity() {
		return static_cast<wxScopedCharTypeBuffer *>(_pEntity);
	}
	inline wxScopedCharTypeBuffer *ReleaseEntity() {
		wxScopedCharTypeBuffer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxScopedCharTypeBuffer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
